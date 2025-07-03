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
 * I2C
 */

/* I2C Attributes */
static I2C_HwAttrs gI2cHwAttrs[CONFIG_I2C_HLD_NUM_INSTANCES] =
{
    {
        .baseAddr       = CSL_I2C2_U_BASE,
        .intNum         = 46,
        .eventId        = 0,
        .funcClk        = 96000000U,
        .enableIntr     = 1,
        .ownTargetAddr   = 0x1C,
    },
    {
        .baseAddr       = CSL_I2C0_U_BASE,
        .intNum         = 44,
        .eventId        = 0,
        .funcClk        = 96000000U,
        .enableIntr     = 1,
        .ownTargetAddr   = 0x1C,
    },
    {
        .baseAddr       = CSL_I2C1_U_BASE,
        .intNum         = 45,
        .eventId        = 0,
        .funcClk        = 96000000U,
        .enableIntr     = 1,
        .ownTargetAddr   = 0x1C,
    },
};

/* I2C Objects - Initialized by the Driver */
static I2C_Object gI2cObjects[CONFIG_I2C_HLD_NUM_INSTANCES];

/* I2C driver configuration */
I2C_Config gI2cConfig[CONFIG_I2C_HLD_NUM_INSTANCES] =
{
    {
        .object = &gI2cObjects[CONFIG_I2C0],
        .hwAttrs = &gI2cHwAttrs[CONFIG_I2C0]
    },
    {
        .object = &gI2cObjects[I2C0],
        .hwAttrs = &gI2cHwAttrs[I2C0]
    },
    {
        .object = &gI2cObjects[I2C1],
        .hwAttrs = &gI2cHwAttrs[I2C1]
    },
};

uint32_t gI2cConfigNum = CONFIG_I2C_HLD_NUM_INSTANCES;

/*
 * GPIO
 */

/* ----------- GPIO Direction, Trigger, Interrupt initialization ----------- */

void GPIO_init()
{
    uint32_t    baseAddr;

    /* Instance 0 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO48_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO48_PIN, GPIO48_DIR);
    GPIO_setTrigType(baseAddr, GPIO48_PIN, GPIO48_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO48_PIN));
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
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO123_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO123_PIN);

    GPIO_setDirMode(baseAddr, GPIO123_PIN, GPIO123_DIR);
    /* Instance 9 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO136_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO136_PIN);

    GPIO_setDirMode(baseAddr, GPIO136_PIN, GPIO136_DIR);
    /* Instance 10 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO127_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO127_PIN);

    GPIO_setDirMode(baseAddr, GPIO127_PIN, GPIO127_DIR);
    /* Instance 11 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO126_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, GPIO126_PIN);

    GPIO_setDirMode(baseAddr, GPIO126_PIN, GPIO126_DIR);
    /* Instance 12 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(SPI0_CS_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, SPI0_CS_PIN);

    GPIO_setDirMode(baseAddr, SPI0_CS_PIN, SPI0_CS_DIR);
    /* Instance 13 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(SPI1_CS_BASE_ADDR);
    GPIO_pinWriteLow(baseAddr, SPI1_CS_PIN);

    GPIO_setDirMode(baseAddr, SPI1_CS_PIN, SPI1_CS_DIR);
    /* Instance 14 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO50_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO50_PIN, GPIO50_DIR);
    GPIO_setTrigType(baseAddr, GPIO50_PIN, GPIO50_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO50_PIN));
    /* Instance 15 */
    /* Get address after translation translate */
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO49_BASE_ADDR);

    GPIO_setDirMode(baseAddr, GPIO49_PIN, GPIO49_DIR);
    GPIO_setTrigType(baseAddr, GPIO49_PIN, GPIO49_TRIG_TYPE);
    GPIO_bankIntrEnable(baseAddr, GPIO_GET_BANK_INDEX(GPIO49_PIN));
}


/* ----------- GPIO Interrupt de-initialization ----------- */
void GPIO_deinit()
{
    uint32_t    baseAddr;

    /* Unregister interrupt Instance 0*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO48_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO48_PIN));
    GPIO_setTrigType(baseAddr, GPIO48_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO48_PIN);
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
    /* Unregister interrupt Instance 14*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO50_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO50_PIN));
    GPIO_setTrigType(baseAddr, GPIO50_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO50_PIN);
    /* Unregister interrupt Instance 15*/
    baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(GPIO49_BASE_ADDR);
    GPIO_bankIntrDisable(baseAddr, GPIO_GET_BANK_INDEX(GPIO49_PIN));
    GPIO_setTrigType(baseAddr, GPIO49_PIN, GPIO_TRIG_TYPE_NONE);
    GPIO_clearIntrStatus(baseAddr, GPIO49_PIN);
}

/*
 * MCSPI
 */
#include "ti_drivers_open_close.h"

uint32_t gMcspiNumCh[2] =
{
    SPI0_NUM_CH,
    SPI1_NUM_CH,
};

