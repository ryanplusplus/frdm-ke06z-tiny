/*!
 * @file
 * @brief
 */

#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_gpio.h"
#include "leds.h"
#include "led.h"

static void WritePin(uint32_t which, bool value) {
  uint32_t current = LL_GPIO_ReadOutputPort(GPIOE);
  LL_GPIO_WriteOutputPort(GPIOE, value ? current | which : current & ~which);
}

static void write(
  i_tiny_digital_output_group_t* self,
  tiny_digital_output_channel_t channel,
  bool value) {
  (void)self;

  switch(channel) {
    case led_n:
      WritePin(LL_GPIO_PIN_9, value);
      break;

    case led_ne:
      WritePin(LL_GPIO_PIN_10, value);
      break;

    case led_e:
      WritePin(LL_GPIO_PIN_11, value);
      break;

    case led_se:
      WritePin(LL_GPIO_PIN_12, value);
      break;

    case led_s:
      WritePin(LL_GPIO_PIN_13, value);
      break;

    case led_sw:
      WritePin(LL_GPIO_PIN_14, value);
      break;

    case led_w:
      WritePin(LL_GPIO_PIN_15, value);
      break;

    case led_nw:
      WritePin(LL_GPIO_PIN_8, value);
      break;
  }
}

static const i_tiny_digital_output_group_api_t api = { write };

static void initialize_pin(uint32_t pin) {
  LL_GPIO_SetPinSpeed(GPIOE, pin, LL_GPIO_SPEED_FREQ_LOW);
  LL_GPIO_SetPinOutputType(GPIOE, pin, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinMode(GPIOE, pin, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinPull(GPIOE, pin, LL_GPIO_PULL_NO);
}

static void initialize_pins(void) {
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);

  initialize_pin(LL_GPIO_PIN_9);
  initialize_pin(LL_GPIO_PIN_10);
  initialize_pin(LL_GPIO_PIN_11);
  initialize_pin(LL_GPIO_PIN_12);
  initialize_pin(LL_GPIO_PIN_13);
  initialize_pin(LL_GPIO_PIN_14);
  initialize_pin(LL_GPIO_PIN_15);
  initialize_pin(LL_GPIO_PIN_8);
}

i_tiny_digital_output_group_t* leds_init(void) {
  initialize_pins();

  static i_tiny_digital_output_group_t self;
  self.api = &api;
  return &self;
}
