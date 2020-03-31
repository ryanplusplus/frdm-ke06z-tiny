/*!
 * @file
 * @brief
 */

#ifndef display_h
#define display_h

#include <stdint.h>
#include "acceleration.h"
#include "i_tiny_digital_output_group.h"

typedef struct {
  i_tiny_digital_output_group_t* leds;
} display_t;

void display_init(display_t* self, i_tiny_digital_output_group_t* leds);
void display_show_acceleration(display_t* self, const acceleration_t* acceleration);

#endif
