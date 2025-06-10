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



void PDM_testing(void *args)
{
    static bool signal;

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
    };

    ADS_ADC adc1 = {
        .spi_handle = gMcspiHandle[SPI1],
        .spi_instance = SPI1,
        .channel = gSpi1ChCfg[0].chNum,
        .cs_base = SPI1_CS_BASE_ADDR,
        .cs_pin = SPI1_CS_PIN,
        .resolution = ADC_RESOLUTION,
        .vref = VREF
    }; // SPI1

    while(true)
    {
        DebugP_log("Running...%d\r\n", test);
        digitalWrite(GPIO127_BASE_ADDR, GPIO127_PIN, signal);
        signal = !signal;
        ClockP_sleep(1);
        DebugP_log("ADC2 = %d\r\n", read_int_ADC(2));
        DebugP_log("ADC3 = %d\r\n", read_int_ADC(3));
        DebugP_log("ADC4 = %d\r\n", read_int_ADC(4));
        DebugP_log("ADC5 = %d\r\n", read_int_ADC(5));
    }

    ADC_disableInterrupt(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADC1_BASE_ADDR, ADC_INT_NUMBER1);
    /* Power down the ADC */
    ADC_disableConverter(ADC1_BASE_ADDR);

    Board_driversClose();
    Drivers_close();
}

