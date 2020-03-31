/*!
 * @file
 * @brief
 */

#include "display.h"

void display_init(display_t* self, i_tiny_digital_output_group_t* leds) {
  self->leds = leds;
}

void display_show_acceleration(display_t* self, const acceleration_t* acceleration) {
  (void)self;
  (void)acceleration;
}
