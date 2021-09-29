#include <msp430.h>
#include "libTimer.h"
#include "led.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  int secondLimit = 250;  // number of ticks (interrupts) per second
  // limit to create a variable number of events every second
  // starts off at 50 (250 / 5) events per second
  static int variableLimit  = 5; 
  static int blinkCount  = 0;    // state variable used to count up to the variable limit
  static int secondCount = 0;    // state variable used to count up to 1 second

  // blink the green led fast
  // how fast depends on variableLimit
  blinkCount ++;
  if (blinkCount >= variableLimit) {
    blinkCount = 0;
    green_on = 1 - green_on;   // flip green LED
    led_changed = 1;           // led has changed
    led_update();
  }

  // measure a second
  secondCount ++;
  if (secondCount >= 250) {       // once each second
    red_on = 1 - red_on;          // flip red led
    led_changed = 1;              // signal update to led state
    led_update();
    secondCount = 0;
    variableLimit *= 3;           // increase time period
    if (variableLimit >= 100) {   // if time period reaches limit
      variableLimit = 5;          // reset
    }
  }
  
} 

