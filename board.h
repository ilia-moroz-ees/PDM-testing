#include <stdlib.h>
#include <drivers/hw_include/cslr_soc.h>
#include <drivers/gpio.h>
#include "ti_drivers_config.h"

#define GPIO44_INT_NUM  CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14
#define GPIO46_INT_NUM  CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15
#define GPIO91_INT_NUM  CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_16
#define GPIO103_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_17
#define GPIO97_INT_NUM  CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_18
#define GPIO101_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_19

typedef struct
{
    HwiP_Object Gpio44HwiObject;
    HwiP_Object Gpio46HwiObject;
    HwiP_Object Gpio91HwiObject;
    HwiP_Object Gpio103HwiObject;
    HwiP_Object Gpio97HwiObject;
    HwiP_Object Gpio101HwiObject;
} Intr_objects;

typedef struct
{
    uint32_t pin;
    uint32_t base_address;
    uint32_t dir;
} Pin_parameters;

typedef struct
{
    Pin_parameters gpio44;
    Pin_parameters gpio46;
} Pins;

Pins pins = {
    {GPIO44_PIN, GPIO44_BASE_ADDR, GPIO44_DIR},
    {GPIO46_PIN, GPIO46_BASE_ADDR, GPIO46_DIR}
};

static void GPIO_bankIsrFxn(void *args);
void init_gpio();
void init_interrupts(Intr_objects *objects);

volatile int test = 0;

Intr_objects intr_objects;