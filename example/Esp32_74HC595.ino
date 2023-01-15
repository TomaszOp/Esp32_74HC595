#include "Esp32_74HC595.h"

Esp32_74HC595 shiftRegister;

void setup() 
{
  Serial.begin(115200);
  shiftRegister.Atach(21, 22, 23);
  shiftRegister.Init(false);
  Serial.println("Initialize System");
}

void loop() 
{
    //example
    /*
    shiftRegister.SetPin(1, HIGH);
    shiftRegister.SaveShiftRegister();

    delay(1000);

    shiftRegister.SetPin(1, LOW);
    shiftRegister.SaveShiftRegister();

    // set pin and saveShiftRegister
    shiftRegister.WritePin(2, HIGH);
    delay(1000);
    shiftRegister.WritePin(2, LOW);
    delay(1000);
    */


    for(int i = 0; i<=7; i++)
    {
      shiftRegister.WritePin(i, HIGH);
      delay(1000);
      shiftRegister.WritePin(i, LOW);

    }
/*
    shiftRegister.WritePin(1, HIGH);
    shiftRegister.WritePin(4, HIGH);
  
    delay(500);
    shiftRegister.WritePin(1, LOW);
    shiftRegister.WritePin(4, LOW);
    delay(500);
  */



  
}
