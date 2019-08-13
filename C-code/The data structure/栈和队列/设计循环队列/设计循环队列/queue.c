#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

void QueueInit(Queue* pq)
{
	//头和尾都指向一个地方
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}
void QueueDestory(Queue* pq)
{
	//再回到原点，清空数据
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}
void QueuePush(Queue* pq, QuDataType x)//入队
{
	//判满
	if (pq->size == QueueMAX)//这里size后面可以+1，为了留一个空间不放元素
	{
		return;
	}
	//不用size判满：
	/*if (pq->rear + 1 - QueueMAX == pq->data&&pq->front == pq->data || pq->rear + 1 == pq->front)
	{
		return;
	}*/
	*pq->rear = x;
	pq->rear++;
	pq->size++;
	//需要判断rear是否到末尾这个跳到中转指针，如果到了rear就自动跳到开始的data，跨越缝隙
	if (pq->rear - pq->data == QueueMAX)//此时对rear取值会越界
	{	
		pq->rear = pq->data;
	}
}
void QueuePop(Queue* pq)//出队
{
	//判空
	if (pq->size == 0)
	{
		return;
	}
	pq->front++;
	pq->size--;
	//需要判断front是否到末尾
	if (pq->front - pq->data == QueueMAX)
	{
		pq->front = pq->data;
	}
}

QuDataType QueueFront(Queue* pq)
{
	//判断size是否为0，是否为空
	if (pq->size == 0)
	{
		return (QuDataType)0;
	}
	else
	{
		return *pq->front;
	}
}
QuDataType QueueBack(Queue* pq)
{
	if (pq->rear == pq->data)
	{
		return pq->data[QueueMAX - 1];
	}
	else
	{
		return *(pq->rear - 1);
	}
}