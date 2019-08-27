/*
  OLED Temperature and Humidity Meter
  oled-temp-humid-meter.ino
  Displays results on 128 x 64 OLED display
  Uses AM2320 I2C Temperature and Humidity sensor
  Uses Adafruit SSD1306 OLED Library
  Uses Adafruit AM2320 Library
  Uses Adafruit GFX Graphics Library

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include Wire Library for I2C
#include <Wire.h>

// Include Adafruit Graphics & OLED libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Include Adafruit AM2320 Temp Humid Library
#include <Adafruit_AM2320.h>

// Reset pin not used but needed for library
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Define object am2320
Adafruit_AM2320 am2320 = Adafruit_AM2320();

void setup() {
  // Start Wire library for I2C
  Wire.begin();
  void setup() {

    // initialize OLED with I2C addr 0x3C
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    // Initialize Temp & Humid Sensor
    am2320.begin();
  }

  void displayTempHumid() {
    // Delay to allow sensor to stabalize
    delay(2000);

    // Read Humidity
    float h = am2320.readHumidity();
    // Read temperature as Celsius
    float t = am2320.readTemperature();

    // Clear the display
    display.clearDisplay();
    //Set the color - always use white despite actual display color
    display.setTextColor(WHITE);
    //Set the font size
    display.setTextSize(1);
    //Set the cursor coordinates
    display.setCursor(0, 0);
    display.print("DroneBot Workshop");
    display.setCursor(0, 10);
    display.print("Humidity:    ");
    display.print(h);
    display.print(" %");
    display.setCursor(0, 20);
    display.print("Temperature: ");
    display.print(t);
    display.print(" C");
  }
  void loop() {
    displayTempHumid();
    display.display();
  }
