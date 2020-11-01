#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"

void main()
{
  // Timer
  configureClocks();          // Start Lib Timer

  // Initialize
  switch_init();              // Setup Switches
  buzzer_init();              // Call Speakers
  led_init();                 // Call LEDs

  // Watchdog
  enableWDTInterrupts();      // Enable Watchdog

  // Power off CPU
  or_sr(0x18);
}
