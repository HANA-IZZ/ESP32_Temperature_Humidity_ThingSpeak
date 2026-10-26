// WIFI ?
// ThingSpeak?

#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// WiFi settings
const char* WIFI_Name = "Wokwi-GUEST";
const char* WIFI_Pass = "";

// ThingSpeak settings
const long channelNumber = 3551728;
const char* apiKey = "Z4JVQ7KT7L2Z9F5H";

// University ID
const char* universityID = "12324223";

// DHT22 sensor settings
#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

WiFiClient clientObject;

// Send data every 20 seconds
unsigned long lastSendTime = 0;
const unsigned long sendInterval = 20000;

void setup() {
  Serial.begin(115200);

  dht.begin();

  Serial.println("University ID:");
  Serial.println(universityID);

  // Connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_Name, WIFI_Pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Status: Not Connected");
    delay(1000);
  }

  Serial.println("Status: Connected");

  // Start ThingSpeak
  ThingSpeak.begin(clientObject);
}

void loop() {
  if (millis() - lastSendTime >= sendInterval) {
    lastSendTime = millis();

    // Read temperature and humidity
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Check sensor readings
    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Error: Failed to read DHT22");
      return;
    }

    // Print readings
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Check WiFi connection
    if (WiFi.status() == WL_CONNECTED) {

      // Send temperature to Field 1
      ThingSpeak.setField(1, temperature);

      // Send humidity to Field 2
      ThingSpeak.setField(2, humidity);

      // Upload both fields
      int stat = ThingSpeak.writeFields(channelNumber, apiKey);

      if (stat == 200) {
        Serial.println("Data Sent to ThingSpeak");
      } else {
        Serial.print("Problem sending data. HTTP error code: ");
        Serial.println(stat);
      }

    } else {
      Serial.println("WiFi Disconnected");
    }

    Serial.println("----------------------");
  }
}
