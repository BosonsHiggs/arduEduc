#include <arduEduc.h>

byte Leds[] = {3, 4, 5, 6, 7}; //Número dos pinos
bool pinStateIn[] = {LOW, LOW, LOW, LOW, LOW}; //Estados iniciais

int blocoComandos[2][5] = {
                            {1, 1, 1, 1, 1}, //Bloco de estados 1
                            {0, 0, 0, 0, 0} //Bloco de estados 2
                          };
//Tamanho do vetor Leds igual a 5 ou
int lenLeds = sizeof(Leds)/sizeof(Leds[0]); //Forma de determinar o tamanho de um vetor

// Instancia um objeto chamado LED no pino 13
arduEduc Arduino(Leds, lenLeds, pinStateIn, 9600); //Default 9600 bit/s

void setup(){
}

void loop()
{
  //800 é o delay em ms
  Arduino.blocoExecutar(blocoComandos[0], 800); //Executar Bloco de estados 1
  Arduino.blocoExecutar(blocoComandos[1], 800); //Executar Bloco de estados 2
}