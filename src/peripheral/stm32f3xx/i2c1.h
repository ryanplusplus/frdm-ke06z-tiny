/*!
 * @file
 * @brief I2C1 master driver.
 *
 * This depends upon SDA and SCL GPIO having been assigned to pins and configured.
 * They should both be configured for the correct alternate function, fast speed,
 * and open drain.
 */

#ifndef i2c1_h
#define i2c1_h

#include "hal/i_tiny_async_i2c.h"

i_tiny_async_i2c_t* i2c1_init(void);

#endif
