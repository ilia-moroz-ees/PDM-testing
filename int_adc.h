#ifndef HW_ADC_H
#define HW_ADC_H

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

extern const float INT_ADC_VREF;          // Reference ADC Voltage
extern const float INT_ADC_RESOLUTION;    // 12 bit resolution
extern const float CURRENT_SCALE_LM74930; // Voltage to Current Conversion factor LM74930

uint16_t read_int_ADC(uint8_t adc_number);
void disable_ADC();

float int_adc_to_voltage(uint16_t raw_adc);
float adc_to_current_LM74930(uint16_t raw_adc);

#endif