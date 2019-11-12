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
  dot();
  dot();
  DisplayDS1307();
}


void checkOut() {
  lcd.clear();
  if (num > 0) {
    num -= 1;
  }
  lcd.setCursor(4, 0);
  lcd.print(message_out_master);
  dash();
  dash();
  DisplayDS1307();
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
