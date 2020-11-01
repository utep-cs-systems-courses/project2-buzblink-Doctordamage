#include <msp430.h>
#include "switches.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2()
{
  //P1
  if (P2IFG & SWITCHES)
    {
    // P1
    P2IFG &= ~SWITCHES;              // P1
    // Call switches.h
    switch_interrupt_handler();
    }
}

