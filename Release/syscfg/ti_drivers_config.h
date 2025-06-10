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

#ifndef TI_DRIVERS_CONFIG_H_
#define TI_DRIVERS_CONFIG_H_

#include <stdint.h>
#include <drivers/hw_include/cslr_soc.h>
#include <drivers/hw_include/hw_types.h>
#include "ti_dpl_config.h"

#ifdef __cplusplus
extern "C" {
#endif


/*
 * Common Functions
 */
void System_init(void);
void System_deinit(void);

/*
 * ADC
 */
#include <drivers/adc.h>
#include <drivers/soc.h>

/* ADC Instance Macros */
#define ADC1_BASE_ADDR (CSL_CONTROLSS_ADC1_U_BASE)
#define ADC1_RESULT_BASE_ADDR (CSL_CONTROLSS_ADC1_RESULT_U_BASE)
#define CONFIG_ADC_NUM_INSTANCES (1U)

/*
 * GPIO
 */
#include <drivers/gpio.h>
#include <kernel/dpl/AddrTranslateP.h>

/* GPIO PIN Macros */
#define GPIO43_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO43_PIN (43)
#define GPIO43_DIR (GPIO_DIRECTION_INPUT)
#define GPIO43_TRIG_TYPE (GPIO_TRIG_TYPE_FALL_EDGE)

#define GPIO43_INTR_NUM      (CSLR__GPIOMUX_INTROUTER0_OUTP_)

#define GPIO44_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO44_PIN (44)
#define GPIO44_DIR (GPIO_DIRECTION_INPUT)
#define GPIO44_TRIG_TYPE (GPIO_TRIG_TYPE_FALL_EDGE)

#define GPIO44_INTR_NUM      (CSLR__GPIOMUX_INTROUTER0_OUTP_)

#define GPIO45_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO45_PIN (45)
#define GPIO45_DIR (GPIO_DIRECTION_INPUT)
#define GPIO45_TRIG_TYPE (GPIO_TRIG_TYPE_FALL_EDGE)

#define GPIO45_INTR_NUM      (CSLR__GPIOMUX_INTROUTER0_OUTP_)

#define GPIO46_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO46_PIN (46)
#define GPIO46_DIR (GPIO_DIRECTION_INPUT)
#define GPIO46_TRIG_TYPE (GPIO_TRIG_TYPE_FALL_EDGE)

#define GPIO46_INTR_NUM      (CSLR__GPIOMUX_INTROUTER0_OUTP_)

#define GPIO51_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO51_PIN (51)
#define GPIO51_DIR (GPIO_DIRECTION_INPUT)
#define GPIO51_TRIG_TYPE (GPIO_TRIG_TYPE_FALL_EDGE)

#define GPIO51_INTR_NUM      (CSLR__GPIOMUX_INTROUTER0_OUTP_)

#define GPIO52_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO52_PIN (52)
#define GPIO52_DIR (GPIO_DIRECTION_INPUT)
#define GPIO52_TRIG_TYPE (GPIO_TRIG_TYPE_FALL_EDGE)

#define GPIO52_INTR_NUM      (CSLR__GPIOMUX_INTROUTER0_OUTP_)

#define GPIO53_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO53_PIN (53)
#define GPIO53_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO53_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO54_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO54_PIN (54)
#define GPIO54_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO54_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO24_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO24_PIN (24)
#define GPIO24_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO24_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO23_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO23_PIN (23)
#define GPIO23_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO23_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO123_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO123_PIN (123)
#define GPIO123_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO123_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO136_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO136_PIN (136)
#define GPIO136_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO136_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO127_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO127_PIN (127)
#define GPIO127_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO127_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO126_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO126_PIN (126)
#define GPIO126_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO126_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define SPI0_CS_BASE_ADDR (CSL_GPIO0_U_BASE)
#define SPI0_CS_PIN (11)
#define SPI0_CS_DIR (GPIO_DIRECTION_OUTPUT)
#define SPI0_CS_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define SPI1_CS_BASE_ADDR (CSL_GPIO0_U_BASE)
#define SPI1_CS_PIN (15)
#define SPI1_CS_DIR (GPIO_DIRECTION_OUTPUT)
#define SPI1_CS_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define CONFIG_GPIO_NUM_INSTANCES (16U)
/*
 * MCSPI
 */
#include <drivers/mcspi.h>

/* MCSPI Instance Macros */
#define SPI0 (0U)
#define SPI1 (1U)
#define CONFIG_MCSPI_NUM_INSTANCES (2U)
#define CONFIG_MCSPI_NUM_DMA_INSTANCES (0U)

/*
 * EDMA
 */
#include <drivers/edma.h>
#include <drivers/soc.h>

/* EDMA Instance Macros */
#define CONFIG_EDMA0_BASE_ADDR (CSL_TPCC0_U_BASE)
#define CONFIG_EDMA0 (0U)
#define CONFIG_EDMA_NUM_INSTANCES (1U)


/*
 * UART
 */
#include <drivers/uart.h>
/* UART Instance Macros */
#define CONFIG_UART0 (0U)
#define CONFIG_UART_NUM_INSTANCES (1U)
#define CONFIG_UART_NUM_DMA_INSTANCES (0U)


#include <drivers/soc.h>
#include <kernel/dpl/CycleCounterP.h>

/*
 * MCU_LBIST
 */
void SDL_lbist_selftest(void);

#ifdef __cplusplus
}
#endif

#endif /* TI_DRIVERS_CONFIG_H_ */
