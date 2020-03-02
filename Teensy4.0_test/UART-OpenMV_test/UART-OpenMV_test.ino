void setup(){
    Serial.begin(9600);
}

void loop(){
    value = Serial.read();
    if value == 1{
	    digitalWrite(13,HIGH);
    }
    else{
	    digitalWrite(13,LOW);
    }
}

