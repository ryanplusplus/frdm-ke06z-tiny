/*!
 * @file
 * @brief Configures 1 KHz time source using the system tick peripheral.
 */

#ifndef systick_h
#define systick_h

#include "i_tiny_time_source.h"

i_tiny_time_source_t* systick_init(void);

#endif
