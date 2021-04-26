#include "Arduino.h"
#include "Wire.h"
#include "Ynvisible_Driver_4.2-1.0.0.h"

YNV_ECD::YNV_ECD(char address, int number_of_segments)
{
  _address = address; 
  _number_of_segments = number_of_segments;
}

// Update the dipslay to a new state
void YNV_ECD::set(bool next_state[])
{
  String data = "SETBIN:";
  for(int i = 0; i<_number_of_segments; i++){
    data = data + next_state[i];
  }
  sendData(data);
}

// Function for single seven segment display
void YNV_ECD::setNumber1x7(int number)
{
  if((number<10) && (number>=0)){
    String data = "SET1X7:";
    data += number;
    sendData(data);
  }
}

// Function for double seven segment display
void YNV_ECD::setNumber2x7(int number)
{
  if((number<100) && (number>=-99)){
    String data = "SET2X7:";
    data += number;
    sendData(data);
  }
}

// Function for the bar display
void YNV_ECD::setBar(int number)
{
  if((number < 8) && (number >= 0)){
    String data = "SETBAR:";
    data += number;
    sendData(data);
  }
}

// Refresh the dipslay
void YNV_ECD::refresh()
{
  String data = "REFRES";
  sendData(data);
}

// Reset the display and remove all content
void YNV_ECD::reset()
{
  String data = "SETRES";
  sendData(data);
}

// Set supply voltage
void YNV_ECD::setSupplyVoltage(float v)
{
  String data = "SETSUP:";
  data += v;
  sendData(data);
}

// Set driving method
void YNV_ECD::setDrivingMethod(char c){
  String data = "SETMET:";
  data += c;
  sendData(data);
}

// Set sequential reduction voltage
void YNV_ECD::setSeqRedVoltage(float v)
{
  String data = "SSRVOL:";
  data += v;
  sendData(data);
}

// Set sequential reduction time
void YNV_ECD::setSeqRedTime(int t)
{
  String data = "SSRTIM:";
  data += t;
  sendData(data);
}

// Set sequential oxidation voltage
void YNV_ECD::setSeqOxiVoltage(float v)
{
  String data = "SSOVOL:";
  data += v;
  sendData(data);
}

// Set sequential oxidation time
void YNV_ECD::setSeqOxiTime(int t)
{
  String data = "SSOTIM:";
  data += t;
  sendData(data);
}

// Set parallel voltage
void YNV_ECD::setParVoltage(float v)
{
  String data = "SEPVOL:";
  data += v;
  sendData(data);
}

// Set parallel switch time
void YNV_ECD::setParSwitchTime(int t)
{
  String data = "SEPTIM:";
  data += t;
  sendData(data);
}

// Set refresh reduction time
void YNV_ECD::setRefreshTime(int t)
{
  String data = "SETREF:";
  data += t;
  sendData(data);
}

// Send data to display
void YNV_ECD::sendData(String data){
  Serial.println(data);
  Wire.beginTransmission(_address);
  Wire.write(data.c_str());
  Wire.endTransmission();
}