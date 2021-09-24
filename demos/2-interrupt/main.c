//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;          // set LED pins to output
  P1OUT &= ~LED_GREEN;    // Turn off green led, leave other devices alone 
  P1OUT |= LED_RED;       // Turn on red led, leave other devices alone

  configureClocks();	  // setup master oscillator, CPU & peripheral clocks
  enableWDTInterrupts();  // enable periodic interrupt
  
  or_sr(0x18);		  // CPU off, GIE on
}


// interrupt handler that executes as a
// result of timer even
// as configured 250 interrupts per second
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  // 250 times per second is too fast
  // count up to 250 (1 second) to see the blink
  const unsigned secondCountLimit = 250;

  static unsigned secondCount = 0;
  secondCount++;
  if (secondCount == secondCountLimit) {
    P1OUT ^= LED_GREEN;  // flip the green led
    secondCount = 0;
  }
} 

