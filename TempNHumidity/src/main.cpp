#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int colorR = 255;
int colorG = 0;
int colorB = 0;

// Define the pin where the DHT22 data pin is connected
#define DHTPIN 4

// Define the type of DHT sensor
#define DHTTYPE DHT22

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    // Start serial communication for debugging
    Serial.begin(9600);

    // Initialize the DHT sensor
    dht.begin();

    // Initialize the LCD
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);

    Serial.println("DHT22 sensor and LCD initialization complete.");
}

void loop() {
    // Wait a few seconds between measurements
    delay(2000);

    // Reading temperature and humidity from the DHT22 sensor
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Check if any readings failed and exit early (to try again)
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        lcd.clear();
        lcd.print("Read Error!");
        return;
    }

    // Print the results to the Serial Monitor 
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");   

    // Set the RGB color based on the temperature
    if (temperature >= 28) {
        // Very Hot - Bright Red
        colorR = 255;
        colorG = 0;
        colorB = 0;
    } 
    else if (temperature >= 15 && temperature < 28) {
        // Warm - Orange
        colorR = 255;
        colorG = 165;
        colorB = 0;
    } 
    else if (temperature >= 10 && temperature < 15) {
        // Mild - Yellow
        colorR = 255;
        colorG = 255;
        colorB = 0;
    } 
    else if (temperature >= 5 && temperature < 10) {
        // Cool - Light Blue
        colorR = 173;
        colorG = 216;
        colorB = 230;
    } 
    else if (temperature >= 0 && temperature < 5) {
        // Cold - Blue
        colorR = 0;
        colorG = 0;
        colorB = 255;
    } 
    else if (temperature < 0) {
        // Very Cold - Dark Blue
        colorR = 0;
        colorG = 0;
        colorB = 139;
    }
    
    lcd.setRGB(colorR, colorG, colorB);

    lcd.clear();  // Clear the LCD screen
    lcd.setCursor(0, 0);  // Set cursor to the first row, first column
    lcd.print("T: ");
    lcd.print(temperature);
    lcd.print("C");

    lcd.setCursor(0, 1);  // Set cursor to the second row, first column
    lcd.print("H: ");
    lcd.print(humidity);
    lcd.print("%");
}