/* MCSPI atrributes */
static MCSPI_Attrs gMcspiAttrs[CONFIG_MCSPI_NUM_INSTANCES] =
{
    {
        .baseAddr           = CSL_MCSPI0_U_BASE,
        .inputClkFreq       = 50000000U,
        .intrNum            = CSLR_R5FSS0_CORE0_INTR_MCSPI0_INTR,
        .operMode           = MCSPI_OPER_MODE_INTERRUPT,
        .intrPriority       = 4U,
        .chMode             = MCSPI_CH_MODE_SINGLE,
        .pinMode            = MCSPI_PINMODE_4PIN,
        .initDelay          = MCSPI_INITDLY_0,
        .multiWordAccess    = FALSE,
    },
    {
        .baseAddr           = CSL_MCSPI1_U_BASE,
        .inputClkFreq       = 50000000U,
        .intrNum            = CSLR_R5FSS0_CORE0_INTR_MCSPI1_INTR,
        .operMode           = MCSPI_OPER_MODE_INTERRUPT,
        .intrPriority       = 4U,
        .chMode             = MCSPI_CH_MODE_SINGLE,
        .pinMode            = MCSPI_PINMODE_4PIN,
        .initDelay          = MCSPI_INITDLY_0,
        .multiWordAccess    = FALSE,
    },
};
/* MCSPI objects - initialized by the driver */
static MCSPI_Object gMcspiObjects[CONFIG_MCSPI_NUM_INSTANCES];
/* MCSPI driver configuration */
MCSPI_Config gMcspiConfig[CONFIG_MCSPI_NUM_INSTANCES] =
{
    {
        &gMcspiAttrs[SPI0],
        &gMcspiObjects[SPI0],
    },
    {
        &gMcspiAttrs[SPI1],
        &gMcspiObjects[SPI1],
    },
};

uint32_t gMcspiConfigNum = CONFIG_MCSPI_NUM_INSTANCES;

#include <drivers/edma.h>
#include <drivers/mcspi/v0/lld/dma/mcspi_dma.h>
#include <drivers/mcspi/v0/lld/dma/edma/mcspi_dma_edma.h>
MCSPI_DmaConfig gMcspiDmaConfig =
{
    .fxns        = NULL,
    .mcspiDmaArgs = (void *)NULL,
};

McspiDma_EdmaArgs gMcspiEdmaArgs =
{
    .drvHandle        = NULL,
};

MCSPI_DmaHandle gMcspiDmaHandle[] =
{
};

uint32_t gMcspiDmaConfigNum = CONFIG_MCSPI_NUM_DMA_INSTANCES;

/*
 * EDMA
 */
/* EDMA atrributes */
static EDMA_Attrs gEdmaAttrs[CONFIG_EDMA_NUM_INSTANCES] =
{
    {

        .baseAddr           = CSL_TPCC0_U_BASE,
        .compIntrNumber     = CSLR_R5FSS0_CORE0_INTR_TPCC0_INT_0,
        .intrPriority       = 15U,
        .errIntrNumber      = CSLR_R5FSS0_CORE0_INTR_TPCC0_ERRAGGR,
        .errIntrPriority    = 15U,
        .intrAggEnableAddr  = CSL_MSS_CTRL_U_BASE + CSL_MSS_CTRL_TPCC0_INTAGG_MASK,
        .intrAggEnableMask  = 0x1FF & (~(2U << 0)),
        .intrAggStatusAddr  = CSL_MSS_CTRL_U_BASE + CSL_MSS_CTRL_TPCC0_INTAGG_STATUS,
        .intrAggClearMask   = (2U << 0),
        .errIntrAggEnableAddr  = CSL_MSS_CTRL_U_BASE + CSL_MSS_CTRL_TPCC0_ERRAGG_MASK,
        .errIntrAggEnableMask  = 0xFFFFFFFF & (~(0x707001F)),
        .errIntrAggStatusAddr  = CSL_MSS_CTRL_U_BASE + CSL_MSS_CTRL_TPCC0_ERRAGG_STATUS,
        .errIntrAggRawStatusAddr  = CSL_MSS_CTRL_U_BASE + CSL_MSS_CTRL_TPCC0_ERRAGG_STATUS_RAW,
        .initPrms           =
        {
            .regionId     = 0,
            .queNum       = 0,
            .initParamSet = FALSE,
            .ownResource    =
            {
                .qdmaCh      = 0x03U,
                .dmaCh[0]    = 0xFFFFFFFFU,
                .dmaCh[1]    = 0x000000FFU,
                .tcc[0]      = 0xFFFFFFFFU,
                .tcc[1]      = 0x000000FFU,
                .paramSet[0] = 0xFFFFFFFFU,
                .paramSet[1] = 0xFFFFFFFFU,
                .paramSet[2] = 0xFFFFFFFFU,
                .paramSet[3] = 0xFFFFFFFFU,
                .paramSet[4] = 0xFFFFFFFFU,
                .paramSet[5] = 0xFFFFFFFFU,
                .paramSet[6] = 0xFFFFFFFFU,
                .paramSet[7] = 0x000007FFU,
            },
            .reservedDmaCh[0]    = 0x00000000U,
            .reservedDmaCh[1]    = 0x00000000U,
        },
    },
};

/* EDMA objects - initialized by the driver */
static EDMA_Object gEdmaObjects[CONFIG_EDMA_NUM_INSTANCES];
/* EDMA driver configuration */
EDMA_Config gEdmaConfig[CONFIG_EDMA_NUM_INSTANCES] =
{
    {
        &gEdmaAttrs[CONFIG_EDMA0],
        &gEdmaObjects[CONFIG_EDMA0],
    },
};

uint32_t gEdmaConfigNum = CONFIG_EDMA_NUM_INSTANCES;

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


    I2C_init();


    GPIO_init();
    MCSPI_init();
    EDMA_init();
    Drivers_uartInit();
}

void System_deinit(void)
{


    I2C_deinit();

    GPIO_deinit();
    MCSPI_deinit();
    EDMA_deinit();
    UART_deinit();
    PowerClock_deinit();

    Dpl_deinit();
}
