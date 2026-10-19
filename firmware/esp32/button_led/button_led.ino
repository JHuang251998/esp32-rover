const int ledPin = 18;
const int buttonPin = 23;
int previousButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(115200);
  previousButtonState = digitalRead(buttonPin);
  Serial.println("ESP32 ready!");
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (buttonState != previousButtonState) {
    if (buttonState == LOW) {
      Serial.println("Button PRESSED");
    } else {
      Serial.println("Button RELEASED");
    }
    previousButtonState = buttonState;
  }
}
