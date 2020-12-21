/*!
 * @file
 * @brief
 */

#include "flash_test.h"
#include "fsl_flash.h"
#include "interrupts.h"

void flash_test_run(void)
{
  flash_config_t config = { 0 };

  FLASH_SetProperty(&config, kFLASH_PropertyFlashClockFrequency, CLOCK_GetFreq(kCLOCK_FlashClk));

  if(FLASH_Init(&config) != kStatus_FLASH_Success) {
    while(1) {
    }
  }

  uint32_t address = config.PFlashBlockBase + config.PFlashTotalSize - config.PFlashSectorSize;

  interrupts_disable();
  {
    if(FLASH_Erase(&config, address, config.PFlashSectorSize, kFLASH_ApiEraseKey) != kStatus_FLASH_Success) {
      while(1) {
      }
    }
  }
  interrupts_enable();

  // Use to get the write alignment/write size increment:
  // FSL_FEATURE_FLASH_PFLASH_BLOCK_WRITE_UNIT_SIZE
  uint32_t data[] = { 0x01234567, 0x89ABCDEF };

  if(FLASH_Program(&config, address, data, sizeof(data)) != kStatus_FLASH_Success) {
    while(1) {
    }
  }
}
