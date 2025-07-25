#include "BQ25856.h"

const BQ25856_Reg bq25856_registers[BQ25856_REG_NUM] = {
    /* Charge Voltage and Current Control */
    {BQ25856_CHARGE_VOLTAGE_LIMIT_REG, 2},
    {BQ25856_CHARGE_CURRENT_LIMIT_REG, 2},
    {BQ25856_INPUT_CURRENT_DPM_LIMIT_REG, 2},
    {BQ25856_INPUT_VOLTAGE_DPM_LIMIT_REG, 2},
    {BQ25856_REVERSE_MODE_INPUT_CURRENT_LIMIT_REG, 2},
    {BQ25856_REVERSE_MODE_INPUT_VOLTAGE_LIMIT_REG, 2},
    {BQ25856_PRECHARGE_CURRENT_LIMIT_REG, 2},
    {BQ25856_TERMINATION_CURRENT_LIMIT_REG, 2},
    {BQ25856_PRECHARGE_TERMINATION_CONTROL_REG, 1},
    {BQ25856_TIMER_CONTROL_REG, 1},
    {BQ25856_CHARGER_CONTROL_REG, 1},
    {BQ25856_PIN_CONTROL_REG, 1},
    {BQ25856_POWER_PATH_REVERSE_MODE_CONTROL_REG, 1},
    {BQ25856_FREQUENCY_DITHER_CONTROL_REG, 1},
    {BQ25856_TS_CHARGING_THRESHOLD_CONTROL_REG, 1},
    {BQ25856_TS_CHARGING_REGION_BEHAVIOR_CONTROL_REG, 1},
    {BQ25856_TS_REVERSE_MODE_THRESHOLD_CONTROL_REG, 1},
    {BQ25856_REVERSE_UNDERVOLTAGE_CONTROL_REG, 1},

    /* Status Registers */
    {BQ25856_CHARGER_STATUS_1_REG, 1},
    {BQ25856_CHARGER_STATUS_2_REG, 1},
    {BQ25856_CHARGER_STATUS_3_REG, 1},
    {BQ25856_FAULT_STATUS_REG, 1},
    {BQ25856_CHARGER_FLAG_1_REG, 1},
    {BQ25856_CHARGER_FLAG_2_REG, 1},
    {BQ25856_FAULT_FLAG_REG, 1},
    {BQ25856_CHARGER_MASK_1_REG, 1},
    {BQ25856_CHARGER_MASK_2_REG, 1},
    {BQ25856_FAULT_MASK_REG, 1},

    /* ADC Registers */
    {BQ25856_ADC_CONTROL_REG, 1},
    {BQ25856_ADC_CHANNEL_CONTROL_REG, 1},
    {BQ25856_IAC_ADC_REG, 2},
    {BQ25856_IBAT_ADC_REG, 2},
    {BQ25856_VAC_ADC_REG, 2},
    {BQ25856_VBAT_ADC_REG, 2},
    {BQ25856_TS_ADC_REG, 2},
    {BQ25856_VFB_ADC_REG, 2},

    /* Gate Driver Control */
    {BQ25856_GATE_DRIVER_STRENGTH_CONTROL_REG, 1},
    {BQ25856_GATE_DRIVER_DEAD_TIME_CONTROL_REG, 1},

    /* Part Info and Misc */
    {BQ25856_PART_INFORMATION_REG, 1},
    {BQ25856_REVERSE_MODE_BATTERY_DISCHARGE_CURRENT_REG, 1}
};

