#ifndef BQ25856_H
#define BQ25856_H

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
#include "i2c_helper.h"
#include <math.h>
#include <stdio.h>

#define BQ25856_ADDR 0x6B
#define BQ25856_REG_ADDR_LEN (1U)
#define BQ25856_REG_VALUE_LEN (2U)

#define BQ25856_CHARGE_VOLTAGE_LIMIT_REG 0x00
#define BQ25856_CHARGE_CURRENT_LIMIT_REG 0x02
#define BQ25856_INPUT_CURRENT_DPM_LIMIT_REG 0x06
#define BQ25856_INPUT_VOLTAGE_DPM_LIMIT_REG 0x08
#define BQ25856_REVERSE_MODE_INPUT_CURRENT_LIMIT_REG 0x0A
#define BQ25856_REVERSE_MODE_INPUT_VOLTAGE_LIMIT_REG 0x0C
#define BQ25856_PRECHARGE_CURRENT_LIMIT_REG 0x10
#define BQ25856_TERMINATION_CURRENT_LIMIT_REG 0x12
#define BQ25856_PRECHARGE_TERMINATION_CONTROL_REG 0x14
#define BQ25856_TIMER_CONTROL_REG 0x15
#define BQ25856_CHARGER_CONTROL_REG 0x17
#define BQ25856_PIN_CONTROL_REG 0x18
#define BQ25856_POWER_PATH_REVERSE_MODE_CONTROL_REG 0x19
#define BQ25856_FREQUENCY_DITHER_CONTROL_REG 0x1A
#define BQ25856_TS_CHARGING_THRESHOLD_CONTROL_REG 0x1B
#define BQ25856_TS_CHARGING_REGION_BEHAVIOR_CONTROL_REG 0x1C
#define BQ25856_TS_REVERSE_MODE_THRESHOLD_CONTROL_REG 0x1D
#define BQ25856_REVERSE_UNDERVOLTAGE_CONTROL_REG 0x1E
#define BQ25856_CHARGER_STATUS_1_REG 0x21
#define BQ25856_CHARGER_STATUS_2_REG 0x22
#define BQ25856_CHARGER_STATUS_3_REG 0x23
#define BQ25856_FAULT_STATUS_REG 0x24
#define BQ25856_CHARGER_FLAG_1_REG 0x25
#define BQ25856_CHARGER_FLAG_2_REG 0x26
#define BQ25856_FAULT_FLAG_REG 0x27
#define BQ25856_CHARGER_MASK_1_REG 0x28
#define BQ25856_CHARGER_MASK_2_REG 0x29
#define BQ25856_FAULT_MASK_REG 0x2A
#define BQ25856_ADC_CONTROL_REG 0x2B
#define BQ25856_ADC_CHANNEL_CONTROL_REG 0x2C
#define BQ25856_IAC_ADC_REG 0x2D
#define BQ25856_IBAT_ADC_REG 0x2F
#define BQ25856_VAC_ADC_REG 0x31
#define BQ25856_VBAT_ADC_REG 0x33
#define BQ25856_TS_ADC_REG 0x37
#define BQ25856_VFB_ADC_REG 0x39
#define BQ25856_GATE_DRIVER_STRENGTH_CONTROL_REG 0x3B
#define BQ25856_GATE_DRIVER_DEAD_TIME_CONTROL_REG 0x3C
#define BQ25856_PART_INFORMATION_REG 0x3D
#define BQ25856_REVERSE_MODE_BATTERY_DISCHARGE_CURRENT_REG 0x62

// Number of registers in BQ25856
#define BQ25856_REG_NUM 40

#define BQ25856_TEST_TIMEOUT (500) // microseconds

int32_t BQ25856_read_reg(uint8_t register_addr, uint8_t length, uint16_t* result);
int32_t BQ25856_write_reg(uint8_t register_addr, uint8_t length, uint16_t data);

void BQ25856_read_faults();
void BQ25856_manual_register_read(void);
void BQ25856_manual_register_write(void);
void BQ25856_init(void);

void BQ25856_print_register_dump(void);


typedef struct
{
    uint32_t address;
    uint8_t length;
} BQ25856_Reg;

extern const BQ25856_Reg bq25856_registers[BQ25856_REG_NUM];

#endif