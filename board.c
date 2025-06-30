#include "board.h"

volatile int test = 0;
Intr_objects intr_objects;

Pins intr_pins = {
    {GPIO48_PIN, GPIO48_BASE_ADDR, GPIO48_DIR, GPIO48_INT_NUM},
    {GPIO44_PIN, GPIO44_BASE_ADDR, GPIO44_DIR, GPIO44_INT_NUM},
    {GPIO45_PIN, GPIO45_BASE_ADDR, GPIO45_DIR, GPIO45_INT_NUM},
    {GPIO46_PIN, GPIO46_BASE_ADDR, GPIO46_DIR, GPIO46_INT_NUM},
    {GPIO50_PIN, GPIO50_BASE_ADDR, GPIO50_DIR, GPIO50_INT_NUM},
    {GPIO51_PIN, GPIO51_BASE_ADDR, GPIO51_DIR, GPIO51_INT_NUM},
    {GPIO52_PIN, GPIO52_BASE_ADDR, GPIO52_DIR, GPIO52_INT_NUM}
};

void GPIO_bankIsrFxn(void *args)
{
    // Passing a struct with pin information
    if (!args) return; // Check for null pointer
    Pin_parameters *pin_parameters = (Pin_parameters*)args;

    uint32_t baseAddr = pin_parameters->base_address;
    uint32_t bankNum = GPIO_GET_BANK_INDEX(pin_parameters->pin_num);
    uint32_t intr_status = GPIO_getBankIntrStatus(baseAddr, bankNum);
    GPIO_clearBankIntrStatus(baseAddr, bankNum, intr_status);
    switch (bankNum)
    {
        case 2:
            
            if (intr_status & GPIO_GET_BANK_BIT_MASK(intr_pins.gpio44.pin_num)) {
                add_log(FAULT, GPIO44);
            }
            if (intr_status & GPIO_GET_BANK_BIT_MASK(intr_pins.gpio45.pin_num)) {
                add_log(FAULT, GPIO45);
            }
            if (intr_status & GPIO_GET_BANK_BIT_MASK(intr_pins.gpio46.pin_num)) {
                add_log(FAULT, GPIO46);
            }
            break;
        case 3:
            if (intr_status & GPIO_GET_BANK_BIT_MASK(intr_pins.gpio48.pin_num)) {
                add_log(FAULT, GPIO48);
            }
            if (intr_status & GPIO_GET_BANK_BIT_MASK(intr_pins.gpio50.pin_num)) {
                BQ25751_timer = ClockP_getTimeUsec();
                BQ25751_timer_en = true;
            }
            if (intr_status & GPIO_GET_BANK_BIT_MASK(intr_pins.gpio51.pin_num)) {
                add_log(FAULT, GPIO51);
            }
            if (intr_status & GPIO_GET_BANK_BIT_MASK(intr_pins.gpio52.pin_num)) {
                add_log(FAULT, GPIO52);
            }
            break;
        default:
            test = 0;
            break;
    }

}


void init_gpio()
{
    GPIO_setDirMode(GPIO24_BASE_ADDR, GPIO24_PIN, GPIO24_DIR);
    DebugP_log("GPIO24 configured as output\r\n");

    GPIO_setDirMode(GPIO23_BASE_ADDR, GPIO23_PIN, GPIO23_DIR);
    DebugP_log("GPIO23 configured as output\r\n");

    GPIO_setDirMode(GPIO53_BASE_ADDR, GPIO53_PIN, GPIO53_DIR);
    DebugP_log("GPIO53 configured as output\r\n");

    GPIO_setDirMode(GPIO54_BASE_ADDR, GPIO54_PIN, GPIO54_DIR);
    DebugP_log("GPIO54 configured as output\r\n");

    GPIO_setDirMode(GPIO123_BASE_ADDR, GPIO123_PIN, GPIO123_DIR);
    DebugP_log("GPIO123 configured as output\r\n");

    GPIO_setDirMode(GPIO136_BASE_ADDR, GPIO136_PIN, GPIO136_DIR);
    DebugP_log("GPIO136 configured as output\r\n");

    GPIO_setDirMode(GPIO127_BASE_ADDR, GPIO127_PIN, GPIO127_DIR);
    DebugP_log("GPIO127 configured as output\r\n");

    GPIO_setDirMode(GPIO126_BASE_ADDR, GPIO126_PIN, GPIO126_DIR);
    DebugP_log("GPIO126 configured as output\r\n");

    GPIO_setDirMode(SPI0_CS_BASE_ADDR, SPI0_CS_PIN, SPI0_CS_DIR);
    DebugP_log("SPI0_CS configured as output\r\n");

    GPIO_setDirMode(SPI1_CS_BASE_ADDR, SPI1_CS_PIN, SPI1_CS_DIR);
    DebugP_log("SPI1_CS configured as output\r\n");
}

void init_global_interrupts(Intr_objects *objects)
{
    init_interrupt(&objects->Gpio48HwiObject, &intr_pins.gpio48);
    DebugP_log("Initialized gpio48 interrupt\r\n");

    init_interrupt(&objects->Gpio44HwiObject, &intr_pins.gpio44);
    DebugP_log("Initialized gpio44 interrupt\r\n");

    init_interrupt(&objects->Gpio45HwiObject, &intr_pins.gpio45);
    DebugP_log("Initialized gpio45 interrupt\r\n");

    init_interrupt(&objects->Gpio46HwiObject, &intr_pins.gpio46);
    DebugP_log("Initialized gpio46 interrupt\r\n");

    init_interrupt(&objects->Gpio50HwiObject, &intr_pins.gpio50);
    DebugP_log("Initialized gpio50 interrupt\r\n");

    init_interrupt(&objects->Gpio51HwiObject, &intr_pins.gpio51);
    DebugP_log("Initialized gpio51 interrupt\r\n");

    init_interrupt(&objects->Gpio52HwiObject, &intr_pins.gpio52);
    DebugP_log("Initialized gpio52 interrupt\r\n");
}

void init_interrupt(HwiP_Object *intr_object, Pin_parameters *pin)
{
    GPIO_setDirMode(pin->base_address, pin->pin_num, pin->dir);

    HwiP_Params hwiPrms;
    HwiP_Params_init(&hwiPrms);
    int32_t retVal;

    hwiPrms.intNum = pin->int_num;
    hwiPrms.callback = &GPIO_bankIsrFxn;
    hwiPrms.args = pin;
    hwiPrms.isPulse = FALSE;
    retVal = HwiP_construct(intr_object, &hwiPrms);
    DebugP_assert(retVal == SystemP_SUCCESS);
}

void digitalWrite(uint32_t base_address, uint32_t pin, bool value)
{
    switch (pin)
    {
        case GPIO53_PIN:
            add_log(value ? PIN_HIGH : PIN_LOW, GPIO53);
            break;
        
        case GPIO54_PIN:
            add_log(value ? PIN_HIGH : PIN_LOW, GPIO54);
            break;
            
        case GPIO123_PIN:
            add_log(value ? PIN_HIGH : PIN_LOW, GPIO123);
            break;
            
        case GPIO136_PIN:
            add_log(value ? PIN_HIGH : PIN_LOW, GPIO136);
            break;
            
        case GPIO126_PIN:
            add_log(value ? PIN_HIGH : PIN_LOW, GPIO126);
            break;
            
        case GPIO127_PIN:
            add_log(value ? PIN_HIGH : PIN_LOW, GPIO127);
            break;
    }

    if (value)
    {
        GPIO_pinWriteHigh(base_address, pin);
    }
    else
    {
        GPIO_pinWriteLow(base_address, pin);
    }
}


