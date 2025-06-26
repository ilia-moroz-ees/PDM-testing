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

    uint8_t tx_buffer[BQ25751_REG_ADDR_LEN + length];

    I2C_Transaction_init(&i2cTransaction);
    // First, writing the register address we want to read 
    tx_buffer[0] = register_addr;

    switch (length) // depending on the length of the register (1 or 2 bytes)
    {
        case 1:
            tx_buffer[1] = (uint8_t)(data & 0xFF);
            break;

        case 2:
            tx_buffer[1] = (uint8_t)(data & 0xFF);
            tx_buffer[2] = (uint8_t)((data >> 8) & 0xFF);
            break;

        default:
            return I2C_STS_ERR;
    }

    i2cTransaction.writeBuf = tx_buffer;
    i2cTransaction.writeCount = BQ25751_REG_ADDR_LEN + length;
    i2cTransaction.targetAddress = BQ25751_ADDR;

    int32_t status = I2C_transfer(i2cHandle, &i2cTransaction);

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

void BQ25751_read_faults()
{
    uint16_t fault24, fault27;
    BQ25751_read_reg(0x27, 1, &fault27);
    BQ25751_read_reg(0x24, 1, &fault24);

    for (uint8_t i = 0; i < 8; i++)
    {
        if (fault24 & (1 << i) || fault27 & (1 << i))
        {
            switch (i)
            {
                case 1:
                    DebugP_log("DRV_SUP pin voltage is out of valid range\r\n");
                    break;

                case 3:
                    DebugP_log("Device in thermal shutdown protection\r\n");
                    break;

                case 4:
                    DebugP_log("Device in Battery over-voltage protection\r\n");
                    break;

                case 5:
                    DebugP_log("Device in Input over-voltage protection\r\n");
                    break;

                case 6:
                    DebugP_log("Device in Input over-voltage protection\r\n");
                    break;

                case 7:
                    DebugP_log(" Device in Input under-voltage protectione\r\n");
                    break;
            }
        }
        else {
            DebugP_log("No faults detected\r\n");
        }
    }
}

void BQ25751_manual_register_read(void)
{
    uint8_t reg_addr = 0;
    uint8_t length = 0;
    uint16_t result = 0;
    int32_t status = 0;
    
    DebugP_log("\r\n");
    DebugP_log("[BQ25751] Manual Register Read - Initiated\r\n");
    DebugP_log("----------------------------------------\r\n");
    
    // Get register address from user
    DebugP_log("Enter register address to read (hex format, e.g., 0x2B): ");
    DebugP_scanf("%hhx", &reg_addr);
    
    // Get data length from user
    DebugP_log("Enter data length (1 for 8-bit, 2 for 16-bit): ");
    DebugP_scanf("%hhu", &length);
    
    // Validate length input
    if (length != 1 && length != 2)
    {
        DebugP_log("[ERROR] Invalid length: %u. Must be 1 or 2.\r\n", length);
        DebugP_log("[BQ25751] Manual Register Read - Aborted\r\n");
        return;
    }
    
    DebugP_log("\r\nAttempting to read register 0x%02X (%u bytes)...\r\n", reg_addr, length);
    
    // Perform the register read
    status = BQ25751_read_reg(reg_addr, length, &result);
    
    // Check operation status
    if (status != I2C_STS_SUCCESS)
    {
        DebugP_log("[ERROR] Read operation failed with status: %d\r\n", status);
    }
    else
    {
        // Log successful read
        DebugP_log("[SUCCESS] Register read complete\r\n");
        DebugP_log("Register 0x%02X value: ", reg_addr);
        
        if (length == 2)
        {
            DebugP_log("0x%04X (16-bit)\r\n", result);
        }
        else
        {
            DebugP_log("0x%02X (8-bit)\r\n", (uint8_t)result);
        }
    }
    
    DebugP_log("[BQ25751] Manual Register Read - Completed\r\n");
    DebugP_log("----------------------------------------\r\n");
}

void BQ25751_manual_register_write(void)
{
    uint8_t reg_addr = 0;
    uint8_t length = 0;
    uint16_t data = 0;
    int32_t status = 0;
    
    DebugP_log("\r\n");
    DebugP_log("[BQ25751] Manual Register Write - Initiated\r\n");
    DebugP_log("-----------------------------------------\r\n");
    
    // Get register address from user
    DebugP_log("Enter register address to write (hex format, e.g., 0x2B): ");
    DebugP_scanf("%hhx", &reg_addr);
    
    // Get data length from user
    DebugP_log("Enter data length (1 for 8-bit, 2 for 16-bit): ");
    DebugP_scanf("%hhu", &length);
    
    // Validate length input
    if (length != 1 && length != 2)
    {
        DebugP_log("[ERROR] Invalid length: %u. Must be 1 or 2.\r\n", length);
        DebugP_log("[BQ25751] Manual Register Write - Aborted\r\n");
        return;
    }
    
    // Get data value from user
    if (length == 1)
    {
        DebugP_log("Enter 8-bit data value (hex format, e.g., 0x3F): ");
        DebugP_scanf("%hx", &data);
        
        // Ensure data fits in 8 bits
        if (data > 0xFF)
        {
            DebugP_log("[ERROR] Data value 0x%04X exceeds 8-bit range\r\n", data);
            DebugP_log("[BQ25751] Manual Register Write - Aborted\r\n");
            return;
        }
    }
    else
    {
        DebugP_log("Enter 16-bit data value (hex format, e.g., 0x1A3F): ");
        DebugP_scanf("%hx", &data);
    }
    
    DebugP_log("\r\nAttempting to write register 0x%02X with value 0x%04X (%u bytes)...\r\n", 
              reg_addr, data, length);
    
    // Perform the register write
    status = BQ25751_write_reg(reg_addr, length, data);
    
    // Check operation status
    if (status != I2C_STS_SUCCESS)
    {
        DebugP_log("[ERROR] Write operation failed with status: %d\r\n", status);
    }
    else
    {
        DebugP_log("[SUCCESS] Register write complete\r\n");
    }
    
    DebugP_log("[BQ25751] Manual Register Write - Completed\r\n");
    DebugP_log("-----------------------------------------\r\n");
}