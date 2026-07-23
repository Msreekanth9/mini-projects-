const int irPin = 7;      // IR sensor output
const int relayPin = 8;   // Relay control pin
const int buzzerPin = 6;  // Buzzer

void setup() {
  Serial.begin(9600);       // Start Serial Monitor
  pinMode(irPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(relayPin, LOW);   // Pump OFF at start
  digitalWrite(buzzerPin, LOW);  // Buzzer OFF at start

  Serial.println("System Ready: Pump OFF");
}

void loop() {
  int handDetected = digitalRead(irPin);

  if (handDetected == HIGH) { // Hand detected
    Serial.println("Hand Detected → Pump ON");

    // Turn ON pump via relay
    digitalWrite(relayPin, HIGH);

    // Beep once when pump starts
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Buzzer: Pump Start Beep");

    // Keep pump ON for 4 seconds
    delay(4000);

    // Turn OFF pump
    digitalWrite(relayPin, LOW);
    Serial.println("Pump OFF");

    // Beep once when pump stops
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Buzzer: Pump Stop Beep");
  }

  delay(200); // small delay before next check
}
