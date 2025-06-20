#include "logger.h"

uint16_t logs_length = 0;

void add_log(uint16_t event_type, uint16_t pin)
{
    if (logs_length >= MAX_LOG_ENTRY_NUMBER)
    {
        DebugP_logWarn("Log buffer overflow, clearing the buffer\r\n");
        clear_logs();
    }
    LogEntry new_log = {
        .timestamp = ClockP_getTimeUsec(),
        .event_id = logs_length,
        .event_type = event_type,
        .pin = pin,
    };

    logs[logs_length] = new_log;
    ++logs_length;
}

void print_log(uint16_t log_number)
{
    if (logs_length == 0)
    {
        return;
    }

    if (log_number >= logs_length)
    {
        DebugP_log("Invalid log index: %d\r\n", log_number);
        return;
    }
    LogEntry log = logs[log_number];

    const char* event_str = "";
    const char* fault_str = "";
    
    // Determine event type string
    switch (log.event_type)
    {
        case FAULT:     event_str = "FAULT"; break;
        case PIN_HIGH:  event_str = "HIGH"; break;
        case PIN_LOW:   event_str = "LOW"; break;
        default:        event_str = "UNKNOWN"; break;
    }
    if (log.pin >= GPIO48 && log.pin <= GPIO52 && log.event_type == FAULT)
    {
        fault_str = " [FAULT TRIGGER]";
    }

    const char* pin_str = "UNKNOWN_PIN";
    switch (log.pin)
    {
        case GPIO48:   pin_str = "GPIO48 (Ideal Diode 1 nFLT)"; break;
        case GPIO44:   pin_str = "GPIO44 (Ideal Diode 2 nFLT)"; break;
        case GPIO45:   pin_str = "GPIO45 (Ideal Diode 3 nFLT)"; break;
        case GPIO46:   pin_str = "GPIO46 (HSS MB Fault)"; break;
        case GPIO51:   pin_str = "GPIO51 (TPS1HTC30 1 Fault)"; break;
        case GPIO52:   pin_str = "GPIO52 (TPS1HTC30 1 Fault)"; break;
        case GPIO53:   pin_str = "GPIO53 (Ideal Diode 1)"; break;
        case GPIO54:   pin_str = "GPIO54 (Ideal Diode 2)"; break;
        case GPIO123:  pin_str = "GPIO123 (TPS1HTC30 1)"; break;
        case GPIO136:  pin_str = "GPIO136(TPS1HTC30 2)"; break;
        case GPIO126:  pin_str = "GPIO126 (HSS MB)"; break;
        case GPIO127:  pin_str = "GPIO127 (Ideal Diode 3)"; break;
    }

    DebugP_log("[%llu] %s: %s -> %s%s\r\n", 
               log.timestamp,
               pin_str,
               event_str,
               (log.event_type == FAULT) ? "Triggered" : "Set",
               fault_str);
    DebugP_log("----------------------------\r\n");
}

void print_logs()
{
    if (logs_length == 0)
    {
        return;
    }

    for (uint16_t i = 0; i < logs_length; i++)
    {
        print_log(i);
    }
}

void clear_logs()
{
    logs_length = 0;
    last_printed_index = 0;
}

void print_pending_logs()
{
    if (last_printed_index >= logs_length) {
        DebugP_log("No new logs available\r\n");
        return;
    }

    DebugP_log("\r\n=== Pending Logs (%d new entries) ===\r\n", 
              logs_length - last_printed_index);

    for (uint16_t i = last_printed_index; i < logs_length; i++) {
        print_log(i); 
    }

    last_printed_index = logs_length;
}