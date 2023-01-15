# Esp32_74HC595
ShiftRegister 74HC595 Arduino Esp32 Library <br>
tested arduino 2.0.4<br>
<br>
use:<br>

Esp32_74HC595 shiftRegister;<br>
<br>
shiftRegister.Atach(21, 22, 23); //(int DS, int SH_CP, int ST_CP);<br> 
shiftRegister.Init(false); // init pins 0|1<br>
<br>
// set pin data<br>
// shiftRegister.SetPin(number pin, state);<br>
shiftRegister.SetPin(0, HIGH);<br>
shiftRegister.SetPin(1, LOW);<br>
shiftRegister.SetPin(2, HIGH);<br>
..<br>
shiftRegister.SetPin(7, HIGH);<br>
// send pin output to chip<br>
shiftRegister.SaveShiftRegister();<br>
<br>
// or set pin directly in chip <br>
//shiftRegister.WritePin(number pin, state);<br>
shiftRegister.WritePin(1, HIGH);<br>
