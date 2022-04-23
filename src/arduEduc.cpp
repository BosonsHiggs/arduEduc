#include "arduEduc.h"

arduEduc::arduEduc(byte pinArray_[]={}, int lenPin_=1)
{
   pinArray = pinArray_;
   lenPin = lenPin_;
}
 
void arduEduc::ligar()
{
   Serial.println(*pinArray);
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

//Ler valores digitais
bool arduEduc::lerDigital()
{
   return digitalRead(*pinArray);
}

//Ler valores analógicos
int* arduEduc::lerAnalogico()
{
   int pins[lenPin];
   if(lenPin > 0 && lenPin < 2)
   {
      pins[0] = analogRead(*pinArray);
      myVal = pins;
      return myVal;
   }
   else if (lenPin > 1)
   {
      for (int n = 0; n < lenPin; n++)
      {
         pins[n] = analogRead(*(pinArray + n));
      }
      myVal = pins;
      return myVal;
   }
}

//Ler valores analógicos
void arduEduc::escreverAnalogico(int val)
{
   int *val_ = &val;
   analogWrite(*pinArray, *val_);
}

void arduEduc::blocoExecutar(int pinState_[]={0}, int Delay=500)
{
   pinState = pinState_;
   if(lenPin > 0 && lenPin < 2)
   {
      digitalWrite(*pinArray, pinState_[0]);
      delay(Delay);
   }
   else if (lenPin > 1)
   {
      for (int n = 0; n < lenPin; n++)
      {
         digitalWrite(*(pinArray + n), *(pinState + n));
      }
      delay(Delay);
   }
}