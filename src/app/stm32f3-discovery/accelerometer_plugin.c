/*!
 * @file
 * @brief
 */

#include "accelerometer_plugin.h"
#include "message.h"
#include "tiny_utils.h"

static void acceleration_updated(void* context, const void* args) {
  reinterpret(self, context, accelerometer_plugin_t*);
  tiny_message_bus_send(self->message_bus, message_acceleration_update, args);
}

void accelerometer_plugin_init(
  accelerometer_plugin_t* self,
  tiny_timer_group_t* timer_group,
  i_tiny_message_bus_t* message_bus,
  i_tiny_i2c_t* i2c) {
  self->message_bus = message_bus;

  lsm303d_init(&self->lsm303d, timer_group, i2c);

  tiny_event_subscription_init(
    &self->acceleration_update_subscription,
    self,
    acceleration_updated);
  tiny_event_subscribe(
    lsm303d_on_acceleration_update(&self->lsm303d),
    &self->acceleration_update_subscription);
}
