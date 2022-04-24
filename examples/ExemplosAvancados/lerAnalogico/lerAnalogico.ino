/* Program: LerAnalogico
 * Author: Francisco Iago Lira Passos 
 * Function: Ler valores analógicos de vários sensores de forma rápido com notação de ponteiros.
 */
#include <arduEduc.h>

//Placa ARduino Mega
byte Pinos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Pino analógico A0 e A1
const int lenPinos = sizeof(Pinos)/sizeof(Pinos[0]); //Quantidade de pinos

int* myPointer;                  //Novo ponteiro
int analogVal[lenPinos], cont=0; //Receber valores analógicos

String myString;

// Instancia um objeto chamado LED no pino 0
//arduEduc Arduino(Pinos, QuantidaDePinos);
arduEduc Arduino(Pinos, lenPinos);

void setup() {
  Serial.begin(9600);     //Iniciar comunicação serial com 9600 bit/s
}

void loop()
{
  //Usa o ponteiro myPointer para receber os valores dos sensores
  myPointer = Arduino.lerAnalogico();
  
  //*(myPointer + cont) passeia pelos índices do vetor
  analogVal[cont] = *(myPointer + cont);

  myString = "analogVal[";
  myString+=cont;
  myString+="] = ";
  myString+=analogVal[cont];
  
  Serial.println(myString);

  Arduino.esperar(10);            //Esperar 10ms

  //cont é igual a 0 se cont==(lenPinos-1), caso contrário soma +1
  //Você pode usar o if...else  normalmente
  cont = (cont==(lenPinos-1)) ? 0 : cont+1; //Operador ternário
}