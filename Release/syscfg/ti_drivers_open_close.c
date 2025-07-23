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

#include "ti_drivers_open_close.h"
#include <kernel/dpl/DebugP.h>

void Drivers_open(void)
{
    Drivers_pmicOpen();

    Drivers_edmaOpen();
    Drivers_i2cOpen();
    Drivers_mcspiOpen();
    {
        /* ADC */

        /* ADC Reference and Monitor Configurations */
        {
            /* Internal Reference Buffer 0, 
               corresponds to ADC instance 1 is enabled */
            SOC_enableAdcInternalReference(1, TRUE);
            /* Delay after the buffers have been enabled */
            ClockP_usleep(800);

            /* Monitor control is enabled for refernece monitor 1 */
            SOC_enableAdcReferenceMonitor(1, TRUE);

            /* Wait for  ClockP_sleep */
            ClockP_usleep(1);
        
            /* Assert the monitor status for monitor 1 */
            DebugP_assert(SOC_getAdcReferenceStatus(1) == true);
        }
        /* ADC - DAC Loop Back Configurations */
        {
            SOC_enableAdcDacLoopback(FALSE);
        }
        /* Global Force Configurations */
        {
            SOC_enableAdcGlobalForce(1, FALSE);
        }
    }

    Drivers_adcOpen();
    Drivers_gpioIntXbarOpen();
    Drivers_uartOpen();
}

void Drivers_close(void)
{
    Drivers_i2cClose();
    Drivers_mcspiClose();
    Drivers_uartClose();
    Drivers_edmaClose();
}

/*
 * I2C
 */



/* I2C Driver handles */
I2C_Handle gI2cHandle[CONFIG_I2C_HLD_NUM_INSTANCES];

/* I2C Driver Parameters */
I2C_Params gI2cParams[CONFIG_I2C_HLD_NUM_INSTANCES] =
{
    {
        .transferMode        = I2C_MODE_BLOCKING,
        .transferCallbackFxn = NULL,
        .bitRate             = I2C_400KHZ,
    },
    {
        .transferMode        = I2C_MODE_BLOCKING,
        .transferCallbackFxn = NULL,
        .bitRate             = I2C_100KHZ,
    },
    {
        .transferMode        = I2C_MODE_BLOCKING,
        .transferCallbackFxn = NULL,
        .bitRate             = I2C_100KHZ,
    },
};

void Drivers_i2cOpen(void)
{
    int32_t  status = SystemP_SUCCESS;
    uint32_t instCnt;



    for(instCnt = 0U; instCnt < CONFIG_I2C_HLD_NUM_INSTANCES; instCnt++)
    {
        gI2cHandle[instCnt] = NULL;   /* Init to NULL so that we can exit gracefully */
    }

    /* Open all instances */
    for(instCnt = 0U; instCnt < CONFIG_I2C_HLD_NUM_INSTANCES; instCnt++)
    {
        gI2cHandle[instCnt] = I2C_open(instCnt, &gI2cParams[instCnt]);
        if(NULL == gI2cHandle[instCnt])
        {
            DebugP_logError("I2C open failed for HLD instance %d !!!\r\n", instCnt);
            status = SystemP_FAILURE;
            break;
        }
    }

    if(SystemP_SUCCESS != status)
    {
        Drivers_i2cClose();   /* Exit gracefully */
    }
    return;
}

void Drivers_i2cClose(void)
{
    uint32_t instCnt;

    /* Close all instances that are open */
    for(instCnt = 0U; instCnt < CONFIG_I2C_HLD_NUM_INSTANCES; instCnt++)
    {
        if(gI2cHandle[instCnt] != NULL)
        {
            I2C_close(gI2cHandle[instCnt]);
            gI2cHandle[instCnt] = NULL;
        }
    }
    return;
}
/*
 * MCSPI
 */
