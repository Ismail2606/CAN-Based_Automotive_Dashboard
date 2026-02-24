
#include <xc.h>
#include <stdint.h>
#include "can.h"
#include "clcd.h"
#include "msg_id.h"
#include "message_handler.h"
#include "timer0.h"
#include "uart.h"
#define _XTAL_FREQ 2000000

static void init_leds(void) {
    TRISB = 0x08; // Set RB2 as output, RB3 as input, remaining as output
    PORTB = 0x00;
}

static void init_config(void) {
    // Initialize CLCD and CANBUS
    init_clcd();
    init_can();
    init_leds();

    // Enable Interrupts
    PEIE = 1;
    GIE = 1;
    init_timer0();
}

void print_ind(char ch) {
    if(ch == '0')
        clcd_print("OFF",LINE2(4));
    else if(ch == '1')
        clcd_print("<- ",LINE2(4));
    else if(ch == '2')
        clcd_print("-> ",LINE2(4));
    else if(ch == '4')
        clcd_print("!  ",LINE2(4));
}
void main(void) {
    // Initialize peripherals
    init_config();
    unsigned int delay = 0;
    uint16_t msg_id, len;
    char data[5], ind, i;
    /* ECU1 main loop */
    while (1) {
        can_receive(&msg_id, data, &len);
        __delay_ms(80);
        data[len] = '\0';
        clcd_print("G : ", LINE1(0));
        clcd_print("S : ", LINE1(8));
        clcd_print("I : ", LINE2(0));
        clcd_print("R : ", LINE2(8));
        
        if(msg_id == SPEED_MSG_ID) {
            clcd_print("  ", LINE1(12+len));
            clcd_print(data, LINE1(12));
        }
        else if(msg_id == GEAR_MSG_ID) clcd_print(data, LINE1(4));
        else if(msg_id == RPM_MSG_ID) {
            clcd_print("   ", LINE2(12+len));
            clcd_print(data, LINE2(12));
        }
        else if(msg_id == INDICATOR_MSG_ID) {
            print_ind(data[0]);
            ind = data[0];
        }
        
        if(delay++ == 20) {
            if(ind == '0')
                PORTB = 0X00;
            else if(ind == '1') {
                if(i++ == 0)
                    PORTB = 0X03;
            }
            else if(ind == '2') {
                if(i++ == 0)
                    PORTB = 0XC0;
            }
            else if(ind == '4') {
                if(i++ == 0)
                    PORTB = 0XC3;
            }
            if(i == 2)
                PORTB = 0X00;
            if(i == 2)
                i = 0;
            delay = 0;
        }
    }

    return;
}