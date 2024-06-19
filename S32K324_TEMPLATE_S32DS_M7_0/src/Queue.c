#include "Queue.h"



Queue_t uartCoutQueue;

static UartState enumUartReceiveState = CMD_RECEIVED;
char uartRxBuf[UART_RX_BUFFER_SIZE];
uint8 uartCoutBuffer[UART_TX_MAX_SIZE];
static UartState emunUartSendState = UART_PREPARE_TO_SEND_DATA;

UartState uartTxEvent = UART_PREPARE_TO_SEND_DATA;
UartState uartRxEvent = UART_COUT_EVENT_NOTHING;
uint16 coutI = 0;

static void uart_cmd(char *pReceivedString, uint8 length);





/***********************
 * Q: Pointer to Queue object
 * buf: pointer to a number array
 * item: how many Byte in an item
 * size: how many item
 */
void queueCreat(Queue_t *Q, uint8 *buf, uint16 itemNum, uint16 size)
{
    Q->data = buf;
    memset(Q->data, 0, size*itemNum);

    Q->front = 0;
    Q->rear = 0;
    Q->itemNum = itemNum;
    Q->itemSize = size;


}

bool isFullQueue(Queue_t *Q)
{
    return ((Q->rear +1) % (Q->itemNum) == Q->front)? true : false;
}

void writeQueue(Queue_t *Q, uint8 *val)
{
    if(isFullQueue(Q))
    {

    }
    else
    {
        if(1== Q->itemSize)
        {
            Q->rear = (Q->rear + 1) % (Q->itemNum);
            Q->data[Q->rear] = *val;
        }
        else
        {
            // Q->rear = (Q->rear + Q->itemSize) % (Q->itemNum);
            // memcpy(&Q->data[Q->rear * Q->itemSize], val, Q->itemSize);
        }
        // Q->rear = (Q->rear) % (Q->itemNum);
    }
}

bool isEmptyQueue(Queue_t *Q)
{
    if(Q->front == ((Q->rear) % Q->itemNum))
        return true;
    else
        return false;
}

bool readQueue(Queue_t *Q, uint8 *val)
{
    bool fValue = false;
    if(isEmptyQueue(Q))
    {
        fValue = false;
    }
    else
    {
        fValue = true;
        if(1 ==  Q->itemSize)
        {
            Q->front = (Q->front + 1) % (Q->itemNum);
            *val = Q->data[Q->front];
        }
        else
        {
            //memcpy(val, &Q->data[Q->front * Q->itemSize], Q->itemSize);
        }
        // Q->front = (Q->front + 1) % (Q->itemNum);
    }
    return fValue;
}




void uart_cout_init(void)
{
    queueCreat(&uartCoutQueue, uartCoutBuffer, UART_TX_MAX_SIZE, 1);
}


static void uart_cout_char(char* c)
{
    writeQueue(&uartCoutQueue, (uint8 *)c);
}


void print(const char *string)
{
	uint8 len = strlen(string);
	for(int i = 0; i< len; i++)
	{
		uart_cout_char(&string[i]);
	}
}

static void Uart_Receive(UartState event)
{
    switch(enumUartReceiveState)
    {
        case CMD_RECEIVED:
            Uart_AsyncReceive(UART_CONFIG_CHANNEL_0, (uint8 *)uartRxBuf, sizeof(uartRxBuf));
            enumUartReceiveState = WAIT_FOR_RECEIVE;
            break;
        case WAIT_FOR_RECEIVE:
            if(event == UART_RECEIVE_EVENT_COMPLETED )
            {
                uart_cmd(uartRxBuf,strlen(uartRxBuf));
                memset(uartRxBuf, 0, sizeof(uartRxBuf));
                enumUartReceiveState = CMD_RECEIVED;//begin next receive
                uartRxEvent = UART_COUT_EVENT_NOTHING;
            }
            break;

        default:
            break;
    }
}

static void uart_cmd(char *pReceivedString, uint8 length)
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

void uart_cout_task(void)
{
    switch (emunUartSendState)
    {
        case UART_PREPARE_TO_SEND_DATA:
            for(uint16 i = 0; i< UART_TX_MAX_SIZE;)
            {
                if(readQueue(&uartCoutQueue, &uartCoutBuffer[i]))
                {
                    coutI = ++i;
                }
                else
                {
                    break;
                }
            }            

            if(coutI >0)
            {
                Uart_AsyncSend(UART_CONFIG_CHANNEL_0, uartCoutBuffer, coutI);
                emunUartSendState = UART_WAIT_SEND_COMPLETED;
            }   
            break; 
        
        case UART_WAIT_SEND_COMPLETED:
            if(uartTxEvent == UART_COUT_EVENT_COMPLETED)
            {
                coutI = 0;
                emunUartSendState = UART_PREPARE_TO_SEND_DATA;
            }
            break;

        default:
            break;
    }
    Uart_Receive(uartRxEvent);

    
    
}

