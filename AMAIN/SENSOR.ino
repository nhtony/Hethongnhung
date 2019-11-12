void SensorInit() {
  /* Phát xung từ chân trig */
  digitalWrite(trig_1, 0);  // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig_1, 1);  // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trig_1, 0);  // tắt chân
  duration_1 = pulseIn(echo_1, HIGH);

  /* Phát xung từ chân trig */
  digitalWrite(trig_2, 0);  // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig_2, 1);  // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trig_2, 0);  // tắt chân trig
  duration_2 = pulseIn(echo_2, HIGH);
}

int getSensorValue(int myduration) {
  return int(myduration / 2 / 29.412);
}

void checkSensor(int checkDistance) {
  distance_1 = getSensorValue(duration_1);
  if (distance_1 < checkDistance) {
    checkOne = true;
    if (!checkTwo) {
      arr[0] = checkOne;
    }
    arr[1] = checkTwo;
  }
  distance_2 = getSensorValue(duration_2);
  if (distance_2 < checkDistance) {
    checkTwo = true;
    if (!checkTwo) {
      arr[0] = checkOne;
    }
    arr[1] = checkTwo;
  }
}
