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
 * GPIO
 */
#include <drivers/gpio.h>
#include <kernel/dpl/AddrTranslateP.h>

/* GPIO PIN Macros */
#define GPIO44_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO44_PIN (44)
#define GPIO44_DIR (GPIO_DIRECTION_INPUT)
#define GPIO44_TRIG_TYPE (GPIO_TRIG_TYPE_FALL_EDGE)

#define GPIO44_INTR_NUM      (CSLR__GPIOMUX_INTROUTER0_OUTP_)

#define GPIO43_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO43_PIN (43)
#define GPIO43_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO43_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO45_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO45_PIN (45)
#define GPIO45_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO45_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO89_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO89_PIN (89)
#define GPIO89_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO89_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO93_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO93_PIN (93)
#define GPIO93_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO93_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO95_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO95_PIN (95)
#define GPIO95_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO95_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define GPIO99_BASE_ADDR (CSL_GPIO0_U_BASE)
#define GPIO99_PIN (99)
#define GPIO99_DIR (GPIO_DIRECTION_OUTPUT)
#define GPIO99_TRIG_TYPE (GPIO_TRIG_TYPE_NONE)
#define CONFIG_GPIO_NUM_INSTANCES (7U)


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
