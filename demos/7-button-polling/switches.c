#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;

/* setup switches */
void 
switch_init()
{  
  P1REN |=  SWITCHES;		// enables resistors for switches
  P1IE  |=  SWITCHES;		// enable interrupts from switches
  P1OUT |=  SWITCHES;		// turn on switches so we can read them
  P1DIR &= ~SWITCHES;		// set switch pins to input
}

void
check_switches()
{
  char p1val = P1IN;
  // Switch reads 0 when down, we want to reverse
  // that so the state variable is 1 when down
  switch_state_down = (p1val & SW1) ? 0 : 1;
  if (switch_state_down) {
    red_on = 1;
    green_on = 0;
  } else {
    red_on = 0;
    green_on = 1;
  }
  led_changed = 1;
  led_update();
}
