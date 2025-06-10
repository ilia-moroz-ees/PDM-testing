#include <stdio.h>
#include <kernel/dpl/DebugP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/adc.h>
#include <drivers/gpio.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include "board.h"
#include "ADS_adc.h"
#include "int_adc.h"
#include "logger.h"
#include "testing.h"

uint16_t log_counter = 0;

void PDM_testing(void *args)
{
    static uint8_t user_input_test_number;

    Drivers_open();
    Board_driversOpen();

    init_gpio();
    init_global_interrupts(&intr_objects);
    ADC_enableConverter(ADC1_BASE_ADDR);
    ClockP_sleep(1);

    ADS_ADC adc0 = {
        .spi_handle = gMcspiHandle[SPI0],
        .spi_instance = SPI0,
        .channel = gSpi0ChCfg[0].chNum,
        .cs_base = SPI0_CS_BASE_ADDR,
        .cs_pin = SPI0_CS_PIN,
        .resolution = ADC_RESOLUTION,
        .vref = VREF
    }; // SPI0

    ADS_ADC adc1 = {
        .spi_handle = gMcspiHandle[SPI1],
        .spi_instance = SPI1,
        .channel = gSpi1ChCfg[0].chNum,
        .cs_base = SPI1_CS_BASE_ADDR,
        .cs_pin = SPI1_CS_PIN,
        .resolution = ADC_RESOLUTION,
        .vref = VREF
    }; // SPI1


    DebugP_uartSetDrvIndex(CONFIG_UART0);
    // conduct_test(0);
    // conduct_test(1);

    while(true)
    {

        DebugP_scanf("%d", &user_input_test_number);
        DebugP_log("%d", user_input_test_number + 1);

    }

    ADC_disableInterrupt(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    /* Power down the ADC */
    ADC_disableConverter(ADC1_BASE_ADDR);

    Board_driversClose();
    Drivers_close();
}

