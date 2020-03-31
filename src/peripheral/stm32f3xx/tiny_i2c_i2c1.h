/*!
 * @file
 * @brief I2C1 master driver.
 *
 * This depends upon SDA and SCL GPIO having been assigned to pins and configured.
 * They should both be configured for the correct alternate function, fast speed,
 * and open drain.
 */

#ifndef tiny_i2c_i2c1_h
#define tiny_i2c_i2c1_h

#include "i_tiny_i2c.h"

i_tiny_i2c_t* tiny_i2c_i2c1_init(void);

#endif
