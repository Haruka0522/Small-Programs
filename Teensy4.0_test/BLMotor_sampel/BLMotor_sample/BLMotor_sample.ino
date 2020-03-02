#include <Servo.h>//ライブラリ

#define pin 1//ESCとの接続ピン

Servo esc;//escという名前で宣言

void setup()
{
  esc.attach(pin, 1000, 2000); //ESCとの接続ピンの指定及び最小値と最大値

  esc.writeMicroseconds(2000);//最大値
  delay(1000);//余裕を持って1秒にしてあります

  esc.writeMicroseconds(1000);//最小値
  delay(5000);//上と同じ理由と急に回らないように5秒としてあります
}

void loop()
{
  //安全のため20%で2秒間回転した後停止するようにしています
  esc.writeMicroseconds(1200);
  delay(1500);
  esc.writeMicroseconds(1500);
  delay(1500);
  esc.writeMicroseconds(1800);
  delay(1500);
  esc.writeMicroseconds(2000);
  delay(1500);
  esc.writeMicroseconds(1800);
  delay(1500);
  esc.writeMicroseconds(1500);
  delay(1500);
  esc.writeMicroseconds(1200);
  delay(1500);
/*
  while (1)
  {
    esc.writeMicroseconds(1000);
  }*/
}
