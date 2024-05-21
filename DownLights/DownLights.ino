#include <SoftwareSerial.h>


SoftwareSerial SerialBT(10, 11); // RX, TX


int relay1 = 5; // GPIO5
int relay2 = 6; // GPIO6
int relay3 = 7; // GPIO7


unsigned long previousMillis = 0; // will store the last time the pattern was changed
const long interval = 2 * 60 * 1000; // interval to change pattern (2 minutes)


char currentPattern = '1'; // default pattern


void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);


  SerialBT.begin(9600); //Start Bluetooth service
  Serial.begin(9600);
  delay(1000); // Wait for the module to initialize


  SerialBT.print("AT+NAME=Lights\r\n"); // Change the name to "YourNewName"
  delay(1000); // Wait for the command to be processed
}


void loop() {
  unsigned long currentMillis = millis();
  
  if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.println(c);
    if (c >= '1' && c <= '9') { // check if the received command is valid
      currentPattern = c; // update the current pattern
      previousMillis = currentMillis; // reset the timer
    }
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
  int relays[] = {relay1, relay2, relay3}; // array of relays
  
  for (int i = 0; i < 3; i++) {
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
  int relays[] = {relay1, relay2, relay3};

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
  }

  for (int i = 2; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    delay(delayTime);
  }
}

void alternatePattern(){
   Serial.println("Aultanative Pattern");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3};

  for (int i = 0; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 0; i < 3; i += 2) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 1; i < 3; i += 2) {
    digitalWrite(relays[i], LOW);
  }
}

void evenOddPattern(){
   Serial.println("EvenOddPatten");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3};

  for (int i = 0; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void randomPattern(){
   Serial.println("Random patten");
  int delayTime = 150;
  int relays[] = {relay1, relay2, relay3};

  for (int i = 0; i < 3; i++) {
    int randomIndex = random(3);
    digitalWrite(relays[randomIndex], HIGH);
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
  }
}

void clockwiseRotationPattern(){
   Serial.println("Clockwise Pattern");
  int delayTime = 750;
  int relays[] = {relay1, relay2, relay3};

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void counterClockwiseRotationPattern(){
   Serial.println("CounterClock patten");
  int delayTime = 750;
  int relays[] = {relay1, relay2, relay3};

  for (int i = 2; i >= 0; i--) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void blinkingPairsPattern(){
   Serial.println("blinkingPairsPattern");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3};

  for (int i = 0; i < 2; i++) {
    digitalWrite(relays[i], HIGH);
    digitalWrite(relays[(i + 2) % 4], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    digitalWrite(relays[(i + 2) % 4], LOW);
  }
}

void alternatingHalvesPattern(){
   Serial.println("alternatingHalvesPattern");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3};

  for (int i = 0; i < 2; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i < 2; i++) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 2; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 2; i < 3; i++) {
    digitalWrite(relays[i], LOW);
  }
}