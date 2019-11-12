void DisplayDS1307()
{
  lcd.setCursor(0, 1);
  lcd.print(hour);
  lcd.print(":");
  lcd.print(minute);
  lcd.print(" ");
  lcd.print(day);
  lcd.print("-");
  lcd.print(month);
  lcd.print("-");
  lcd.print(year);
}

void DisplayNum()
{
  lcd.setCursor(0, 0);
  lcd.print("Num:");
  lcd.print(num);
}

void DisplayCurrentPassword() {
  lcd.setCursor(0, 0);
  lcd.print("Current password");
  keypadController();
}

void DisplayNewPassword() {
  lcd.setCursor(0, 0);
  lcd.print("New password");
  keypadController();
}

void DisplaySetting() {
  lcd.setCursor(0, 0);
  lcd.print("SETTING: CHANGE");
  lcd.setCursor(0, 1);
  lcd.print("1.Pasword 2.Text");
  keypadController();
}

void DisplayNewMessIn() {
  lcd.setCursor(0, 0);
  lcd.print("Message In");
  keypadController();
}

void DisplayNewMessOut() {
  lcd.setCursor(0, 0);
  lcd.print("Message Out");
  keypadController();
}

void DisplayChangeMessage() {
  lcd.setCursor(0, 0);
  lcd.print("CHANGE MESSAGE");
  lcd.setCursor(0, 1);
  lcd.print("1.In 2.Out");
  keypadController();
}
