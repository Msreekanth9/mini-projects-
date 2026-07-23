const int soilPin = A0;  
const int relayPin = 8;   

int threshold = 500;      

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); 
  Serial.println("System Ready: Pump OFF");
}

void loop() {
  int soilValue = analogRead(soilPin);
  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  // Invert logic: Wet → OFF, Dry → ON
  if (soilValue > threshold) {
    Serial.println("Sensor in Water → Pump OFF");
    digitalWrite(relayPin, LOW);  
  } else {
    Serial.println("Sensor Dry → Pump ON");
    digitalWrite(relayPin, HIGH); 
  }

  delay(1000);
}
