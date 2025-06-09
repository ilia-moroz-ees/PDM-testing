#ifndef ADS_ADC_H
#define ADS_ADC_H

#include "ti_board_open_close.h"
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include <drivers/adc.h>
#include <drivers/gpio.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/DebugP.h>
#include <math.h>
#include <stdio.h>

extern const float VREF;          // Reference ADC Voltage
extern const float ADC_RESOLUTION; // 12 bit resolution
extern const float CURRENT_SCALE_CH0; // Voltage to Current Conversion factor CH0
extern const float CURRENT_SCALE_CH1; // Voltage to Current Conversion factor CH1
extern const float DISCREPANCY;

typedef struct
{
    MCSPI_Handle spi_handle;
    uint32_t spi_instance;
    uint32_t cs_base;
    uint32_t cs_pin;
    uint32_t channel;
    float vref;
    float resolution;

} ADS_ADC;

extern uint16_t readADC(ADS_ADC *adc, uint8_t channel);
extern float adc_to_voltage(uint16_t raw_adc);
extern float adc_to_current_ch0(uint16_t raw_adc);
extern float adc_to_current_ch1(uint16_t raw_adc);
extern void read_values(float *ch0, float *ch1, bool *gpio44_value, bool *gpio46_value);
extern uint16_t SPI_ReadWrite(ADS_ADC *adc, uint16_t data);

extern void test_high_side_switches();
extern bool check_test_values(float ch0, float ch1, bool gpio44_value,
                              bool gpio46_value, float ch0_expected_value,
                              float ch1_expected_value,
                              bool gpio44_expected_value,
                              bool gpio46_expected_value);


#endif