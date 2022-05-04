#include "arduEduc.h"

//Init da biblioteca
arduEduc::arduEduc(byte pinArray_[]={}, int lenPin_=1)
{
   pinArray = pinArray_;
   lenPin = lenPin_;
}

//Enviar estado HIGH para o pino
void arduEduc::ligar()
{
   Serial.println(*pinArray);
   digitalWrite(*pinArray, HIGH);
}

//Enviar estado low para o pino 
void arduEduc::desligar()
{
   digitalWrite(*pinArray, LOW);
}

//Inverter estado de um pino 
void arduEduc::inverter()
{
   digitalWrite(*pinArray, !digitalRead(*pinArray));
}

//Delay
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

//Medir distancia com sensor ultrassônico SR04
long* arduEduc::distanciaUltra()
{
   long pins[lenPin];
   if(lenPin > 1 && lenPin < 3)
   {
      delayMicroseconds(5);
      digitalWrite(*(pinArray+1), HIGH);
      delayMicroseconds(10);
      digitalWrite(*(pinArray+1), LOW);

      pins[0] = long(pulseIn(*pinArray, HIGH)/58);

      myValUltra = pins;
      return myValUltra;
   }
   else if (lenPin > 2)
   {
      for (int n = 1; n < lenPin/2+1; n++)
      {
         delayMicroseconds(5);
         digitalWrite(*(pinArray+2*n-1), HIGH);
         delayMicroseconds(10);
         digitalWrite(*(pinArray+2*n-1), LOW);

         pins[n-1] = long(pulseIn(*(pinArray+2*(n-1)), HIGH)/58);
      }
      myValUltra = pins;
      return myValUltra;
   }
}

//Ler valores analógicos
void arduEduc::escreverAnalogico(int val)
{
   int *val_ = &val;
   analogWrite(*pinArray, *val_);
}


//Executar um bloco de comandos
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

//função de mapeamento
float arduEduc::mapear(long x, long in_min, long in_max, long out_min, long out_max) 
{
  return ((float)(x) - (float)(in_min)) * ((float)(out_max) - (float)(out_min)) / ((float)(in_max) - (float)(in_min)) + (float)(out_min);
}

void arduEduc::imprimir(String value)
{
   Serial.println(value);
}

void arduEduc::imprimir(int value)
{
   Serial.println(value);
}

void arduEduc::imprimir(float value)
{
   Serial.println(value);
}

void arduEduc::imprimir(bool value)
{
   Serial.println(value);
}

void arduEduc::imprimir(long value)
{
   Serial.println(value);
}

void arduEduc::imprimir(unsigned long value)
{
   Serial.println(value);
}