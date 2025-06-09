#include <stdio.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include "ti_drivers_config.h"

#define GPIO43_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO44_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO45_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO46_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO51_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15
#define GPIO52_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15

typedef struct
{
    HwiP_Object Gpio43HwiObject;
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
    Pin_parameters gpio43;
    Pin_parameters gpio44;
    Pin_parameters gpio45;
    Pin_parameters gpio46;
    Pin_parameters gpio51;
    Pin_parameters gpio52;
} Pins;

Pins intr_pins = {
    {GPIO43_PIN, GPIO43_BASE_ADDR, GPIO43_DIR, GPIO43_INT_NUM},
    {GPIO44_PIN, GPIO44_BASE_ADDR, GPIO44_DIR, GPIO44_INT_NUM},
    {GPIO45_PIN, GPIO45_BASE_ADDR, GPIO45_DIR, GPIO45_INT_NUM},
    {GPIO46_PIN, GPIO46_BASE_ADDR, GPIO46_DIR, GPIO46_INT_NUM},
    {GPIO51_PIN, GPIO51_BASE_ADDR, GPIO51_DIR, GPIO51_INT_NUM},
    {GPIO52_PIN, GPIO52_BASE_ADDR, GPIO52_DIR, GPIO52_INT_NUM}
};

static void GPIO_bankIsrFxn(void *args);
void init_gpio();
void init_global_interrupts(Intr_objects *objects);
void init_interrupt(HwiP_Object *intr_object, Pin_parameters *pin);

volatile int test = 0;

Intr_objects intr_objects;