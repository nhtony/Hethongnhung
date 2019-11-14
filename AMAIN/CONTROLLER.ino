
void sensorController() {
  if (arr[0] == 1) {
    if (checkTwo == 1) {
      checkIn();
      arr[0] = 0;
      arr[1] = 0;
      checkOne = false;
      checkTwo = false;
    }
    else {
      lcd.clear();
      DisplayNum();
      DisplayDS1307();
    }
  }

  else if (arr[1] == 1) {
    if (checkOne == 1) {
      checkOut();
      arr[0] = 0;
      arr[1] = 0;
      checkOne = false;
      checkTwo = false;
    }
    else {
      lcd.clear();
      DisplayNum();
      DisplayDS1307();
    }
  }

  else {
    lcd.clear();
    DisplayNum();
    DisplayDS1307();
    arr[0] = 0;
    arr[1] = 0;
    checkOne = false;
    checkTwo = false;
  }
  delay(100);
}

void keypadController() {
  char temp = keypad.getKey();
  if ((int)keypad.getState() ==  PRESSED) {
    if (temp != 0) {
      key = temp;
      switch (choosen) {
        case '1':
          enterPassword(temp);
          break;
        case '2':
          if (iscorrect) {
            if (key == '1' || key == '2' || key == 'C') {
              choosenMess = key;
              key = ' ';
            }
            switch (choosenMess) {
              case '1':
                enterMessage(temp, true);
                break;
              case '2':
                enterMessage(temp, false);
                break;
              case 'C':
                mode = false;
                choosenMess = ' ';
                completeMessage = true;
                key = ' ';
            }
          }
          else enterPassword(temp);
          break;

        case '3':
          if (iscorrect) {
            enterThreshold(temp);
          }
          else enterPassword(temp);
          break;

        case 'C':
          mode = false;
          choosen = ' ';
          key = ' ';
          break;
      }
    }
  }
  if ((int)keypad.getState() ==  HOLD) {
    state++;
    state = constrain(state, 1, n - 1);
    delay(holdDelay);
  }
  if ((int)keypad.getState() ==  RELEASED) {
    key += state;
    state = 0;

    if (isshowSetting) {
      if (key == '1' || key == '2' || key == 'C' || key == '3') {
        choosen = key;
        key = ' ';
      }
    }
  }
  delay(100);
}

void programController() {
  if (key == '$' || key == '#') {
    mode = true;
    isshowSetting = true;
  }
}
