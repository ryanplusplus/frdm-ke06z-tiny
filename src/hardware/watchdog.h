/*!
 * @file
 * @brief
 */

#ifndef watchdog_h
#define watchdog_h

#include "tiny_timer.h"

void watchdog_init(void);
void watchdog_enable_kicker(tiny_timer_group_t* timer_group);

#endif
