#include "i2c_helper.h"

void i2c_read_error_handler(int32_t status)
{
    switch(status)
    {
        case I2C_STS_ERR:
            DebugP_logError("[I2C]: Generic error occurred");
            break;
        case I2C_STS_ERR_TIMEOUT:
            DebugP_logError("[I2C]: Timeout error occurred");
            break;
        case I2C_STS_ERR_NO_ACK:
            DebugP_logError("[I2C]: No acknowledgement received");
            break;
        case I2C_STS_ERR_ARBITRATION_LOST:
            DebugP_logError("[I2C]: Arbitration lost");
            break;
        case I2C_STS_ERR_BUS_BUSY:
            DebugP_logError("[I2C]: Bus Busy error occurred");
            break;
    }
    return;
}