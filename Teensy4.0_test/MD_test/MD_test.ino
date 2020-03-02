void setup() {
  // put your setup code here, to run once:
	pinMode(3,OUTPUT);
	analogWriteFrequency(2,100000);  //PWM周波数を100kHzにする
}

void loop() {
  // put your main code here, to run repeatedly:
	gyakuten(200);
	delay(1000);
	seiten(100);
	delay(1000);
}

void seiten(int speed){
  digitalWrite(3,HIGH);
  analogWrite(2,speed);
}

void gyakuten (int speed){
  digitalWrite(3,LOW);
  analogWrite(2,speed);
}
