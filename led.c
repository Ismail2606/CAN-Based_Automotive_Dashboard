

#include <xc.h>
#include "led.h"

void init_led(void) {
    LED_PORT_DDR = LED_PORT_DDR & 0X3C;
    LED_PORT = LED_PORT & 0X3C;
}