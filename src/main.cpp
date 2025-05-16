#include <Arduino.h>

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

void setup() {
  Serial.begin(9600);
}

void loop() {
  SensorData data;
  data.temperature = 25;
  data.voltage = 3.7;

  Serial.write((uint8_t *)&data, sizeof(data));

  delay(2000);
}
