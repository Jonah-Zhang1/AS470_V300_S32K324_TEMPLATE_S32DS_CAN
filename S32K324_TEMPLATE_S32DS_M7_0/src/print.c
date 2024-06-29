
#include "print.h"

char USART_TX_BUF[100];

void print(char* fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    vsprintf((char*)USART_TX_BUF,fmt,ap);
    va_end(ap);

    Uart_SyncSend(UART_CONFIG_CHANNEL_0, (uint8_t *)USART_TX_BUF, strlen(USART_TX_BUF),0xffff);

}