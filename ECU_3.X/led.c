/*
 * File:   led.c
 * Author: Ajinkya
 *
 * Created on November 7, 2025, 3:16 PM
 */


#include <xc.h>
#include "led.h"

void init_led(void) {
    LED_PORT_DDR = 0X00;
    LED_PORT = 0X00;
}
