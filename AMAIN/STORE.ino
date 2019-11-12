#include <EEPROM.h>

void clearPassword() // clear memory
{
  Serial.println("clearPassword");
  for (int i = 0 ; i < 17 ; i++) {
    Serial.println(i);
    EEPROM.write(i, 0);
    delay(5);
  }
}

void clearMessIn() // clear memory
{
  Serial.println("clearMessIn");
  for (int i = 17 ; i < 33; i++) {
    Serial.println(i);
    EEPROM.write(i, 0);
    delay(5);
  }
}

void clearMessOut() // clear memory
{
  Serial.println("clearMessOut");
  for (int i = 33 ; i < 49 ; i++) {
    Serial.println(i);
    EEPROM.write(i, 0);
    delay(5);
  }
}


void writePassword(char first[], size_t len)
{
  Serial.println("pass: ");

  for (int i = 0; i < len; i++)
  {
    Serial.println(first[i]);
    EEPROM.write(i, first[i]);
    delay(5);
  }
}

void writeMsgIn(char second[], size_t len)
{
  Serial.print("msgin: ");
  Serial.println(second);
  for (int i = 17; i < 17 + len; i++)
  {
    Serial.println(second[i-17]);
    EEPROM.write(i, second[i-17]);
    delay(5);
  }
}

void writeMsgOut(char third[], size_t len)
{
  Serial.print("msgout: ");
  Serial.println(third);

  for (int i = 33; i < 33 + len; i++)
  {
    Serial.println(third[i-33]);
    EEPROM.write(i, third[i-33]);
    delay(5);
  }
}

void readPassword()
{
  byte res;
  for (int i = 0; i < 17; i++)
  {
    res = EEPROM.read(i);
    Master[i] = res;
  }
  Serial.print("readPassword: ");
  Serial.println(Master);
}


void readMsgIn()
{
  byte resIn;
  for (int i = 17; i < 33; i++)
  {
    resIn = EEPROM.read(i);
    message_in_master[i - 17] = resIn;
  }
  message_in_master[33 - 17] = resIn;
  Serial.print("readMsgIn: ");
  Serial.println(message_in_master);
}

void readMsgOut()
{
  byte resOut;
  for (int i = 33; i < 49; i++)
  {
    resOut = EEPROM.read(i);
    message_out_master[i - 33] = resOut;
  }
  message_in_master[49 - 33] = resOut;
  Serial.print("readMsgOut: ");
  Serial.println(message_out_master);
}
