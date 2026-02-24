

#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"
#include "dkp.h"

uint16_t get_rpm()
{
    //Implement the rpm function
    return (read_adc(CHANNEL4) / 0.1705);
}

uint16_t get_engine_temp()
{
    //Implement the engine temperature function
}

unsigned char process_indicator()
{
    //Implement the indicator function
    static unsigned char ind = '0';
    unsigned char key = read_digital_keypad(STATE_CHANGE);
    if(key == SWITCH1)
        ind = '1';
    else if(key == SWITCH2)
        ind = '2';
    else if(key == SWITCH3)
        ind = '0';
    else if(key == SWITCH4)
        ind = '4';
    return ind;
}