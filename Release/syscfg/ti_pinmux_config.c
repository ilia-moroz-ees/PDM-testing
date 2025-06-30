/*
 *  Copyright (C) 2021-2024 Texas Instruments Incorporated
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
#include <drivers/pinmux.h>

static Pinmux_PerCfg_t gPinMuxMainDomainCfg[] = {
            /* I2C2 pin config */
    /* I2C2_SCL -> UART0_RTSn (C7) */
    {
        PIN_UART0_RTSN,
        ( PIN_MODE(1) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
    /* I2C2 pin config */
    /* I2C2_SDA -> UART0_CTSn (B7) */
    {
        PIN_UART0_CTSN,
        ( PIN_MODE(1) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
            /* I2C0 pin config */
    /* I2C0_SCL -> I2C0_SCL (A13) */
    {
        PIN_I2C0_SCL,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
    /* I2C0 pin config */
    /* I2C0_SDA -> I2C0_SDA (B13) */
    {
        PIN_I2C0_SDA,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },

                /* GPIO48 -> EPWM2_B (C1) */
    {
        PIN_EPWM2_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO44 -> EPWM0_B (B1) */
    {
        PIN_EPWM0_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO45 -> EPWM1_A (D3) */
    {
        PIN_EPWM1_A,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO46 -> EPWM1_B (D2) */
    {
        PIN_EPWM1_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO51 -> EPWM4_A (D1) */
    {
        PIN_EPWM4_A,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO52 -> EPWM4_B (E4) */
    {
        PIN_EPWM4_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO53 -> EPWM5_A (F2) */
    {
        PIN_EPWM5_A,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO54 -> EPWM5_B (G2) */
    {
        PIN_EPWM5_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO24 -> I2C1_SDA (C8) */
    {
        PIN_I2C1_SDA,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO23 -> I2C1_SCL (D7) */
    {
        PIN_I2C1_SCL,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO123 -> SDFM0_D0 (D14) */
    {
        PIN_SDFM0_D0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO136 -> MCAN2_TX (B12) */
    {
        PIN_MCAN2_TX,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO127 -> SDFM0_D2 (C13) */
    {
        PIN_SDFM0_D2,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO126 -> SDFM0_CLK2 (B15) */
    {
        PIN_SDFM0_CLK2,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO11 -> SPI0_CS0 (C11) */
    {
        PIN_SPI0_CS0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO15 -> SPI1_CS0 (C9) */
    {
        PIN_SPI1_CS0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO50 -> EPWM3_B (E3) */
    {
        PIN_EPWM3_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },

            /* SPI0 pin config */
    /* SPI0_CLK -> SPI0_CLK (A11) */
    {
        PIN_SPI0_CLK,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
    /* SPI0 pin config */
    /* SPI0_D0 -> SPI0_D0 (C10) */
    {
        PIN_SPI0_D0,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
    /* SPI0 pin config */
    /* SPI0_D1 -> SPI0_D1 (B11) */
    {
        PIN_SPI0_D1,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
            /* SPI1 pin config */
    /* SPI1_CLK -> SPI1_CLK (A10) */
    {
        PIN_SPI1_CLK,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
    /* SPI1 pin config */
    /* SPI1_D0 -> SPI1_D0 (B10) */
    {
        PIN_SPI1_D0,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
    /* SPI1 pin config */
    /* SPI1_D1 -> SPI1_D1 (D9) */
    {
        PIN_SPI1_D1,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },

                
            /* UART0 pin config */
    /* UART0_RXD -> UART0_RXD (A7) */
    {
        PIN_UART0_RXD,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },
    /* UART0 pin config */
    /* UART0_TXD -> UART0_TXD (A6) */
    {
        PIN_UART0_TXD,
        ( PIN_MODE(0) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW )
    },

    {PINMUX_END, PINMUX_END}
};


/*
 * Pinmux
 */


void Pinmux_init(void)
{



    Pinmux_config(gPinMuxMainDomainCfg, PINMUX_DOMAIN_ID_MAIN);
    
}


