#ifndef BOARD_H
#define BOARD_H

// This file contains most of the interrupt related varialbes and functions

#include <stdio.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include "ti_drivers_config.h"
#include "logger.h"
#include "BQ25751.h"

// VIM_MODULE0_0...VIM_MODULE0_3 maps to
// CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14...CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_17

// Every VIM module handles one GPIO bank
// Every GPIO bank contains 16 pins
// Single ISR can be connected to the bank. Inside the ISR, we can check which pin caused the interrupt

#define GPIO48_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15 // bank 3 (VIM_MODULE0_1)
#define GPIO44_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14 // bank 2 (VIM_MODULE0_0)
#define GPIO45_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14 // bank 2 (VIM_MODULE0_0)
#define GPIO46_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_14 // bank 2 (VIM_MODULE0_0)
#define GPIO49_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15 // bank 3 (VIM_MODULE0_1)
#define GPIO50_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15 // bank 3 (VIM_MODULE0_1)
#define GPIO51_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15 // bank 3 (VIM_MODULE0_1)
#define GPIO52_INT_NUM CSLR_R5FSS0_CORE0_INTR_GPIO_INTRXBAR_OUT_15 // bank 3 (VIM_MODULE0_1)

#define GPIO_MODULE_0_BASE_ADDRESS GPIO48_BASE_ADDR

typedef struct
{
    HwiP_Object Gpio48HwiObject;
    HwiP_Object Gpio44HwiObject;
    HwiP_Object Gpio45HwiObject;
    HwiP_Object Gpio46HwiObject;
    HwiP_Object Gpio49HwiObject;
    HwiP_Object Gpio50HwiObject;
    HwiP_Object Gpio51HwiObject;
    HwiP_Object Gpio52HwiObject;
} Intr_objects;

// Struct containing all information about interrupt pin for easier pass to the functions
typedef struct
{
    uint32_t pin_num;
    uint32_t base_address;
    uint32_t dir;
    uint32_t int_num;
} Pin_parameters;

// Struct containing all the interrupt pins for easier access inside of ISR
typedef struct
{
    Pin_parameters gpio48;
    Pin_parameters gpio44;
    Pin_parameters gpio45;
    Pin_parameters gpio46;
    Pin_parameters gpio49;
    Pin_parameters gpio50;
    Pin_parameters gpio51;
    Pin_parameters gpio52;
} Pins;

extern Pins intr_pins;

// ISR function, will be called when interrupt occurs
// Could be a separate function for every bank, but in this case,
// it manually checks which bank and pin caused the interrupt, then handles that accordingly
extern void GPIO_bankIsrFxn(void *args);

// Sets direction of every GPIO pin according to the sysconfig configuration
extern void init_gpio();

// Calls init_interrupt function for every interrupt pin
extern void init_global_interrupts(Intr_objects *objects);

// Function for initializing the interrupt of a particular pin
// Sets all the interrupt configurations, connects an ISR function, and passes arguments into it
extern void init_interrupt(HwiP_Object *intr_object, Pin_parameters *pin);

// Helper function for more convenient GPIO interaction (single function for clearing and setting the output)
extern void digitalWrite(uint32_t base_address, uint32_t pin, bool value);

extern Intr_objects intr_objects;

#endif