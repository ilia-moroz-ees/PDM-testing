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

#ifndef TI_DRVIERS_OPEN_CLOSE_H_
#define TI_DRVIERS_OPEN_CLOSE_H_

#include <stdint.h>
#include "ti_drivers_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Common Functions
 */
void Drivers_open(void);
void Drivers_close(void);

/*
 * I2C
 */


#include <drivers/i2c.h>

/* I2C Driver handles  */
extern I2C_Handle gI2cHandle[CONFIG_I2C_HLD_NUM_INSTANCES];

/*
 * I2C Driver Advance Parameters - to be used only when Driver_open() and
 * Driver_close() is not used by the application
 */

/* I2C Driver Parameters */
extern I2C_Params gI2cParams[CONFIG_I2C_HLD_NUM_INSTANCES];

/* I2C Driver open/close - can be used by application when Driver_open() and
 * Driver_close() is not used directly and app wants to control the various driver
 * open/close sequences */
void Drivers_i2cOpen(void);
void Drivers_i2cClose(void);




/* Include ti_drivers_open_close.h to call MCSPI open*/
void Drivers_pmicOpen();

/*
 * MCSPI
 */
#include <drivers/mcspi.h>
#include <drivers/edma.h>
#include <drivers/mcspi/v0/lld/dma/mcspi_dma.h>
#include <drivers/mcspi/v0/lld/dma/edma/mcspi_dma_edma.h>

/* MCSPI Driver handles */
extern MCSPI_Handle gMcspiHandle[CONFIG_MCSPI_NUM_INSTANCES];
/*
 * MCSPI Driver Advance Parameters - to be used only when Driver_open() and
 * Driver_close() is not used by the application
 */
/* MCSPI Driver Open Parameters */
extern MCSPI_OpenParams gMcspiOpenParams[CONFIG_MCSPI_NUM_INSTANCES];
/* MCSPI Channel Macros */
#define SPI0_NUM_CH (1U)
#define SPI1_NUM_CH (1U)
/* MCSPI Driver Channel Configurations */
extern MCSPI_ChConfig gSpi0ChCfg[SPI0_NUM_CH];
extern MCSPI_ChConfig gSpi1ChCfg[SPI1_NUM_CH];
/* MCSPI Driver open/close - can be used by application when Driver_open() and
 * Driver_close() is not used directly and app wants to control the various driver
 * open/close sequences */
void Drivers_mcspiOpen(void);
void Drivers_mcspiClose(void);

/*
 * EDMA
 */
#include <drivers/edma.h>

/* EDMA Driver handles */
extern EDMA_Handle gEdmaHandle[CONFIG_EDMA_NUM_INSTANCES];

/*
 * EDMA Driver Advance Parameters - to be used only when Driver_open() and
 * Driver_close() is not used by the application
 */
/* EDMA Driver Open Parameters */
extern EDMA_Params gEdmaParams[CONFIG_EDMA_NUM_INSTANCES];
/* EDMA Driver open/close - can be used by application when Driver_open() and
 * Driver_close() is not used directly and app wants to control the various driver
 * open/close sequences */
void Drivers_edmaOpen(void);
void Drivers_edmaClose(void);

#include <drivers/adc.h>
#include <kernel/dpl/ClockP.h>

void Drivers_adcOpen(void);
#include <drivers/soc/am263px/soc_xbar.h>
void Drivers_gpioIntXbarOpen(void);
/*
 * UART
 */
#include <drivers/uart.h>

/* UART Driver handles */
extern UART_Handle gUartHandle[CONFIG_UART_NUM_INSTANCES];

/*
 * UART Driver Advance Parameters - to be used only when Driver_open() and
 * Driver_close() is not used by the application
 */
/* UART Driver Parameters */
extern UART_Params gUartParams[CONFIG_UART_NUM_INSTANCES];
/* UART Driver open/close - can be used by application when Driver_open() and
 * Driver_close() is not used directly and app wants to control the various driver
 * open/close sequences */
void Drivers_uartOpen(void);
void Drivers_uartClose(void);


#ifdef __cplusplus
}
#endif

#endif /* TI_DRVIERS_OPEN_CLOSE_H_ */
