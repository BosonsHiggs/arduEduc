#include <arduEduc.h>

byte Leds[] = {3}; //Número dos pinos
bool pinStateIn[] = {LOW}; //Estados iniciais

//Tamanho do vetor Leds igual a 5 ou
int lenLeds = sizeof(Leds)/sizeof(Leds[0]); //Forma de determinar o tamanho de um vetor

// Instancia um objeto chamado LED no pino 13
arduEduc Arduino(Leds, lenLeds, pinStateIn, 9600); //Default 9600 bit/s

void setup(){
}

void loop()
{
  //800 é o delay em ms
  Arduino.ligar(); //Ligar o Led
  Arduino.esperar(800); //esperar 800 ms
  Arduino.desligar(); //Desligar o Led
  Arduino.esperar(800); //esperar 800 ms
}