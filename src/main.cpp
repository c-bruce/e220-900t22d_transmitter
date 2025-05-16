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
  // BPM-280
  float temperature;
  float pressure;
  float altitude;
  // MPU-6050
  float accX;
  float accY;
  float accZ;
  float gyroX;
  float gyroY;
  float gyroZ;
  // GPS
  float latitude;
  float longitude;
  float altitudeGPS;
  float speed;
  float course;
};

SoftwareSerial loraSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600);
}

void loop() {
  SensorData data;
  data.temperature = 1.1;
  data.pressure = 1.2;
  data.altitude = 1.3;
  data.accX = 2.1;
  data.accY = 2.2;
  data.accZ = 2.3;
  data.gyroX = 2.4;
  data.gyroY = 2.5;
  data.gyroZ = 2.6;
  data.latitude = 3.1;
  data.longitude = 3.2;
  data.altitudeGPS = 3.3;
  data.speed = 3.4;
  data.course = 3.5;

  loraSerial.write((uint8_t *)&data, sizeof(data));

  delay(2000);
}
