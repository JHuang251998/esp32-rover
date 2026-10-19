const int ledPin = LED_BUILTIN;

bool ledState = LOW;
unsigned long previousMillis = 0;
const unsigned long interval = 100;  // 100 ms per toggle = 5 full blinks/sec

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
