// Define the pins for the sensors
const int mq135Pin = A1; // Analog pin connected to MQ-135
const int soilMoisturePin = A0; // Analog pin connected to Soil Moisture Sensor

void setup() {
  // Start the Serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the MQ-135 sensor
  int mq135Value = analogRead(mq135Pin);
  
  // Read the analog value from the Soil Moisture sensor
  int soilMoistureValue = analogRead(soilMoisturePin);
  
  // Print the MQ-135 value to the Serial Monitor
  Serial.print("MQ-135 Value: ");
  Serial.println(mq135Value);
  
  // Judging air quality based on the MQ-135 value
  if (mq135Value < 200) {
    Serial.println("Air Quality: Good");
  } else if (mq135Value < 400) {
    Serial.println("Air Quality: Moderate");
  } else if (mq135Value < 600) {
    Serial.println("Air Quality: Unhealthy for Sensitive Groups");
  } else if (mq135Value < 800) {
    Serial.println("Air Quality: Unhealthy");
  } else if (mq135Value < 1000) {
    Serial.println("Air Quality: Very Unhealthy");
  } else {
    Serial.println("Air Quality: Hazardous");
  }

  // Print the Soil Moisture value to the Serial Monitor
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);
  
  // Judging soil moisture based on the sensor value
  if (soilMoistureValue < 300) {
    Serial.println("Soil Moisture: Wet");
  } else if (soilMoistureValue < 700) {
    Serial.println("Soil Moisture: Moist");
  } else {
    Serial.println("Soil Moisture: Dry");
  }
  
  // Add a delay for readability
  delay(1000); // Delay for 1 second
}