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

void digitalWrite(uint32_t base_address, uint32_t pin, bool value);

void PDM_testing(void *args)
{

    static bool signal;

    Drivers_open();
    Board_driversOpen();

    init_gpio();
    init_global_interrupts(&intr_objects);

    while(true)
    {
        DebugP_log("Running...%d\r\n", test);
        digitalWrite(GPIO136_BASE_ADDR, GPIO136_PIN, signal);
        signal = !signal;
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
    uint32_t bankNum =  GPIO_GET_BANK_INDEX(pin_parameters->pin_num);
    uint32_t intrStatus, pinMask = GPIO_GET_BANK_BIT_MASK(pin_parameters->pin_num);

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

    GPIO_setDirMode(GPIO24_BASE_ADDR, GPIO24_PIN, GPIO24_DIR);
    DebugP_log("GPIO24 configured as output\r\n");

    GPIO_setDirMode(GPIO23_BASE_ADDR, GPIO23_PIN, GPIO23_DIR);
    DebugP_log("GPIO23 configured as output\r\n");

    GPIO_setDirMode(GPIO53_BASE_ADDR, GPIO53_PIN, GPIO53_DIR);
    DebugP_log("GPIO53 configured as output\r\n");

    GPIO_setDirMode(GPIO54_BASE_ADDR, GPIO54_PIN, GPIO54_DIR);
    DebugP_log("GPIO54 configured as output\r\n");

    GPIO_setDirMode(GPIO123_BASE_ADDR, GPIO123_PIN, GPIO123_DIR);
    DebugP_log("GPIO123 configured as output\r\n");

    GPIO_setDirMode(GPIO136_BASE_ADDR, GPIO136_PIN, GPIO136_DIR);
    DebugP_log("GPIO136 configured as output\r\n");

}

void init_global_interrupts(Intr_objects *objects)
{
    init_interrupt(&objects->Gpio43HwiObject, &intr_pins.gpio43);
    DebugP_log("Initialized gpio43 interrupt\r\n");

    init_interrupt(&objects->Gpio44HwiObject, &intr_pins.gpio44);
    DebugP_log("Initialized gpio44 interrupt\r\n");

    init_interrupt(&objects->Gpio45HwiObject, &intr_pins.gpio45);
    DebugP_log("Initialized gpio45 interrupt\r\n");

    init_interrupt(&objects->Gpio46HwiObject, &intr_pins.gpio46);
    DebugP_log("Initialized gpio46 interrupt\r\n");

    init_interrupt(&objects->Gpio51HwiObject, &intr_pins.gpio51);
    DebugP_log("Initialized gpio51 interrupt\r\n");

    init_interrupt(&objects->Gpio52HwiObject, &intr_pins.gpio52);
    DebugP_log("Initialized gpio52 interrupt\r\n");
}

void init_interrupt(HwiP_Object *intr_object, Pin_parameters *pin)
{
    HwiP_Params hwiPrms;
    HwiP_Params_init(&hwiPrms);
    int32_t retVal;

    hwiPrms.intNum = pin->int_num;
    hwiPrms.callback = &GPIO_bankIsrFxn;
    hwiPrms.args = pin;
    hwiPrms.isPulse = FALSE;
    retVal = HwiP_construct(intr_object, &hwiPrms);
    DebugP_assert(retVal == SystemP_SUCCESS);
}

void digitalWrite(uint32_t base_address, uint32_t pin, bool value)
{
    if (value)
    {
        GPIO_pinWriteHigh(base_address, pin);
    }
    else
    {
        GPIO_pinWriteLow(base_address, pin);
    }
}