/* MCSPI Driver handles */
MCSPI_Handle gMcspiHandle[CONFIG_MCSPI_NUM_INSTANCES];
/* MCSPI Driver Open Parameters */
MCSPI_OpenParams gMcspiOpenParams[CONFIG_MCSPI_NUM_INSTANCES] =
{
    {
        .transferMode           = MCSPI_TRANSFER_MODE_BLOCKING,
        .transferTimeout        = SystemP_WAIT_FOREVER,
        .transferCallbackFxn    = NULL,
        .msMode                 = MCSPI_MS_MODE_CONTROLLER,
        .mcspiDmaIndex = -1,
    },
    {
        .transferMode           = MCSPI_TRANSFER_MODE_BLOCKING,
        .transferTimeout        = SystemP_WAIT_FOREVER,
        .transferCallbackFxn    = NULL,
        .msMode                 = MCSPI_MS_MODE_CONTROLLER,
        .mcspiDmaIndex = -1,
    },
};
/* MCSPI Driver Channel Configurations */
MCSPI_ChConfig gSpi0ChCfg[SPI0_NUM_CH] =
{
    {
        .chNum              = MCSPI_CHANNEL_0,
        .frameFormat        = MCSPI_FF_POL0_PHA0,
        .bitRate            = 1000000,
        .csPolarity         = MCSPI_CS_POL_LOW,
        .trMode             = MCSPI_TR_MODE_TX_RX,
        .inputSelect        = MCSPI_IS_D1,
        .dpe0               = MCSPI_DPE_ENABLE,
        .dpe1               = MCSPI_DPE_DISABLE,
        .slvCsSelect        = MCSPI_SLV_CS_SELECT_0,
        .startBitEnable     = FALSE,
        .startBitPolarity   = MCSPI_SB_POL_LOW,
        .csIdleTime         = MCSPI_TCS0_0_CLK,
        .turboEnable        = FALSE,
        .defaultTxData      = 0x0U,
        .txFifoTrigLvl      = 16U,
        .rxFifoTrigLvl      = 16U,
    },
};
MCSPI_ChConfig gSpi1ChCfg[SPI1_NUM_CH] =
{
    {
        .chNum              = MCSPI_CHANNEL_0,
        .frameFormat        = MCSPI_FF_POL0_PHA0,
        .bitRate            = 1000000,
        .csPolarity         = MCSPI_CS_POL_LOW,
        .trMode             = MCSPI_TR_MODE_TX_RX,
        .inputSelect        = MCSPI_IS_D1,
        .dpe0               = MCSPI_DPE_ENABLE,
        .dpe1               = MCSPI_DPE_DISABLE,
        .slvCsSelect        = MCSPI_SLV_CS_SELECT_0,
        .startBitEnable     = FALSE,
        .startBitPolarity   = MCSPI_SB_POL_LOW,
        .csIdleTime         = MCSPI_TCS0_0_CLK,
        .turboEnable        = FALSE,
        .defaultTxData      = 0xFU,
        .txFifoTrigLvl      = 16U,
        .rxFifoTrigLvl      = 16U,
    },
};

MCSPI_ChConfig *gConfigMcspiChCfg[2] =
{
    gSpi0ChCfg,
    gSpi1ChCfg,
};



MCSPI_DmaChConfig gMcspiDmaChConfig[2] =
{
    NULL,
    NULL,
};

void Drivers_mcspiOpen(void)
{
    uint32_t instCnt;
    int32_t  status = SystemP_SUCCESS;

    for(instCnt = 0U; instCnt < CONFIG_MCSPI_NUM_INSTANCES; instCnt++)
    {
        gMcspiHandle[instCnt] = NULL;   /* Init to NULL so that we can exit gracefully */
    }

    /* Open all instances */
    for(instCnt = 0U; instCnt < CONFIG_MCSPI_NUM_INSTANCES; instCnt++)
    {
        gMcspiHandle[instCnt] = MCSPI_open(instCnt, &gMcspiOpenParams[instCnt]);
        if(NULL == gMcspiHandle[instCnt])
        {
            DebugP_logError("MCSPI open failed for instance %d !!!\r\n", instCnt);
            status = SystemP_FAILURE;
            break;
        }
    }

    if(SystemP_FAILURE == status)
    {
        Drivers_mcspiClose();   /* Exit gracefully */
    }

    return;
}

void Drivers_mcspiClose(void)
{
    uint32_t instCnt;
    /* Close all instances that are open */
    for(instCnt = 0U; instCnt < CONFIG_MCSPI_NUM_INSTANCES; instCnt++)
    {
        if(gMcspiHandle[instCnt] != NULL)
        {
            MCSPI_close(gMcspiHandle[instCnt]);
            gMcspiHandle[instCnt] = NULL;
        }
    }
    return;
}

