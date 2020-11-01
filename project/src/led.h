#include <msp430.h>

#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

void led_init();/* initialize LEDs */
void led_update();/* update leds */

extern unsigned char led_changed, green_led_state, red_led_state, green_on, red_on,led_state;
void led_switch();

#endif
