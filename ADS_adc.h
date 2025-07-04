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

extern const float EXT_ADC_VREF;          // Reference ADC Voltage
extern const float EXT_ADC_RESOLUTION;    // 12 bit resolution
extern const float CURRENT_SCALE_HSS_MB;  // Voltage to Current Conversion factor HSS Motherboard
extern const float CURRENT_SCALE_TPS;     // Voltage to Current Conversion factor TPS1HTC30EVM

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

uint16_t read_ext_ADC(ADS_ADC *adc, uint8_t channel);
float ext_adc_to_voltage(uint16_t raw_adc);
float adc_to_current_HSS_MB(uint16_t raw_adc);
float adc_to_current_TPS(uint16_t raw_adc);
uint16_t SPI_ReadWrite(ADS_ADC *adc, uint16_t data);

extern ADS_ADC ext_adc0;
extern ADS_ADC ext_adc1;

#endif