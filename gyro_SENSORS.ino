#include <Wire.h>
#include <MPU6050_light.h>
MPU6050 mpu(Wire);
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.setAddress(0x68);
  mpu.begin();
  mpu.calcOffsets();
 // mpu.setGyroOffsets(float x, float y, float z)

}

void loop() {
  mpu.update();
  float angle[3]={mpu.getAccAngleX(), mpu.getAccAngleY(), mpu.getAngleZ()};
  float gyro[3]={mpu.getGyroX(), mpu.getGyroY(), mpu.getGyroZ()};
  Serial.print(angle[0]);
  Serial.print("  ");
  Serial.print(angle[1]);
  Serial.print("  ");
  Serial.print(angle[2]);
  Serial.print(" | ");
  Serial.println(gyro[0]);
  Serial.print("  ");
  Serial.println(gyro[1]);
  Serial.print("  ");
  Serial.println(gyro[2]);
 delay(100);

}
