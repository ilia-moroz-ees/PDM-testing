#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include "ti_drivers_config.h"
#include "logger.h"

#define GPIO48_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15
#define GPIO44_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO45_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO46_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO51_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15
#define GPIO52_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15

#define GPIO_MODULE_0_BASE_ADDRESS GPIO48_BASE_ADDR

typedef struct
{
    HwiP_Object Gpio48HwiObject;
    HwiP_Object Gpio44HwiObject;
    HwiP_Object Gpio45HwiObject;
    HwiP_Object Gpio46HwiObject;
    HwiP_Object Gpio51HwiObject;
    HwiP_Object Gpio52HwiObject;
} Intr_objects;

typedef struct
{
    uint32_t pin_num;
    uint32_t base_address;
    uint32_t dir;
    uint32_t int_num;
} Pin_parameters;

typedef struct
{
    Pin_parameters gpio48;
    Pin_parameters gpio44;
    Pin_parameters gpio45;
    Pin_parameters gpio46;
    Pin_parameters gpio51;
    Pin_parameters gpio52;
} Pins;

extern Pins intr_pins;

extern void GPIO_bankIsrFxn(void *args);
extern void init_gpio();
extern void init_global_interrupts(Intr_objects *objects);
extern void init_interrupt(HwiP_Object *intr_object, Pin_parameters *pin);
extern void digitalWrite(uint32_t base_address, uint32_t pin, bool value);

extern volatile int test;

extern Intr_objects intr_objects;

#endif