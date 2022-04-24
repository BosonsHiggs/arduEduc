#include <arduEduc.h>

//Use na ordem {echoPin1, trigPin1, echoPin2, trigPin2,...}
byte Pinos[] = {2, 3, 4, 5};

//Variável para distância
long* distancia = 0;
const int lenPinos = sizeof(Pinos)/sizeof(Pinos[0]); //Quantidade de pinos

long analogVal[lenPinos];
String myString;
int cont = 0;

// Instancia um objeto chamado Arduino
arduEduc Arduino(Pinos, lenPinos);

void setup(){
  Serial.begin(9600);
  for(int n=0; n < lenPinos/2; n++) pinMode(Pinos[n], OUTPUT); //trigPin como saída
}

void loop()
{
    distancia =  Arduino.distanciaUltra();
    analogVal[0] = *distancia;

    myString = "ultra[";
    myString+=cont;
    myString+="]  = "
    myString+=analogVal[cont];

    Serial.println(myString);

    Arduino.esperar(60);  //Esperar 60ms
}
