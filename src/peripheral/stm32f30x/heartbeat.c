/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "stm32f30x.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"
#include "heartbeat.h"

enum {
  half_period_in_msec = 500,
  pin_5 = (1 << 5)
};

static struct {
  tiny_timer_t timer;
  bool state;
} self;

static void blink(tiny_timer_group_t* group, void* context) {
  (void)context;
  self.state ^= 1;
  GPIO_WriteBit(GPIOE, GPIO_Pin_9, self.state);
  tiny_timer_start(group, &self.timer, half_period_in_msec, blink, NULL);
}

void heartbeat_init(tiny_timer_group_t* timer_group) {
  GPIO_InitTypeDef gpio_init;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
  gpio_init.GPIO_Pin = GPIO_Pin_9;
  gpio_init.GPIO_Mode = GPIO_Mode_OUT;
  gpio_init.GPIO_Speed = GPIO_Speed_Level_1;
  gpio_init.GPIO_OType = GPIO_OType_PP;
  gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOE, &gpio_init);

  tiny_timer_start(timer_group, &self.timer, half_period_in_msec, blink, NULL);
}
