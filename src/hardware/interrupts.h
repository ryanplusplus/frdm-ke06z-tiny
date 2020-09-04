/*!
 * @file
 * @brief
 */

#ifndef interrupts_h
#define interrupts_h

#include "cmsis_compiler.h"

static inline void interrupts_enable(void)
{
  __enable_irq();
}

static inline void interrupts_disable(void)
{
  __disable_irq();
}

#endif
