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

#define GPIO44_INT_NUM  CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO46_INT_NUM  
#define GPIO91_INT_NUM
#define GPIO103_INT_NUM
#define GPIO97_INT_NUM
#define GPIO101_INT_NUM

static void GPIO_bankIsrFxn(void *args);
void init_gpio();
void init_interrupts();

volatile int test = 0;

void empty_main(void *args)
{

    

    Drivers_open();
    Board_driversOpen();

    init_gpio();
    init_interrupts();

    

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
    uint32_t bankNum =  GPIO_GET_BANK_INDEX(GPIO44_PIN);
    uint32_t intrStatus, pinMask = GPIO_GET_BANK_BIT_MASK(GPIO44_PIN);

    /* Get and clear bank interrupt status */
    intrStatus = GPIO_getBankIntrStatus(GPIO44_BASE_ADDR, bankNum);
    GPIO_clearBankIntrStatus(GPIO44_BASE_ADDR, bankNum, intrStatus);

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

void init_interrupts()
{
    HwiP_Params hwiPrms;
    HwiP_Object gGpioHwiObject;
    HwiP_Params_init(&hwiPrms);
    /* Register pin interrupt */
    
    hwiPrms.intNum = GPIO44_INT_NUM; //GPIO44
    hwiPrms.callback = &GPIO_bankIsrFxn;
    hwiPrms.isPulse = FALSE;
    int32_t retVal = HwiP_construct(&gGpioHwiObject, &hwiPrms);
    DebugP_assert(retVal == SystemP_SUCCESS);
}