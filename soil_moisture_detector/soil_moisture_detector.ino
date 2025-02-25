// Define the pin for the soil moisture sensor
const int sensorPin = A0; // Analog pin connected to the sensor
const int ledPin = 8;      // Digital pin for LED or Buzzer

void setup() {
  Serial.begin(9600);      // Start the Serial communication
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the sensor value
  Serial.print("Soil Moisture Level: ");
  Serial.println(sensorValue); // Print the value to Serial Monitor

  // Map the sensor value to a moisture level (0-100%)
  int moistureLevel = map(sensorValue, 0, 1023, 100, 0); // Adjust based on your sensor
  Serial.print("Moisture Level (%): ");
  Serial.println(moistureLevel);

  // Control LED or Buzzer based on moisture level
  if (moistureLevel < 30) { // Threshold for dry soil
    digitalWrite(ledPin, HIGH); // Turn on LED or Buzzer
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED or Buzzer
  }

  delay(2000); // Wait for 2 seconds before the next reading
}