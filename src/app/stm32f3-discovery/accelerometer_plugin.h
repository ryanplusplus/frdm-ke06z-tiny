/*!
 * @file
 * @brief
 */

#ifndef accelerometer_plugin_h
#define accelerometer_plugin_h

#include "i_tiny_message_bus.h"
#include "tiny_timer.h"
#include "hal/i_tiny_async_i2c.h"
#include "lsm303d.h"

typedef struct {
  lsm303d_t lsm303d;
  i_tiny_message_bus_t* message_bus;
  tiny_event_subscription_t acceleration_update_subscription;
} accelerometer_plugin_t;

void accelerometer_plugin_init(
  accelerometer_plugin_t* self,
  tiny_timer_group_t* timer_group,
  i_tiny_message_bus_t* message_bus,
  i_tiny_async_i2c_t* i2c);

#endif
