/*!
 * @file
 * @brief
 */

#include "display_plugin.h"
#include "message.h"
#include "tiny_utils.h"

static void message_received(void* context, const void* _args) {
  reinterpret(self, context, display_plugin_t*);
  reinterpret(args, _args, const tiny_message_bus_on_receive_args_t*);

  if(args->message == message_acceleration_update) {
    reinterpret(acceleration, args->data, const acceleration_t*);
    display_show_acceleration(&self->display, acceleration);
  }
}

void display_plugin_init(
  display_plugin_t* self,
  i_tiny_message_bus_t* message_bus,
  i_tiny_digital_output_group_t* leds) {
  display_init(&self->display, leds);

  tiny_event_subscription_init(&self->message_received_subscription, self, message_received);
  tiny_event_subscribe(tiny_message_bus_on_receive(message_bus), &self->message_received_subscription);
}
