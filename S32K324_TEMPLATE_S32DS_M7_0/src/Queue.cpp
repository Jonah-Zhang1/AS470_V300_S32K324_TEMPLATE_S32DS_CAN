// #include "Queue.h"


// /*顺序队列*/
// class CSqQueue
// {
// private:
// 	/* data */
// 	QueueElemType  data[SQ_QUEUE_MAX_SIZE];
// 	uint16 front;//保存对头元素下标         front的位置不放元素，加1之后的位置放元素
// 	uint16 rear;//保存队尾元素下标          就是最后的元素下标

// public:
// 	/*队列初始化*/
// 	CSqQueue(/* args */);

// 	/*队列销毁*/
// 	~CSqQueue();

// 	/*队列初始化*/
// 	Std_ReturnType InitQueue();

// 	/*判断队空*/
// 	Std_ReturnType IsEmpty();

// 	/*判断队满*/
// 	Std_ReturnType IsFull();

// 	/*元素入队*/
// 	Std_ReturnType Push(const QueueElemType &Val);

// 	/*元素出队*/
// 	Std_ReturnType Pop(QueueElemType &Val);

// 	/*获取队头元素*/
// 	Std_ReturnType GetFrontElem(QueueElemType &Val);

// 	/*获取队尾元素*/
// 	Std_ReturnType GetRearElem(QueueElemType &Val);

// };




// /************************************************************ */

// /*C 语言调用函数*/
// void print(const char *string)
// {
// 	print_cpp(string);
// }
// QueueElemType coutchar()
// {
// 	return coutChar_cpp();
// }

// /*串口队列初始化*/
// static CSqQueue UartQueue;

// /*串口打印函数接口*/
// void print_cpp(const char *string)
// {
// 	uint8 lenStr = strlen(string);
// 	for(uint8 i = 0; i < lenStr; i++)
// 	{
// 		UartQueue.Push(*string);
// 		string ++;
// 	}
// 	QueueElemType c = coutChar_cpp();
//     Uart_AsyncSend(UART_CONFIG_CHANNEL_0, &c, 1);
// }

// QueueElemType coutChar_cpp()
// {
// 	QueueElemType c;
// 	UartQueue.Pop(c);
// 	return c;
// }

// /********************************************* */
// /*队列初始化*/
// CSqQueue::CSqQueue()
// {
// 	front = 0;
// 	rear = 0;
// }

// /*队列销毁*/
// CSqQueue::~CSqQueue()
// {
// 	front = 0;
// 	rear = 0;
// }

// /*判断队空*/
// Std_ReturnType CSqQueue::IsEmpty()
// {
// 	/*队头指针和队尾指针在同一个位置，表明队空*/
// 	return (this->front == this->rear)? E_OK : E_NOT_OK;
// }

// /*判断队满*/
// Std_ReturnType CSqQueue::IsFull()
// {
// 	/*队列中始终有一个位置是不放元素的，就是队头的位置永远是空的*/
// 	/*如果队头的位置 的 前一个位置 是队尾，那就是满了*/
// 	return ((this->rear +1) % SQ_QUEUE_MAX_SIZE == this->front)? E_OK : E_NOT_OK;
// }

// /*元素入队*/
// Std_ReturnType CSqQueue::Push(const QueueElemType &Val)
// {
// 	/*如果队满，不能入队*/
// 	if(IsFull() == E_OK)
// 	{
// 		return QUEUE_STATE_FULL;
// 	}
// 	else
// 	{
// 		/*队首指针不动，先把队尾指针后移，再在队尾的位置放新元素*/
// 		this->rear = (this->rear + 1) % SQ_QUEUE_MAX_SIZE;
// 		this->data[this->rear] = Val;
// 		return E_OK;
// 	}
// }

// /*元素出队*/
// Std_ReturnType CSqQueue::Pop(QueueElemType &Val)
// {
// 	/*队空，不能出队*/
// 	if(IsEmpty() == E_OK)
// 	{
// 		return QUEUE_STATE_EMPTY;
// 	}
// 	else
// 	{
// 		/*队头指针后移一个，把队头指向的位置元素返回*/
// 		/*队头指向的位置不放元素，队头+1的位置是实际上的队头元素*/
// 		this->front = (this->front + 1) % SQ_QUEUE_MAX_SIZE;
// 		Val = this->data[this->front];
// 		return E_OK;
// 	}
// }

// /*获取对头元素*/
// Std_ReturnType CSqQueue::GetFrontElem(QueueElemType &Val)
// {
// 	/*队空，无元素*/
// 	if(IsEmpty() == E_OK)
// 	{
// 		return QUEUE_STATE_EMPTY;
// 	}
// 	else
// 	{
// 		QueueElemType temp = this->front + 1;
// 		Val = this->data[temp];
// 		return E_OK;
// 	}
// }

// /*获取队尾元素*/
// Std_ReturnType CSqQueue::GetRearElem(QueueElemType &Val)
// {
// 	/*队空，无元素*/
// 	if(IsEmpty() == E_OK)
// 	{
// 		return QUEUE_STATE_EMPTY;
// 	}
// 	else
// 	{	
// 		Val = this->data[Q.rear];
// 		return E_OK;
// 	}
// }




