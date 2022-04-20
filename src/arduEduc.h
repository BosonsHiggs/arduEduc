#ifndef ARDUEDUC_H
#define ARDUEDUC_H

#include <Arduino.h>

class arduEduc
{
public:
    arduEduc(int pin);
    void liga();
    void desliga();
    void inverte();

private:
    int pino;
};

#endif