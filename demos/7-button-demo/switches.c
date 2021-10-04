#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;

/* update he interrupt sense bits so 
   interrupts are fired when a switch changes
   position */
static char 
switch_update_interrupt_sense()
{
  char p1val = P1IN;
  P1IES |= (p1val & SWITCHES);	// if switch up, sense down
  P1IES &= (p1val | ~SWITCHES);	// if switch down, sense up
  return p1val;
}

/* setup switches */
void 
switch_init()
{  
  P1REN |=  SWITCHES;		// enables resistors for switches
  P1IE  |=  SWITCHES;		// enable interrupts from switches
  P1OUT |=  SWITCHES;		// turn on switches so we can read them
  P1DIR &= ~SWITCHES;		// set switch pins to input
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
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
  led_update();
}
