#include "ti_board_open_close.h"
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include <drivers/adc.h>
#include <drivers/gpio.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/DebugP.h>
#include <math.h>
#include <stdio.h>
#include <drivers/hw_include/cslr_soc.h>
#include "board/pmic/pmic_lld/blackbird/include/pmic_core.h"

#define SLEEP_TIME_U 100*1000

#define PMIC_STATE_CTRL_REG_ADDR 0x16
#define PMIC_STBY_CFG_REG_ADDR 0x19

#define PMIC_STBY_REQUEST 0x04



Pmic_CoreHandle_t* handle;

void pmic_init();
int32_t pmic_write_reg(uint16_t regAddr, uint8_t txData);
int32_t pmic_read_reg(uint16_t regAddr, uint8_t *rxBuffer);