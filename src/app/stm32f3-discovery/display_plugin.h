/*!
 * @file
 * @brief
 */

#ifndef display_plugin_h
#define display_plugin_h

#include "display.h"
#include "i_tiny_message_bus.h"
#include "hal/i_tiny_digital_output_group.h"

typedef struct {
  display_t display;
  tiny_event_subscription_t message_received_subscription;
} display_plugin_t;

void display_plugin_init(
  display_plugin_t* self,
  i_tiny_message_bus_t* message_bus,
  i_tiny_digital_output_group_t* leds);

#endif
