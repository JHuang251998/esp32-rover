// Week 2 - HC-SR04 ultrasonic distance sensor (Arduino Uno)
// Wiring: VCC -> 5V, GND -> GND, TRIG -> D9, ECHO -> D10
// Note: HC-SR04 ECHO is typically 5V; do not connect directly to ESP32 GPIO.

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  // Send a 10-microsecond trigger pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the HIGH pulse; stop waiting after 30 milliseconds.
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    Serial.println("No echo detected");
  } else {
    // Approximate speed of sound at 20 C: 0.0343 cm/microsecond.
    // Divide by two because sound travels to the object and back.
    float distanceCm = duration * 0.0343 / 2.0;

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  delay(200);
}
