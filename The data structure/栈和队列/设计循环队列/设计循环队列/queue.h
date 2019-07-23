#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define QueueMAX 5
typedef int QuDataType;

typedef struct Queue
{
	QuDataType data[QueueMAX];//data是一个基准值，全程不动。data即使是静态数组，也最好申请空间。堆空间无限大，随便用。但当数组长度过大时会导致栈炸
	QuDataType *front;//尾
	QuDataType *rear;//头
	size_t size;//实际上可以不要，但有能舒服一点
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);

QuDataType QueueFront(Queue* pq);
QuDataType QueueBack(Queue* pq);

#endif // !_QUEUE_H_
