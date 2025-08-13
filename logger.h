#ifndef LOGGER_H
#define LOGGER_H

// This file contains all the variables and functions related to logging events

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

// Maximum number of logs we can store
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

// Array of logs. If this overflows, need to clear it.
LogEntry logs[MAX_LOG_ENTRY_NUMBER];
extern uint16_t logs_length;

// Variable for storing the last printed log
static uint16_t last_printed_index = 0;

// Add log entry to the logs array
void add_log(uint16_t event_type, uint16_t pin);

// Print particular log
void print_log(uint16_t log_number);

// Prints every log
void print_logs();

// Print logs that haven't been printed yet
void print_pending_logs();

// Clear the logs array
void clear_logs();


#endif