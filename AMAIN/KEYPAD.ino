char previousLetter;

void enterPassword(char temp) {

  if ( temp != 'A' ) { // Bỏ các ký tự A, B , C, D để check password
    Data[data_count] = temp; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    delay(300);
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print('*');
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
  }
}


void enterMessage(char temp, boolean messType) {
  
  if ( temp != 'A' ) { // Bỏ các ký tự A, B , C, D để check password
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
        data_mess_count++;
        temp = ' ';
        if (data_mess_count > 16) data_mess_count = 0;
        break;
    }

    if (messType) {
      message_in[data_mess_count] = temp; // store char into data array
      displayMessage_in[data_mess_count] = temp;
      displayMessage_in[data_mess_count + 1] = '_';
      lcd.setCursor(data_mess_count, 1); // move cursor to show each new char
      lcd.print(displayMessage_in[data_mess_count]); // print char at said cursor
      lcd.setCursor(data_mess_count + 1, 1); // move cursor to show each new char
      lcd.print( displayMessage_in[data_mess_count + 1]); // print char at said cursor
    }
    else {
      message_out[data_mess_count] = temp; // store char into data array
      displayMessage_out[data_mess_count] = temp;
      displayMessage_out[data_mess_count + 1] = '_';
      lcd.setCursor(data_mess_count, 1); // move cursor to show each new char
      lcd.print(displayMessage_out[data_mess_count]); // print char at said cursor
      lcd.setCursor(data_mess_count + 1, 1); // move cursor to show each new char
      lcd.print( displayMessage_out[data_mess_count + 1]); // print char at said cursor
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
