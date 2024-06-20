#include "Queue.h"



SqQueue User_UartTranmsitQueue;
SqQueue User_UartReceiveQueue;

char User_UartReceiveBuffer[UART_RX_BUFFER_SIZE];
uint8 User_UartTransmitBuffer[UART_TX_BUFFER_SIZE];

static UartState enumUartReceiveState = UART_BEGIN_TO_RECEIVED;
static UartState emunUartTransmitState = UART_BEGIN_TO_TRANSMIT;

UartState uartTxEvent = UART_BEGIN_TO_TRANSMIT;
UartState uartRxEvent = UART_RECEIVE_NOTHING;
static uint16 TransmitElementsNum = 0;

static void User_UartReceiveCmd(char *pReceivedString);

/***********************
 * Q: Pointer to Queue object
 * buf: pointer to a number array
 * item: how many Byte in an item
 * size: how many item
 */



void InitQueue(SqQueue *Q, uint8 *buf, uint16 wholeBytesInBuffer)
{
    Q->data = buf;
	Q->front = 0;
	Q->rear = 0;
    Q->wholeBytesInBuffer = wholeBytesInBuffer;
    Q->bytesNumOfElement = sizeof(QueueElemType);
}


Std_ReturnType SqQueue_IsFull(SqQueue *Q)
{
    return ((Q->rear +1) % (Q->wholeBytesInBuffer) == Q->front)? E_OK : E_NOT_OK;
}


Std_ReturnType SqQueue_IsEmpty(SqQueue *Q)
{
    return (Q->front == Q->rear)? E_OK : E_NOT_OK;
}

Std_ReturnType SqQueue_Push(SqQueue *Q, const QueueElemType *Val)
{
    uint8 *bytePtr = (uint8*)Val;
	if(SqQueue_IsFull(Q) == E_OK)
	{
		return E_NOT_OK;;
	}
    else
    {            
        for(uint8 i = 0;i < Q->bytesNumOfElement; i++)
        {
            Q->rear = (Q->rear + 1) % (Q->wholeBytesInBuffer);
            Q->data[Q->rear] = bytePtr[i];
        }        
        return E_OK;
    }
}

Std_ReturnType SqQueue_Pop(SqQueue *Q, QueueElemType *Val)
{
    uint8 *bytePtr = (uint8*)Val;
    if(SqQueue_IsEmpty(Q) == E_OK)
	{
		return E_NOT_OK;
	}
	else
	{
		for(uint8 i = 0;i < Q->bytesNumOfElement; i++)
        {
            Q->front = (Q->front + 1) % (Q->wholeBytesInBuffer);
	        bytePtr[i] = Q->data[Q->front];
        }
		return E_OK;
	}
}

void User_UartInit(void)
{
    InitQueue(&User_UartTranmsitQueue, User_UartTransmitBuffer, UART_TX_BUFFER_SIZE);
    InitQueue(&User_UartReceiveQueue, (uint8*)User_UartReceiveBuffer, UART_RX_BUFFER_SIZE);
}


static void User_UartReceiveCmd(char *pReceivedString)
{
    if(strstr(pReceivedString, "led3_on") != 0)  /*check whether "led0_on" in received string*/
    {
    	Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTA31_LED3_RED, STD_LOW);
    }
    else if(strstr(pReceivedString, "led3_off") != 0)
	{
    	Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTA31_LED3_RED, STD_HIGH);
	}
}

#define NUM_TRANSMIT_MAX_ONCE 100
void User_UartTask(void)
{
    /*************Transmit Task************************* */
    SqQueue *Q = &User_UartTranmsitQueue;
    QueueElemType elems[NUM_TRANSMIT_MAX_ONCE];//At most Transmit 100 elements
    switch (emunUartTransmitState)
    {
        case UART_BEGIN_TO_TRANSMIT:
            while((SqQueue_IsEmpty(Q) == E_NOT_OK) && (TransmitElementsNum < NUM_TRANSMIT_MAX_ONCE))
            {
                if(SqQueue_Pop(Q, &elems[TransmitElementsNum]) == E_OK)
                {
                    TransmitElementsNum ++;
                }
            }
        
            if(TransmitElementsNum > 0)
            {
                Uart_AsyncSend(UART_CONFIG_CHANNEL_0, (uint8*)elems, TransmitElementsNum * Q->bytesNumOfElement);
                emunUartTransmitState = UART_WAIT_FOR_SEND_COMPLETED;
            }   
            break; 
        
        case UART_WAIT_FOR_SEND_COMPLETED:
            if(uartTxEvent == UART_TRANSMIT_EVENT_COMPLETED)
            {
                TransmitElementsNum = 0;
                emunUartTransmitState = UART_BEGIN_TO_TRANSMIT;
            }
            break;

        default:
            break;
    }

    /*************Receive Task************************* */
    switch(enumUartReceiveState)
    {
        case UART_BEGIN_TO_RECEIVED:
            Uart_AsyncReceive(UART_CONFIG_CHANNEL_0, (uint8 *)User_UartReceiveBuffer, sizeof(User_UartReceiveBuffer));
            enumUartReceiveState = UART_WAITING_FOR_RECEIVE;
            break;
        case UART_WAITING_FOR_RECEIVE:
            if(uartRxEvent == UART_RECEIVE_EVENT_COMPLETED )
            {
                User_UartReceiveCmd(User_UartReceiveBuffer);
                memset(User_UartReceiveBuffer, 0, sizeof(User_UartReceiveBuffer));
                enumUartReceiveState = UART_BEGIN_TO_RECEIVED;//begin next receive
                uartRxEvent = UART_RECEIVE_NOTHING;
            }
            break;

        default:
            break;
    }

}

void User_UartPrintString(const char *string)
{
    uint16 len = strlen(string);
    for(uint16 i = 0; i < len; i++)
    {
        SqQueue_Push(&User_UartTranmsitQueue, (uint8*)(&string[i]));
    }       
}
