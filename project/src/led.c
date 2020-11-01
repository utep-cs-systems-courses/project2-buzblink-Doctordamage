#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

unsigned char led_changed = 0, green_on=0, red_on=0, led_state=0;
char ledFlags = 0;

// Keep P1 because LEDs are on the board
void led_init()

{
  P1DIR |= LEDS;                      // bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed)
    {
      ledFlags=0;
      if(!(led_state)){
	ledFlags |= LED_RED;
      }

      else
	{
	  ledFlags |= LED_GREEN;
	}

      P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
      P1OUT |= ledFlags;     // set bit for on leds
      led_changed = 0;
    }
}

void led_toggle()
{
  led_state = 1 - led_state;
  led_changed = 1;
}

void led_advance()
{
  led_state+=1;
  led_changed = 1;
}
