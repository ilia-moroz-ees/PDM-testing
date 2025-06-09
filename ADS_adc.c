#include "ADS_adc.h"

#define SLEEP_TIME 1000 * 200

#define ADS7953_CMD(channel)                                                   \
  (0x1000 | ((channel & 0x0F)                                                  \
             << 7)) // MACRO for generating a command for ADC in Manual Mode

const float VREF = 2.5f;           // Reference ADC Voltage
const float ADC_RESOLUTION = 4095.0f; // 12 bit resolution
const float CURRENT_SCALE_CH0 =
    0.108f; // Voltage to Current Conversion factor CH0
const float CURRENT_SCALE_CH1 =
    0.383f; // Voltage to Current Conversion factor CH1
const float DISCREPANCY = 0.1;


uint16_t SPI_ReadWrite(ADS_ADC *adc, uint16_t data) {
//   adc->spi_handle = gMcspiHandle[adc->spi_instance];
  MCSPI_Transaction spiTransaction;
  uint16_t txData = data;
  uint16_t rxData = 0;

  MCSPI_Transaction_init(&spiTransaction);
  spiTransaction.channel = adc->channel;
  spiTransaction.dataSize = 16;    // 16-bit for ADS7953
  spiTransaction.csDisable = true; // Manual Control CS
  spiTransaction.count = 1;
  spiTransaction.txBuf = (void *)&txData;
  spiTransaction.rxBuf = (void *)&rxData;
  spiTransaction.args = NULL;

  GPIO_pinWriteLow(adc->cs_base, adc->cs_pin);

  if (MCSPI_transfer(adc->spi_handle, &spiTransaction) != SystemP_SUCCESS) {
    DebugP_log("SPI transfer failed!\r\n");
    return 0xFFFF; // Error value
  }

  GPIO_pinWriteHigh(adc->cs_base, adc->cs_pin);

  return rxData & 0x0FFF; // Getting the value from the package
}

uint16_t readADC(ADS_ADC *adc, uint8_t channel) {
  uint16_t command = ADS7953_CMD(channel);

  SPI_ReadWrite(adc, 24); // Since response comes only in the third package,
                          // doing 2 empty reads

  SPI_ReadWrite(adc, 24);

  return SPI_ReadWrite(adc, 24); // here reading actual data
}

float adc_to_voltage(uint16_t raw_adc) {
  return ((float)raw_adc / ADC_RESOLUTION) * VREF;
}

float adc_to_current_ch0(uint16_t voltage) {
  return adc_to_voltage((float)voltage) / CURRENT_SCALE_CH0;
}

float adc_to_current_ch1(uint16_t voltage) {
  return adc_to_voltage((float)voltage) / CURRENT_SCALE_CH1;
}

// void read_values(ADS_ADC *adc, float *ch0, float *ch1, bool *gpio44_value,
//                  bool *gpio46_value) {
//   *ch0 = adc_to_current_ch0(readADC(adc, 0));
//   *ch1 = adc_to_current_ch1(readADC(adc, 1));
//   *gpio44_value = GPIO_pinRead(GPIO44_BASE_ADDR, GPIO44_PIN);
//   *gpio46_value = GPIO_pinRead(GPIO46_BASE_ADDR, GPIO46_PIN);
// }

// Pass [amps] as ch0 and ch1 here
// bool check_test_values(float ch0, float ch1, bool gpio44_value,
//                        bool gpio46_value, float ch0_expected_value,
//                        float ch1_expected_value, bool gpio44_expected_value,
//                        bool gpio46_expected_value) {

//   if (fabs(ch1 - ch1_expected_value) > DISCREPANCY) {
//     DebugP_log("Unexpected value in ADC_CH1\r\n");
//     return false;
//   }

//   if (fabs(ch0 - ch0_expected_value) > DISCREPANCY) {
//     DebugP_log("Unexpected value in ADC_CH0\r\n");
//     return false;
//   }

//   if (gpio44_value != gpio44_expected_value) {
//     DebugP_log("Unexpected value in GPIO44\r\n");
//     return false;
//   }

//   if (gpio46_value != gpio46_expected_value) {
//     DebugP_log("Unexpected value in GPIO46\r\n");
//     return false;
//   }

//   return true;
// }