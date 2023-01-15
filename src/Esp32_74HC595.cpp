#include "Esp32_74HC595.h"

Esp32_74HC595::Esp32_74HC595()
{
  ShiftRegister = (bool*)malloc(8 * sizeof(bool));

  for(int i = 0 ; i< 8; i++)
  {
    ShiftRegister[i] = false;
  }
}

Esp32_74HC595::~Esp32_74HC595() 
{
  free(ShiftRegister);
}

void Esp32_74HC595::Atach(int DS, int SH_CP, int ST_CP)
{
  this->dataPin = DS;
  this->clockPin = SH_CP;
  this->loadPin = ST_CP;

  pinMode(this->dataPin, OUTPUT);
  pinMode(this->clockPin, OUTPUT);
  pinMode(this->loadPin, OUTPUT);
  
  ClearShiftRegister();
  SaveShiftRegister();
}

void Esp32_74HC595::Init(bool value)
{
  for(int i = 0 ; i< 8; i++)
  {
    ShiftRegister[i] = value;
  }
  
  ClearShiftRegister();
  SaveShiftRegister();
}

void Esp32_74HC595::ClearShiftRegister(){
  for(int i=0; i< 8; i++)
    ShiftRegister[i]=LOW;
}

void Esp32_74HC595::SaveShiftRegister()
{
  byte bitSpecified = 0;
  
  for(int i = 0 ; i< 8 ; i++)
  {
    if(ShiftRegister[i] == true)
      bitWrite(bitSpecified, i, HIGH);
    else
      bitWrite(bitSpecified, i, LOW);
  }

  #ifdef LOG_ON
  Serial.println(bitSpecified);
  #endif

  digitalWrite(loadPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, bitSpecified);
  digitalWrite(loadPin, HIGH);
}

void Esp32_74HC595::SetPin(int nr, int value)
{
  ShiftRegister[nr]=value;
}

void Esp32_74HC595::WritePin(int nr, int value)
{
  SetPin (nr, value);
  SaveShiftRegister();
}

bool Esp32_74HC595::GetPin(int nr)
{
  return ShiftRegister[nr];
}




