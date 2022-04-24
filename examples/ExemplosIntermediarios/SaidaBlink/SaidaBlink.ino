/*
  Program: Array de LEDs
  Author: Francisco Iago Lira Passos
  Function: Automatização de estados de pinos
  E-mail: iagolirapassos@gmail.com
*/

#include <arduEduc.h>

/*
Os pinos devem ser adicionados em vetores, conforme o exemplo abaixo:
*/
byte Leds[] = {3, 4, 5, 6, 7}; //Número dos pinos

/*
TODO:
Os blocos de comandos executam tarefas automáticas ligando ou desligando os leds.
Você pode inserir quantos blocos forem necessários!
*/
int blocoComandos[4][5] = {
                            {HIGH, HIGH, HIGH, HIGH, HIGH}, //Bloco de estados 1
                            {LOW, LOW, LOW, LOW, LOW}, //Bloco de estados 2
                            {HIGH, LOW, LOW, LOW, LOW}, //Bloco de estados 3
                            {LOW, HIGH, LOW, HIGH, LOW} //Bloco de estados 4
                          };
//Tamanho do vetor Leds igual a 5 ou
int lenLeds = sizeof(Leds)/sizeof(Leds[0]); //Forma de determinar o tamanho de um vetor

/*
TODO:
É preciso passar o tamanho do vetor quando temos vários led
*/
arduEduc Arduino(Leds, lenLeds); // Instancia um objeto chamado LED nos pinos Leds

void setup(){
    for (int n = 0; n < lenLeds; n++)
    {
      pinMode(Leds[n], OUTPUT);
    }
}

void loop()
{
  // O loop vai até 4 porque temos 4 blocos em blocoComandos
  //800 é o delay em ms
  for(int i=0; i<4; i++)
  {
    Arduino.blocoExecutar(blocoComandos[i], 800); //Executar Blocos
  }
}