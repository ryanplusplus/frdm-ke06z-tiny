/*!
 * @file
 * @brief
 */

#ifndef lsm303dlhc_h
#define lsm303dlhc_h

#include "i_tiny_i2c.h"

typedef struct {
  i_tiny_i2c_t* i2c;
  uint8_t read_buffer[1];
} lsm303dlhc_t;

void lsm303dlhc_init(lsm303dlhc_t* self, i_tiny_i2c_t* i2c);

#endif
