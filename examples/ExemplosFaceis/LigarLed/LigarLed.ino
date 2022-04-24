#include <arduEduc.h>

byte Led[] = {4}; //Número do pino

// Instancia um objeto chamado Arduino no pino 4
arduEduc Arduino(Led);

void setup(){
  pinMode(Led[0], OUTPUT); //Muda o estado do pino 4 para OUTPUT
}

void loop()
{
  //800 é o delay em ms
  Arduino.ligar();      //Ligar o Led
  Arduino.esperar(800); //esperar 800 ms
  Arduino.desligar();   //Desligar o Led
  Arduino.esperar(800); //esperar 800 ms
}