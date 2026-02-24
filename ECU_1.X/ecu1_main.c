
#include "adc.h"
#include "can.h"
#include "ecu1_sensor.h"
#include "msg_id.h"
#include "uart.h"
#include "ssd.h"
#include<stdio.h>
#define _XTAL_FREQ 2000000
void init_config(void) {
    init_adc();
    init_digital_keypad();
    init_uart();
    init_can();
//    init_ssd();
}
int main()
{
    //Call the functions
    init_config();
    uint16_t speed;
    uint8_t len;
    unsigned char gear;
    char buff[4],data[4];
    while(1) {
        speed = get_speed();
        gear =  get_gear_pos();
        if(gear == 'N' && speed > 0) speed = 0;
        else if(gear == '1' && speed > 20) speed = 20;
        else if(gear == '2' && speed > 40) speed = 40;
        else if(gear == '3' && speed > 60) speed = 60;
        else if(gear == '4' && speed > 80) speed = 80;
        if(speed >= 0 && speed <= 9) len = 1;
        else if(speed >= 10 && speed <= 99) len = 2;
        else if(speed == 100) len = 3;
        sprintf(buff, "%hd", speed);
        can_transmit(SPEED_MSG_ID, buff, len);
        __delay_ms(80);
        can_transmit(GEAR_MSG_ID, &gear, 1);
        __delay_ms(80);
    }
}