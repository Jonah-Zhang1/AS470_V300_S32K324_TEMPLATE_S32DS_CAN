#ifndef _QUEUE_H
#define _QUEUE_H

#include "String.h"
#include "StandardTypes.h"
#include "CDD_Uart.h"
#include "Dio.h"
#include "main.h"

#define NUM_TRANSMIT_MAX_ONCE        (2048U)

#define   QUEUE_STATE_FULL       0xA1
#define   QUEUE_STATE_EMPTY      0xA2
#define   QUEUE_STATE_NOT_FULL   0xA3
#define   QUEUE_STATE_NOT_EMPTY  0xA4




#define UART_RX_BUFFER_SIZE     (200U)

#define UART_TX_BUFFER_SIZE     (2048U)

typedef enum
{
    UART_BEGIN_TO_RECEIVED = 0,
    UART_WAITING_FOR_RECEIVE,

}UartReceiveCmd;

typedef enum
{
    UART_RECEIVE_NOTHING,
    UART_RECEIVE_EVENT_COMPLETED    
}UartReceiveEventState;

typedef enum
{
    UART_BEGIN_TO_TRANSMIT,
    UART_WAIT_FOR_TRANSMIT_COMPLETED
}UartTransmitCmd;

typedef enum
{
    UART_TRANSMIT_NOTHING,
    UART_TRANSMIT_EVENT_COMPLETED,
}UartTransmitEventState;
/**************************************
 * elem type: you  can choose uint8/uint16 or stuct and so on
 ***************************************/
typedef uint8 QueueElemType;

void User_UartPrintString(const char *string);

void User_UartInit(void);
void User_UartTask(void);


typedef struct queue
{
    uint8 *data;
    volatile uint16 front;
    volatile uint16 rear;
    uint16 wholeBytesInBuffer;//how many bytes in the whole buffer
    uint16 bytesNumOfElement;//how many bytes in an element
}SqQueue;



#endif/*#ifndef _QUEUE_H*/
