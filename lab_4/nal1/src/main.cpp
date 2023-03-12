#include <Arduino.h>


#define ROT_SW 2
#define ROT_A 3
#define ROT_B 4


void setup() {

    Serial.begin(115200);

    Serial.println("=== REstart ===");


    pinMode(ROT_SW, INPUT_PULLUP);
    pinMode(ROT_A, INPUT);
    pinMode(ROT_B, INPUT);
}



bool prevStateA, curStateA, curStateB;

void loop() {

    // naloga 1
    if (!digitalRead(ROT_SW)) {
        Serial.println("tipka je pritisjena");
    }


    // naloga 2
    if (!digitalRead(ROT_A) || !digitalRead(ROT_B)) {
        Serial.println("rot dajalnik se vrti v neko smer");
    }



    // naloga 3
    curStateA = digitalRead(ROT_A);
    if (curStateA != prevStateA && curStateA) {
        if (digitalRead(ROT_B)) {
            Serial.println("CW");
        } else {
            Serial.println("CCW");
        }
    }
    prevStateA = curStateA;




    delayMicroseconds(500);


}

