#include "arduEduc.h"

arduEduc::arduEduc(byte pinArray_[], int lenPin_, bool pinStateIn_, int serial_speed=9600)
{
   pinArray = pinArray_;
   lenPin = lenPin_;

   Serial.begin(serial_speed);
   for (int n = 0; n < lenPin_; n++)
   {
      pinMode(*(pinArray + n), pinStateIn_);
   }
}
 
void arduEduc::ligar()
{
   digitalWrite(*pinArray, HIGH);
}
 
void arduEduc::desligar()
{
   digitalWrite(*pinArray, LOW);
}
 
void arduEduc::inverter()
{
   digitalWrite(*pinArray, !digitalRead(*pinArray));
}

void arduEduc::esperar(unsigned long tempo)
{
   delay(tempo);
}

void arduEduc::blocoExecutar(int pinState_[], int Delay)
{
   pinState = pinState_;
   for (int n = 0; n < lenPin; n++)
   {
      digitalWrite(*(pinArray + n), *(pinState + n));
   }
   delay(Delay);
}