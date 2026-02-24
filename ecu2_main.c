

#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"
#include "led.h"
#include "ssd.h"
#include<stdio.h>
#define _XTAL_FREQ 2000000

void init_config(void) {
    init_adc();
    init_digital_keypad();
    init_uart();
    init_led();
    init_can();
}
int main()
{
    //call the functions
    init_config();
    uint16_t rpm, i = 0;
    uint8_t len; 
    unsigned char ind;
    unsigned int delay = 0;
    char buff[5];
    while(1) {
        rpm = get_rpm();
        ind = process_indicator();
        if(rpm >= 0 && rpm <= 9) len = 1;
        else if(rpm >= 10 && rpm <= 99) len = 2;
        else if(rpm >= 100 && rpm <= 999) len = 3;
        else if(rpm >= 1000 && rpm <= 6000) len = 4;
        sprintf(buff, "%hd", rpm);
        
        can_transmit(RPM_MSG_ID, buff, len);
        __delay_ms(80);
        can_transmit(INDICATOR_MSG_ID, &ind, 1);
        __delay_ms(80);
        
        
        if(delay++ == 10) {
            if(ind == '0')
                LED_PORT &= 0X3C;
            else if(ind == '1') {
                if(i++ == 0)
                    LED_PORT = 0X03;
            }
            else if(ind == '2') {
                if(i++ == 0)
                    LED_PORT = 0XC0;
            }
            else if(ind == '4') {
                if(i++ == 0)
                    LED_PORT = 0XC3;
            }
            if(i == 2)
                LED_PORT &= 0X3C;
            if(i == 2)
                i = 0;
            delay = 0;
        }
        
    }
}