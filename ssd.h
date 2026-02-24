#ifndef SSD_H
#define	SSD_H

#define MAX_SSD_CNT                 4

#define SSD_DATA_PORT_DDR           TRISD
#define SSD_CONTROL_PORT_DDR        TRISA

#define SSD_DATA_PORT               PORTD
#define SSD_CONTROL_PORT            PORTA

#define SW1                         RC0

/* For Common Cathode Display */
#define ZERO   0xE7
#define ONE    0x21
#define TWO    0xCB
#define THREE  0x6B
#define FOUR   0x2D
#define FIVE   0x6E
#define SIX    0xEE
#define SEVEN  0x23
#define EIGHT  0xEF
#define NINE   0x6F

unsigned char digit[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
void init_ssd(void);
void display(unsigned char data[]);

#endif