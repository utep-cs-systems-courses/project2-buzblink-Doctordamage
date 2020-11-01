#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

static enum {off=0, dim=1, bright=2} ledMode;
static char count = 0;

void slow_clock() /* slowly cycle through {off, dim, bright} */
{
  ledMode = (ledMode + 1) % 3;
}

void fast_clock() /* quickly cycle through 0...3 */
{
  count = (count + 1) & 3;
}

void update_led()
{
  char new_red_on;
  switch (ledMode)
    {
    case off:
      new_red_on = 0;
      break;
    case bright:
      new_red_on = 1;
      break;
    case dim:
      new_red_on = (count < 1);
      break; 
  }
  if (red_on != new_red_on)
    {
      red_on = new_red_on;
      led_changed = 1;
    }
}





char toggle_red() /* always toggle! */
{
  static char state = 0;
  switch (state)
    {
    case 0:
      red_on = 1;
      state = 1;
      break;
    case 1:
      red_on = 0;
      state = 0;
      break;
    }
  return 1;    /* always changes an led */
}

char toggle_green() /* only toggle green if red is on!*/
{
  char changed = 0;
  if (red_on)
    {
      green_on ^= 1;
      changed = 1;
    }
  return changed;
}

void state_advance()/* alternate between toggling red & green */
{
  char changed = 0;
  static enum {R=0, G=1} color = G;
  switch (color)
    {
    case R: changed = toggle_red(); color = G; break;
    case G: changed = toggle_green(); color = R; break;
    }
  led_changed = changed; // switch_state_changed
  led_update();
}
