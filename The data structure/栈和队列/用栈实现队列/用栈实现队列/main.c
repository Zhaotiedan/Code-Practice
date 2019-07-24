#define _CRT_SECURE_NO_WARNINGS 1

#include"Stackto.h"

int main()
{
	SQueue myqueue;
	QueuePush(&myqueue, 1);
	QueuePush(&myqueue, 2);
	QueuePush(&myqueue, 3);
	QueuePush(&myqueue, 4);
	QueuePush(&myqueue, 5);

	printf("%d\n", QueueFront(&myqueue));
	printf("%d\n", QueueBack(&myqueue));

	QueuePop(&myqueue);
	printf("%d\n", QueueFront(&myqueue));
	printf("%d\n", QueueBack(&myqueue));

	system("pause");
	return 0;
}