/****************************下面是我的代码 没有成功把串口数据发出来********************************************* */
// typedef struct 
// {
//     /* data */
//     QueueElemType  data[SQ_QUEUE_MAX_SIZE];
// 	uint16 front;
// 	uint16 rear;
// }SqQueue;


// static SqQueue UartQueue;




// void InitQueue(SqQueue *Q);


// Std_ReturnType SqQueue_IsEmpty(SqQueue *Q);


// Std_ReturnType SqQueue_IsFull(SqQueue *Q);


// Std_ReturnType SqQueue_Push(SqQueue *Q, const QueueElemType *Val);


// Std_ReturnType SqQueue_Pop(SqQueue *Q, QueueElemType *Val);


// Std_ReturnType SqQueue_GetFrontElem(SqQueue *Q, QueueElemType *Val);


// Std_ReturnType SqQueue_GetRearElem(SqQueue *Q, QueueElemType *Val);






// /************************************************************ */


// void coutChar()
// {
// 	QueueElemType c;
// 	if(SqQueue_Pop(&UartQueue, &c) != QUEUE_STATE_EMPTY)
// 	{
// 		Uart_AsyncSend(UART_CONFIG_CHANNEL_0, &c, 1);
// 	}

// }


// void print(const char *string)
// {
// 	uint8 lenStr = strlen(string);
// 	for(uint8 i = 0; i < lenStr; i++)
// 	{
// 		if(SqQueue_Push(&UartQueue, string) != QUEUE_STATE_FULL)
// 		{
// 			string ++;
// 		}
// 		else
// 		{
// 			return;
// 		}

// 	}
// //	coutChar();
// }



// /********************************************* */

// void InitQueue(SqQueue *Q)
// {
// 	Q->front = 0;
// 	Q->rear = 0;
// }


// void DestroyQueue(SqQueue *Q)
// {
// 	Q->front = 0;
// 	Q->rear = 0;
// }


// Std_ReturnType SqQueue_IsEmpty(SqQueue *Q)
// {

// 	return (Q->front == Q->rear)? E_OK : E_NOT_OK;
// }


// Std_ReturnType SqQueue_IsFull(SqQueue *Q)
// {
	
// 	return ((Q->rear +1) % SQ_QUEUE_MAX_SIZE == Q->front)? E_OK : E_NOT_OK;
// }


// Std_ReturnType SqQueue_Push(SqQueue *Q, const QueueElemType *Val)
// {
	
// 	if(SqQueue_IsFull(Q) == E_OK)
// 	{
// 		return QUEUE_STATE_FULL;
// 	}
// 	else
// 	{
		
// 		Q->rear = (Q->rear + 1) % SQ_QUEUE_MAX_SIZE;
// 		Q->data[Q->rear] = *Val;
// 		return E_OK;
// 	}
// }


// Std_ReturnType SqQueue_Pop(SqQueue *Q, QueueElemType *Val)
// {
	
// 	if(SqQueue_IsEmpty(Q) == E_OK)
// 	{
// 		return QUEUE_STATE_EMPTY;
// 	}
// 	else
// 	{
		
// 		Q->front = (Q->front + 1) % SQ_QUEUE_MAX_SIZE;
// 		*Val = Q->data[Q->front];
// 		return E_OK;
// 	}
// }


// Std_ReturnType SqQueue_GetFrontElem(SqQueue *Q, QueueElemType *Val)
// {

// 	if(SqQueue_IsEmpty(Q) == E_OK)
// 	{
// 		return QUEUE_STATE_EMPTY;
// 	}
// 	else
// 	{
// 		QueueElemType temp = Q->front + 1;
// 		*Val = Q->data[temp];
// 		return E_OK;
// 	}
// }


// Std_ReturnType SqQueue_GetRearElem(SqQueue *Q, QueueElemType *Val)
// {

// 	if(SqQueue_IsEmpty(Q) == E_OK)
// 	{
// 		return QUEUE_STATE_EMPTY;
// 	}
// 	else
// 	{	
// 		*Val = Q->data[Q->rear];
// 		return E_OK;
// 	}
// }




