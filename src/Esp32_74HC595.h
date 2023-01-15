#ifndef _Esp32_74HC595_H__
#define _Esp32_74HC595_H__

#include <Arduino.h>

class Esp32_74HC595
{
public:
  Esp32_74HC595();
  ~Esp32_74HC595();

  int dataPin;  // DS
  int clockPin; // SH_CP
  int loadPin;   // ST_CP     

  void Atach(int DS, int SH_CP, int ST_CP);  
  void Init(bool value);     
  void SetPin(int nr, int value);  
  bool GetPin(int nr); 

  void WritePin(int nr, int value);

  void ClearShiftRegister();
  void SaveShiftRegister();

  private: 

  bool *ShiftRegister;

}; 




#endif
