#include <stdio.h>
#include <kernel/dpl/DebugP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/adc.h>
#include <drivers/gpio.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include <ioexp_tca6424.h>
#include <board/ioexp/ioexp_tca6424.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include "board.h"
#include "ADS_adc.h"
#include "int_adc.h"
#include "logger.h"
#include "testing.h"
#include "BQ25751.h"

uint16_t log_counter = 0;

void PDM_testing(void *args)
{
    static uint16_t user_input_test_number;

    Drivers_open();
    Board_driversOpen();

    DebugP_uartSetDrvIndex(CONFIG_UART0);
    init_gpio();
    init_global_interrupts(&intr_objects);
    ADC_enableConverter(ADC1_BASE_ADDR);
    ClockP_sleep(1);

    ext_adc0.spi_handle = gMcspiHandle[SPI0];
    ext_adc0.channel = gSpi0ChCfg[0].chNum;

    ext_adc1.spi_handle = gMcspiHandle[SPI1];
    ext_adc1.channel = gSpi1ChCfg[0].chNum;
    
    while(true)
    {

        // uint16_t fault24, fault27;
        // BQ25751_read_reg(0x27, 1, &fault27);
        // BQ25751_read_reg(0x24, 1, &fault24);
        // DebugP_log("Fault24: %d, Fault27: %d\r\n", fault24, fault27); // Extracting part number, should be 1
        
        DebugP_log("Enter test number: \r\n");
        DebugP_scanf("%d", &user_input_test_number);

        switch (user_input_test_number)
        {
            // A few commands to interact with logs
            case 990:
                clear_logs();
                DebugP_log("logs buffer cleared\r\n");
                break;
            
            case 991:
                print_logs();
                break;
            
            case 992:
                DebugP_log("Current number of logs: %d/%d\r\n", logs_length, MAX_LOG_ENTRY_NUMBER);
                break;

            case 995: // test of reading part number of BQ25751
            {
                BQ25751_read_faults();
                break;
            }

            case 996: // Write a register from BQ25751 with value manually
                BQ25751_manual_register_write();
                break;

            case 997: // Read a register from BQ25751 manually
               BQ25751_manual_register_read();
               break;

            case 998: // Print a regusters dump
                BQ25751_print_register_dump();
                break;
            
            default:
                conduct_test(user_input_test_number);
                break;
        }
    }

    disable_ADC();

    Board_driversClose();
    Drivers_close();
}

