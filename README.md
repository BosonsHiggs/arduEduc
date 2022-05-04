arduEduc
=========

arduEduc é uma biblioteca para [Arduino](https://www.arduino.cc/) com várias ferramentas úteis. A bibloteca foi escrita completamente em C++ e possui várias otimizações que tornarão os programas mais rápidos e eficientes. A biblioteca pode ser usada em qualquer versão da IDE do Arduino.

Installation
=============

The preferred way to install is with [pip](http://www.pip-installer.org/en/latest/)::

     pip install git+https://github.com/BosonsHiggs/arduPython

You can also install from source with ``python setup.py install``. You will need to have [setuptools](https://pypi.python.org/pypi/setuptools) installed ::

     git clone https://github.com/BosonsHiggs/arduPython.git
     cd pyFirmata
     python setup.py install


Use
====

Basic usage::

    >>> from pyfirmata import Arduino, util
    >>> board = Arduino('/dev/ttyXXXX') or just board = Arduino()
    >>> board.digital[13].write(1)

To use analog ports, it is probably useful to start an iterator chain. Otherwise, the board will keep sending data to your serial, until it bursts:

    >>> it = util.Iterator(board)
    >>> it.start()
    >>> board.analog[0].enable_reporting()
    >>> board.analog[0].read()
    0.661440304938

If you use a pin more often, it might be worth using the board's ``get_pin`` method. It allows you to specify which pin you need by a string, made up of 'a' or 'd' (depending on whether you need an analog or digital pin), the pin number and the mode ('i' for input, ' o 'for output, 'p' for pwm). All separated by ``:``. For example. ``a:0:i`` for analog 0 as input or ``d:3:p`` for digital pin 3 as pwm. ::

    >>> analog_0 = board.get_pin('a:0:i')
    >>> analog_0.read()
    0.661440304938
    >>> pin3 = board.get_pin('d:3:p')
    >>> pin3.write(0.6)

Layout of any Arduino board
============================

If you want to use a board with a different layout than the standard Arduino or Arduino Mega (for which there are shortcut classes ``pyfirmata.Arduino`` and ``pyfirmata.ArduinoMega``), instantiate the Board class with a dictionary as the ``layout`` argument. This is the layout adage for Mega, for example::

     >>> mega = {
     ... 'digital' : tuple(x for x in range(54)),
     ... 'analog' : tuple(x for x in range(16)),
     ... 'pwm' : tuple(x for x in range(2,14)),
     ... 'use_ports' : True,
     ... 'disabled' : (0, 1, 14, 15) # Rx, Tx, Crystal
     ... }

Ping support (pulseIn)
=======================

If you want to use ultrasonic range sensors that use a pulse to measure distance (like the very cheap and common ``HC-SR04``
- See [datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf),
you will need to use a ``pulseIn`` compatible Firmata on your card.

You can download it from the [``pulseIn``](https://github.com/jgautier/arduino-1/tree/pulseIn) branch of the Firmata repository:

Simply connect the sensor's ``Trig`` and ``Echo`` pins to a digital pin on your board.

![Source: https://github.com/NeoPolus/pyFirmata](Examples/Figures/ping.png)

And then use the ping method on the pin:

     >>> echo_pin = board.get_pin('d:7:o')
     >>> echo_pin.ping()
     1204

You can use the ``ping_time_to_distance`` function to convert
the result of the ping (echo time) in distance:

     >>> from pyfirmata.util import ping_time_to_distance
     >>> echo_pin = board.get_pin('d:7:o')
     >>> ping_time_to_distance(echo_pin.ping())
     20.4854580555607776

NOTE
====

The codes will only work if you download and load the [``pulseIn``](https://github.com/jgautier/arduino-1/tree/pulseIn) code on the Arduino board! It has to be exactly the code quoted!

Credits
========

- [NeoPolus](https://github.com/NeoPolus/pyFirmata)
- [Tino](https://github.com/tino/pyFirmata)

Links
=====

- [Official Discord Server](https://discord.gg/nPejnfC3Nu)
- **My Discord User:** *Aril Ogai#5646*