#include "Wire.h"

const int address = 0x60;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);

//  //Write 0x123 to volatile memory
//  Wire.beginTransmission(address);
//  Wire.write(0x01);
//  Wire.write(0x23);
//
//  if (Wire.endTransmission() == 0)
//    Serial.println("Successful write to volatile memory");
//  else {
//    Serial.println("Wire transmission not successful. Freezing");
//    while(1);
//  }

  //Write 0x46 to non-volatile memory
  //First, erase NVM
  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0xC0);
  //Config 0
  Wire.write(0x00);
  //Wait
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0xA0);
  //Config 0
  Wire.write(0x00);
  //Wait
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0x80);
  //Config 0
  Wire.write(0x00);
  //Wait
  Wire.write(0x00);
  Wire.endTransmission();

  //Then, write to NVM
  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0xC0);
  //Config 0
  Wire.write(0x00);
  //Wait
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0xA0);
  //Config 0
  Wire.write(0x04);
  //Wait
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0x80);
  //Config 0
  Wire.write(0x06);
  //Wait
  Wire.write(0x00);
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
