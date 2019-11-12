
/* DESIGN BY HAO NHAT HAO
           2019
*/
#include <SimpleTimer.h>
#include <Wire.h>                                   //Thư viện Wire giao tiếp I2C
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "CONSTANT.h"
#include <EEPROM.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);

SimpleTimer timer;

char Data[17] = "123";
char Master[17] = "";

char message_out[17] = "";
char message_out_master[17] = "";

char message_in[17] = "";
char message_in_master[17] = "";

char displayMessage_out[17] = "";
char displayMessage_in[17] = "";

byte data_count = 0, master_count = 0, data_mess_count = 0;

int letter = 0;
int currentPosition = 0;

int second, minute, hour, day, wday, month, year;   //Biến lưu giá trị
unsigned long duration_1;                           // biến đo thời gian
unsigned long duration_2;                           // biến đo thời gian
int distance_1;
int distance_2;   // biến lưu khoảng cách

int num = 0;
String date = "";
boolean checkOne = false;
boolean checkTwo = false;
boolean isClearMenu = true;
boolean isClearOne = true;
boolean isClearTwo = true;


boolean isshowSetting = true;
boolean ishowMessageDisplay = true;
boolean isshowCurrentPassDisplay = true;

int arr[2];

int state = 0; // state = 0 => không nhấn, state = 1 => nhấn nút, state = 2 => giữ lâu
char key = 0;
char choosen;
char choosenMess;
boolean mode = false; // mode = true => vào setting, mode = false => trở lại main
boolean iscorrect = false;
boolean completePassword = false;
boolean completeMessage  = false ;


//cài đặt thư viện keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);

void setup()
{
  Wire.begin();  //Khai báo giao thức I2C
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(trig_1, OUTPUT);  // chân trig sẽ phát tín hiệu
  pinMode(echo_1, INPUT);   // chân echo sẽ nhận tín hiệu
  pinMode(trig_2, OUTPUT);  // chân trig sẽ phát tín hiệu
  pinMode(echo_2, INPUT);   // chân echo sẽ nhận tín hiệu
  Serial.begin(9600);

  readPassword();  
  readMsgIn();
  readMsgOut();
}

void loop()
{
  if (!Serial.available())                           //Nếu không có tín hiệu Serial
  {
    ReadDS1307();
  }                                                  //Đọc từ RTC
  else                                               //Ngược lại
  {
    ReadSerial();                                    //Đọc giá trị Serial
  }

  if (mode) {// chế độ setting

    programController();
    if (isshowSetting) {
      DisplaySetting();
    }

    if (isClearMenu) {
      lcd.clear();
      isClearMenu = false;
    }

    switch (choosen) {
      case '1': {                                   // Đổi mật khẩu
          if (isClearOne) {
            lcd.clear();
            clearData();
            isshowSetting = false;
            isClearOne = false;
          }

          do {
            DisplayCurrentPassword();
            if (key == 'A') {
              checkPassword();
              key = ' ';
            }
          } while (!iscorrect);

          if (iscorrect) {
            do {
              DisplayNewPassword();
              if (key == 'A') {
                savePassword();
                completePassword = true;
                key = ' ';
              }
            } while (!completePassword);
          }

          if (completePassword) {
            choosen = ' ';
            mode = false;
            completePassword = false;
            isClearOne = true;
            choosenMess = ' ';
            key = ' ';
            data_count = 0;
            master_count = 0;
            data_mess_count = 0;
            iscorrect = false;
          }
          break;
        }

      case '2': {                                    // Đổi thông báo
          if (isClearTwo) {
            lcd.clear();
            clearData();
            isshowSetting = false;
            isClearTwo = false;
          }
          if (isshowCurrentPassDisplay) {
            do {
              DisplayCurrentPassword();
              if (key == 'A') {
                checkPassword();
                key = ' ';
              }
            } while (!iscorrect);
          }
          if (iscorrect) {
            if (ishowMessageDisplay) {
              DisplayChangeMessage();
              isshowCurrentPassDisplay = false;
            }
            switch (choosenMess) {
              case '1':
                lcd.clear();
                ishowMessageDisplay = false;
                do {
                  DisplayNewMessIn();
                  if (key == 'A') {
                    saveMessageIn();

                    completeMessage = true;
                    key = ' ';
                  }
                } while (!completeMessage);
                break;
              case '2':
                lcd.clear();
                ishowMessageDisplay = false;
                do {
                  DisplayNewMessOut();
                  if (key == 'A') {
                    saveMessageOut();
                    completeMessage = true;
                    key = ' ';
                  }
                } while (!completeMessage);
                break;
            }
          }

          if (completeMessage) {
            choosen = ' ';
            choosenMess = ' ';
            key = ' ';
            mode = false;
            completeMessage = false;
            isClearTwo = true;
            data_count = 0;
            master_count = 0;
            data_mess_count = 0;
            isshowCurrentPassDisplay = true;
            ishowMessageDisplay = true;
            iscorrect = false;
            Serial.println("completeMessage");
          }
          break;
        }
    }
  }
  else {                                             // chương trình chính
    keypadController();
    programController();
    DisplayNum();
    DisplayDS1307();
    //    SensorInit();
    //    sensorController();
    //    testSensor();
  }
}
