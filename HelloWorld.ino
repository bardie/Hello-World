//Arduino Uno with Matrix Orbital MOS-AO202C (I2C Mode)
//Created by Matrix Orbital, 16/5/2018
//support@matrixorbital.ca 
//www.matrixorbital.ca/appnotes

#include <Wire.h>

//global variables
byte ASCII_value = 0x30; //Going to start with a value of ASCII 0

void setup(){

  //***Arduino Configuration***
  Wire.begin(); //Setup I2C in the Arduino

  //***Display Configuration***

  //Set the display Transmission Protocol Select to I2C
  Wire.beginTransmission(0x28); // I2C transmit to device to address 0x28
  Wire.write(254); //Display command prefix
  Wire.write(160); //Sets the display Transmission Protocol Select to I2C
  Wire.write(0); //I2C Mode
  Wire.endTransmission();    // stop transmitting

  //***Begin Program***

  //Clear the screen on the display
  Wire.beginTransmission(0x28); // I2C transmit to device to address 0x28
  Wire.write(254); //Display command prefix
  Wire.write("X"); //Clear screen Command    
  Wire.endTransmission();    // stop transmitting  

  //Write Hello Word to the screen
  Wire.beginTransmission(0x28); // I2C transmit to device to address 0x28
  Wire.write("Hello World! ASCII:"); //Text to send to display
  Wire.endTransmission();    // stop transmitting  

}

void loop(){  //Main  menu loop

  //Set Cursor Position to Column 20, Row 1
  Wire.beginTransmission(0x28); // I2C transmit to device to address 0x28
  Wire.write(254); //Display command prefix
  Wire.write("G"); //Clear Set Cursor Position Command  
  Wire.write(20); //Column 20
  Wire.write(1); //Row 1
  Wire.endTransmission();    // stop transmitting 

  //Write to screen
  Wire.beginTransmission(0x28); // I2C transmit to device to address 0x28
  Wire.write(ASCII_value); //Write value to display
  Wire.endTransmission();    // stop transmitting 

  delay (750); //delay 750ms
  
  ASCII_value++;
}
