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
#include "BQ25856.h"
#include "pmic_test.h"

void PDM_testing(void *args)
{
    static uint16_t user_input_test_number;

    Drivers_open();
    Board_driversOpen();

    DebugP_uartSetDrvIndex(CONFIG_UART0);
    init_gpio();
    BQ25751_init();
    BQ25856_init();
    pmic_init();
    init_global_interrupts(&intr_objects);
    ADC_enableConverter(ADC1_BASE_ADDR);
    ClockP_sleep(1);

    ext_adc0.spi_handle = gMcspiHandle[SPI0];
    ext_adc0.channel = gSpi0ChCfg[0].chNum;

    ext_adc1.spi_handle = gMcspiHandle[SPI1];
    ext_adc1.channel = gSpi1ChCfg[0].chNum;
    
    while(true)
    {
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

            case 993: // BQ25751 test mode
                PPMC_run_test_mode();
                break;

            case 994: // test of reading part number of BQ25751
            {
                BQ25751_read_faults();
                break;
            }

            case 995: // Manually write a register to BQ25751
                BQ25751_manual_register_write();
                break;

            case 996: // Manually read a register from BQ25751
               BQ25751_manual_register_read();
               break;

            case 997: // Print a regusters dump
                BQ25751_print_register_dump();
                break;

            case 998: // Manually write a register to BQ25856
                BQ25856_manual_register_write();
                break;

            case 999: // Manually read a register from BQ25856
                BQ25856_manual_register_read();
                break;

            case 1000: // Print a register dump from supercapacitor controller (BQ25856)
                BQ25856_print_register_dump();
                break;

            case 1001: // Request PMIC Standby mode
                digitalWrite(GPIO47_BASE_ADDR, GPIO47_PIN, 0); // Pull WAKE1 pin low
                // Maybe pull WAKE2 low too

                pmic_write_reg(PMIC_STBY_CFG_REG_ADDR, 0b00010111); // STBY_EN = 1
                pmic_write_reg(PMIC_STATE_CTRL_REG_ADDR, 0x04); // STATE_REQ = 4h
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

