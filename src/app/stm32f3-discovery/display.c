/*!
 * @file
 * @brief
 */

#include <stdlib.h>
#include "display.h"
#include "led.h"

void display_init(display_t* self, i_tiny_digital_output_group_t* leds) {
  self->leds = leds;
}

void display_show_acceleration(display_t* self, const acceleration_t* acceleration) {
  int16_t x = acceleration->x;
  int16_t y = acceleration->y;

  if(abs(x) > 3000 || abs(y) > 3000) {
    for(uint8_t i = 0; i < led_count; i++) {
      tiny_digital_output_group_write(self->leds, i, false);
    }

    tiny_digital_output_channel_t led;

    if(y < 0 && x >= 0) {
      if(abs(y) > abs(2 * x)) {
        led = led_e;
      }
      else if(abs(x) > 2 * abs(y)) {
        led = led_n;
      }
      else {
        led = led_ne;
      }
    }
    else if(y < 0 && x < 0) {
      if(abs(y) > abs(2 * x)) {
        led = led_e;
      }
      else if(abs(x) > 2 * abs(y)) {
        led = led_s;
      }
      else {
        led = led_se;
      }
    }
    else if(y >= 0 && x >= 0) {
      if(abs(y) > abs(2 * x)) {
        led = led_w;
      }
      else if(abs(x) > 2 * abs(y)) {
        led = led_n;
      }
      else {
        led = led_nw;
      }
    }
    else {
      if(abs(y) > abs(2 * x)) {
        led = led_w;
      }
      else if(abs(x) > 2 * abs(y)) {
        led = led_s;
      }
      else {
        led = led_sw;
      }
    }

    tiny_digital_output_group_write(self->leds, led, true);
  }
}
