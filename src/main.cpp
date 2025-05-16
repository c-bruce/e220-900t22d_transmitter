#include <Arduino.h>
#include <SoftwareSerial.h>

// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   Serial.println("H");
//   delay(1000);
//   Serial.println("L");
//   delay(1000);
// }

struct SensorData {
  int temperature;
  float voltage;
};

SoftwareSerial loraSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600);
}

void loop() {
  SensorData data;
  data.temperature = 25;
  data.voltage = 3.7;

  loraSerial.write((uint8_t *)&data, sizeof(data));

  delay(2000);
}
