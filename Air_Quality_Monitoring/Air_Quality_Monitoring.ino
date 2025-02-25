// Define the pin for the MQ-135 sensor
const int mq135Pin = A0; // Analog pin connected to MQ-135

void setup() {
  // Start the Serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the MQ-135 sensor
  int mq135Value = analogRead(mq135Pin);
  
  // Print the value to the Serial Monitor
  Serial.print("MQ-135 Value: ");
  Serial.println(mq135Value);
  
  // Add a delay for readability
  delay(1000); // Delay for 1 second
}
