#include "pmic.h"



void pmic_init()
{
    uint8_t val = (uint8_t)0;

    handle = PMIC_getCoreHandle(CONFIG_PMIC0);
    DebugP_assert(NULL != handle);

    //Unlock PMIC registers if locked
    Pmic_getRegLockState(handle, &val);
}

int32_t pmic_write_reg(uint16_t regAddr, uint8_t txData)
{
    int32_t status = Pmic_ioTxByte(handle, regAddr, txData);

    ClockP_usleep(SLEEP_TIME_U);
    return status;
}


int32_t pmic_read_reg(uint16_t regAddr, uint8_t *rxBuffer)
{
    int32_t status = Pmic_ioRxByte(handle, regAddr, rxBuffer);

    ClockP_usleep(SLEEP_TIME_U);
    return status;
}