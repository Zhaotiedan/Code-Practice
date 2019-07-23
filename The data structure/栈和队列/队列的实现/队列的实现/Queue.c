#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)
{
	pq->_front = pq->_rear = (QueueNode*)malloc(sizeof(QueueNode));
	pq->_front->_next = NULL;
}
void QueueDestory(Queue* pq)
{
	//从头节点开始删除,不停的后删
	while (pq->_front != NULL)
	{
		//先找到头结点后面的节点
		pq->_rear = pq->_front->_next;
		free(pq->_front);
		pq->_front = pq->_rear;
	}
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}
void QueuePush(Queue* pq, QUDataType x)//入队--尾插
{
	QueueNode *tmp = BuyQueueNode(x);
	pq->_rear->_next = tmp;
	pq->_rear = tmp;
}
void QueuePop(Queue* pq)//出队--头删
{
	if (QueueEmpty == 0)
	{
		return;
	}
	QueueNode*tmp = pq->_front->_next;
	free(pq->_front);
	pq->_front = tmp;
}
QUDataType QueueFront(Queue* pq)//获得队头元素
{
	if (QueueEmpty == 0)
	{
		return (QUDataType*)0;
	}
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq) // 获得队尾元素
{
	if (QueueEmpty == 0)
	{
		return;
	}
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq)//判空
{
	if (pq->_front == pq->_rear)
	{
		return 0;
	}
	return 1;
}