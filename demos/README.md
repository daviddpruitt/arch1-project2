## Description
This directory contains demo programs that demonstrate basic I/O using timer and button interrupts.

Program            | Description
------------------ | -----------
1-led              | Basic demo that turns on 1 led
2-interrupt        | Uses interrupts to flash 1 led
3-blink-pattern    | Shows how to use state machines to flash the leds in several patterns, with 1 state machine triggering another
4-modular          | Same as 3-blink-pattern but splits out functionality into related files
5-assy             | Shows implementing a simple function in both C and assembly and how it links with other files
6-buzzer           | Shows how to use the buzzer to make a simple sound
7-button-polling   | Shows how to read the buttons using a loop
8-button-interrupt | Shows how to read the buttons using interrupts

## Some suggested things you may want to try

* Change the LEDs and the buzzer together

* Make the LED have verying levels of brightness instead of just on or off

## How to Use

The Makefile in this direcory contains rules to run the Makefile in each demo directory. Use **make** in this directory to build all demo programs and the timer library. Once the programs are built, you can load the program onto the MSP430 by changing into the corresponding demo directory and using **make load**.

You may use **mspdebug rf2500 "erase"** to clear a program from the MSP430.
