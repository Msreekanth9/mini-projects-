const int TRIG_PIN = 2; // New pin
const int ECHO_PIN = 3; // New pin

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration, distance;

  // Clear trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure time
  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  distance = (duration / 2) / 29.1;

  // Unfreeze Hack: If sensor locks up at 0, briefly force the Echo pin to reset
  if (distance == 0) {
    pinMode(ECHO_PIN, OUTPUT);
    digitalWrite(ECHO_PIN, LOW);
    delayMicroseconds(200);
    pinMode(ECHO_PIN, INPUT);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(200);
}
