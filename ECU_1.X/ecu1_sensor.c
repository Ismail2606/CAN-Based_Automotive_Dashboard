

#include "ecu1_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"
uint16_t get_speed()
{
    return (uint16_t)(read_adc(CHANNEL4) / 10.23);
    // Implement the speed function
}

unsigned char get_gear_pos()
{
    static unsigned char gear = 'N';
    // Implement the gear function
    unsigned char key;
    key = read_digital_keypad(STATE_CHANGE);
    if(key == SWITCH1) {
        // increment gear
        if(gear == 'R' || gear == 'N')
            gear = '1';
        else if(gear < '5')
            gear++;
    }
    else if(key == SWITCH2) {
        // decrement gear
        if(gear > '1' && gear != 'R' && gear != 'N')
            gear--;
    }
    else if(key == SWITCH3)
        // reverse
        gear = 'R';
    else if(key == SWITCH4)
        // nuatral
        gear = 'N';
    
    return gear;
}