#include "BQ25751.h"

int32_t BQ25751_read_reg(uint8_t register_addr, uint8_t length, uint16_t* result)
{
    I2C_Transaction i2cTransaction;
    I2C_Handle i2cHandle;

    i2cHandle = gI2cHandle[I2C1];

    uint8_t tx_buffer[BQ25751_REG_ADDR_LEN];

    I2C_Transaction_init(&i2cTransaction);
    // First, writing the register address we want to read 
    tx_buffer[0] = register_addr;
    i2cTransaction.writeBuf = tx_buffer;
    i2cTransaction.writeCount = BQ25751_REG_ADDR_LEN;
    i2cTransaction.targetAddress = BQ25751_ADDR;

    int32_t status = I2C_transfer(i2cHandle, &i2cTransaction);

    if (status != I2C_STS_SUCCESS)
    {
        i2c_read_error_handler(i2cTransaction.status);
        return status;
    }

    // Second, Reading the register data
    I2C_Transaction_init(&i2cTransaction);
    uint8_t rx_buffer[length];

    i2cTransaction.writeBuf = NULL;
    i2cTransaction.writeCount = 0;
    i2cTransaction.readBuf = rx_buffer;
    i2cTransaction.readCount = length;
    i2cTransaction.targetAddress = BQ25751_ADDR;
    
    status = I2C_transfer(i2cHandle, &i2cTransaction);

    if (status == I2C_STS_SUCCESS)
    {
        switch (length) // register length, could be 1 or 2 bytes
        {
            case 1:
                *result = rx_buffer[0];
                break;
            
            case 2:
                *result = (rx_buffer[1] << 8) | rx_buffer[0];
                break;
        }
    }
    else
    {
        i2c_read_error_handler(status);
    }

    return status;
}

int32_t BQ25751_write_reg(uint8_t register_addr, uint8_t length, uint16_t data)
{
    I2C_Transaction i2cTransaction;
    I2C_Handle i2cHandle;

    i2cHandle = gI2cHandle[I2C1];

    uint8_t tx_reg_addr_buffer[BQ25751_REG_ADDR_LEN];

    I2C_Transaction_init(&i2cTransaction);
    // First, writing the register address we want to read 
    tx_reg_addr_buffer[0] = register_addr;
    i2cTransaction.writeBuf = tx_reg_addr_buffer;
    i2cTransaction.writeCount = BQ25751_REG_ADDR_LEN;
    i2cTransaction.targetAddress = BQ25751_ADDR;

    int32_t status = I2C_transfer(i2cHandle, &i2cTransaction);

    if (status != I2C_STS_SUCCESS)
    {
        i2c_read_error_handler(i2cTransaction.status);
        return status;
    }

    // Second, sending actual data
    I2C_Transaction_init(&i2cTransaction);
    uint8_t tx_data_buffer[length];
    switch (length) // depending on the length of the register (1 or 2 bytes)
    {
        case 1:
            tx_data_buffer[0] = (uint8_t)(data & 0xFF);
            break;

        case 2:
            tx_data_buffer[0] = (uint8_t)(data & 0xFF);
            tx_data_buffer[1] = (uint8_t)((data >> 8) & 0xFF);
            break;
    }
    
    i2cTransaction.writeBuf = tx_data_buffer;
    i2cTransaction.writeCount = length;
    i2cTransaction.targetAddress = BQ25751_ADDR;
    
    status = I2C_transfer(i2cHandle, &i2cTransaction);

    if (status != I2C_STS_SUCCESS)
    {
        i2c_read_error_handler(status);
    }

    return status;
}

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