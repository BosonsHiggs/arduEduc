#include <arduEduc.h>

//Use na ordem {echoPin1, trigPin1, echoPin2, trigPin2,...}
byte Pinos[] = {2, 3, 4, 5};

//Variável para distância
const int lenPinos = sizeof(Pinos)/sizeof(Pinos[0]); //Quantidade de pinos

long* distancia = new long[lenPinos];

String myString;
int cont = 0;

// Instancia um objeto chamado Arduino
arduEduc Arduino(Pinos, lenPinos);

void setup(){
  Serial.begin(9600);
  for(int n=1; n <= lenPinos; n+=2) pinMode(Pinos[n], OUTPUT); //trigPin como saída
}

void loop()
{
    distancia =  Arduino.distanciaUltra();

    myString = "ultra[";
    myString+=cont;
    myString+="]  = ";
    myString+=distancia[cont];

    Arduino.imprimir(myString);

    if (cont==(lenPinos/2 - 1)) 
    {
      cont=0;
      delete[] distancia;
    }else {
      cont+1;
    }
}