#include <DHT.h>

#define DHTPIN 2          // DHT11 data pin
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define MQ135_PIN A0     // MQ135 analog pin

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read temperature and humidity from DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read air quality from MQ135
  int mq135Value = analogRead(MQ135_PIN);
  
  // Print the results to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.print(" %, Air Quality (MQ135): ");
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


  // Wait a few seconds between measurements
  delay(2000);
}