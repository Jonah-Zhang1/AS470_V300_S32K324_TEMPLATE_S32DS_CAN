#ifndef _QUEUE_H
#define _QUEUE_H

#include "String.h"
#include "StandardTypes.h"
#include "CDD_Uart.h"
#include "Dio.h"

#define UART_CONFIG_CHANNEL_0       (0U)  //zm3 Add 20240613  for UART channel0

#define   QUEUE_STATE_FULL       0xA1
#define   QUEUE_STATE_EMPTY      0xA2
#define   QUEUE_STATE_NOT_FULL   0xA3
#define   QUEUE_STATE_NOT_EMPTY  0xA4




#define UART_RX_BUFFER_SIZE  (200U)

#define UART_TX_MAX_SIZE     (200U)

typedef enum
{
    CMD_RECEIVED = 0,
    WAIT_FOR_RECEIVE,

    UART_RECEIVE_EVENT_COMPLETED,
    
    UART_COUT_EVENT_NOTHING,
    UART_COUT_EVENT_COMPLETED,

    UART_PREPARE_TO_SEND_DATA,
    UART_WAIT_SEND_COMPLETED
}UartState;


void print(const char *string);

void uart_cout_init(void);
void uart_cout_task(void);

// typedef char QueueElemType;
typedef uint8 QueueElemType;

typedef struct queue
{
    uint8 *data;
    volatile uint16 front;
    volatile uint16 rear;
    uint16 itemNum;
    uint16 itemSize;
}Queue_t;

#endif/*#ifndef _QUEUE_H*/
