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
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO44_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO44_PIN, GPIO44_DIR);
    GPIO_setTrigType(baseAddr, GPIO44_PIN, GPIO44_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO44_PIN));
    /* Instance 1 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO43_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO43_PIN);

    GPIO_setDirMode(baseAddr, GPIO43_PIN, GPIO43_DIR);
    /* Instance 2 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO45_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO45_PIN);

    GPIO_setDirMode(baseAddr, GPIO45_PIN, GPIO45_DIR);
    /* Instance 3 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO89_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO89_PIN);

    GPIO_setDirMode(baseAddr, GPIO89_PIN, GPIO89_DIR);
    /* Instance 4 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO93_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO93_PIN);

    GPIO_setDirMode(baseAddr, GPIO93_PIN, GPIO93_DIR);
    /* Instance 5 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO95_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO95_PIN);

    GPIO_setDirMode(baseAddr, GPIO95_PIN, GPIO95_DIR);
    /* Instance 6 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO99_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO99_PIN);

    GPIO_setDirMode(baseAddr, GPIO99_PIN, GPIO99_DIR);
    /* Instance 7 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO46_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO46_PIN, GPIO46_DIR);
    GPIO_setTrigType(baseAddr, GPIO46_PIN, GPIO46_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO46_PIN));
    /* Instance 8 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO91_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO91_PIN, GPIO91_DIR);
    GPIO_setTrigType(baseAddr, GPIO91_PIN, GPIO91_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO91_PIN));
    /* Instance 9 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO103_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO103_PIN, GPIO103_DIR);
    GPIO_setTrigType(baseAddr, GPIO103_PIN, GPIO103_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO103_PIN));
    /* Instance 10 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO97_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO97_PIN, GPIO97_DIR);
    GPIO_setTrigType(baseAddr, GPIO97_PIN, GPIO97_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO97_PIN));
    /* Instance 11 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO101_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO101_PIN, GPIO101_DIR);
    GPIO_setTrigType(baseAddr, GPIO101_PIN, GPIO101_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO101_PIN));
}


/* ----------- GPIO Interrupt de-initialization ----------- */
void GPIO_deinit()
{
    uint32_t    baseAddr;

    /* Unregister interrupt Instance 0*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO44_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO44_PIN));
    GPIO_setTrigType(baseAddr, GPIO44_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO44_PIN);
    /* Unregister interrupt Instance 7*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO46_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO46_PIN));
    GPIO_setTrigType(baseAddr, GPIO46_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO46_PIN);
    /* Unregister interrupt Instance 8*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO91_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO91_PIN));
    GPIO_setTrigType(baseAddr, GPIO91_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO91_PIN);
    /* Unregister interrupt Instance 9*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO103_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO103_PIN));
    GPIO_setTrigType(baseAddr, GPIO103_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO103_PIN);
    /* Unregister interrupt Instance 10*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO97_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO97_PIN));
    GPIO_setTrigType(baseAddr, GPIO97_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO97_PIN);
    /* Unregister interrupt Instance 11*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO101_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO101_PIN));
    GPIO_setTrigType(baseAddr, GPIO101_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO101_PIN);
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
