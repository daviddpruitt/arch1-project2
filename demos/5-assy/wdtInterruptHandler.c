#include <msp430.h>
#include "libTimer.h"
#include "stateMachines.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  secondCounter();
  fastCounter();
} 

