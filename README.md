# Temperature-monitoring-system


## Overview
This project is a Temperature Monitoring System using an NTC Thermistor and an I2C LCD Display with an Arduino Uno. The system reads temperature data from the NTC sensor, calculates the temperature using the Beta formula, and displays it on both the Serial Monitor and I2C LCD.

## Features
- Real-time temperature monitoring using an NTC Thermistor.
- Displays temperature on an I2C 16x2 LCD.
- Outputs temperature data to Serial Monitor.
- Uses I2C communication for reduced wiring complexity.
- Simulated in Wokwi (Online Simulator).

## Components Required
- Arduino Uno
- NTC Thermistor
- I2C LCD Display (16x2, Address: 0x27)
- Connecting Wires

## Circuit Connections
## NTC Thermistor Wiring:
- One leg → A0 (Analog Input)
- Other leg → 5V

## I2C LCD Wiring:
- SDA → A4  
- SCL → A5  
- VCC → 5V  
- GND → GND

## Installation & Usage
1. Clone the repository:
2. Open the project in Arduino IDE.
3. Install necessary libraries (if not already installed):
   - `LiquidCrystal_I2C` (for I2C LCD support)
4. Upload the code to Arduino Uno.
5. Open Serial Monitor (9600 baud rate) to view temperature data.


## Simulation in Wokwi
You can test this project using Wokwi Simulator:
1. Go to [Wokwi](https://wokwi.com/).
2. Create a new Arduino Uno project.
3. Add NTC Thermistor, and I2C LCD.
4. Connect components as described above.
5. Paste the code and start the simulation.

## Future Enhancements
- Add Fahrenheit display option.
- Implement Data Logging to SD Card.
- Connect to IoT Dashboard for remote monitoring.

