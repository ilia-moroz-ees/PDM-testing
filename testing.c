#include "testing.h"

const float VOLTAGE_TOLERANCE = 0.1f;
const float CURRENT_TOLERANCE = 0.1f;

const TestCase test_cases[TESTS_NUMBER] = {
    {0, 0, 0, 0, 0},
    {1,0,0,1,0}
};

const TestResult test_results[TESTS_NUMBER] = {
    {{0, 1.8699}, {0, 1.8699}, {0, 1.8699}, {0, 0}, {0, 0}},
    {{4, 1.8699}, {0, 1.8699}, {0, 1.8699}, {4, 24}, {0, 0}}
};

void conduct_test(uint8_t test_number)
{
    if (test_number >= TESTS_NUMBER)
    {
        DebugP_logError("Invalid test number");
        return;
    }

    TestCase test_case = test_cases[test_number];
    TestResult expected = test_results[test_number];

    // Set GPIOs according to the test case
    digitalWrite(GPIO53_BASE_ADDR, GPIO53_PIN, test_case.GPIO53_en);
    digitalWrite(GPIO54_BASE_ADDR, GPIO54_PIN, test_case.GPIO54_en);
    digitalWrite(GPIO127_BASE_ADDR, GPIO127_PIN, test_case.GPIO127_en);
    digitalWrite(GPIO126_BASE_ADDR, GPIO126_PIN, test_case.GPIO126_en);
    digitalWrite(GPIO123_BASE_ADDR, GPIO123_PIN, test_case.GPIO123_en);

    print_pending_logs();

    // Allow settling time
    ClockP_sleep(1);
    
    // Take measurements
    TestResult actual;
    
    // Measure ideal diodes
    // actual.ideal_diode1.imon = adc_to_current_ch0(read_ext_ADC(&adc0, 0));
    // actual.ideal_diode1.vfb = adc_to_voltage(read_int_ADC(2));
    
    // actual.ideal_diode2.imon = adc_to_current_ch0(read_ext_ADC(&adc0, 1));
    // actual.ideal_diode2.vfb = adc_to_voltage(read_int_ADC(3));
    
    // actual.ideal_diode3.imon = adc_to_current_ch1(read_ext_ADC(&adc1, 0));
    // actual.ideal_diode3.vfb = adc_to_voltage(read_int_ADC(4));
    
    // // Measure HSS MB
    // actual.hss_mb.i_sns = adc_to_current_ch1(read_ext_ADC(&adc1, 1));
    // actual.hss_mb.vout = adc_to_voltage(read_int_ADC(5));
    
    // // Measure TPS1HTC30
    // actual.tps1htc30.i_sns = adc_to_current_ch0(read_ext_ADC(&adc0, 2));
    // actual.tps1htc30.vout = adc_to_voltage(read_int_ADC(6));

    //========================Temporary test =================================
    actual.ideal_diode1.imon = 0;
    actual.ideal_diode1.vfb = 0;
    
    actual.ideal_diode2.imon = 0;
    actual.ideal_diode2.vfb = 0;
    
    actual.ideal_diode3.imon = 0;
    actual.ideal_diode3.vfb = 0;
    
    // Measure HSS MB
    actual.hss_mb.i_sns = 0;
    actual.hss_mb.vout = 0;
    
    // Measure TPS1HTC30
    actual.tps1htc30.i_sns = 0;
    actual.tps1htc30.vout = 0;  

    bool test_passed = true;
    // Comparing test results
    // Ideal diode 1
    if (fabs(actual.ideal_diode1.imon - expected.ideal_diode1.imon) > CURRENT_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE1 IMON: FAIL (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode1.imon, actual.ideal_diode1.imon);
        test_passed = false;
    }

    if (fabs(actual.ideal_diode1.vfb - expected.ideal_diode1.vfb) > VOLTAGE_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE1 VFB: FAIL (Expected %.2fV, Got %.2fV)\r\n", 
                  expected.ideal_diode1.vfb, actual.ideal_diode1.vfb);
        test_passed = false;
    }

    // Ideal Diode 2
    if (fabs(actual.ideal_diode2.imon - expected.ideal_diode2.imon) > CURRENT_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE2 IMON: FAIL (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode2.imon, actual.ideal_diode2.imon);
        test_passed = false;
    }

    if (fabs(actual.ideal_diode2.vfb - expected.ideal_diode2.vfb) > VOLTAGE_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE2 VFB: FAIL (Expected %.2fV, Got %.2fV)\r\n", 
                  expected.ideal_diode2.vfb, actual.ideal_diode2.vfb);
        test_passed = false;
    }

    // Ideal Diode 3
    if (fabs(actual.ideal_diode3.imon - expected.ideal_diode3.imon) > CURRENT_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE3 IMON: FAIL (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode3.imon, actual.ideal_diode3.imon);
        test_passed = false;
    }

    if (fabs(actual.ideal_diode3.vfb - expected.ideal_diode3.vfb) > VOLTAGE_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE3 VFB: FAIL (Expected %.2fV, Got %.2fV)\r\n", 
                  expected.ideal_diode3.vfb, actual.ideal_diode3.vfb);
        test_passed = false;
    }

    // HSS MB
    if(fabs(actual.hss_mb.i_sns - expected.hss_mb.i_sns) > CURRENT_TOLERANCE)
    {
        DebugP_log("  HSS MB I_SNS: FAIL (Expected %.2fA, Got %.2fA)\r\n",
                  expected.hss_mb.i_sns, actual.hss_mb.i_sns);
        test_passed = false;
    }

    if(fabs(actual.hss_mb.vout - expected.hss_mb.vout) > CURRENT_TOLERANCE)
    {
        DebugP_log("  HSS MB V_OUT: FAIL (Expected %.2fV, Got %.2fV)\r\n",
                  expected.hss_mb.vout, actual.hss_mb.vout);
        test_passed = false;
    }

    // TPS1HTC30
    if(fabs(actual.tps1htc30.i_sns - expected.tps1htc30.i_sns) > CURRENT_TOLERANCE)
    {
        DebugP_log("  TPS1HTC30 I_SNS: FAIL (Expected %.2fA, Got %.2fA)\r\n",
                  expected.tps1htc30.i_sns, actual.tps1htc30.i_sns);
        test_passed = false;
    }

    if(fabs(actual.tps1htc30.vout - expected.tps1htc30.vout) > CURRENT_TOLERANCE)
    {
        DebugP_log("  TPS1HTC30 V_OUT: FAIL (Expected %.2fV, Got %.2fV)\r\n",
                  expected.tps1htc30.vout, actual.tps1htc30.vout);
        test_passed = false;
    }

    // Final test result
    if(test_passed)
    {
        DebugP_log("\r\nTEST %d PASSED\r\n", test_number);
    }
    else
    {
        DebugP_log("\r\nTEST %d FAILED\r\n", test_number);
    }

}