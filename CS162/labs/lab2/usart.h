#ifndef USART_H
#define USART_H

#include <stdint.h>

void USART_Init(unsigned int baud);
void USART_Transmit(unsigned char data);
unsigned char USART_Available(void);
unsigned char USART_Receive(void);
void USART_SendString(const char* str);

#endif // USART_H
