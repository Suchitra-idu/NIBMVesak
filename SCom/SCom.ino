#include <Arduino.h>

int relay1 = 3; // Orange 8 Board
int relay2 = 2; // Red 8 Board
int relay3 = 10; // 1 16 Board
int relay4 = 11; // 2 16 Board
int relay5 = 12; // 3 16 Board 
int relay6 = 13; // 4 16 Board
int relay7 = 14; // 5 16 Board
int relay8 = 15; // 6 16 Board
int relay9 = 16; // 7 16 Board
int relay10 = 17; // 8 16 Board
int relay11 = 18; // 9 16 Board
int relay12 = 19; // 10 16 Board
int relay13 = 20; // 12 16 Board
int relay14 = 21; // 11 16 Board
int relay15 = 22; // 14 16 Board
int relay16 = 24; // 13 16 Board
int relay17 = 26; // 16 16 Board
int relay18 = 28; // 15 16 Board
// Parent Lanterns
int relay19 = 9; // White 8 board
int relay20 = 8; // Gray 8 board
int relay21 = 7; // Purple 8 board
int relay22 = 6; // Blue 8 board
int relay23 = 5; // Green 8 board
int relay24 = 4; // Yellow 8 board

unsigned long previousMillis = 0; // will store the last time the pattern was changed
const long interval = 0.5 * 60 * 1000; // interval to change pattern (2 minutes)

int relays[] = {relay19, relay20, relay21, relay22, relay23, relay24, relay1, relay2, relay3, relay4,relay5, relay6, relay7, relay8,relay9, relay10, relay11, relay12,relay13, relay14, relay15,relay16, relay17, relay18};

char currentPattern = '1'; // default pattern

void setup() {
  // Set all relays as OUTPUT
  for (int i = 0; i < 24; i++) {
    pinMode(relays[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int patternNumber = currentPattern - '0'; // convert char to int
    patternNumber++; // increment the pattern number
    if (patternNumber > 9) patternNumber = 1; // reset to the first pattern
    currentPattern = patternNumber + '0'; // convert back to char
  }

  switch (currentPattern) {
    case '1': patternRun(); break;
    case '2': wavePattern(); break;
    case '3': alternatePattern(); break;
    case '4': evenOddPattern(); break;
    case '5': randomPattern(); break;
    case '6': clockwiseRotationPattern(); break;
    case '7': counterClockwiseRotationPattern(); break;
    case '8': blinkingPairsPattern(); break;
    case '9': alternatingHalvesPattern(); break;
  }
}

void patternRun(){
  int delayTime = 500; // delay time in milliseconds
   // array of relays
  
  for (int i = 0; i < 24; i++) {
    digitalWrite(relays[i], HIGH); // turn the current relay on
    delay(delayTime); // wait for delayTime
    digitalWrite(relays[i], LOW); // turn the current relay off
  }
}

void wavePattern(){
  int delayTime = 500;
  

  for (int i = 0; i < 24; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
  }

  for (int i = 23; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    delay(delayTime);
  }
}

void alternatePattern(){
  int delayTime = 1000;
  

  for (int i = 0; i < 24; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 0; i < 24; i += 2) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 24; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 1; i < 24; i += 2) {
    digitalWrite(relays[i], LOW);
  }
}

void evenOddPattern(){
  int delayTime = 1000;
  

  for (int i = 0; i < 24; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 24; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void randomPattern(){
  int delayTime = 150;
  

  for (int i = 0; i < 24; i++) {
    int randomIndex = random(24);
    digitalWrite(relays[randomIndex], HIGH);
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
  }
}

void clockwiseRotationPattern(){
  int delayTime = 750;
  

  for (int i = 0; i < 24; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void counterClockwiseRotationPattern(){
  int delayTime = 750;
  

  for (int i = 23; i >= 0; i--) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void blinkingPairsPattern(){
  int delayTime = 1000;
  

  for (int i = 0; i < 23; i++) {
    digitalWrite(relays[i], HIGH);
    digitalWrite(relays[(i + 2) % 24], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    digitalWrite(relays[(i + 2) % 24], LOW);
  }
}

void alternatingHalvesPattern(){
  int delayTime = 1000;

  for (int i = 0; i <= 11; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i <= 11; i++) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 12; i <= 23; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 12; i <= 23; i++) {
    digitalWrite(relays[i], LOW);
  }
}