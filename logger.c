#include "logger.h"

uint16_t logs_length = 0;

void add_log(uint16_t event_type, uint16_t pin)
{
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
        case FAULT:      event_str = "FAULT"; break;
        case PIN_HIGH:  event_str = "HIGH"; break;
        case PIN_LOW:   event_str = "LOW"; break;
        default:        event_str = "UNKNOWN"; break;
    }
    if (log.pin >= GPIO43 && log.pin <= GPIO52 && log.event_type == FAULT)
    {
        fault_str = " [FAULT TRIGGER]";
    }

    const char* pin_str = "UNKNOWN_PIN";
    switch (log.pin)
    {
        case GPIO43:   pin_str = "GPIO43"; break;
        case GPIO44:   pin_str = "GPIO44"; break;
        case GPIO45:   pin_str = "GPIO45"; break;
        case GPIO46:   pin_str = "GPIO46"; break;
        case GPIO51:   pin_str = "GPIO51"; break;
        case GPIO52:   pin_str = "GPIO52"; break;
        case GPIO53:   pin_str = "GPIO53"; break;
        case GPIO54:   pin_str = "GPIO54"; break;
        case GPIO123:  pin_str = "GPIO123"; break;
        case GPIO136:  pin_str = "GPIO136"; break;
        case GPIO126:  pin_str = "GPIO126"; break;
        case GPIO127:  pin_str = "GPIO127"; break;
    }

    DebugP_log("[%llu] %s: %s -> %s%s\r\n", 
               log.timestamp,
               pin_str,
               event_str,
               (log.event_type == FAULT) ? "Triggered" : "Set to",
               fault_str);
    DebugP_log("----------------------------\r\n");
}

void print_logs()
{
    for (uint16_t i = 0; i < logs_length; i++)
    {
        print_log(i);
    }
}