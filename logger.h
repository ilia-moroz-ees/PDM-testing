#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>
#include <kernel/dpl/DebugP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/adc.h>
#include <drivers/gpio.h>
#include <drivers/hw_include/tistdtypes.h>
#include <drivers/mcspi.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include "board.h"
#include "ADS_adc.h"
#include "int_adc.h"

#define MAX_LOG_ENTRY_NUMBER 200

typedef struct
{
    uint64_t timestamp;
    uint16_t event_id;
    uint8_t event_type;
    uint16_t pin;
    
} LogEntry;

enum EVENT_TYPE 
{
    FAULT,
    PIN_HIGH,
    PIN_LOW
};

enum PIN
{
    GPIO44,
    GPIO45,
    GPIO46,
    GPIO48,
    GPIO49,
    GPIO50,
    GPIO51,
    GPIO52,
    GPIO53,
    GPIO54,
    GPIO123,
    GPIO136,
    GPIO126,
    GPIO127
};

LogEntry logs[MAX_LOG_ENTRY_NUMBER];
extern uint16_t logs_length;
static uint16_t last_printed_index = 0;

void add_log(uint16_t event_type, uint16_t pin);
void print_log(uint16_t log_number);
void print_logs();
void print_pending_logs();
void clear_logs();


#endif