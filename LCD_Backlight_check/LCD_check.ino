#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create an LCD object with the I2C address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to 0x3F if needed

void setup() {
  // Initialize the LCD
  lcd.begin(16,2);
  // Turn on the backlight
  lcd.backlight();
  // Print "Hello, World!" to the LCD
  lcd.setCursor(0, 0); // Set cursor to the first column of the first row
  lcd.print("Hello, World!");
}

void loop() {
  // Do nothing here...
}