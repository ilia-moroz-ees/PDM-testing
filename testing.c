#include "testing.h"

const float VOLTAGE_TOLERANCE = 0.1f;
const float CURRENT_TOLERANCE = 0.1f;

const TestCase test_cases[TESTS_NUMBER] = {
    // Reset, nothing enabled
    {0, 0, 0, 0, 0},
    // Test ID #1
    {1, 0, 0, 1, 0},
    // Test ID #2
    {0, 1, 0, 1, 0},
    // Test ID #3
    {0, 0, 1, 1, 0},
    // Test Having 2 enabled in parallel
    {1, 1, 0, 1, 0},
    // Force #2 to take load
    {1, 1, 0, 1, 0},
    // Force #1 to take load
    {1, 1, 0, 1, 0},
    // Tests loss of a power source
    {1, 1, 0, 1, 0},
    // Clear UVLO Fault from ID 1
    {0, 0, 0, 0, 0},
    // Test HSS Motherboard
    {1, 0, 0, 1, 0},
    // Test TPS1HTC30EVM
    {1, 0, 0, 0, 1},
    // Combined loads -> overcurrent fault
    {1, 0, 0, 1, 1},
    // Reset fault
    {0, 0, 0, 0, 0},
    // 2 Diodes Online
    {1, 1, 0, 0, 1},
    // 2 Diodes Heavy Load
    {1, 1, 0, 1, 1},
    // Reset faults
    {0, 0, 0, 0, 0},
    // Normal Operation through TPS1HTC30
    {1, 0, 0, 0, 1},
    // Short through TPS1HTC30
    {1, 0, 0, 0, 1},
    // Reset fault
    {0, 0, 0, 0, 0},
    // Normal through HSS-Motherboard
    {1, 0, 0, 1, 0},
    // Short through HSS Motherboard
    {1, 0, 0, 1, 0},
    // Reset Faults
    {0, 0, 0, 0, 0},
    // HSS-Motherboard and TPS1HTC30 Both Loading 1 Ideal diode
    {1, 0, 0, 1, 1},
    // Short HSS Motherboard
    {1, 0, 0, 1, 1},
    // Reset Faults
    {0, 0, 0, 0, 0},
    // HSS-Motherboard and TPS1HTC30 Both Loading 1 Ideal diode
    {1, 0, 0, 1, 1},
    // Short TPS1HTC30
    {1, 0, 0, 1, 1},
    // Reset Faults
    {0, 0, 0, 0, 0},
    // Test HSS Motherboard
    {1, 0, 0, 1, 0},
    // Test TPS1HTC30EVM
    {1, 0, 0, 0, 1}
};

