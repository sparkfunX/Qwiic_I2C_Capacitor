#include "Wire.h"

const int address = 0x60;

void setup() {
  Wire.begin();
  Serial.begin(115200);

  Serial.println("Write 0x123 to volatilte memory:");
  Wire.beginTransmission(address);
  Wire.write(0x01);
  Wire.write(0x23);
  Wire.endTransmission();
  
  //This is the read function
  Wire.requestFrom(address, 4);
  while(Wire.available()) {
    uint8_t temp = Wire.read();
    Serial.print("0x");
    Serial.println(temp, HEX);
  }

  Serial.println("Write 0x7 to volatile memory:");
  Wire.beginTransmission(address);
  Wire.write(0x00);
  Wire.write(0x07);
  Wire.endTransmission();

  //This is the read function
  Wire.requestFrom(address, 4);
  while(Wire.available()) {
    uint8_t temp = Wire.read();
    Serial.print("0x");
    Serial.println(temp, HEX);
  }

  Serial.println("Write 0x1F9 to volatile memory:");
  Wire.beginTransmission(address);
  Wire.write(0x01);
  Wire.write(0xF9);
  Wire.endTransmission();
 
  //This is the read function
  Wire.requestFrom(address, 4);
  while(Wire.available()) {
    uint8_t temp = Wire.read();
    Serial.print("0x");
    Serial.println(temp, HEX);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
