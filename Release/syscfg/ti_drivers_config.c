/*
 *  Copyright (C) 2021 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Auto generated file
 */

#include "ti_drivers_config.h"

/*
 * GPIO
 */

/* ----------- GPIO Direction, Trigger, Interrupt initialization ----------- */

void GPIO_init()
{
    uint32_t    baseAddr;

    /* Instance 0 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO43_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO43_PIN, GPIO43_DIR);
    GPIO_setTrigType(baseAddr, GPIO43_PIN, GPIO43_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO43_PIN));
    /* Instance 1 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO44_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO44_PIN, GPIO44_DIR);
    GPIO_setTrigType(baseAddr, GPIO44_PIN, GPIO44_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO44_PIN));
    /* Instance 2 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO45_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO45_PIN, GPIO45_DIR);
    GPIO_setTrigType(baseAddr, GPIO45_PIN, GPIO45_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO45_PIN));
    /* Instance 3 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO46_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO46_PIN, GPIO46_DIR);
    GPIO_setTrigType(baseAddr, GPIO46_PIN, GPIO46_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO46_PIN));
    /* Instance 4 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO51_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO51_PIN, GPIO51_DIR);
    GPIO_setTrigType(baseAddr, GPIO51_PIN, GPIO51_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO51_PIN));
    /* Instance 5 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO52_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO52_PIN, GPIO52_DIR);
    GPIO_setTrigType(baseAddr, GPIO52_PIN, GPIO52_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO52_PIN));
    /* Instance 6 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO53_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO53_PIN);

    GPIO_setDirMode(baseAddr, GPIO53_PIN, GPIO53_DIR);
    /* Instance 7 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO54_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO54_PIN);

    GPIO_setDirMode(baseAddr, GPIO54_PIN, GPIO54_DIR);
    /* Instance 8 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO24_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO24_PIN);

    GPIO_setDirMode(baseAddr, GPIO24_PIN, GPIO24_DIR);
    /* Instance 9 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO23_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO23_PIN);

    GPIO_setDirMode(baseAddr, GPIO23_PIN, GPIO23_DIR);
    /* Instance 10 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO123_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO123_PIN);

    GPIO_setDirMode(baseAddr, GPIO123_PIN, GPIO123_DIR);
    /* Instance 11 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO136_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO136_PIN);

    GPIO_setDirMode(baseAddr, GPIO136_PIN, GPIO136_DIR);
}


/* ----------- GPIO Interrupt de-initialization ----------- */
void GPIO_deinit()
{
    uint32_t    baseAddr;

    /* Unregister interrupt Instance 0*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO43_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO43_PIN));
    GPIO_setTrigType(baseAddr, GPIO43_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO43_PIN);
    /* Unregister interrupt Instance 1*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO44_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO44_PIN));
    GPIO_setTrigType(baseAddr, GPIO44_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO44_PIN);
    /* Unregister interrupt Instance 2*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO45_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO45_PIN));
    GPIO_setTrigType(baseAddr, GPIO45_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO45_PIN);
    /* Unregister interrupt Instance 3*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO46_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO46_PIN));
    GPIO_setTrigType(baseAddr, GPIO46_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO46_PIN);
    /* Unregister interrupt Instance 4*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO51_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO51_PIN));
    GPIO_setTrigType(baseAddr, GPIO51_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO51_PIN);
    /* Unregister interrupt Instance 5*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO52_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO52_PIN));
    GPIO_setTrigType(baseAddr, GPIO52_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO52_PIN);
}

/*
 * UART
 */

/* UART atrributes */
static UART_Attrs gUartAttrs[CONFIG_UART_NUM_INSTANCES] =
{
        {
            .baseAddr           = CSL_UART0_U_BASE,
            .inputClkFreq       = 48000000U,
        },
};
/* UART objects - initialized by the driver */
static UART_Object gUartObjects[CONFIG_UART_NUM_INSTANCES];
/* UART driver configuration */
UART_Config gUartConfig[CONFIG_UART_NUM_INSTANCES] =
{
        {
            &gUartAttrs[CONFIG_UART0],
            &gUartObjects[CONFIG_UART0],
        },
};

uint32_t gUartConfigNum = CONFIG_UART_NUM_INSTANCES;

#include <drivers/uart/v0/lld/dma/uart_dma.h>
UART_DmaHandle gUartDmaHandle[] =
{
};

uint32_t gUartDmaConfigNum = CONFIG_UART_NUM_DMA_INSTANCES;

void Drivers_uartInit(void)
{
    UART_init();
}

/*
 * MCU_LBIST
 */

uint32_t gMcuLbistTestStatus = 0U;

void SDL_lbist_selftest(void)
{
}

void Pinmux_init(void);
void PowerClock_init(void);
void PowerClock_deinit(void);
/*
 * Common Functions
 */
void System_init(void)
{
    /* DPL init sets up address transalation unit, on some CPUs this is needed
     * to access SCICLIENT services, hence this needs to happen first
     */
    Dpl_init();

    
    /* initialize PMU */
    CycleCounterP_init(SOC_getSelfCpuClk());

    PowerClock_init();
    /* Now we can do pinmux */
    Pinmux_init();
    /* finally we initialize all peripheral drivers */
    GPIO_init();
    Drivers_uartInit();
}

void System_deinit(void)
{
    GPIO_deinit();
    UART_deinit();
    PowerClock_deinit();

    Dpl_deinit();
}
