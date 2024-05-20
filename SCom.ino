#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// TODO: Edit these pins
int relay1 = 13; // D13
int relay2 = 12; // D12
int relay3 = 14; // D14
int relay4 = 27; // D27
int relay5 = 26; // D26
int relay6 = 25; // D25
int relay7C = 33; // D33
int relay8C = 32; // D32
int relay9C = 35; // D35

void setup() {
  // Set pin modes
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7C, OUTPUT);
  pinMode(relay8C, OUTPUT);
  pinMode(relay9C, OUTPUT);

  SerialBT.begin("Parent Top Light System");
  Serial.begin(9600);
  SerialESP.begin(9600, SERIAL_8N1, RXp2, TXp2); // Get data from ESP
  turnEverythingOn();
}
void loop() {
  if (Serial.available()) {
    String message = SerialESP.readString();
    Serial.println(message);

    switch (message) {
      case 's': suchiPatternChild(); break;
      case 'w': wavePatternChild(); break;
      case 'a': alternatePatternChild(); break;
      case 'e': evenOddPatternChild(); break;
      case 'r': randomPatternChild(); break;
      case 'c': clockwiseRotationPatternChild(); break;
      case 't': counterClockwiseRotationPatternChild(); break;
      case 'b': blinkingPairsPatternChild(); break;
      case 'h': alternatingHalvesPatternChild(); break;
      case '0': turnEverythingOnChild(); break;
      default: turnEverythingOnChild(); break;
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
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  Serial.println("Everything turned on!");

  for (int i = 0; i < 6; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
}

void suchiPattern(){
  int delayTime = 1000; // delay time in milliseconds
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  Serial.println("Suchi Pattern");
  
  for (int i = 0; i < 6; i++) {
    digitalWrite(relays[i], HIGH); // turn the current relay on
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime); // wait for delayTime
    digitalWrite(relays[i], LOW); // turn the current relay off
    Serial.println("Lrelay" + String(i+1));
  }
}

void wavePattern() {
  Serial.printlln("Wave Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 0; i < 6; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
  }

  for (int i = 5; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
    delay(delayTime);
  }
}

void alternatePattern() {
  Serial.println("Alternate Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 0; i < 6; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);

  for (int i = 0; i < 6; i += 2) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }

  for (int i = 1; i < 6; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);

  for (int i = 1; i < 6; i += 2) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void evenOddPattern() {
  Serial.println("Even Odd Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 0; i < 6; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }

  for (int i = 1; i < 6; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void randomPattern() {
  Serial.println("Random Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 0; i < 6; i++) {
    int randomIndex = random(6);
    digitalWrite(relays[randomIndex], HIGH);
    Serial.println("Hrelay" + String(randomIndex+1));
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
    Serial.println("Lrelay" + String(randomIndex+1));
  }
}

void clockwiseRotationPattern() {
  Serial.println("Clockwise Rotation Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 0; i < 6; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void counterClockwiseRotationPattern() {
  Serial.println("Counter-clockwise Rotation Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 5; i >= 0; i--) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void blinkingPairsPattern() {
  Serial.println("Blinking Pairs Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    digitalWrite(relays[(i + 3) % 6], HIGH);
    Serial.println("Hrelay" + String(((i + 3) % 6)+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
    digitalWrite(relays[(i + 3) % 6], LOW);
    Serial.println("Lrelay" + String(((i + 3) % 6)+1));
  }
}

void alternatingHalvesPattern() {
  Serial.println("Alternating Halves Pattern");

  int delayTime = 1000;
  int relays[] = {relay1, relay2, relay3, relay4, relay5, relay6}; // array of relays

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);
  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }

  for (int i = 3; i < 6; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);
  for (int i = 3; i < 6; i++) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

// Child Functions
// ----------------

void turnEverythingOnChild() {
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  Serial.println("Everything turned on!");

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
}

void suchiPatternChild(){
  int delayTime = 1000; // delay time in milliseconds
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  Serial.println("Suchi Pattern");
  
  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH); // turn the current relay on
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime); // wait for delayTime
    digitalWrite(relays[i], LOW); // turn the current relay off
    Serial.println("Lrelay" + String(i+1));
  }
}

void wavePatternChild() {
  Serial.printlln("Wave Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
  }

  for (int i = 2; i >= 0; i--) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
    delay(delayTime);
  }
}

void alternatePatternChild() {
  Serial.println("Alternate Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 0; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);

  for (int i = 0; i < 3; i += 2) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }

  for (int i = 1; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);

  for (int i = 1; i < 3; i += 2) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void evenOddPatternChild() {
  Serial.println("Even Odd Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 0; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }

  for (int i = 1; i < 3; i += 2) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void randomPatternChild() {
  Serial.println("Random Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 0; i < 3; i++) {
    int randomIndex = random(6);
    digitalWrite(relays[randomIndex], HIGH);
    Serial.println("Hrelay" + String(randomIndex+1));
    delay(delayTime);
    digitalWrite(relays[randomIndex], LOW);
    Serial.println("Lrelay" + String(randomIndex+1));
  }
}

void clockwiseRotationPatternChild() {
  Serial.println("Clockwise Rotation Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void counterClockwiseRotationPatternChild() {
  Serial.println("Counter-clockwise Rotation Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 2; i >= 0; i--) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}

void blinkingPairsPatternChild() {
  Serial.println("Blinking Pairs Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
    digitalWrite(relays[(i + 3) % 6], HIGH);
    Serial.println("Hrelay" + String(((i + 3) % 6)+1));
    delay(delayTime);
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
    digitalWrite(relays[(i + 3) % 6], LOW);
    Serial.println("Lrelay" + String(((i + 3) % 6)+1));
  }
}

void alternatingHalvesPatternChild() {
  Serial.println("Alternating Halves Pattern");

  int delayTime = 1000;
  int relays[] = {relay7C, relay8C, relay9C}; // array of relays

  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);
  for (int i = 0; i < 3; i++) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }

  for (int i = 3; i < 6; i++) {
    digitalWrite(relays[i], HIGH);
    Serial.println("Hrelay" + String(i+1));
  }
  delay(delayTime);
  for (int i = 3; i < 6; i++) {
    digitalWrite(relays[i], LOW);
    Serial.println("Lrelay" + String(i+1));
  }
}