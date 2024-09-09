#include <SPI.h>
#include <WiFiNINA.h>

// WIFI (Only accepts 2.4hz)
const char* ssid = "Group3#2.4";
const char* password = "Group3passwordf0r2.4";

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Check for the WiFi module:
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        // Don't continue
        while (true);
    }

    // Attempt to connect to Wi-Fi network:
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    // Connect to the network
    while (WiFi.begin(ssid, password) != WL_CONNECTED) {
        // Wait 1 second for the connection to establish
        delay(1000);
        Serial.print(".");
    }

    // Connected to Wi-Fi
    Serial.println("\nConnected to Wi-Fi network!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // Your code here to run after connecting to Wi-Fi
}