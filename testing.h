#ifndef TESTING_H
#define TESTING_H
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
#include "logger.h"

#define TESTS_NUMBER 30

extern const float VOLTAGE_TOLERANCE;
extern const float CURRENT_TOLERANCE;

typedef struct 
{
    bool GPIO53_en;
    bool GPIO54_en;
    bool GPIO127_en;
    bool GPIO126_en;
    bool GPIO123_en;
} TestCase;

typedef struct
{
    float imon;
    float vfb;
} LM74930;

typedef struct
{
    float i_sns;
    float vout;
} HSS_MB;

typedef struct
{
    float i_sns;
    float vout;
} TPS1HTC30;

typedef struct
{
    LM74930 ideal_diode1;
    LM74930 ideal_diode2;
    LM74930 ideal_diode3;
    HSS_MB hss_mb;
    TPS1HTC30 tps1htc30;

} TestResult;


extern const TestCase test_cases[TESTS_NUMBER];
extern const TestResult test_results[TESTS_NUMBER];

void conduct_test(uint8_t test_number);


#endif