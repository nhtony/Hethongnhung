boolean isDelete = false;
int previousIndex = 0;

void enterPassword(char temp) {
  if ( temp != 'A' && temp != 'B' && temp != 'C' && temp != 'D' ) { // Bỏ các ký tự A, B , C, D để check password
    Data[data_count] = temp; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    delay(300);
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print('*');
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
  }
  else if ( temp == 'C' ) {
    iscorrect = true;
    completePassword = true;
    completeMessage = true;
    completeThreshold = true;
    choosen = 'C';
  }
}

void enterThreshold(char temp) {
  if ( temp != 'A' && temp != 'B' && temp != 'C' && temp != 'D') { // Bỏ các ký tự A, B , C, D để check password
    if (threshold_count < 3) {
      threshold[threshold_count] = temp; // store char into data array
      lcd.setCursor(threshold_count + 13, 0); // move cursor to show each new char
      lcd.print(threshold[threshold_count]); // print char at said cursor
      threshold_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
    }
  }
  else if ( temp == 'C' ) {
    iscorrect = true;
    completeThreshold = true;
    choosen = 'C';
  }
}

void enterMessage(char temp, boolean messType) {
  if ( temp != 'A' ) {
    switch (temp) {
      case '2':
        temp = key_2[letter];
        letter++;
        if (letter > 2) letter = 0;
        break;
      case '3':
        temp = key_3[letter];
        letter++;
        if (letter > 2) letter = 0;
        break;
      case '4':
        temp = key_4[letter];
        letter++;
        if (letter > 2) letter = 0;
        break;
      case '5':
        temp = key_5[letter];
        letter++;
        if (letter > 2) letter = 0;
        break;
      case '6':
        temp = key_6[letter];
        letter++;
        if (letter > 2) letter = 0;
        break;
      case '7':
        temp = key_7[letter];
        letter++;
        if (letter > 3) letter = 0;
        break;
      case '8':
        temp = key_8[letter];
        letter++;
        if (letter > 2) letter = 0;
        break;
      case '9':
        temp = key_9[letter];
        letter++;
        if (letter > 3) letter = 0;
        break;
      case '0':
        mess_count++;
        temp = ' ';
        Serial.print("data_mess_count: ");
        Serial.println(mess_count);
        if (mess_count > 16) mess_count = 0;
        break;
      case 'D':
        if (mess_count > 0) {
          mess_count--;
          temp = ' ';
          isDelete = true;
        }
        else {
          temp = ' ';
        }
        break;
    }

    if (isDelete) {
      previousIndex = mess_count;
      mess_count++;
    }

    if (messType) {
      message_in[mess_count] = temp; // store char into data array
      displayMessage_in[mess_count] = temp;
      lcd.setCursor(mess_count, 1); // move cursor to show each new char
      lcd.print(displayMessage_in[mess_count]);
      if (isDelete) {
        mess_count = previousIndex;
        isDelete = false;
      }
    }
    else {
      message_out[mess_count] = temp; // store char into data array
      displayMessage_out[mess_count] = temp;
      lcd.setCursor(mess_count, 1); // move cursor to show each new char
      lcd.print(displayMessage_out[mess_count]); // print char at said cursor
      if (isDelete) {
        mess_count = previousIndex;
        isDelete = false;
      }
    }
  }
}

void clearData()
{
  while (data_count != 0)
  { // This can be used for any array size,
    Data[data_count--] = 0; //clear array for new data
  }
  return;
}
