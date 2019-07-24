#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int QUDataType;
//节点结构体
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
//队列结构体
typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _rear; // 队尾
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);//入队
void QueuePop(Queue* pq);//出队
QUDataType QueueFront(Queue* pq);//获得队首元素
QUDataType QueueBack(Queue* pq);//获得队尾元素
int QueueEmpty(Queue* pq);//判空


#endif // !_QUEUE_H_

