void checkPassword() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Password is ");
  Serial.print(Data);
  if (!strcmp(Data, Master)) { // equal to (strcmp(Data, Master) == 0)
    lcd.print("Good");
    iscorrect = true;
    
  }
  else {
    iscorrect = false;
   
    lcd.print("Bad");
  }
  delay(1000);// added 1 second delay to make sure the password is completely shown on screen before it gets cleared.
  lcd.clear();
  clearData();
}
