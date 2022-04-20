#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
public:
    Saida(int pin);
    void liga();
    void desliga();
    void inverte();

private:
    int pino;
};

#endif