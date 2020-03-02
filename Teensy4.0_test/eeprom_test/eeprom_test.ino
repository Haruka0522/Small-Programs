#include <EEPROM.h>

void setup(){
    Serial.begin(9600);
    /*書き込み
    for (int i=0; i<256; ++i){
        EEPROM.write(i,i);
    }
    */


}

void loop(){

    /*読み込み*/
    for (int i=0; i<256; ++i){
        int value = EEPROM.read(i);
        Serial.println(value);
    }
}