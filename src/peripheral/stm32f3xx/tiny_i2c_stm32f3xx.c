/*!
 * @file
 * @brief
 *
 * Copyright GE Appliances - Confidential - All rights reserved.
 */

#include "tiny_i2c_stm32f3xx.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_rcc_ex.h"

/*!
 * Todo
 * - Test with accelerometer (address 0x32)
 */

static i_tiny_i2c_t instance;
static I2C_HandleTypeDef i2c;
static tiny_i2c_callback_t callback;
static void* context;

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef* i2c) {
  callback(context, false);
}

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef* i2c) {
  callback(context, true);
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef* i2c) {
  callback(context, true);
}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2c) {
  (void)i2c;

  GPIO_InitTypeDef gpio;
  RCC_PeriphCLKInitTypeDef rcc;

  // Configure the I2C clock
  rcc.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  rcc.I2c1ClockSelection = RCC_I2C1CLKSOURCE_SYSCLK;
  HAL_RCCEx_PeriphCLKConfig(&rcc);
  __HAL_RCC_I2C1_CLK_ENABLE();

  // SCL pin
  __HAL_RCC_GPIOB_CLK_ENABLE();
  gpio.Pin = GPIO_PIN_6;
  gpio.Mode = GPIO_MODE_AF_OD;
  gpio.Pull = GPIO_PULLUP;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &gpio);

  // SDA pin
  __HAL_RCC_GPIOB_CLK_ENABLE();
  gpio.Pin = GPIO_PIN_7;
  gpio.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &gpio);

  HAL_NVIC_SetPriority(I2C1_ER_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
  HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0, 2);
  HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
}

void I2C1_EV_IRQHandler(void) {
  HAL_I2C_EV_IRQHandler(&i2c);
}

void I2C1_ER_IRQHandler(void) {
  HAL_I2C_ER_IRQHandler(&i2c);
}

static void write(
  i_tiny_i2c_t* self,
  uint8_t address,
  bool prepare_for_restart,
  const uint8_t* buffer,
  uint8_t buffer_size,
  tiny_i2c_callback_t _callback,
  void* _context) {
  (void)self;

  callback = _callback;
  context = _context;

  HAL_I2C_Master_Sequential_Transmit_IT(
    &i2c,
    address,
    (void*)buffer, // I hate that this cast is necessary, but it should be safe on ARM
    buffer_size,
    prepare_for_restart ? I2C_LAST_FRAME : I2C_FIRST_AND_LAST_FRAME);
}

static void read(
  i_tiny_i2c_t* self,
  uint8_t address,
  uint8_t* buffer,
  uint8_t buffer_size,
  tiny_i2c_callback_t _callback,
  void* _context) {
  (void)self;

  callback = _callback;
  context = _context;

  HAL_I2C_Master_Receive_IT(&i2c, address, buffer, buffer_size);
}

static void reset(i_tiny_i2c_t* self) {
  (void)self;

  HAL_I2C_DeInit(&i2c);
  HAL_I2C_Init(&i2c);
}

static const i_tiny_i2c_api_t api = { write, read, reset };

i_tiny_i2c_t* tiny_i2c_stm32f3xx_init(void) {
  i2c.Instance = I2C1;
  i2c.Init.Timing = 0x2000090E; // magic, stolen from generated code
  i2c.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  i2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  i2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  i2c.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

  HAL_I2C_Init(&i2c);

  instance.api = &api;

  return &instance;
}
