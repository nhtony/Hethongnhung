/*DS1307*/
const byte DS1307 = 0x68;                           //Địa chỉ DS1307
const byte NumberOfFields = 7;                      //Số byte cần đọc

/*CẢM BIẾN SIÊU ÂM*/
const int trig_1 = 10;
const int echo_1 = 11;

const int trig_2 = 12;
const int echo_2 = 13;

/*BUZZER*/
int Buzzer = 13;

const int ToneMusic = 400;
const int DotLength = 100;
const int DashLength = DotLength * 3;
const int Length = 100;

/*KEYPAD 4X4*/
const byte rows = 4; //số hàng
const byte columns = 4; //số cột

const int holdDelay = 700; //thời gian trễ để xem là nhấn 1 nút nhằm tránh nhiễu
const int n = 3;

// Các giá trị trả về khi nhấn nút
const char keys[rows][columns] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[rows] = {9, 8, 7, 6}; //Cách nối chân với Arduino
byte columnPins[columns] = {5, 4, 3, 2};

const char key_2[4] = {'a', 'b', 'c'};
const char key_3[4] = {'d', 'e', 'f'};
const char key_4[4] = {'g', 'h', 'i'};
const char key_5[4] = {'j', 'k', 'l'};
const char key_6[4] = {'m', 'n', 'o'};
const char key_7[5] = {'p', 'q', 'r', 's'};
const char key_8[4] = {'t', 'u', 'v'};
const char key_9[5] = {'w', 'x', 'y', 'z'};
