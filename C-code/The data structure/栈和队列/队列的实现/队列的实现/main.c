#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

int main()
{
	Queue myqueue;
	QueueInit(&myqueue);
	QueuePush(&myqueue, 1);
	QueuePush(&myqueue, 2);
	QueuePush(&myqueue, 3);
	QueuePush(&myqueue, 4);
	QueuePush(&myqueue, 5);

	printf("%d\n", QueueFront(&myqueue));
	printf("%d\n", QueueBack(&myqueue));

	printf("\n");

	QueuePop(&myqueue);
	printf("%d\n", QueueFront(&myqueue));
	QueuePop(&myqueue);
	printf("%d\n", QueueFront(&myqueue));
	QueuePop(&myqueue);
	printf("%d\n", QueueFront(&myqueue));

	system("pause");
	return 0;
}