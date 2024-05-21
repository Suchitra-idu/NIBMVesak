#include <SoftwareSerial.h>


SoftwareSerial SerialBT(10, 11); // RX, TX

int relay1 = 2; // 
int relay2 = 3; // 
int relay3 = 4; // 
int relay4 = 5; // 
int relay5 = 6; // 
int relay6 = 7; // 
int relay7 = 8; // 
int relay8 = 9; // 
int relay9 = 10; // 
int relay10 = 11; // 
int relay11 = 12; // 
int relay12 = 13; //
int relay13 = 44; // 
int relay14 = 45; //
int relay15 = 46; // 
int relay16 = 47; // 
int relay17 = 48; //
int relay18 = 49; // 


unsigned long previousMillis = 0; // will store the last time the pattern was changed
const long interval = 0.5 * 60 * 1000; // interval to change pattern (2 minutes)


char currentPattern = '1'; // default pattern
int relays[] = {relay1, relay2, relay3, relay4,relay5, relay6, relay7, relay8,relay9, relay10, relay11, relay12,relay13, relay14, relay15,relay16, relay17, relay18};

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
    Serial.println(c);
    if (c >= '1' && c <= '4') { // check if the received command is valid
      currentPattern = c; // update the current pattern
      previousMillis = currentMillis; // reset the timer
    }
  }


  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    currentPattern++; // change the pattern
    if (currentPattern > '4') currentPattern = '1'; // reset to the first pattern
  }


  switch (currentPattern) {
    case '1':
      patternRun();
      break;
    case '2':
      wavePattern();
      break;
    case '3':
      alternatePattern();
      break;
    case '4':
      evenOddPattern();
      break;
    // Add more cases as needed
  }
}
void patternRun(){
  Serial.println("Pattern Run");
  int delayTime = 1000; // delay time in milliseconds
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
  int delayTime = 1000;
  

  for (int i = 0; i < 18; i++) {
      digitalWrite(relays[i], HIGH);
    digitalWrite(relays[i+3], HIGH);
    digitalWrite(relays[i+6], HIGH);
    digitalWrite(relays[i+9], HIGH);
    digitalWrite(relays[i+12], HIGH);
    digitalWrite(relays[i+15], HIGH);
    digitalWrite(relays[i+18], HIGH);
    delay(delayTime);
  }

  for (int i = 17; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    digitalWrite(relays[i+3], LOW);
    digitalWrite(relays[i+6], LOW);
    digitalWrite(relays[i+9], LOW);
    digitalWrite(relays[i+12], LOW);
    digitalWrite(relays[i+15], LOW);
    digitalWrite(relays[i+18], LOW);
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
  int delayTime = 1000;
  

  for (int i = 0; i < 18; i++) {
    int randomIndex = random(4);
    digitalWrite(relays[randomIndex], HIGH);
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
  }
}

void clockwiseRotationPattern(){
   Serial.println("Clockwise Pattern");
  int delayTime = 1000;
  

  for (int i = 0; i < 18; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void counterClockwiseRotationPattern(){
   Serial.println("CounterClock patten");
  int delayTime = 1000;


  for (int i = 17; i >= 0; i--) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void blinkingPairsPattern(){
   Serial.println("blinkingPairsPattern");
  int delayTime = 1000;


  for (int i = 0; i < 7; i++) {
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


  for (int i = 0; i < 7; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i < 7; i++) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 2; i < 18; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 2; i < 18; i++) {
    digitalWrite(relays[i], LOW);
  }
}