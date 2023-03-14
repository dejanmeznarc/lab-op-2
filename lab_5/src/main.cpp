#include <Arduino.h>

#define PIN_ROT_SW 2
#define PIN_ROT_A 3
#define PIN_ROT_B 4


char odmik = 65;
char prevOdmik = 0;


void setup() {
    Serial.begin(115200);

    pinMode(PIN_ROT_A, INPUT_PULLUP);
    pinMode(PIN_ROT_B, INPUT_PULLUP);
    pinMode(PIN_ROT_SW, INPUT_PULLUP);
}


void readRotaryEncoder() {
    static bool prevStateA;

    bool curStateA = digitalRead(PIN_ROT_A);
    if (curStateA != prevStateA && curStateA) {
        digitalRead(PIN_ROT_B) ? ++odmik : --odmik;
    }
    prevStateA = curStateA;

}


char TEXT[100] = "";
char *TEXT_ptr = TEXT;

// naloga pravi, da je treba to s pointerji naredit, čeprav zgleda grdo
void vstaviZnak(char znak) {

    (*TEXT_ptr) = znak;
    TEXT_ptr++;
}


unsigned long msLastRotCall = 0;
unsigned long msLastBtnPress = 0;
bool rotBtnStatePrev = false;

void loop() {

    if (millis() - msLastRotCall > 1) {
        readRotaryEncoder();
        msLastRotCall = millis();
    }

    if (odmik < 65) {
        Serial.println("Odmik je lahko min 65 (A)");
        odmik = 65;
    } else if (odmik > 90) {
        Serial.println("Odmik je lahko max 90 (Z)");
        odmik = 90;
    }

    if (prevOdmik != odmik) {
        Serial.println(odmik);
        prevOdmik = odmik;
    }


    bool rotBtnStateCur = digitalRead(PIN_ROT_SW);
    if (rotBtnStatePrev != rotBtnStateCur && msLastBtnPress - millis() > 50 && !rotBtnStateCur) {

        vstaviZnak(odmik);
        Serial.print("Znak " + String(odmik) + " je dodan na seznam: ");
        Serial.println(TEXT);

        msLastBtnPress = millis();
    }
    rotBtnStatePrev = rotBtnStateCur;

}
