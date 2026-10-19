const int ledPin = 18;
const int buttonPin = 23;

const unsigned long interval = 250;  // 250 ms per toggle = 2 full blinks/sec
unsigned long previousMillis = 0;

bool ledState = LOW;
bool wasPressed = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  bool isPressed = (digitalRead(buttonPin) == LOW);

  if (isPressed) {
    // Button takes priority: override blinking and hold LED on.
    ledState = HIGH;
    digitalWrite(ledPin, ledState);
  } else {
    // On release, restart the blink cycle from LED off.
    if (wasPressed) {
      ledState = LOW;
      digitalWrite(ledPin, LOW);
      previousMillis = currentMillis;
    }

    // Toggle LED only after the specified interval has elapsed.
    if (currentMillis - previousMillis >= interval) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      previousMillis = currentMillis;
    }
  }

  wasPressed = isPressed;
}
