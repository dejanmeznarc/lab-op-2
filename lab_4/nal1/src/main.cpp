#include <Arduino.h>


#define PIN_ROT_SW 2
#define PIN_ROT_A 3
#define PIN_ROT_B 4


void setup() {

    Serial.begin(115200);

    Serial.println("=== REstart ===");


    pinMode(PIN_ROT_SW, INPUT_PULLUP);
    pinMode(PIN_ROT_A, INPUT);
    pinMode(PIN_ROT_B, INPUT);
}



bool prevStateA, curStateA, curStateB;

void loop() {

    // naloga 1
    if (!digitalRead(PIN_ROT_SW)) {
        Serial.println("tipka je pritisjena");
    }


    // naloga 2
    if (!digitalRead(PIN_ROT_A) || !digitalRead(PIN_ROT_B)) {
        Serial.println("rot dajalnik se vrti v neko smer");
    }



    // naloga 3
    curStateA = digitalRead(PIN_ROT_A);
    if (curStateA != prevStateA && curStateA) {
        if (digitalRead(PIN_ROT_B)) {
            Serial.println("CW");
        } else {
            Serial.println("CCW");
        }
    }
    prevStateA = curStateA;




    delayMicroseconds(500);


}

