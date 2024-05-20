#define RXp2 16
#define TXp2 17
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

int relay1 = 13; // D13
int relay2 = 12; // D12
int relay3 = 14; // D14
int relay4 = 27; // D27
int relay5 = 26; // D26
int relay6 = 25; // D25
int relay7 = 33; // D33
int relay8 = 32; // D32
int relay9 = 35; // D35
int relay10 = 15; // D15
int relay11 = 2; // D2
int relay12 = 4; // D4

bool sRelay[] = {false, false, false, false, false, false};

void setup() {
  // Set pin modes
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

  SerialBT.begin("Childs Top Light System");
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, RXp2, TXp2); // Get data from Arduino
  turnEverythingOn();
}

void loop() {
  // Takes status of relays of Arduino
  if (Serial.available()) {
    String message = Serial1.readString();
    if (message == "Trelay1") {
      sRelay[0] = true;
    } else if (message == "Frelay1") {
      sRelay[0] = false;
    } else if (message == "Trelay2") {
      sRelay[1] = true;
    } else if (message == "Frelay2") {
      sRelay[1] = false;
    } else if (message == "Trelay3") {
      sRelay[2] = true;
    } else if (message == "Frelay3") {
      sRelay[2] = false;
    } else if (message == "Trelay4") {
      sRelay[3] = true;
    } else if (message == "Frelay4") {
      sRelay[3] = false;
    } else if (message == "Trelay5") {
      sRelay[4] = true;
    } else if (message == "Frelay5") {
      sRelay[4] = false;
    } else if (message == "Trelay6") {
      sRelay[5] = true;
    } else if (message == "Frelay6") {
      sRelay[5] = false;
    }
  }

  if (SerialBT.available()) { // Check whether there is a signal from the phone
    int x = SerialBT.read(); // Store whatever is read from the bt serial device into variable x
    Serial.write(x); // Output variable x on serial monitor

    switch (x) {
      case 's': suchiPattern(); break;
      case 'w': wavePattern(); break;
      case 'a': alternatePattern(); break;
      case 'e': evenOddPattern(); break;
      case 'r': randomPattern(); break;
      case 'c': clockwiseRotationPattern(); break;
      case 't': counterClockwiseRotationPattern(); break;
      case 'b': blinkingPairsPattern(); break;
      case 'h': alternatingHalvesPattern(); break;
      case '0': turnEverythingOn(); break;
      default: turnEverythingOn(); break;
    }
  }
}

void turnEverythingOn() {
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  Serial.println("Everything turned on!");

  for (int i = 0; i < 12; i++) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
  }
}

void suchiPattern(){
  int delayTime = 1000; // delay time in milliseconds
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays
  
  for (int i = 0; i < 12; i++) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH); // turn the current relay on
      delay(delayTime); // wait for delayTime
      digitalWrite(relays[i], LOW); // turn the current relay off
    }
  }
}

void wavePattern() {
  Serial.println("Wave Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 0; i < 12; i++) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
      delay(delayTime);
    }
  }

  for (int i = 11; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    delay(delayTime);
  }
}

void alternatePattern() {
  Serial.println("Alternate Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 0; i < 12; i += 2) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
    
  }
  delay(delayTime);

  for (int i = 0; i < 12; i += 2) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 12; i += 2) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
  }
  delay(delayTime);

  for (int i = 1; i < 12; i += 2) {
    digitalWrite(relays[i], LOW);
  }
}

void evenOddPattern() {
  Serial.println("Even Odd Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 0; i < 12; i += 2) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }

  for (int i = 1; i < 12; i += 2) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void randomPattern() {
  Serial.println("Random Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 0; i < 12; i++) {
    int randomIndex = random(6);
    if (sRelay[randomIndex]) {
      digitalWrite(relays[randomIndex], HIGH);
    }
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
  }
}

void clockwiseRotationPattern() {
  Serial.println("Clockwise Rotation Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 0; i < 12; i++) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void counterClockwiseRotationPattern() {
  Serial.println("Counter-clockwise Rotation Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 11; i >= 0; i--) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
    delay(delayTime);
    digitalWrite(relays[i], LOW);
  }
}

void blinkingPairsPattern() {
  Serial.println("Blinking Pairs Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 0; i < 6; i++) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
      digitalWrite(relays[(i + 3) % 6], HIGH);
    }
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    digitalWrite(relays[(i + 3) % 6], LOW);
  }
}

void alternatingHalvesPattern() {
  Serial.println("Alternating Halves Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12}; // array of relays

  for (int i = 0; i < 6; i++) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
  }
  delay(delayTime);
  for (int i = 0; i < 6; i++) {
    digitalWrite(relays[i], LOW);
  }

  for (int i = 6; i < 12; i++) {
    if (sRelay[i]) {
      digitalWrite(relays[i], HIGH);
    }
  }
  delay(delayTime);
  for (int i = 6; i < 12; i++) {
    digitalWrite(relays[i], LOW);
  }
}