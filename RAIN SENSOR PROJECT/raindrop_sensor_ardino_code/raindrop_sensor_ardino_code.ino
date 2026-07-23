#include <Servo.h>
Servo clothServo;

const int rainPin = 7;    // Rain sensor D0
const int servoPin = 9;  // Servo motor
const int buzzerPin = 6;  // Buzzer

void setup() {
  pinMode(rainPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  clothServo.attach(servoPin);
  clothServo.write(0); // Start closed
  digitalWrite(buzzerPin, LOW); // Ensure buzzer is OFF at start
}

void loop() {
  int rainDetected = digitalRead(rainPin);

  if (rainDetected == HIGH) {
    // Rain detected → move servo + buzzer ON
    clothServo.write(90);            // Move cloth
    digitalWrite(buzzerPin, HIGH);   // Buzzer ON continuously while rain detected
  } else {
    // No rain → return cloth + buzzer OFF
    clothServo.write(0);             // Return cloth
    digitalWrite(buzzerPin, LOW);    // Buzzer OFF
  }

  delay(100); // small delay for stability
}
