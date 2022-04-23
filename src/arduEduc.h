#ifndef arduEduc_h
#define arduEduc_h

#include "Arduino.h"

class arduEduc
{
private:
    byte* pinArray;
    int *pinState;
    int lenPin;
    byte* onePin;

public:
    int* myVal;
    arduEduc(byte Pin_[]={}, int lenPin_=1);
    void ligar();
    void desligar();
    void inverter();
    void esperar(unsigned long tempo);
    void blocoExecutar(int pinState_[], int Delay);
    bool lerDigital();
    int* lerAnalogico();
    void escreverAnalogico(int val);
};

#endif