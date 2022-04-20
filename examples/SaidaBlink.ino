#include "libraries/Led.h"

// Instancia um objeto chamado LED no pino 13
MeuLed LED(13);

void setup(){
}

void loop()
{
    MeuLed.liga();       // liga o led
    delay(1000);      // aguarda 1 segundo
    MeuLed.desliga();    // desliga o Led
    delay(1000);      // aguarda 1 segundo
}