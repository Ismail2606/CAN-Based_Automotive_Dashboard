
#include <xc.h>
#include <string.h>
#include "message_handler.h"
#include "msg_id.h"
#include "can.h"
#include "clcd.h"

unsigned int delay = 0;
uint16_t msg_id, len;
char buff[4], data[5], ind, i;

volatile unsigned char led_state = LED_OFF, status = e_ind_off;


void handle_speed_data(uint8_t *data, uint8_t len)
{
    //Implement the speed function
//    clcd_print("S : ", LINE1(8));
//    clcd_print(data, LINE1(12));
}

void handle_gear_data(uint8_t *data, uint8_t len) 
{
    //Implement the gear function
//    clcd_print("G : ", LINE1(0));
//    clcd_print(data, LINE1(4));
}

void handle_rpm_data(uint8_t *data, uint8_t len) 
{
    //Implement the rpm function
//    clcd_print("R : ", LINE2(8));
//    clcd_print(data, LINE2(12));
}

void handle_engine_temp_data(uint8_t *data, uint8_t len) 
{
    //Implement the temperature function
}

void handle_indicator_data(uint8_t *data, uint8_t len) 
{
    //Implement the indicator function
}

void process_canbus_data() 
{   
 
}