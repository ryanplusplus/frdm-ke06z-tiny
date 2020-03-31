/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include "tiny_i2c_i2c1.h"
#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_i2c.h"
#include "stm32f3xx_ll_rcc.h"

static i_tiny_i2c_t instance;
static tiny_i2c_callback_t callback;
static void* context;
static struct {
  union {
    uint8_t* read;
    const uint8_t* write;
  };
} buffer;
static uint8_t buffer_index;
static uint8_t buffer_size;

static void initialize_peripheral(void) {
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C1);
  LL_RCC_SetI2CClockSource(LL_RCC_I2C1_CLKSOURCE_SYSCLK);

  NVIC_SetPriority(I2C1_EV_IRQn, 0);
  NVIC_EnableIRQ(I2C1_EV_IRQn);

  NVIC_SetPriority(I2C1_ER_IRQn, 0);
  NVIC_EnableIRQ(I2C1_ER_IRQn);

  LL_I2C_Disable(I2C1);

  LL_I2C_SetTiming(I2C1, 0x2000090E); // 100 KHz (taken from STM32CubeMX)
  LL_I2C_DisableOwnAddress1(I2C1);
  LL_I2C_EnableClockStretching(I2C1);
  LL_I2C_SetDigitalFilter(I2C1, 0x00);
  LL_I2C_EnableAnalogFilter(I2C1);

  LL_I2C_DisableOwnAddress2(I2C1);
  LL_I2C_SetMasterAddressingMode(I2C1, LL_I2C_ADDRESSING_MODE_7BIT);

  LL_I2C_SetMode(I2C1, LL_I2C_MODE_I2C);

  LL_I2C_Enable(I2C1);

  LL_I2C_EnableIT_RX(I2C1);
  LL_I2C_EnableIT_NACK(I2C1);
  LL_I2C_EnableIT_ERR(I2C1);
  LL_I2C_EnableIT_STOP(I2C1);
  LL_I2C_EnableIT_TC(I2C1);
  LL_I2C_EnableIT_TX(I2C1);
}

static void write(
  i_tiny_i2c_t* self,
  uint8_t address,
  bool prepare_for_restart,
  const uint8_t* _buffer,
  uint8_t _buffer_size,
  tiny_i2c_callback_t _callback,
  void* _context) {
  (void)self;

  callback = _callback;
  context = _context;
  buffer.write = _buffer;
  buffer_size = _buffer_size;
  buffer_index = 0;

  LL_I2C_HandleTransfer(
    I2C1,
    address,
    LL_I2C_ADDRSLAVE_7BIT,
    buffer_size,
    prepare_for_restart ? LL_I2C_MODE_SOFTEND : LL_I2C_MODE_AUTOEND,
    LL_I2C_GENERATE_START_WRITE);
}

static void read(
  i_tiny_i2c_t* self,
  uint8_t address,
  uint8_t* _buffer,
  uint8_t _buffer_size,
  tiny_i2c_callback_t _callback,
  void* _context) {
  (void)self;

  callback = _callback;
  context = _context;
  buffer.read = _buffer;
  buffer_size = _buffer_size;
  buffer_index = 0;

  LL_I2C_HandleTransfer(
    I2C1,
    address,
    LL_I2C_ADDRSLAVE_7BIT,
    buffer_size,
    LL_I2C_MODE_AUTOEND,
    LL_I2C_GENERATE_START_READ);
}

static void reset(i_tiny_i2c_t* self) {
  (void)self;
  initialize_peripheral();
}

static const i_tiny_i2c_api_t api = { write, read, reset };

void I2C1_EV_IRQHandler(void) {
  if(LL_I2C_IsActiveFlag_RXNE(I2C1)) {
    buffer.read[buffer_index++] = LL_I2C_ReceiveData8(I2C1);
  }
  else if(LL_I2C_IsActiveFlag_STOP(I2C1)) {
    LL_I2C_ClearFlag_STOP(I2C1);
    callback(context, true);
  }
  else if(LL_I2C_IsActiveFlag_TXIS(I2C1)) {
    LL_I2C_TransmitData8(I2C1, buffer.write[buffer_index++]);
  }
  else if(LL_I2C_IsActiveFlag_STOP(I2C1) || LL_I2C_IsActiveFlag_TC(I2C1)) {
    callback(context, true);
  }
  else {
    reset(NULL);
    callback(context, false);
  }
}

void I2C1_ER_IRQHandler(void) {
  reset(NULL);
  callback(context, false);
}

i_tiny_i2c_t* tiny_i2c_i2c1_init(void) {
  initialize_peripheral();
  instance.api = &api;
  return &instance;
}
