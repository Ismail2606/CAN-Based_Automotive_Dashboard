
#include <xc.h>
#include "ssd.h"

void init_ssd(void) {
    /* Seeting the SSD data line as Output */
    SSD_DATA_PORT_DDR = 0x00;
    
    /* Setting SSD Control Line as Output (RA5 - RA2) */
    SSD_CONTROL_PORT_DDR = SSD_CONTROL_PORT_DDR & 0xF0;
}

void display(unsigned char data[]) {   
    for (unsigned char i = 0; i < MAX_SSD_CNT; i++)
    {
        SSD_CONTROL_PORT =(unsigned char)(1 << i);
        SSD_DATA_PORT = data[i];
        
       for (unsigned long int wait = 1000; wait--; );
    }
}