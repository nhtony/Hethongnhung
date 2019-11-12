void savePassword() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Saving...");
  clearPassword();
  delay(1000);
  Serial.print("PASSWORD: ");
  Serial.println(Data);
  writePassword(Data, String(Data).length());
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Done!");

}

void saveMessageIn() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Saving...");
  clearMessIn();
  delay(1000);
  Serial.print("MESSIN: ");
  Serial.println(message_in);
  writeMsgIn(message_in, String(message_in).length());
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Done!");

}

void saveMessageOut() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Saving...");
  clearMessOut();
  delay(1000);
  Serial.print("MESSOUT: ");
  Serial.println(message_out);
  writeMsgOut(message_out, String(message_out).length());
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Done!");

}
