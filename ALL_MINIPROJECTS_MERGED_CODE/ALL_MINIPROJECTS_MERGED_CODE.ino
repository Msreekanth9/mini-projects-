#include <Servo.h>

Servo lidServo;
const int trigPin = 2;
const int echoPin = 3;
const int lidServoPin = 4;
long duration;
int distance;

Servo clothServo;
const int rainPin = 5;
const int clothServoPin = 6;

const int soilPin = A0;
const int relayPin = 7;
int threshold = 500;

Servo doorServo1;
const int pirPin1 = 8;
const int doorServoPin1 = 9;

Servo doorServo2;
const int pirPin2 = 10;
const int doorServoPin2 = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lidServo.attach(lidServoPin);
  lidServo.write(0);

  pinMode(rainPin, INPUT);
  clothServo.attach(clothServoPin);
  clothServo.write(0);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  pinMode(pirPin1, INPUT);
  doorServo1.attach(doorServoPin1);
  doorServo1.write(0);

  pinMode(pirPin2, INPUT);
  doorServo2.attach(doorServoPin2);
  doorServo2.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 20000);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 10) {
    if (lidServo.read() != 90) lidServo.write(90);  // open when detected
  } else {
    if (lidServo.read() != 0) {
      delay(3000);              // wait 3 seconds before closing
      lidServo.write(0);        // then close
    }
  

  delay(200);
}


  int rainDetected = digitalRead(rainPin);
  if (rainDetected == HIGH) clothServo.write(0);
  else clothServo.write(90);

  int soilValue = analogRead(soilPin);
  if (soilValue > threshold) digitalWrite(relayPin, LOW);
  else digitalWrite(relayPin, HIGH);

  int motion1 = digitalRead(pirPin1);
  if (motion1 == HIGH) {
    if (doorServo1.read() != 90) doorServo1.write(90);
  } else {
    if (doorServo1.read() != 0){
      delay(3000);
    
    
    doorServo1.write(0);
  }
  }
  int motion2 = digitalRead(pirPin2);
  if (motion2 == HIGH) {
    if (doorServo2.read() != 90) doorServo2.write(90);
  } else {
    if (doorServo2.read() != 0)
    {
      delay(3000);
      doorServo2.write(0);
    }
  }

  delay(300);
}
