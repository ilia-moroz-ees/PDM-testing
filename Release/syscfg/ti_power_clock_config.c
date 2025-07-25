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

#include <kernel/dpl/DebugP.h>
#include <drivers/soc.h>

#define SOC_MODULES_END     (0xFFFFFFFFu)

typedef struct {

    uint32_t moduleId;
    uint32_t clkId;
    uint32_t clkRate;

} SOC_ModuleClockFrequency;

uint32_t gSocModules[] = {
    SOC_RcmPeripheralId_I2C,

    SOC_RcmPeripheralId_MCSPI0,
    SOC_RcmPeripheralId_MCSPI1,

    SOC_RcmPeripheralId_LIN0_UART0,

    SOC_MODULES_END,
};

SOC_ModuleClockFrequency gSocModulesClockFrequency[] = {
    { SOC_RcmPeripheralId_I2C, SOC_RcmPeripheralClockSource_DPLL_PER_HSDIV0_CLKOUT1, 96000000},

    { SOC_RcmPeripheralId_MCSPI0, SOC_RcmPeripheralClockSource_DPLL_CORE_HSDIV0_CLKOUT0, 50000000},
    { SOC_RcmPeripheralId_MCSPI1, SOC_RcmPeripheralClockSource_DPLL_CORE_HSDIV0_CLKOUT0, 50000000},

    { SOC_RcmPeripheralId_LIN0_UART0, SOC_RcmPeripheralClockSource_DPLL_PER_HSDIV0_CLKOUT1, 48000000},

    { SOC_MODULES_END, SOC_MODULES_END, SOC_MODULES_END },
};

void Module_clockEnable(void)
{
    int32_t status;
    uint32_t i = 0;

    while(gSocModules[i]!=SOC_MODULES_END)
    {
        status = SOC_moduleClockEnable(gSocModules[i], 1);
        DebugP_assertNoLog(status == SystemP_SUCCESS);
        i++;
    }
}

void Module_clockDisable(void)
{
    int32_t status;
    uint32_t i = 0;

    while(gSocModules[i]!=SOC_MODULES_END)
    {
        status = SOC_moduleClockEnable(gSocModules[i], 0);
        DebugP_assertNoLog(status == SystemP_SUCCESS);
        i++;
    }
}

void Module_clockSetFrequency(void)
{
    int32_t status;
    uint32_t i = 0;

    while(gSocModulesClockFrequency[i].moduleId!=SOC_MODULES_END)
    {
        status = SOC_moduleSetClockFrequency(
                    gSocModulesClockFrequency[i].moduleId,
                    gSocModulesClockFrequency[i].clkId,
                    gSocModulesClockFrequency[i].clkRate
                    );
        DebugP_assertNoLog(status == SystemP_SUCCESS);
        i++;
    }
}


void PowerClock_init(void)
{
    Module_clockEnable();
    Module_clockSetFrequency();
}

void PowerClock_deinit(void)
{
    Module_clockDisable();
}