const TestResult test_results[TESTS_NUMBER] = {
    // Reset, nothing enabled
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // Test ID #1
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {4, 24}, {0, 0}},
    // Test ID #2
    {{0, 0.47}, {4, 0.47}, {0, 0.47}, {4, 24}, {0, 0}},
    // Test ID #3
    {{0, 0.47}, {0, 0.47}, {4, 0.47}, {4, 24}, {0, 0}},
    // Test Having 2 enabled in parallel
    {{2, 0.47}, {2, 0.47}, {0, 0.47}, {4, 24}, {0, 0}},
    // Force #2 to take load
    {{0, 1.7141}, {4, 0.47}, {0, 0.47}, {4, 24}, {0, 0}},
    // Force #1 to take load
    {{4, 0.47}, {0, 1.7141}, {0, 0.47}, {4, 24}, {0, 0}},
    // Tests loss of a power source
    {{0, 0}, {4, 1.7141}, {0, 0.47}, {4, 22}, {0, 0}},
    // Clear UVLO Fault from ID 1
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // Test HSS Motherboard
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {4, 24}, {0, 0}},
    // Test TPS1HTC30EVM
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {4, 24}},
    // Combined loads -> overcurrent fault
    {{8, 0.47}, {0, 0.47}, {0, 0.47}, {4, 24}, {4, 24}},
    // Reset fault
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // 2 Diodes Online
    {{2, 0.47}, {2, 0.47}, {0, 0.47}, {0, 0}, {4, 24}},
    // 2 Diodes Heavy Load
    {{4, 0.47}, {4, 0.47}, {0, 0.47}, {4, 24}, {4, 24}},
    // Reset faults
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // Normal Operation through TPS1HTC30
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {4, 24}},
    // Short through TPS1HTC30
    {{10, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {10, 24}},
    // Reset fault
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // Normal through HSS-Motherboard
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {4, 24}, {0, 0}},
    // Short through HSS Motherboard
    {{10, 0.47}, {0, 0.47}, {0, 0.47}, {10, 24}, {0, 0}},
    // Reset Faults
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // HSS-Motherboard and TPS1HTC30 Both Loading 1 Ideal diode
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {1, 24}, {3, 24}},
    // Short HSS Motherboard
    {{13, 0.47}, {0, 0.47}, {0, 0.47}, {10, 24}, {3, 24}},
    // Reset Faults
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // HSS-Motherboard and TPS1HTC30 Both Loading 1 Ideal diode
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {3, 24}, {1, 24}},
    // Short TPS1HTC30
    {{13, 0.47}, {0, 0.47}, {0, 0.47}, {3, 24}, {10, 24}},
    // Reset Faults
    {{0, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {0, 0}},
    // Test HSS Motherboard
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {4, 24}, {0, 0}},
    // Test TPS1HTC30EVM
    {{4, 0.47}, {0, 0.47}, {0, 0.47}, {0, 0}, {4, 24}}
};

