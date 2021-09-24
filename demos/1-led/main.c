//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;          // set LED pins to output
  P1OUT &= ~LED_GREEN;    // Turn off green led, leave other devices alone 
  P1OUT |= LED_RED;       // Turn on red led, leave other devices alone

  configureClocks();	  // setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();  // enable periodic interrupt */
  
  or_sr(0x18);		  // CPU off, GIE on
}