int32_t BQ25856_read_reg(uint8_t register_addr, uint8_t length, uint16_t* result)
{
    if (length != 1 && length != 2) // Making sure buffers don't overflow
    {
        return I2C_STS_ERR; // Invalid length
    }
    I2C_Transaction i2cTransaction;
    I2C_Handle i2cHandle;

    i2cHandle = gI2cHandle[I2C1];

    uint8_t tx_buffer[BQ25856_REG_ADDR_LEN];

    I2C_Transaction_init(&i2cTransaction);
    // First, writing the register address we want to read 
    tx_buffer[0] = register_addr;
    i2cTransaction.writeBuf = tx_buffer;
    i2cTransaction.writeCount = BQ25856_REG_ADDR_LEN;
    i2cTransaction.targetAddress = BQ25856_ADDR;

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
    i2cTransaction.targetAddress = BQ25856_ADDR;
    
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

int32_t BQ25856_write_reg(uint8_t register_addr, uint8_t length, uint16_t data)
{
    if (length != 1 && length != 2) // Making sure buffers don't overflow
    {
        return I2C_STS_ERR; // Invalid length
    }
    I2C_Transaction i2cTransaction;
    I2C_Handle i2cHandle;

    i2cHandle = gI2cHandle[I2C1];

    uint8_t tx_buffer[BQ25856_REG_ADDR_LEN + length];

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
    i2cTransaction.writeCount = BQ25856_REG_ADDR_LEN + length;
    i2cTransaction.targetAddress = BQ25856_ADDR;

    int32_t status = I2C_transfer(i2cHandle, &i2cTransaction);

    if (status != I2C_STS_SUCCESS)
    {
        i2c_read_error_handler(status);
    }

    return status;
}

void BQ25856_read_faults()
{
    uint16_t fault24, fault27;
    BQ25856_read_reg(BQ25856_FAULT_STATUS_REG, 1, &fault27);
    BQ25856_read_reg(BQ25856_FAULT_FLAG_REG, 1, &fault24);

    if (!fault24 && !fault27)
    {
        DebugP_log("No faults detected\r\n");
    }

    for (uint8_t i = 0; i < 8; i++)
    {
        if (fault24 & (1 << i) || fault27 & (1 << i))
        {
            switch (i)
            {
                case 1:
                    DebugP_log("DRV_SUP pin voltage is out of valid range\r\n");
                    break;

                case 2:
                    DebugP_log("Charge safety timer expired\r\n");
                    break;

                case 3:
                    DebugP_log("Device in thermal shutdown protection\r\n");
                    break;

                case 4:
                    DebugP_log("Device in Battery over-voltage protection\r\n");
                    break;

                case 5:
                    DebugP_log("Battery over-current detected\r\n");
                    break;

                case 6:
                    DebugP_log("Device in Input over-voltage protection\r\n");
                    break;

                case 7:
                    DebugP_log(" Device in Input under-voltage protectione\r\n");
                    break;
            }
        }
    }
}

void BQ25856_manual_register_read(void)
{
    uint8_t reg_addr = 0;
    uint8_t length = 0;
    uint16_t result = 0;
    int32_t status = 0;
    
    DebugP_log("\r\n");
    DebugP_log("[BQ25856] Manual Register Read - Initiated\r\n");
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
        DebugP_log("[BQ25856] Manual Register Read - Aborted\r\n");
        return;
    }
    
    DebugP_log("\r\nAttempting to read register 0x%02X (%u bytes)...\r\n", reg_addr, length);
    
    // Perform the register read
    status = BQ25856_read_reg(reg_addr, length, &result);
    
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
    
    DebugP_log("[BQ25856] Manual Register Read - Completed\r\n");
    DebugP_log("----------------------------------------\r\n");
}

void BQ25856_manual_register_write(void)
{
    uint8_t reg_addr = 0;
    uint8_t length = 0;
    uint16_t data = 0;
    int32_t status = 0;
    
    DebugP_log("\r\n");
    DebugP_log("[BQ25856] Manual Register Write - Initiated\r\n");
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
        DebugP_log("[BQ25856] Manual Register Write - Aborted\r\n");
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
            DebugP_log("[BQ25856] Manual Register Write - Aborted\r\n");
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
    status = BQ25856_write_reg(reg_addr, length, data);
    
    // Check operation status
    if (status != I2C_STS_SUCCESS)
    {
        DebugP_log("[ERROR] Write operation failed with status: %d\r\n", status);
    }
    else
    {
        DebugP_log("[SUCCESS] Register write complete\r\n");
    }

    // Double checking if register value was written successfully
    uint16_t readback_value;
    BQ25856_read_reg(reg_addr, length, &readback_value);
    if (readback_value != data)
    {
        DebugP_log("[WARNING] Write verification failed (expected: 0x%04X, read: 0x%04X)\r\n", data, readback_value);
    }
    
    DebugP_log("[BQ25856] Manual Register Write - Completed\r\n");
    DebugP_log("-----------------------------------------\r\n");
}

void BQ25856_print_register_dump(void)
{
    for (uint8_t i = 0; i < BQ25856_REG_NUM; i++)
    {
        uint16_t result;
        BQ25856_read_reg(bq25856_registers[i].address, bq25856_registers[i].length, &result);
        DebugP_log("Register 0x%04X: 0x%04X\r\n", bq25856_registers[i].address, result);
        ClockP_usleep(50*1000);
    }
}

void BQ25856_init(void)
{
    BQ25856_write_reg(BQ25856_CHARGE_CURRENT_LIMIT_REG, 2, 0x30); // Charging limit specified in Polarion
    BQ25856_write_reg(BQ25856_REVERSE_MODE_INPUT_VOLTAGE_LIMIT_REG, 2, 0x12C0); // 24V Reverse mode
    BQ25856_write_reg(BQ25856_PRECHARGE_TERMINATION_CONTROL_REG, 1, 0x06); // Disabling EN_PRECHG and EN_TERM
    BQ25856_write_reg(BQ25856_TIMER_CONTROL_REG, 1, 0x05); // Disabling watchdog, enable EN_CHG_TMR 
    BQ25856_write_reg(BQ25856_POWER_PATH_REVERSE_MODE_CONTROL_REG, 1, 0x03); // Enabling Auto Reverse Mode
    BQ25856_write_reg(BQ25856_REVERSE_UNDERVOLTAGE_CONTROL_REG, 1, 0x03); // Set minimum voltage of the capacitor to 3.3V
    BQ25856_write_reg(BQ25856_CHARGER_MASK_1_REG, 1, 0x75); // Disable interrupts in charger mask 1
    BQ25856_write_reg(BQ25856_CHARGER_MASK_2_REG, 1, 0x92); // Disable interrupts in charger mask 2
    BQ25856_write_reg(BQ25856_FAULT_MASK_REG, 1, 0xFE); // Disable fault interrupts
}
