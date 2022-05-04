arduEduc
=========

arduEduc é uma biblioteca para [Arduino](https://www.arduino.cc/) com várias ferramentas úteis. A biblioteca foi escrita completamente em C++ e possui várias otimizações que tornarão os programas mais rápidos e eficientes. A biblioteca pode ser usada em qualquer versão da IDE do Arduino.

Instalação
===========

Baixe o arquivo no diretório das bibliotecas da IDE do Arduino ou execute, no diretório das bibliotecas, os seguintes comandos::

     git clone https://github.com/BosonsHiggs/arduEduc.git

Uso
====

Uso básico:

```c++
     #include <arduEduc.h>

     byte Led[] = {4}; //Número do pino

     // Instancia um objeto chamado Arduino no pino 4
     arduEduc Arduino(Led);

     void setup(){
          pinMode(Led[0], OUTPUT); //Muda o estado do pino 4 para OUTPUT
     }

     void loop()
     {
          //800 é o delay em ms
          Arduino.ligar();      //Ligar o Led
          Arduino.esperar(800); //esperar 800 ms
          Arduino.desligar();   //Desligar o Led
          Arduino.esperar(800); //esperar 800 ms
     }
```

Contatos
=========

- [Official Discord Server](https://discord.gg/nPejnfC3Nu)
- **My Discord User:** *Aril Ogai#5646*