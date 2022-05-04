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
    long* myValUltra;
    arduEduc(byte Pin_[]={}, int lenPin_=1);
    void ligar();
    void desligar();
    void inverter();
    void esperar(unsigned long tempo);
    void blocoExecutar(int pinState_[], int Delay);
    bool lerDigital();
    int* lerAnalogico();
    void escreverAnalogico(int val);
    long* distanciaUltra();
    float mapear(long value, long xmin, long xmax, long ymin, long ymax);
    void imprimir(String text);
    void imprimir(int value);
    void imprimir(float value);
    void imprimir(bool value);
    void imprimir(long value);
    void imprimir(unsigned long value);
};

#endif