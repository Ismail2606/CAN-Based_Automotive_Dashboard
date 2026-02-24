#ifndef SCI_H
#define SCI_H

#define RX_PIN					TRISC7
#define TX_PIN					TRISC6

void init_uart(void);
void my_putch(unsigned char byte);
int my_puts(const char *s);
unsigned char my_getch(void);
unsigned char getch_with_timeout(unsigned short max_time);
unsigned char my_getche(void);

#endif
