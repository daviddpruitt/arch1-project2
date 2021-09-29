//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  led_init();            // setup the leds
  
  configureClocks();	 // setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts(); // enable periodic interrupt
  
  or_sr(0x18);		 // CPU off, GIE on
}
