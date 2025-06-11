#include "ADS_adc.h"

#define SLEEP_TIME 1000 * 200

#define ADS7953_CMD(channel)                                                   \
  (0x1000 | ((channel & 0x0F)                                                  \
             << 7)) // MACRO for generating a command for ADC in Manual Mode

const float EXT_ADC_VREF = 2.5f;            // Reference ADC Voltage
const float EXT_ADC_RESOLUTION = 4095.0f;   // 12 bit resolution
const float CURRENT_SCALE_HSS_MB = 0.108f;  // Voltage to Current Conversion factor HSS MB
const float CURRENT_SCALE_TPS = 0.383f;     // Voltage to Current Conversion factor TPS1HTC30EVM

ADS_ADC ext_adc0 = {
  .spi_handle = NULL,
  .spi_instance = SPI0,
  .channel = 0,
  .cs_base = SPI0_CS_BASE_ADDR,
  .cs_pin = SPI0_CS_PIN,
  .resolution = EXT_ADC_RESOLUTION,
  .vref = EXT_ADC_VREF
}; // SPI0

ADS_ADC ext_adc1 = {
  .spi_handle = NULL,
  .spi_instance = SPI1,
  .channel = 0,
  .cs_base = SPI1_CS_BASE_ADDR,
  .cs_pin = SPI1_CS_PIN,
  .resolution = EXT_ADC_RESOLUTION,
  .vref = EXT_ADC_VREF
}; // SPI1

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

uint16_t read_ext_ADC(ADS_ADC *adc, uint8_t channel) {
  uint16_t command = ADS7953_CMD(channel);

  SPI_ReadWrite(adc, command); // Since response comes only in the third package,
                               // doing 2 empty reads
  SPI_ReadWrite(adc, command);
  return SPI_ReadWrite(adc, command); // here reading actual data
}

float ext_adc_to_voltage(uint16_t raw_adc) {
  return ((float)raw_adc / EXT_ADC_RESOLUTION) * EXT_ADC_VREF;
}

float adc_to_current_HSS_MB(uint16_t raw_adc) {
  return ext_adc_to_voltage((float)raw_adc) / CURRENT_SCALE_HSS_MB;
}

float adc_to_current_TPS(uint16_t raw_adc) {
  return ext_adc_to_voltage((float)raw_adc) / CURRENT_SCALE_TPS;
}
