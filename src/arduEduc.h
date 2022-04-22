#ifndef arduEduc_h
#define arduEduc_h

#include "Arduino.h"

class arduEduc
{
private:
    int myPin;
    byte* pinArray;
    int *pinState;
    int lenPin;

public:
    int *Pin; //byte array
    arduEduc(byte Pin_[], int lenPin, bool pinStateIn_, int serial_speed=9600);
    void ligar();
    void desligar();
    void inverter();
    void esperar(unsigned long tempo);
    void blocoExecutar(int pinState_[], int Delay);
};

#endif