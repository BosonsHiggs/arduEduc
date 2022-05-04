/* Program: LerAnalogico
 * Author: Francisco Iago Lira Passos 
 * Function: Ler valores analógicos de vários sensores de forma rápido com notação de ponteiros.
 */
#include <arduEduc.h>

//Placa Arduino Uno
byte Pinos[] = {0}; //Pino analógico A0
const int lenPinos = 1; //Quantidade de pinos
int cont=0; //contador

int* analogVal = new int[lenPinos]; //Vetor em ponteiro C++


//arduEduc Arduino(Pinos, QuantidaDePinos);
arduEduc Arduino(Pinos, lenPinos);

void setup() {
  Serial.begin(9600);     //Iniciar comunicação serial com 9600 bit/s
}

void loop()
{

  analogVal = Arduino.lerAnalogico();
  
  Arduino.imprimir(analogVal[0]); //Ler sensor 1 do vetor

  Arduino.esperar(10);            //Esperar 10ms
}