#include <Arduino.h>

// Define the pin where the sound sensor signal pin is connected
#define SOUND_SENSOR_PIN A3

// Threshold for sound level in dB (example value, adjust based on your calibration)
const int dB_THRESHOLD = 40;

// Function to approximate dB from sensor value
int calculateDB(int sensorValue) {
    float dB = map(sensorValue, 0, 1023, 10, 80); // Maps sensorValue (0-1023) to dB range (10-80)
    return (int)dB;
}

void setup() {
    // Start serial communication for debugging
    Serial.begin(9600);
    
    // Initialize the sound sensor pin as input (optional, as analog pins are input by default)
    pinMode(SOUND_SENSOR_PIN, INPUT);
    
    Serial.println("Sound sensor initialization complete.");
}

void loop() {
    // Read the analog value from the sound sensor
    int sensorValue = analogRead(SOUND_SENSOR_PIN);
    
    // Convert sensor value to approximate dB
    int soundLevelDB = calculateDB(sensorValue);

    // Print the sound level in dB to the Serial Monitor
    Serial.print("Sound Level: ");
    Serial.print(soundLevelDB);
    Serial.println(" dB");
    
    // Check if the sound level exceeds the dB threshold
    if (soundLevelDB > dB_THRESHOLD) {
        Serial.println("Sound threshold exceeded!");
        // Add additional actions to perform when the threshold is exceeded
    }

    // Wait a short while before the next reading
    delay(1000);  // 1 second delay
}
