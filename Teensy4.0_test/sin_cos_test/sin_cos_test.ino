#include <math.h>

#define PI 3.141592

void setup(){
    Serial.begin(9600);
}

void loop(){
    double deg = 30;
    double rad = deg * PI /180.0;
    double a = cos(rad);
    double b = sin(rad);
    Serial.print("cos = ");
    Serial.println(a);
    Serial.print("sin = ");
    Serial.println(b);
    delay(1000);
}

