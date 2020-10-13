#include "Wire.h"

const int address = 0x60;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);

  Serial.println("Write 0x7D to NVM");

  
  //Clear NV address 0x0
  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0x80);
  //Config 0
  Wire.write(0xF0);
  //Wait
  Wire.write(0xFF);
  Wire.endTransmission();

  //Write 0xD to NV address 0x0
  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0x80);
  //Config 0
  Wire.write(0xFD);
  //Wait
  Wire.write(0xFF);
  Wire.endTransmission();

  //Clear NV address 0x1
  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0xA0);
  //Config 0
  Wire.write(0xF0);
  //Wait
  Wire.write(0xFF);
  Wire.endTransmission();

  //Write 0x7 to NV address 0x1
  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0xA0);
  //Config 0
  Wire.write(0xF7);
  //Wait
  Wire.write(0xFF);
  Wire.endTransmission();

  //Clear NV address 0x2
  Wire.beginTransmission(address);
  //Config 1
  Wire.write(0xC0);
  //Config 0
  Wire.write(0xF0);
  //Wait
  Wire.write(0xFF);
  Wire.endTransmission();


  
  //This is the read function
  Wire.requestFrom(address, 4);
  while(Wire.available()) {
    uint8_t temp = Wire.read();
    Serial.print("0x");
    Serial.println(temp, HEX);
  }
  
    //Set NVM mode -- I think this works
  Wire.beginTransmission(address);
  Wire.write(0x90);
  Wire.write(0xFF);
  Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:

}
