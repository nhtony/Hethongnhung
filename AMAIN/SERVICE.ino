void savePassword() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Saving...");
  clearPassword();
  delay(1000);
  Serial.print("PASSWORD: ");
  Serial.println(Data);
  writePassword(Data, String(Data).length());
  updateData = true;
  completePassword = true;
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
  updateData = true;
  completeMessage = true;
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
  updateData = true;
  completeMessage = true;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Done!");

}

void saveThreshold() {
  if (validThreshold()) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Saving...");
    clearThreshold();
    delay(1000);
    Serial.print("Rate: ");
    Serial.println(threshold);
    writeThreshold(threshold, String(threshold).length());
    updateData = true;
    completeThreshold = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Done!");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Must <= 450");
    threshold[3] = "";
    completeThreshold = false;
    threshold_count = 0;
    delay(1000);
  }
}
