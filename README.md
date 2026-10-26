# ESP32 and ThingSpeak Lab

## Lab Information

- **Name:** Hana Izzdeen
- **University ID:** 12324223

## Lab Description

In this lab, I used an ESP32 and a DHT22 sensor to read temperature and humidity values. I connected the ESP32 to Wi-Fi and sent the sensor readings to ThingSpeak, where the data is displayed in charts.

## Connections

| DHT22 | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA / DATA | GPIO 15 |

## ThingSpeak

- **Channel ID:** 3551728
- **Field 1:** Temperature (°C)
- **Field 2:** Humidity (%)
- **Update interval:** 20 seconds

## Results

The ESP32 connected to Wi-Fi and read the temperature and humidity values from the DHT22 sensor. The Serial Monitor displayed the readings and the message `Data Sent to ThingSpeak`, confirming that the data was sent successfully.

The temperature and humidity charts can be viewed on my ThingSpeak channel.

**ThingSpeak Channel:** https://thingspeak.mathworks.com/channels/3551728

## Wokwi Simulation

https://wokwi.com/projects/478961827212652545

## Screenshots

The `screenshots` folder contains the circuit, Serial Monitor output, and ThingSpeak charts.
