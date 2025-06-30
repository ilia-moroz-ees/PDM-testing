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

/* Charge Voltage and Current Control */
#define BQ25751_CHARGE_VOLTAGE_LIMIT_REG         0x00
#define BQ25751_CHARGE_CURRENT_LIMIT_REG         0x02
#define BQ25751_INPUT_CURRENT_DPM_LIMIT_REG      0x06
#define BQ25751_INPUT_VOLTAGE_DPM_LIMIT_REG      0x08
#define BQ25751_REVERSE_MODE_INPUT_CURRENT_LIMIT_REG 0x0A
#define BQ25751_REVERSE_MODE_SYSTEM_VOLTAGE_LIMIT_REG 0x0C
#define BQ25751_TERMINATION_CURRENT_LIMIT_REG    0x12
#define BQ25751_TERMINATION_CONTROL_REG          0x14
#define BQ25751_TIMER_CONTROL_REG                0x15
#define BQ25751_THREE_STAGE_CHARGE_CONTROL_REG   0x16
#define BQ25751_CHARGER_CONTROL_REG              0x17
#define BQ25751_PIN_CONTROL_REG                  0x18
#define BQ25751_POWER_PATH_REVERSE_MODE_CONTROL_REG 0x19 //enable reverse here
#define BQ25751_MPPT_CONTROL_REG                 0x1A
#define BQ25751_TS_CHARGING_THRESHOLD_REG        0x1B
#define BQ25751_TS_CHARGING_BEHAVIOR_REG         0x1C
#define BQ25751_TS_REVERSE_MODE_THRESHOLD_REG    0x1D
#define BQ25751_REVERSE_UNDERVOLTAGE_CONTROL_REG 0x1E
#define BQ25751_VAC_MAX_POWER_POINT_REG          0x1F

/* Status and Fault Registers */
#define BQ25751_CHARGER_STATUS_1_REG             0x21
#define BQ25751_CHARGER_STATUS_2_REG             0x22
#define BQ25751_CHARGER_STATUS_3_REG             0x23
#define BQ25751_FAULT_STATUS_REG                 0x24
#define BQ25751_CHARGER_FLAG_1_REG               0x25
#define BQ25751_CHARGER_FLAG_2_REG               0x26
#define BQ25751_FAULT_FLAG_REG                   0x27
#define BQ25751_CHARGER_MASK_1_REG               0x28
#define BQ25751_CHARGER_MASK_2_REG               0x29
#define BQ25751_FAULT_MASK_REG                   0x2A

/* ADC Monitoring Registers */
#define BQ25751_ADC_CONTROL_REG                  0x2B
#define BQ25751_ADC_CHANNEL_CONTROL_REG          0x2C
#define BQ25751_IAC_ADC_REG                      0x2D
#define BQ25751_IBAT_ADC_REG                     0x2F
#define BQ25751_VAC_ADC_REG                      0x31
#define BQ25751_VBAT_ADC_REG                     0x33
#define BQ25751_VSYS_ADC_REG                     0x35
#define BQ25751_TS_ADC_REG                       0x37
#define BQ25751_VFB_ADC_REG                      0x39

/* Gate Driver Control */
#define BQ25751_GATE_DRIVER_STRENGTH_REG         0x3B
#define BQ25751_GATE_DRIVER_DEAD_TIME_REG        0x3C

/* Device Information */
#define BQ25751_PART_INFORMATION_REG             0x3D

/* Reverse Mode Control */
#define BQ25751_REVERSE_MODE_BAT_DISCHARGE_CURRENT_REG 0x62

// Number of registers in BQ25751
#define BQ25751_REG_NUM 44

#define BQ25751_TEST_TIMEOUT (500 * 1000)

int32_t BQ25751_read_reg(uint8_t register_addr, uint8_t length, uint16_t* result);
int32_t BQ25751_write_reg(uint8_t register_addr, uint8_t length, uint16_t data);
void i2c_read_error_handler(int32_t status);

void BQ25751_read_faults();
void BQ25751_manual_register_read(void);
void BQ25751_manual_register_write(void);
void BQ25751_init(void);

void BQ25751_print_register_dump(void);

extern uint64_t BQ25751_timer;
extern volatile bool BQ25751_timer_en;
extern bool BQ25751_timer_init;

void BQ25751_run_test_mode(void);

typedef struct
{
    uint32_t address;
    uint8_t length;
} BQ25751_Reg;

extern const BQ25751_Reg bq25751_registers[BQ25751_REG_NUM];



#endif