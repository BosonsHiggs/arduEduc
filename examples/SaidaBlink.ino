#include "libraries/arduEduc.h"

// Instancia um objeto chamado LED no pino 13
Arduino arduEduc(13);

void setup(){
}

void loop()
{
    Arduino.liga();       // liga o led
    delay(1000);      // aguarda 1 segundo
    Arduino.desliga();    // desliga o Led
    delay(1000);      // aguarda 1 segundo
}