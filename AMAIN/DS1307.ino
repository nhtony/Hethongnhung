void ReadSerial()
{
  byte hr; byte min; byte sec; byte wd; byte d; byte mth; byte yr;    //Biến lưu
  String buff = Serial.readStringUntil('\n');                         //Đọc đến khi hết dòng
  String tmp;                                                         //Biến tạm để tách

  for (int i = 0; i < 7; i++)                                         //Đọc vào 7 thông tin theo thứ tự (Giờ-Phút-Giây-Thứ trong tuần-Ngày-Tháng-Năm)
  {
    int index = buff.indexOf(" ");                                    //Lấy vị trí đến dấu cách
    tmp = buff.substring(0, index);                                   //Tách biến tạm
    buff = buff.substring(index + 1, buff.length());                  //Tính lại buff
    switch (i)                                                        //Đọc dữ liệu và gán vào
    {
      case 0:
        hr = tmp.toInt();
        break;
      case 1:
        min = tmp.toInt();
        break;
      case 2:
        sec = tmp.toInt();
        break;
      case 3:
        wd = tmp.toInt();
        break;
      case 4:
        d = tmp.toInt();
        break;
      case 5:
        mth = tmp.toInt();
        break;
      case 6:
        yr = tmp.toInt();
        break;
    }
  }
  SetTime(hr, min, sec, wd, d, mth, yr);                    //Thiết lập lại thời gian
}

void ReadDS1307()
{
  Wire.beginTransmission(DS1307);
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307, NumberOfFields);

  second = bcd2dec(Wire.read() & 0x7f);
  minute = bcd2dec(Wire.read() );
  hour   = bcd2dec(Wire.read() & 0x3f); // chế độ 24h.
  wday   = bcd2dec(Wire.read() );
  day    = bcd2dec(Wire.read() );
  month  = bcd2dec(Wire.read() );
  year   = bcd2dec(Wire.read() );
  year   += 2000;
}

int bcd2dec(byte num) {
  return ((num / 16 * 10) + (num % 16));  // Chuyển từ format BCD (Binary-Coded Decimal) sang Decimal
}
int dec2bcd(byte num) {
  return ((num / 10 * 16) + (num % 10));  // Chuyển từ Decimal sang BCD
}
void SetTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr)
{
  Wire.beginTransmission(DS1307); //Bắt đầu truyền đến địa chỉ DS1307
  Wire.write(byte(0x00));         //Đặt lại con trỏ
  Wire.write(dec2bcd(sec));
  Wire.write(dec2bcd(min));
  Wire.write(dec2bcd(hr));
  Wire.write(dec2bcd(wd));        //Ngày trong tuần: 1 = Chủ nhật; 7 = Thứ bảy
  Wire.write(dec2bcd(d));
  Wire.write(dec2bcd(mth));
  Wire.write(dec2bcd(yr));
  Wire.endTransmission();         //Ngắt tín hiệu
}
