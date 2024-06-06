// Relay pins for the first set
int relay1 = 5;
int relay2 = 6;
int relay3 = 7;

// Relay pins for the second set
int relay4 = 3;
int relay5 = 2;
int relay6 = 10;
int relay7 = 11;
int relay8 = 12;
int relay9 = 13;
int relay10 = 14;
int relay11 = 15;
int relay12 = 16;
int relay13 = 17;
int relay14 = 18;
int relay15 = 19;
int relay16 = 20;
int relay17 = 21;
int relay18 = 22;
int relay19 = 24;
int relay20 = 26;
int relay21 = 28;
int relay22 = 9;
int relay23 = 8;
int relay24 = 7;

// Define patterns
char currentPattern = '1'; // Default pattern

// Timing variables
unsigned long previousMillis = 0;
const long interval = 2 * 60 * 1000; // Interval to change pattern (2 minutes)

// Initialize the relay pins
int relayPins[] = {relay1, relay2, relay3, relay4, relay5, relay6, relay7, relay8, relay9, relay10, relay11, relay12, relay13, relay14, relay15, relay16, relay17, relay18, relay19, relay20, relay21, relay22, relay23, relay24};
const int numRelays = sizeof(relayPins) / sizeof(relayPins[0]);

void setup() {
  // Initialize relay pins as outputs
  for (int i = 0; i < numRelays; i++) {
    pinMode(relayPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if it's time to change the pattern
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int patternNumber = currentPattern - '0'; // Convert char to int
    patternNumber++; // Increment the pattern number
    if (patternNumber > 9) patternNumber = 1; // Reset to the first pattern
    currentPattern = patternNumber + '0'; // Convert back to char
  }

  // Run the appropriate pattern based on the currentPattern value
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

// Function to turn all relays off
void allOff() {
  for (int i = 0; i < numRelays; i++) {
    digitalWrite(relayPins[i], LOW);
  }
}

// Pattern function: Turns all relays on
void patternRun() {
  allOff(); // Turn off all relays
  for (int i = 0; i < numRelays; i++) {
    digitalWrite(relayPins[i], HIGH);
  }
}

// Pattern function: Creates a wave effect
void wavePattern() {
  allOff();
  int delayTime = 250;
  for (int i = 0; i < numRelays; i++) {
    digitalWrite(relayPins[i], HIGH);
    delay(delayTime);
    digitalWrite(relayPins[i], LOW);
  }
}

// Pattern function: Creates an alternate effect
void alternatePattern() {
  allOff();
  int delayTime = 250;
  for (int i = 0; i < numRelays; i += 2) {
    digitalWrite(relayPins[i], HIGH);
    delay(delayTime);
    digitalWrite(relayPins[i], LOW);
    digitalWrite(relayPins[i + 1], HIGH);
    delay(delayTime);
    digitalWrite(relayPins[i + 1], LOW);
  }
}

// Pattern function: Creates an even-odd effect
void evenOddPattern() {
  allOff();
  int delayTime = 250;
  for (int i = 0; i < numRelays; i += 2) {
    digitalWrite(relayPins[i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i < numRelays; i += 2) {
    digitalWrite(relayPins[i], LOW);
  }
  for (int i = 1; i < numRelays; i += 2) {
    digitalWrite(relayPins[i], HIGH);
  }
  delay(delayTime);
  for (int i = 1; i < numRelays; i += 2) {
    digitalWrite(relayPins[i], LOW);
  }
}

// Pattern function: Creates a random effect
void randomPattern() {
  allOff();
  int delayTime = 150;
  for (int i = 0; i < numRelays; i++) {
    int randomIndex = random(numRelays);
    digitalWrite(relayPins[randomIndex], HIGH);
    delay(delayTime);
    digitalWrite(relayPins[randomIndex], LOW);
  }
}

// Pattern function: Creates a clockwise rotation effect
void clockwiseRotationPattern() {
  allOff();
  int delayTime = 250;
  for (int i = 0; i < numRelays; i++) {
    digitalWrite(relayPins[i], HIGH);
    delay(delayTime);
    digitalWrite(relayPins[i], LOW);
  }
}

// Pattern function: Creates a counter-clockwise rotation effect
void counterClockwiseRotationPattern() {
  allOff();
  int delayTime = 250;
  for (int i = numRelays - 1; i >= 0; i--) {
    digitalWrite(relayPins[i], HIGH);
    delay(delayTime);
    digitalWrite(relayPins[i], LOW);
  }
}

// Pattern function: Creates a blinking pairs effect
void blinkingPairsPattern() {
  allOff();
  int delayTime = 250;
  for (int i = 0; i < numRelays - 1; i += 2) {
    digitalWrite(relayPins[i], HIGH);
    digitalWrite(relayPins[i + 1], HIGH);
    delay(delayTime);
    digitalWrite(relayPins[i], LOW);
    digitalWrite(relayPins[i + 1], LOW);
  }
}

// Pattern function: Creates an alternating halves effect
void alternatingHalvesPattern() {
  allOff();
  int delayTime = 500;
  for (int i = 0; i < numRelays / 2; i++) {
    digitalWrite(relayPins[i], HIGH);
    digitalWrite(relayPins[numRelays / 2 + i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i < numRelays / 2; i++) {
    digitalWrite(relayPins[i], LOW);
    digitalWrite(relayPins[numRelays / 2 + i], LOW);
  }
}
