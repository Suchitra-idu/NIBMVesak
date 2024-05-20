#include <SoftwareSerial.h>

SoftwareSerial SerialBT(10, 11); // RX, TX


int relay1 = 5; // GPIO5
int relay2 = 6; // GPIO18
int relay3 = 7; // GPIO19
int relay4 = 8; // GPIO21

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  SerialBT.begin(9600); //Start Bluetooth service
  Serial.begin(9600);
  delay(1000); // Wait for the module to initialize

  SerialBT.print("AT+NAME=YourNewName\r\n"); // Change the name to "YourNewName"
  delay(1000); // Wait for the command to be processed
}

void loop() {
  if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.println(c);
    switch (c) {
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
}

void patternRun(){
  Serial.println("Pattern Run");
  int delayTime = 1000; // delay time in milliseconds
  int relays[] = {relay1, relay2, relay3, relay4}; // array of relays
  
  for (int i = 0; i < 4; i++) {
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
  int relays[] = {relay1, relay2, relay3, relay4};

  for (int i = 0; i < 4; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
  }

  for (int i = 3; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    delay(delayTime);
  }
}

void alternatePattern(){
   Serial.println("Aultanative Pattern");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4};

  for (int i = 0; i < 4; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 0; i < 4; i += 2) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 4; i += 2) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);

  for (int i = 1; i < 4; i += 2) {
    digitalWrite(relays[i], LOW);
  }
}

void evenOddPattern(){
   Serial.println("EvenOddPatten");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4};

  for (int i = 0; i < 4; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 4; i += 2) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void randomPattern(){
   Serial.println("Random patten");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4};

  for (int i = 0; i < 4; i++) {
    int randomIndex = random(4);
    digitalWrite(relays[randomIndex], HIGH);
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
  }
}

void clockwiseRotationPattern(){
   Serial.println("Clockwise Pattern");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4};

  for (int i = 0; i < 4; i++) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void counterClockwiseRotationPattern(){
   Serial.println("CounterClock patten");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4};

  for (int i = 3; i >= 0; i--) {
    digitalWrite(relays[i], HIGH);
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void blinkingPairsPattern(){
   Serial.println("blinkingPairsPattern");
  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4};

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
  int relays[] = {relay1, relay2, relay3, relay4};

  for (int i = 0; i < 2; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i < 2; i++) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 2; i < 4; i++) {
    digitalWrite(relays[i], HIGH);
  }
  delay(delayTime);
  for (int i = 2; i < 4; i++) {
    digitalWrite(relays[i], LOW);
  }
}
