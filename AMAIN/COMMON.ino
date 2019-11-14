void dot()
{
  tone (Buzzer, ToneMusic );
  delay(DotLength);
  noTone(Buzzer);
  delay(Length);
}
void dash()
{
  tone (Buzzer, ToneMusic );
  delay(DashLength);
  noTone(Buzzer);
  delay(Length);
}

void checkIn() {
  lcd.clear();
  num += 1;
  lcd.setCursor(4, 0);
  lcd.print(message_in_master);
  delay(1000);
  Serial.println(message_in_master);
  DisplayDS1307();
  mode = false;
}


void checkOut() {
  lcd.clear();
  if (num > 0) {
    num -= 1;
  }
  lcd.setCursor(4, 0);
  lcd.print(message_out_master);
  Serial.println(message_out_master);
  delay(1000);
  DisplayDS1307();
  mode = false;
}

void testSensor() {
  Serial.print("Distance 1: ");
  Serial.print(distance_1);
  Serial.print(" One: ");
  Serial.println(checkOne);
  Serial.print("Distance 2: ");
  Serial.print(distance_2);
  Serial.print(" Two: ");
  Serial.println(checkTwo);
  delay(100);
}

void completePasswordChange() {
  if (completePassword) {
    key = ' ';
    choosen = ' ';
    choosenMess = ' ';

    mode = false;
    iscorrect = false;
    updateData = true;
    completePassword = false;


    isClearCurrentDisplay = true;
    data_count = 0;
    master_count = 0;

  }
}


void completeMessageChange() {
  if (completeMessage) {

    key = ' ';
    choosen = ' ';
    choosenMess = ' ';

    mode = false;
    iscorrect = false;
    completeMessage = false;
    updateData = true;

    isClearCurrentDisplay = true;
    ishowMessageDisplay = true;
    isshowCurrentPassDisplay = true;

    data_count = 0;
    master_count = 0;
    mess_count = 0;

  }
}


void completeThresholdChange() {
  if (completeThreshold) {
    mode = false;
    iscorrect = false;
    completeThreshold = false;
    updateData = true;


    isClearCurrentDisplay = true;

    key = ' ';
    choosen = ' ';
    choosenMess = ' ';

    data_count = 0;
    master_count = 0;
    threshold_count = 0;
  }
}

void clearCurrentDisplay() {
  if (isClearCurrentDisplay) {
    lcd.clear();
    isshowSetting = false;
    isClearCurrentDisplay = false;
  }
}

void showMessageDisplay() {
  if (ishowMessageDisplay) {
    DisplayChangeMessage();
    isshowCurrentPassDisplay = false;
  }
}

void hideMessageDisplay() {
  lcd.clear();
  ishowMessageDisplay = false;
}
