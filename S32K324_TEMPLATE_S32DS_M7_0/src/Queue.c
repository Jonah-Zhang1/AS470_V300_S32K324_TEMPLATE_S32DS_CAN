#include "Queue.h"
#include "main.h"


SqQueue User_UartTranmsitQueue;
SqQueue User_UartReceiveQueue;

char User_UartReceiveBuffer[UART_RX_BUFFER_SIZE];
uint8 User_UartTransmitBuffer[UART_TX_BUFFER_SIZE];

static UartReceiveCmd enumUartReceiveCmd = UART_BEGIN_TO_RECEIVED;
static UartTransmitCmd emunUartTransmitCmd = UART_BEGIN_TO_TRANSMIT;

UartTransmitEventState uartTxEvent = UART_TRANSMIT_NOTHING;
UartReceiveEventState uartRxEvent = UART_RECEIVE_NOTHING;

uint16 count = 0;

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
		return E_NOT_OK;
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
    if(strstr(pReceivedString, "led3_on") != NULL)  /*check whether "led0_on" in received string*/
    {
    	Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTA31_LED3_RED, STD_LOW);
    }
    else if(strstr(pReceivedString, "led3_off") != NULL)
	{
    	Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTA31_LED3_RED, STD_HIGH);
	}
}


void User_Uart_TransmitTask(void)
{
    /*************Transmit Task************************* */
	uint16 TransmitElementsNum = 0;
    SqQueue *Q = &User_UartTranmsitQueue;
    QueueElemType elems[NUM_TRANSMIT_MAX_ONCE];//At most Transmit 100 elements
    switch (emunUartTransmitCmd)
    {
        case UART_BEGIN_TO_TRANSMIT:
//            while((SqQueue_IsEmpty(Q) == E_NOT_OK) && (TransmitElementsNum < NUM_TRANSMIT_MAX_ONCE))
        	for(;TransmitElementsNum < NUM_TRANSMIT_MAX_ONCE;)
            {
                if(SqQueue_Pop(Q, &elems[TransmitElementsNum]) == E_OK)
                {
                	count = ++TransmitElementsNum;
                }
                else
                {
                	break;
                }
            }
        
            if(count > 0)
            {
                Uart_AsyncSend(UART_CONFIG_CHANNEL_0, (uint8*)elems, (count) * Q->bytesNumOfElement);
                emunUartTransmitCmd = UART_WAIT_FOR_TRANSMIT_COMPLETED;
            }   
            break; 
        
        case UART_WAIT_FOR_TRANSMIT_COMPLETED:
            if(UART_TRANSMIT_EVENT_COMPLETED == uartTxEvent)
            {
            	count = 0;
                emunUartTransmitCmd = UART_BEGIN_TO_TRANSMIT;
                uartTxEvent = UART_TRANSMIT_NOTHING;
            }
            break;

        default:
            break;
    }
}
void User_Uart_ReceiveTask(void)
{
    /*************Receive Task************************* */
    switch(enumUartReceiveCmd)
    {
        case UART_BEGIN_TO_RECEIVED:
            Uart_AsyncReceive(UART_CONFIG_CHANNEL_0, (uint8 *)User_UartReceiveBuffer, sizeof(User_UartReceiveBuffer));
            enumUartReceiveCmd = UART_WAITING_FOR_RECEIVE;
            break;
        case UART_WAITING_FOR_RECEIVE:
            if(UART_RECEIVE_EVENT_COMPLETED == uartRxEvent)
            {
                User_UartReceiveCmd(User_UartReceiveBuffer);
                memset(User_UartReceiveBuffer, 0, sizeof(User_UartReceiveBuffer));
                enumUartReceiveCmd = UART_BEGIN_TO_RECEIVED;//begin next receive
                uartRxEvent = UART_RECEIVE_NOTHING;
            }
            break;

        default:
            break;
    }

}

void  User_UartTask(void)
{
	User_Uart_TransmitTask();
	User_Uart_ReceiveTask();
}

void User_UartPrintString(const char *string)
{
	IRQ_DISENABLE;//disable all interrupt

    uint16 len = strlen(string);
    for(uint16 i = 0; i < len; i++)
    {
        SqQueue_Push(&User_UartTranmsitQueue, (uint8*)(&string[i]));
    }

    IRQ_ENABLE;//enable all interrupt
}
