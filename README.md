# Esp32_74HC595
ShiftRegister 74HC595 Arduino Esp32 Library <br>
tested arduino 2.0.4<br>
<br>
use:<br>

Esp32_74HC595 shiftRegister;

shiftRegister.Atach(21, 22, 23); //(int DS, int SH_CP, int ST_CP); 
shiftRegister.Init(false); // init pins 0|1

// set pin data
// shiftRegister.SetPin(number pin, state);
shiftRegister.SetPin(0, HIGH);
shiftRegister.SetPin(1, LOW);
shiftRegister.SetPin(2, HIGH);
..
shiftRegister.SetPin(7, HIGH);
// send pin output to chip
shiftRegister.SaveShiftRegister();

// or set pin directly in chip 
//shiftRegister.WritePin(number pin, state);
shiftRegister.WritePin(1, HIGH);
