#ifndef BQ25751_H
#define BQ25751_H

#include "ti_board_open_close.h"
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include <drivers/adc.h>
#include <drivers/gpio.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include <drivers/i2c.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/DebugP.h>
#include <math.h>
#include <stdio.h>

#define BQ25751_ADDR 0x6B
#define BQ25751_REG_ADDR_LEN (1U)
#define BQ25751_REG_VALUE_LEN (2U)

#define BQ25751_PART_NUMBER_REG 0x3D


int32_t BQ25751_read_reg(uint8_t register_addr, uint8_t length, uint16_t* result);
int32_t BQ25751_write_reg(uint8_t register_addr, uint8_t length, uint16_t data);
void i2c_read_error_handler(int32_t status);

#endif