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
                /* GPIO44 -> EPWM0_B (B1) */
    {
        PIN_EPWM0_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO43 -> EPWM0_A (B2) */
    {
        PIN_EPWM0_A,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO45 -> EPWM1_A (D3) */
    {
        PIN_EPWM1_A,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO89 -> PR0_PRU0_GPIO10 (G18) */
    {
        PIN_PR0_PRU0_GPIO10,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO93 -> PR0_PRU0_GPIO0 (K17) */
    {
        PIN_PR0_PRU0_GPIO0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO95 -> PR0_PRU0_GPIO2 (J18) */
    {
        PIN_PR0_PRU0_GPIO2,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO99 -> PR0_PRU0_GPIO11 (M16) */
    {
        PIN_PR0_PRU0_GPIO11,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO46 -> EPWM1_B (D2) */
    {
        PIN_EPWM1_B,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO91 -> PR0_PRU0_GPIO6 (K15) */
    {
        PIN_PR0_PRU0_GPIO6,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO103 -> PR0_PRU1_GPIO5 (F15) */
    {
        PIN_PR0_PRU1_GPIO5,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO97 -> PR0_PRU0_GPIO16 (H18) */
    {
        PIN_PR0_PRU0_GPIO16,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
    },
                /* GPIO101 -> PR0_PRU0_GPIO13 (H17) */
    {
        PIN_PR0_PRU0_GPIO13,
        ( PIN_MODE(7) | PIN_PULL_DISABLE | PIN_SLEW_RATE_LOW | PIN_GPIO_R5SS0_0 )
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


