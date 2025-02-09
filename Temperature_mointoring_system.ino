#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define NTC_PIN A0  // NTC Thermistor connected to A0

// Initialize I2C LCD (Address: 0x27, 16x2 Display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Constants for NTC calculations
#define SERIES_RESISTOR 10000  // 10kΩ Resistor
#define NOMINAL_RESISTANCE 10000  // 10kΩ at 25°C
#define NOMINAL_TEMPERATURE 25.0  // 25°C
#define BETA_COEFFICIENT 3950  // Beta coefficient for NTC
#define ADC_MAX 1023.0  // 10-bit ADC max value

void setup() {
  Serial.begin(9600);  // Start Serial Monitor
  lcd.init();          // Initialize I2C LCD
  lcd.backlight();     // Turn on LCD backlight
}

void loop() {
  int adcValue = analogRead(NTC_PIN);  // Read ADC value from NTC
  float resistance = SERIES_RESISTOR / ((ADC_MAX / adcValue) - 1);  // Calculate resistance

  // Calculate temperature using Beta formula
  float temperature = 1.0 / ((log(resistance / NOMINAL_RESISTANCE) / BETA_COEFFICIENT) + (1.0 / (NOMINAL_TEMPERATURE + 273.15)));
  temperature -= 273.15;  // Convert from Kelvin to Celsius

  // Display temperature on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Display temperature on I2C LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  delay(1000);  // Update every second
}
