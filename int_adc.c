#include "int_adc.h"

const float INT_ADC_VREF = 3.3f;             // Reference ADC Voltage
const float INT_ADC_RESOLUTION = 4095.0f;    // 12 bit resolution
const float CURRENT_SCALE_LM74930 = 0.432f;  // Voltage to Current Conversion factor LM74930

// SOC2 - INT1 - ADC1_AIN2
// SOC3 - INT2 - ADC1_AIN3
// SOC4 - INT3 - ADC1_AIN4
// SOC5 - INT4 - ADC1_AIN5

uint16_t read_int_ADC(uint8_t adc_number) {
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1);

    uint16_t conversion_result;
    
    // Need to wait a little bit after starting conversion, otherwise Result doesn't update properly
    switch (adc_number) {
        case 0:
            ADC_setInterruptSource(ADC1_BASE_ADDR, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER0);
            ClockP_usleep(10);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1) == false) {
            /* Wait for the SOC conversion to complete */
            }
            ClockP_usleep(10);
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER0);
            break;

        case 1:
            ADC_setInterruptSource(ADC1_BASE_ADDR, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER1);
            ClockP_usleep(10);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1) == false) {
            /* Wait for the SOC conversion to complete */
            }
            ClockP_usleep(10);
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER1);
            break;

        case 2:
            ADC_setInterruptSource(ADC1_BASE_ADDR, ADC_INT_NUMBER1, ADC_SOC_NUMBER2);
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER2);
            ClockP_usleep(10);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1) == false) {
            /* Wait for the SOC conversion to complete */
            }
            ClockP_usleep(10);
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER2);
            break;

        case 3:
            ADC_setInterruptSource(ADC1_BASE_ADDR, ADC_INT_NUMBER1, ADC_SOC_NUMBER3);
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER3);
            ClockP_usleep(10);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1) == false) {
            /* Wait for the SOC conversion to complete */
            }
            ClockP_usleep(10);
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER3);
            break;

        case 4:
            ADC_setInterruptSource(ADC1_BASE_ADDR, ADC_INT_NUMBER1, ADC_SOC_NUMBER4);
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER4);
            ClockP_usleep(10);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1) == false) {
            /* Wait for the SOC conversion to complete */
            }
            ClockP_usleep(10);
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER4);
            break;

        case 5:
            ADC_setInterruptSource(ADC1_BASE_ADDR, ADC_INT_NUMBER1, ADC_SOC_NUMBER5);
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER5);
            ClockP_usleep(10);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1) == false) {
            /* Wait for the SOC conversion to complete */
            }
            ClockP_usleep(10);
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER5);
            break;
    }

    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1);

    return conversion_result;
}

void disable_ADC()
{
    // Disable interrupts
    ADC_disableInterrupt(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    /* Power down the ADC */
    ADC_disableConverter(ADC1_BASE_ADDR);
}

float int_adc_to_voltage(uint16_t raw_adc)
{
    return ((float)raw_adc / INT_ADC_RESOLUTION) * INT_ADC_VREF;
}

float adc_to_current_LM74930(uint16_t raw_adc)
{
    return int_adc_to_voltage((float)raw_adc) / CURRENT_SCALE_LM74930;
}