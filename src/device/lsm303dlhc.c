/*!
 * @file
 * @brief
 */

#include "lsm303dlhc.h"
#include "tiny_utils.h"

enum {
  accelerometer_address = 0x01, //0x19,
  status_register = 0x27
};

static void party(void* context, bool success) {
  (void)context;

  if(!success) {
    volatile int derp = -1;
    derp++;
    derp++;
  }
  else {
    volatile unsigned char derp = 4;
    derp++;
    derp++;
  }
}

static void register_selected(void* context, bool success) {
  reinterpret(self, context, lsm303dlhc_t*);

  if(!success) {
    volatile int derp = 4;
    derp++;
    derp++;
  }

  tiny_i2c_read(
    self->i2c,
    accelerometer_address,
    false,
    self->read_buffer,
    sizeof(self->read_buffer),
    register_selected,
    self);
}

static void start_status_read(lsm303dlhc_t* self) {
  static const uint8_t register_address = status_register;
  tiny_i2c_write(
    self->i2c,
    accelerometer_address,
    true,
    &register_address,
    sizeof(register_address),
    register_selected,
    self);
}

void lsm303dlhc_init(lsm303dlhc_t* self, i_tiny_i2c_t* i2c) {
  self->i2c = i2c;
  start_status_read(self);
}
