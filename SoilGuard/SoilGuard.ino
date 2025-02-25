#include <DHT.h>

#define DHTPIN 2          // DHT11 data pin
#define DHTTYPE DHT11     // DHT 11
#define SOIL_MOISTURE_PIN A0 // Soil moisture sensor pin
#define MQ135_PIN A1      // MQ-135 sensor pin

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read temperature and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  // Read soil moisture
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  
  // Read air quality
  int mq135Value = analogRead(MQ135_PIN);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  // Print soil moisture
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  // Print air quality
  Serial.print("MQ-135 Value: ");
  Serial.println(mq135Value);

  // Judging air quality
  if (mq135Value < 200) {
    Serial.println("Air Quality: Good");
  } else if (mq135Value < 400) {
    Serial.println("Air Quality: Moderate");
  } else {
    Serial.println("Air Quality: Poor");
  }

  // Judging soil moisture
  if (soilMoistureValue < 300) {
    Serial.println("Soil Moisture: dry");
  } else if (soilMoistureValue < 700) {
    Serial.println("Soil Moisture: Moist");
  } else {
    Serial.println("Soil Moisture: wet");
  }

  Serial.println();
  delay(2000); // Wait for 2 seconds before the next loop
}