/*
 * EDMA
 */
/* EDMA Driver handles */
EDMA_Handle gEdmaHandle[CONFIG_EDMA_NUM_INSTANCES];

/* EDMA Driver Open Parameters */
EDMA_Params gEdmaParams[CONFIG_EDMA_NUM_INSTANCES] =
{
    {
        .intrEnable = TRUE,
        .errIntrEnable = FALSE,
    },
};

void Drivers_edmaOpen(void)
{
    uint32_t instCnt;
    int32_t  status = SystemP_SUCCESS;

    for(instCnt = 0U; instCnt < CONFIG_EDMA_NUM_INSTANCES; instCnt++)
    {
        gEdmaHandle[instCnt] = NULL;   /* Init to NULL so that we can exit gracefully */
    }

    /* Open all instances */
    for(instCnt = 0U; instCnt < CONFIG_EDMA_NUM_INSTANCES; instCnt++)
    {
        gEdmaHandle[instCnt] = EDMA_open(instCnt, &gEdmaParams[instCnt]);
        if(NULL == gEdmaHandle[instCnt])
        {
            DebugP_logError("EDMA open failed for instance %d !!!\r\n", instCnt);
            status = SystemP_FAILURE;
            break;
        }
    }

    if(SystemP_FAILURE == status)
    {
        Drivers_edmaClose();   /* Exit gracefully */
    }

    return;
}

void Drivers_edmaClose(void)
{
    uint32_t instCnt;

    /* Close all instances that are open */
    for(instCnt = 0U; instCnt < CONFIG_EDMA_NUM_INSTANCES; instCnt++)
    {
        if(gEdmaHandle[instCnt] != NULL)
        {
            EDMA_close(gEdmaHandle[instCnt]);
            gEdmaHandle[instCnt] = NULL;
        }
    }

    return;
}

