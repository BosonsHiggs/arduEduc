#include <arduEduc.h>

//Use na ordem {echoPin1, trigPin1, echoPin2, trigPin2,...}
byte Pinos[] = {2, 8}; //echoPin = 2 e trigPin = 8

//Variável para diastância
long* distancia = 0;
const int lenPinos = sizeof(Pinos)/sizeof(Pinos[0]); //Quantidade de pinos

long analogVal[lenPinos];
String myString;

// Instancia um objeto chamado Arduino
arduEduc Arduino(Pinos, 2);

void setup(){
  Serial.begin(9600);
  pinMode(Pinos[1], OUTPUT); //trigPin como saída
}

void loop()
{
    distancia =  Arduino.distanciaUltra();
    analogVal[0] = *distancia;

    myString = "ultra = ";
    myString+=analogVal[0];

    Serial.println(myString);

    Arduino.esperar(60);  //Esperar 60ms
}