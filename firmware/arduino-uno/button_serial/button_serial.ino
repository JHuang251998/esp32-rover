const int buttonPin = 2;
int previousButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  previousButtonState = digitalRead(buttonPin);
  Serial.println("Button monitor ready!");
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState != previousButtonState) {
    if (buttonState == LOW) {
      Serial.println("Button PRESSED");
    } else {
      Serial.println("Button RELEASED");
    }
    previousButtonState = buttonState;
  }
}
