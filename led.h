#ifndef LED_H
#define LED_H

#define LED_PORT                PORTB
#define LED_PORT_DDR            TRISB

#define LEFT_IND                0X03
#define RIGHT_IND               0XC0
#define OFF                     0X

void init_led(void);
#endif