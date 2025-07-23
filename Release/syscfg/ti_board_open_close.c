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

#include "ti_board_open_close.h"

int32_t Board_driversOpen(void)
{
    int32_t status = SystemP_SUCCESS;
    if(status==SystemP_SUCCESS)
    {
        status = Board_ioexpOpen();
        if(status == SystemP_FAILURE)
        {
            DebugP_log("IO Expander Configuration Failed!!\r\n");
        }
    }



    return status;
}

void Board_driversClose(void)
{

    Board_pmicClose();

}

/*
 * IOEXP
 */
int32_t Board_ioexpOpen()
{
    int32_t  status = SystemP_SUCCESS;
    static TCA6424_Config  gTCA6424_Config;
    TCA6424_Params      TCA6424Params;
    TCA6424_Params_init(&TCA6424Params);

    TCA6424Params.i2cInstance  =  I2C2;
    TCA6424Params.i2cAddress  = 0x22U;
    status = TCA6424_open(&gTCA6424_Config, &TCA6424Params);
    
    /* Configure State */
    status = TCA6424_setOutput(
                    &gTCA6424_Config,
                    IO_EXP_I2C0_MUX_SEL_LINE,
                    IO_EXP_I2C0_MUX_SEL_STATE);

    /* Configure as output  */
    status += TCA6424_config(
                    &gTCA6424_Config,
                    IO_EXP_I2C0_MUX_SEL_LINE,
                    TCA6424_MODE_OUTPUT);
    
    if(status != SystemP_SUCCESS)
    {
        DebugP_log("Failure to Set IO Expander lines\r\n");
        TCA6424_close(&gTCA6424_Config);
    }
    
    /* Configure State */
    status = TCA6424_setOutput(
                    &gTCA6424_Config,
                    IO_EXP_SPI1_MUX_SEL_LINE,
                    IO_EXP_SPI1_MUX_SEL_STATE);

    /* Configure as output  */
    status += TCA6424_config(
                    &gTCA6424_Config,
                    IO_EXP_SPI1_MUX_SEL_LINE,
                    TCA6424_MODE_OUTPUT);
    
    if(status != SystemP_SUCCESS)
    {
        DebugP_log("Failure to Set IO Expander lines\r\n");
        TCA6424_close(&gTCA6424_Config);
    }



    if(SystemP_FAILURE == status)
    {
        /* Exit gracefully */
    }

    return status;
}

/*
 * PMIC
 */
/* PMIC specific includes */
#include <board/pmic/pmic_tps653860xx.h>

/* PMIC Object - initalized during PMIC_open() */
PMIC_Object gPmicObject[CONFIG_PMIC_NUM_INSTANCES];
/* PMIC Driver handles - opened during Board_pmicOpen() */
PMIC_Handle gPmicHandle[CONFIG_PMIC_NUM_INSTANCES];

/* PMIC Config */
PMIC_Config gPmicConfig[CONFIG_PMIC_NUM_INSTANCES] =
{
    {
        .fxns = &gPmicFxns_TPS653860xx,
        .object = (void *)&gPmicObject[0],
    },
};
uint32_t gPmicConfigNum = CONFIG_PMIC_NUM_INSTANCES;

/* PMIC params */
PMIC_Params gPmicParams[CONFIG_PMIC_NUM_INSTANCES] =
{
    {
        .deviceType  = PMIC_DEV_BB_TPS65386X,
        .commMode    = PMIC_INTF_SPI,
        .instType    = PMIC_MAIN_INST,
        .instance    = SPI1,
    },
};

int32_t Board_pmicOpen()
{
    uint32_t instCnt;
    int32_t  status = SystemP_SUCCESS;

    for(instCnt = 0U; instCnt < CONFIG_PMIC_NUM_INSTANCES; instCnt++)
    {
        gPmicHandle[instCnt] = NULL;   /* Init to NULL so that we can exit gracefully */
    }

    /* Open all instances */
    for(instCnt = 0U; instCnt < CONFIG_PMIC_NUM_INSTANCES; instCnt++)
    {
        gPmicHandle[instCnt] = PMIC_open(instCnt, &gPmicParams[instCnt]);
        if(NULL == gPmicHandle[instCnt])
        {
            DebugP_logError("PMIC open failed for instance %d !!!\r\n", instCnt);
            status = SystemP_FAILURE;
            break;
        }

        status = PMIC_configure(gPmicHandle[instCnt]);

        if(status == SystemP_FAILURE)
        {
            DebugP_logError("PMIC configure failed for instance %d !!!\r\n", instCnt);
            break;
        }
    }
    if(SystemP_FAILURE == status)
    {
        Board_pmicClose();   /* Exit gracefully */
    }

    return status;
}

void Board_pmicClose(void)
{
    uint32_t instCnt;

    /* Close all instances that are open */
    for(instCnt = 0U; instCnt < CONFIG_PMIC_NUM_INSTANCES; instCnt++)
    {
        if(gPmicHandle[instCnt] != NULL)
        {
            PMIC_close(gPmicHandle[instCnt]);
            gPmicHandle[instCnt] = NULL;
        }
    }

    return;
}

void Drivers_pmicOpen()
{
    Drivers_mcspiOpen();
    Board_pmicOpen();
    Drivers_mcspiClose();
    /*Wait 5ms for LDO rail to get initilized*/
    ClockP_usleep(5000);
}