void Drivers_adcOpen()
{
	/* ADC1 initialization */

	/* Configures the analog-to-digital converter module prescaler. */
	ADC_setPrescaler(ADC1_BASE_ADDR, ADC_CLK_DIV_4_0);
	/* Configures the analog-to-digital converter resolution and signal mode. */
	ADC_setMode(ADC1_BASE_ADDR, ADC_RESOLUTION_12BIT, ADC_MODE_SINGLE_ENDED);
	/* Sets the priority mode of the SOCs. */
	ADC_setSOCPriority(ADC1_BASE_ADDR, ADC_PRI_ALL_ROUND_ROBIN);

	/* Start of Conversion 0 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 0, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 0, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 1 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 1, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN1, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 1, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 2 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 2, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN2, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 2, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 3 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 3, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN3, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 3, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 4 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 4, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN4, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 4, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 5 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 5, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN5, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 5, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 6 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 6, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 6, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 7 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 7, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 7, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 8 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 8, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 8, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 9 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 9, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 9, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 10 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 10, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 10, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 11 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 11, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 11, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 12 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 12, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 12, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 13 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 13, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 13, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 14 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 14, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 14, ADC_INT_SOC_TRIGGER_NONE);

	/* Start of Conversion 15 Configuration */
	/* Configures a start-of-conversion (SOC) in the ADC. */
	ADC_setupSOC(ADC1_BASE_ADDR, 15, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
	/* Configures the interrupt SOC trigger of an SOC. */
	ADC_setInterruptSOCTrigger(ADC1_BASE_ADDR, 15, ADC_INT_SOC_TRIGGER_NONE);

	/* Powers up the analog-to-digital converter core. */
	ADC_enableConverter(ADC1_BASE_ADDR);
    /* Delay for ADC to power up. */
    ClockP_usleep(500);
	/* Sets the timing of the end-of-conversion pulse */
	ADC_setInterruptPulseMode(ADC1_BASE_ADDR, ADC_PULSE_END_OF_ACQ_WIN);
    //
    // Sets the timing of early interrupt generation.
    //
    ADC_setInterruptCycleOffset(ADC1_BASE_ADDR, 0U);
    //
    // Enable alternate timings for DMA trigger
    //
	ADC_enableAltDMATiming(ADC1_BASE_ADDR);


	/* ADC Interrupt 1 Configuration */
	/* Enables an ADC interrupt source. */
	ADC_enableInterrupt(ADC1_BASE_ADDR, 0);
	/* Sets the source EOC for an analog-to-digital converter interrupt. */
	ADC_setInterruptSource(ADC1_BASE_ADDR, 0, ADC_SOC_NUMBER2);
	/* Disables continuous mode for an ADC interrupt. */
	ADC_disableContinuousMode(ADC1_BASE_ADDR, 0);

	/* ADC Interrupt 2 Configuration */
	/* Disables an ADC interrupt source. */
	ADC_disableInterrupt(ADC1_BASE_ADDR, 1);
	/* Sets the source EOC for an analog-to-digital converter interrupt. */
	ADC_setInterruptSource(ADC1_BASE_ADDR, 1, ADC_SOC_NUMBER0);
	/* Disables continuous mode for an ADC interrupt. */
	ADC_disableContinuousMode(ADC1_BASE_ADDR, 1);

	/* ADC Interrupt 3 Configuration */
	/* Disables an ADC interrupt source. */
	ADC_disableInterrupt(ADC1_BASE_ADDR, 2);
	/* Sets the source EOC for an analog-to-digital converter interrupt. */
	ADC_setInterruptSource(ADC1_BASE_ADDR, 2, ADC_SOC_NUMBER4);
	/* Disables continuous mode for an ADC interrupt. */
	ADC_disableContinuousMode(ADC1_BASE_ADDR, 2);

	/* ADC Interrupt 4 Configuration */
	/* Disables an ADC interrupt source. */
	ADC_disableInterrupt(ADC1_BASE_ADDR, 3);
	/* Sets the source EOC for an analog-to-digital converter interrupt. */
	ADC_setInterruptSource(ADC1_BASE_ADDR, 3, ADC_SOC_NUMBER5);
	/* Disables continuous mode for an ADC interrupt. */
	ADC_disableContinuousMode(ADC1_BASE_ADDR, 3);



	/* Post Processing Block 1 Configuration */
	/* Configures a post-processing block (PPB) in the ADC. */
	ADC_setupPPB(ADC1_BASE_ADDR, 0, ADC_SOC_NUMBER0);
	/* Disables individual ADC PPB event sources. */
	ADC_disablePPBEvent(ADC1_BASE_ADDR, 0, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Disables individual ADC PPB event interrupt sources. */
	ADC_disablePPBEventInterrupt(ADC1_BASE_ADDR, 0, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Sets the post processing block offset correction. */
	ADC_setPPBCalibrationOffset(ADC1_BASE_ADDR, 0, 0);
	/* Sets the post processing block reference offset. */
	ADC_setPPBReferenceOffset(ADC1_BASE_ADDR, 0, 0);
	/* Disables two's complement capability in the PPB. */
	ADC_disablePPBTwosComplement(ADC1_BASE_ADDR, 0);
	/* Sets the windowed trip limits for a PPB. */
	ADC_setPPBTripLimits(ADC1_BASE_ADDR, 0, 0, 0);
    /* Disables cycle by cycle clear of ADC PPB event flags. */
    ADC_disablePPBEventCBCClear(ADC1_BASE_ADDR, 0);
	ADC_setPPBCountLimit(ADC1_BASE_ADDR, 0,0);
	ADC_selectPPBSyncInput(ADC1_BASE_ADDR, 0,ADC_SYNCIN_DISABLE);
	ADC_selectPPBCompareSource(ADC1_BASE_ADDR, 0,ADC_PPB_COMPSOURCE_RESULT);
	ADC_setPPBShiftValue(ADC1_BASE_ADDR, 0,0);
	ADC_disablePPBAbsoluteValue(ADC1_BASE_ADDR, 0);

	/* Post Processing Block 2 Configuration */
	/* Configures a post-processing block (PPB) in the ADC. */
	ADC_setupPPB(ADC1_BASE_ADDR, 1, ADC_SOC_NUMBER0);
	/* Disables individual ADC PPB event sources. */
	ADC_disablePPBEvent(ADC1_BASE_ADDR, 1, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Disables individual ADC PPB event interrupt sources. */
	ADC_disablePPBEventInterrupt(ADC1_BASE_ADDR, 1, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Sets the post processing block offset correction. */
	ADC_setPPBCalibrationOffset(ADC1_BASE_ADDR, 1, 0);
	/* Sets the post processing block reference offset. */
	ADC_setPPBReferenceOffset(ADC1_BASE_ADDR, 1, 0);
	/* Disables two's complement capability in the PPB. */
	ADC_disablePPBTwosComplement(ADC1_BASE_ADDR, 1);
	/* Sets the windowed trip limits for a PPB. */
	ADC_setPPBTripLimits(ADC1_BASE_ADDR, 1, 0, 0);
    /* Disables cycle by cycle clear of ADC PPB event flags. */
    ADC_disablePPBEventCBCClear(ADC1_BASE_ADDR, 1);
	ADC_setPPBCountLimit(ADC1_BASE_ADDR, 1,0);
	ADC_selectPPBSyncInput(ADC1_BASE_ADDR, 1,ADC_SYNCIN_DISABLE);
	ADC_selectPPBCompareSource(ADC1_BASE_ADDR, 1,ADC_PPB_COMPSOURCE_RESULT);
	ADC_setPPBShiftValue(ADC1_BASE_ADDR, 1,0);
	ADC_disablePPBAbsoluteValue(ADC1_BASE_ADDR, 1);

	/* Post Processing Block 3 Configuration */
	/* Configures a post-processing block (PPB) in the ADC. */
	ADC_setupPPB(ADC1_BASE_ADDR, 2, ADC_SOC_NUMBER0);
	/* Disables individual ADC PPB event sources. */
	ADC_disablePPBEvent(ADC1_BASE_ADDR, 2, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Disables individual ADC PPB event interrupt sources. */
	ADC_disablePPBEventInterrupt(ADC1_BASE_ADDR, 2, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Sets the post processing block offset correction. */
	ADC_setPPBCalibrationOffset(ADC1_BASE_ADDR, 2, 0);
	/* Sets the post processing block reference offset. */
	ADC_setPPBReferenceOffset(ADC1_BASE_ADDR, 2, 0);
	/* Disables two's complement capability in the PPB. */
	ADC_disablePPBTwosComplement(ADC1_BASE_ADDR, 2);
	/* Sets the windowed trip limits for a PPB. */
	ADC_setPPBTripLimits(ADC1_BASE_ADDR, 2, 0, 0);
    /* Disables cycle by cycle clear of ADC PPB event flags. */
    ADC_disablePPBEventCBCClear(ADC1_BASE_ADDR, 2);
	ADC_setPPBCountLimit(ADC1_BASE_ADDR, 2,0);
	ADC_selectPPBSyncInput(ADC1_BASE_ADDR, 2,ADC_SYNCIN_DISABLE);
	ADC_selectPPBCompareSource(ADC1_BASE_ADDR, 2,ADC_PPB_COMPSOURCE_RESULT);
	ADC_setPPBShiftValue(ADC1_BASE_ADDR, 2,0);
	ADC_disablePPBAbsoluteValue(ADC1_BASE_ADDR, 2);

	/* Post Processing Block 4 Configuration */
	/* Configures a post-processing block (PPB) in the ADC. */
	ADC_setupPPB(ADC1_BASE_ADDR, 3, ADC_SOC_NUMBER0);
	/* Disables individual ADC PPB event sources. */
	ADC_disablePPBEvent(ADC1_BASE_ADDR, 3, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Disables individual ADC PPB event interrupt sources. */
	ADC_disablePPBEventInterrupt(ADC1_BASE_ADDR, 3, (ADC_EVT_TRIPHI | ADC_EVT_TRIPLO | ADC_EVT_ZERO));
	/* Sets the post processing block offset correction. */
	ADC_setPPBCalibrationOffset(ADC1_BASE_ADDR, 3, 0);
	/* Sets the post processing block reference offset. */
	ADC_setPPBReferenceOffset(ADC1_BASE_ADDR, 3, 0);
	/* Disables two's complement capability in the PPB. */
	ADC_disablePPBTwosComplement(ADC1_BASE_ADDR, 3);
	/* Sets the windowed trip limits for a PPB. */
	ADC_setPPBTripLimits(ADC1_BASE_ADDR, 3, 0, 0);
    /* Disables cycle by cycle clear of ADC PPB event flags. */
    ADC_disablePPBEventCBCClear(ADC1_BASE_ADDR, 3);
	ADC_setPPBCountLimit(ADC1_BASE_ADDR, 3,0);
	ADC_selectPPBSyncInput(ADC1_BASE_ADDR, 3,ADC_SYNCIN_DISABLE);
	ADC_selectPPBCompareSource(ADC1_BASE_ADDR, 3,ADC_PPB_COMPSOURCE_RESULT);
	ADC_setPPBShiftValue(ADC1_BASE_ADDR, 3,0);
	ADC_disablePPBAbsoluteValue(ADC1_BASE_ADDR, 3);

	/* Set SOC burst mode. */
	ADC_setBurstModeConfig(ADC1_BASE_ADDR, ADC_TRIGGER_SW_ONLY, 1);
	/* Disables SOC burst mode. */
	ADC_disableBurstMode(ADC1_BASE_ADDR);
}

void Drivers_gpioIntXbarOpen()
{
    /*
    * GPIO INTERRUPT XBAR
    */
    SOC_xbarSelectGpioIntrXbarInputSource(CSL_GPIO_INTR_XBAR_U_BASE, GPIO_INT_XBAR_VIM_MODULE0_0, GPIO_INT_XBAR_GPIO_0_BANK_INTR_2);
    SOC_xbarSelectGpioIntrXbarInputSource(CSL_GPIO_INTR_XBAR_U_BASE, GPIO_INT_XBAR_VIM_MODULE0_1, GPIO_INT_XBAR_GPIO_0_BANK_INTR_3);
}

/*
 * UART
 */

/* UART Driver handles */
UART_Handle gUartHandle[CONFIG_UART_NUM_INSTANCES];

#include <drivers/uart/v0/lld/dma/uart_dma.h>
#include <kernel/dpl/ClockP.h>
#include <drivers/edma.h>

UART_DmaChConfig gUartDmaChConfig[CONFIG_UART_NUM_INSTANCES] =
{
                NULL,
};

/* UART Driver Parameters */
UART_Params gUartParams[CONFIG_UART_NUM_INSTANCES] =
{
        {
            .baudRate           = 115200,
            .dataLength         = UART_LEN_8,
            .stopBits           = UART_STOPBITS_1,
            .parityType         = UART_PARITY_NONE,
            .readMode           = UART_TRANSFER_MODE_BLOCKING,
            .readReturnMode     = UART_READ_RETURN_MODE_FULL,
            .writeMode          = UART_TRANSFER_MODE_BLOCKING,
            .readCallbackFxn    = NULL,
            .writeCallbackFxn   = NULL,
            .hwFlowControl      = FALSE,
            .hwFlowControlThr   = UART_RXTRIGLVL_16,
            .transferMode       = UART_CONFIG_MODE_INTERRUPT,
            .skipIntrReg         = FALSE,
            .uartDmaIndex = -1,
            .intrNum            = 38U,
            .intrPriority       = 4U,
            .operMode           = UART_OPER_MODE_16X,
            .rxTrigLvl          = UART_RXTRIGLVL_8,
            .txTrigLvl          = UART_TXTRIGLVL_32,
            .rxEvtNum           = 0U,
            .txEvtNum           = 0U,
        },
};

void Drivers_uartOpen(void)
{
    uint32_t instCnt;
    int32_t  status = SystemP_SUCCESS;

    for(instCnt = 0U; instCnt < CONFIG_UART_NUM_INSTANCES; instCnt++)
    {
        gUartHandle[instCnt] = NULL;   /* Init to NULL so that we can exit gracefully */
    }

    /* Open all instances */
    for(instCnt = 0U; instCnt < CONFIG_UART_NUM_INSTANCES; instCnt++)
    {
        gUartHandle[instCnt] = UART_open(instCnt, &gUartParams[instCnt]);
        if(NULL == gUartHandle[instCnt])
        {
            DebugP_logError("UART open failed for instance %d !!!\r\n", instCnt);
            status = SystemP_FAILURE;
            break;
        }
    }

    if(SystemP_FAILURE == status)
    {
        Drivers_uartClose();   /* Exit gracefully */
    }

    return;
}

void Drivers_uartClose(void)
{
    uint32_t instCnt;

    /* Close all instances that are open */
    for(instCnt = 0U; instCnt < CONFIG_UART_NUM_INSTANCES; instCnt++)
    {
        if(gUartHandle[instCnt] != NULL)
        {
            UART_close(gUartHandle[instCnt]);
            gUartHandle[instCnt] = NULL;
        }
    }

    return;
}