void conduct_test(uint8_t test_number)
{
    if (test_number >= TESTS_NUMBER)
    {
        DebugP_logError("Invalid test number\r\n");
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
    ClockP_sleep(2);
    
    // Take measurements
    TestResult actual;
    
    // Measure ideal diodes
    actual.ideal_diode1.imon = adc_to_current_LM74930(read_int_ADC(0));
    actual.ideal_diode1.vfb = int_adc_to_voltage(read_int_ADC(1));
    
    actual.ideal_diode2.imon = adc_to_current_LM74930(read_int_ADC(2));
    actual.ideal_diode2.vfb = int_adc_to_voltage(read_int_ADC(3));
    
    actual.ideal_diode3.imon = adc_to_current_LM74930(read_int_ADC(4));
    actual.ideal_diode3.vfb = int_adc_to_voltage(read_int_ADC(5));
    
    // Measure HSS MB
    actual.hss_mb.i_sns = adc_to_current_HSS_MB(read_ext_ADC(&ext_adc0, 0));
    // actual.hss_mb.vout = ext_adc_to_voltage(read_ext_ADC(&ext_adc0, 1));
    
    // Measure TPS1HTC30
    actual.tps1htc30.i_sns = adc_to_current_TPS(read_ext_ADC(&ext_adc1, 0));
    // actual.tps1htc30.vout = ext_adc_to_voltage(read_ext_ADC(&ext_adc1, 1));  

    bool test_passed = true;
    // Comparing test results
    // Ideal diode 1
    if (fabs(actual.ideal_diode1.imon - expected.ideal_diode1.imon) > CURRENT_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE1 IMON: FAIL (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode1.imon, actual.ideal_diode1.imon);
        test_passed = false;
    }
    else
    {
        DebugP_log("  IDEAL DIODE1 IMON: SUCCESS (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode1.imon, actual.ideal_diode1.imon);
    }

    if (fabs(actual.ideal_diode1.vfb - expected.ideal_diode1.vfb) > VOLTAGE_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE1 VFB: FAIL (Expected %.2fV, Got %.2fV)\r\n", 
                  expected.ideal_diode1.vfb, actual.ideal_diode1.vfb);
        test_passed = false;
    }
    else
    {
        DebugP_log("  IDEAL DIODE1 VFB: SUCCESS (Expected %.2fV, Got %.2fA)\r\n", 
                  expected.ideal_diode1.vfb, actual.ideal_diode1.vfb);
    }

    // Ideal Diode 2
    if (fabs(actual.ideal_diode2.imon - expected.ideal_diode2.imon) > CURRENT_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE2 IMON: FAIL (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode2.imon, actual.ideal_diode2.imon);
        test_passed = false;
    }
    else
    {
        DebugP_log("  IDEAL DIODE2 IMON: SUCCESS (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode2.imon, actual.ideal_diode2.imon);
    }

    if (fabs(actual.ideal_diode2.vfb - expected.ideal_diode2.vfb) > VOLTAGE_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE2 VFB: FAIL (Expected %.2fV, Got %.2fV)\r\n", 
                  expected.ideal_diode2.vfb, actual.ideal_diode2.vfb);
        test_passed = false;
    }
    else
    {
        DebugP_log("  IDEAL DIODE2 VFB: SUCCESS (Expected %.2fV, Got %.2fA)\r\n", 
                  expected.ideal_diode2.vfb, actual.ideal_diode2.vfb);
    }

    // Ideal Diode 3
    if (fabs(actual.ideal_diode3.imon - expected.ideal_diode3.imon) > CURRENT_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE3 IMON: FAIL (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode3.imon, actual.ideal_diode3.imon);
        test_passed = false;
    }
    else
    {
        DebugP_log("  IDEAL DIODE3 IMON: SUCCESS (Expected %.2fA, Got %.2fA)\r\n", 
                  expected.ideal_diode3.imon, actual.ideal_diode3.imon);
    }

    if (fabs(actual.ideal_diode3.vfb - expected.ideal_diode3.vfb) > VOLTAGE_TOLERANCE)
    {
        DebugP_log("  IDEAL DIODE3 VFB: FAIL (Expected %.2fV, Got %.2fV)\r\n", 
                  expected.ideal_diode3.vfb, actual.ideal_diode3.vfb);
        test_passed = false;
    }
    else
    {
        DebugP_log("  IDEAL DIODE3 VFB: SUCCESS (Expected %.2fV, Got %.2fA)\r\n", 
                  expected.ideal_diode3.vfb, actual.ideal_diode3.vfb);
    }

    // HSS MB
    if(fabs(actual.hss_mb.i_sns - expected.hss_mb.i_sns) > CURRENT_TOLERANCE)
    {
        DebugP_log("  HSS MB I_SNS: FAIL (Expected %.2fA, Got %.2fA)\r\n",
                  expected.hss_mb.i_sns, actual.hss_mb.i_sns);
        test_passed = false;
    }
    else
    {
        DebugP_log("  HSS MB I_SNS: SUCCESS (Expected %.2fA, Got %.2fA)\r\n",
                  expected.hss_mb.i_sns, actual.hss_mb.i_sns);
    }

    // Will be measured with multimeter
    // if(fabs(actual.hss_mb.vout - expected.hss_mb.vout) > CURRENT_TOLERANCE)
    // {
    //     DebugP_log("  HSS MB V_OUT: FAIL (Expected %.2fV, Got %.2fV)\r\n",
    //               expected.hss_mb.vout, actual.hss_mb.vout);
    //     test_passed = false;
    // }

    // TPS1HTC30
    if(fabs(actual.tps1htc30.i_sns - expected.tps1htc30.i_sns) > CURRENT_TOLERANCE)
    {
        DebugP_log("  TPS1HTC30 I_SNS: FAIL (Expected %.2fA, Got %.2fA)\r\n",
                  expected.tps1htc30.i_sns, actual.tps1htc30.i_sns);
        test_passed = false;
    }
    else
    {
        DebugP_log("  TPS1HTC30 I_SNS: SUCCESS (Expected %.2fA, Got %.2fA)\r\n",
                  expected.tps1htc30.i_sns, actual.tps1htc30.i_sns);
    }

    // will be measured with multimeter
    // if(fabs(actual.tps1htc30.vout - expected.tps1htc30.vout) > CURRENT_TOLERANCE)
    // {
    //     DebugP_log("  TPS1HTC30 V_OUT: FAIL (Expected %.2fV, Got %.2fV)\r\n",
    //               expected.tps1htc30.vout, actual.tps1htc30.vout);
    //     test_passed = false;
    // }

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