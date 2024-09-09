#include <Arduino.h>

// Define the pin where the buzzer is connected
const int buzzerPin = 5;  // Example pin, change as needed

void setup() {
    // Initialize the buzzer pin as an output
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    // Turn the buzzer on
    digitalWrite(buzzerPin, HIGH);
    delay(500);  // Wait for 500 milliseconds (half a second)

    // Turn the buzzer off
    digitalWrite(buzzerPin, LOW);
    delay(500);  // Wait for 500 milliseconds (half a second)
}
