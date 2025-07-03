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

