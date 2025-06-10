#include "int_adc.h"

// SOC2 - INT1 - ADC1_AIN2
// SOC3 - INT2 - ADC1_AIN3
// SOC4 - INT3 - ADC1_AIN4
// SOC5 - INT4 - ADC1_AIN5

uint16_t read_int_ADC(uint8_t adc_number) {
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER2);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER3);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER4);

    uint16_t conversion_result;

    switch (adc_number) {
        case 2:
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER2);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1) == false) {
            /* Wait for the SOC conversion to complete */
            }
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER2);
            break;

        case 3:
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER3);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER2) == false) {
            /* Wait for the SOC conversion to complete */
            }
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER3);
            break;

        case 4:
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER4);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER3) == false) {
            /* Wait for the SOC conversion to complete */
            }
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER4);
            break;

        case 5:
            ADC_forceSOC(ADC1_BASE_ADDR, ADC_SOC_NUMBER5);
            while (ADC_getInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER4) == false) {
            /* Wait for the SOC conversion to complete */
            }
            conversion_result = ADC_readResult(ADC1_RESULT_BASE_ADDR, ADC_SOC_NUMBER5);
            break;
    }

    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER2);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER3);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER4);

    return conversion_result;
}