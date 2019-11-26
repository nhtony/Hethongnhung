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
  completePassword = true;
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
  completeMessage = true;
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
  completeMessage = true;
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
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Done!");
    completeThreshold = true;
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
