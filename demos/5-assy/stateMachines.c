#include "stateMachines.h"
#include "led.h"

static int variableLimit  = 5; 

// limit to create a variable number of events every second
// starts off at 50 (250 / 5) events per second
void fastCounter(void)
{
  static int count  = 0;    // state variable used to count up to the variable limit

  // blink the green led fast
  // how fast depends on variableLimit
  count ++;
  if (count >= variableLimit) {
    count = 0;
    green_on = 1 - green_on;   // flip green LED
    greenOn(green_on);
  }
}

// executes code once per second
void secondCounter (void)
{
  const  int secondLimit = 250;  // number of ticks (interrupts) per second
  static int secondCount = 0;    // state variable used to count up to 1 second

  // measure a second
  secondCount ++;
  if (secondCount >= 250) {       // once each second
    red_on = 1 - red_on;          // flip red led
    led_changed = 1;              // signal update to led state
    led_update();
    secondCount = 0;
    variableLimit *= 3;           // increase time period on variable count
    if (variableLimit >= 100) {   // if time period reaches limit
      variableLimit = 5;          // reset
    }
  }
}
