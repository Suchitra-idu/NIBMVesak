#include <SoftwareSerial.h>


SoftwareSerial SerialBT(0, 1); // RX, TX

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
const long interval = 2 * 60 * 1000; // interval to change pattern (2 minutes)

int relays[] = {relay1, relay2, relay3, relay4,relay5, relay6, relay7, relay8,relay9, relay10, relay11, relay12,relay13, relay14, relay15,relay16, relay17, relay18};
int relaysParent[] = {relay19, relay20, relay21, relay22, relay23, relay24};

char currentPattern = '1'; // default pattern

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(relay9, OUTPUT);
  pinMode(relay10, OUTPUT);
  pinMode(relay11, OUTPUT);
  pinMode(relay12, OUTPUT);
  pinMode(relay13, OUTPUT);
  pinMode(relay14, OUTPUT);
  pinMode(relay15, OUTPUT);
  pinMode(relay16, OUTPUT);
  pinMode(relay17, OUTPUT);
  pinMode(relay18, OUTPUT);
  pinMode(relay19, OUTPUT);
  pinMode(relay20, OUTPUT);
  pinMode(relay21, OUTPUT);
  pinMode(relay22, OUTPUT);
  pinMode(relay23, OUTPUT);
  pinMode(relay24, OUTPUT);

  SerialBT.begin(9600); //Start Bluetooth service
  Serial.begin(9600);
  delay(1000); // Wait for the module to initialize


  SerialBT.print("AT+NAME=YourNewName\r\n"); // Change the name to "YourNewName"
  delay(1000); // Wait for the command to be processed
}


void loop() {
  unsigned long currentMillis = millis();
  
  if (SerialBT.available()) {
    char c = SerialBT.read();
    currentPattern = c; // update the current pattern
    previousMillis = currentMillis; // reset the timer
  }


  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    currentPattern++; // change the pattern
    if (currentPattern > '9') currentPattern = '1'; // reset to the first pattern
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
  Serial.println("Pattern Run");
  int delayTime = 200; // delay time in milliseconds
   // array of relays
  
  for (int i = 0; i < 18; i++) {
    digitalWrite(relays[i], HIGH); // turn the current relay on
    Serial.println("Light #" + String(i) + " HIGH");
    delay(delayTime); // wait for delayTime
    digitalWrite(relays[i], LOW); // turn the current relay off
    Serial.println("Light #" + String(i) + " LOW");
  }
}

void wavePattern(){
   Serial.println("Wave patton");
  int delayTime = 500;
  

  for (int i = 0; i < 18; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
  }

  for (int i = 17; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    delay(delayTime);
  }
}

void alternatePattern(){
   Serial.println("Aultanative Pattern");
  int delayTime = 1000;
  

  for (int i = 0; i < 18; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 0; i < 18; i += 2) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 18; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 1; i < 18; i += 2) {
    digitalWrite(relays[i], LOW);
  }
}

void evenOddPattern(){
   Serial.println("EvenOddPatten");
  int delayTime = 1000;
  

  for (int i = 0; i < 18; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 18; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void randomPattern(){
   Serial.println("Random patten");
  int delayTime = 150;
  

  for (int i = 0; i < 18; i++) {
    int randomIndex = random(18);
    digitalWrite(relays[randomIndex], HIGH);
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
  }
}

void clockwiseRotationPattern(){
   Serial.println("Clockwise Pattern");
  int delayTime = 750;
  

  for (int i = 0; i < 18; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void counterClockwiseRotationPattern(){
   Serial.println("CounterClock patten");
  int delayTime = 750;
  

  for (int i = 17; i >= 0; i--) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void blinkingPairsPattern(){
   Serial.println("blinkingPairsPattern");
  int delayTime = 1000;
  

  for (int i = 0; i < 17; i++) {
    digitalWrite(relays[i], HIGH);
    digitalWrite(relays[(i + 2) % 18], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    digitalWrite(relays[(i + 2) % 18], LOW);
  }
}

void alternatingHalvesPattern(){
   Serial.println("alternatingHalvesPattern");
  int delayTime = 1000;
  

  for (int i = 0; i = 17; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i = 17; i++) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 17; i < 18; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 17; i < 18; i++) {
    digitalWrite(relays[i], LOW);
  }
}