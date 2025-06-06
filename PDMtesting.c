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

void PDM_testing(void *args)
{

    Drivers_open();
    Board_driversOpen();

    init_gpio();
    init_interrupts(&intr_objects);

    while(true)
    {
        DebugP_log("Running...%d\r\n", test);
        ClockP_sleep(1);
    }

    Board_driversClose();
    Drivers_close();
}

static void GPIO_bankIsrFxn(void *args)
{
    // Passing a struct with pin information
    if (!args) return; // Check for null pointer
    Pin_parameters *pin_parameters = (Pin_parameters*)args;
    uint32_t bankNum =  GPIO_GET_BANK_INDEX(pin_parameters->pin);
    uint32_t intrStatus, pinMask = GPIO_GET_BANK_BIT_MASK(pin_parameters->pin);

    /* Get and clear bank interrupt status */
    intrStatus = GPIO_getBankIntrStatus(pin_parameters->base_address, bankNum);
    GPIO_clearBankIntrStatus(pin_parameters->base_address, bankNum, intrStatus);

    /* Per pin interrupt handling */
    if(intrStatus & pinMask)
    {
        test++;
    }
}

void init_gpio()
{
    GPIO_setDirMode(GPIO43_BASE_ADDR, GPIO43_PIN, GPIO43_DIR);
    DebugP_log("GPIO43 configured as output\r\n");

    GPIO_setDirMode(GPIO45_BASE_ADDR, GPIO45_PIN, GPIO45_DIR);
    DebugP_log("GPIO45 configured as output\r\n");

    GPIO_setDirMode(GPIO89_BASE_ADDR, GPIO89_PIN, GPIO89_DIR);
    DebugP_log("GPIO89 configured as output\r\n");

    GPIO_setDirMode(GPIO93_BASE_ADDR, GPIO93_PIN, GPIO93_DIR);
    DebugP_log("GPIO93 configured as output\r\n");

    GPIO_setDirMode(GPIO95_BASE_ADDR, GPIO95_PIN, GPIO95_DIR);
    DebugP_log("GPIO95 configured as output\r\n");

    GPIO_setDirMode(GPIO99_BASE_ADDR, GPIO99_PIN, GPIO99_DIR);
    DebugP_log("GPIO99 configured as output\r\n");
}

void init_interrupts(Intr_objects *objects)
{
    HwiP_Params hwiPrms;
    HwiP_Params_init(&hwiPrms);
    int32_t retVal;
    /* Register pin interrupt */

    hwiPrms.intNum = GPIO44_INT_NUM; //GPIO44
    hwiPrms.callback = &GPIO_bankIsrFxn;
    hwiPrms.args = &pins.gpio44;
    hwiPrms.isPulse = FALSE;
    retVal = HwiP_construct(&objects->Gpio44HwiObject, &hwiPrms);
    DebugP_assert(retVal == SystemP_SUCCESS);
}