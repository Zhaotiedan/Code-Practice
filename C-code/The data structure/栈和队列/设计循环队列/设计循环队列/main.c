#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

int main()
{
	Queue que;
	QueueInit(&que);

	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);
	QueuePush(&que, 5);

	printf("%d\n", QueueFront(&que));
	QueuePop(&que);
	printf("%d\n", QueueFront(&que));
	QueuePop(&que);
	printf("%d\n", QueueFront(&que));

	QueuePush(&que, 9);
	QueuePush(&que, 10);
	QueuePush(&que, 11);
	printf("\n");
	printf("%d\n", QueueFront(&que));
	QueuePop(&que);
	printf("%d\n", QueueFront(&que));
	QueuePop(&que);
	printf("%d\n", QueueFront(&que));
	QueuePop(&que);
	printf("%d\n", QueueFront(&que));
	QueuePop(&que);
	printf("%d\n", QueueFront(&que));
	
	printf("%d\n", QueueBack(&que)); 

	QueueDestory(&que);

	printf("%d\n", QueueFront(&que));
	printf("%d\n", QueueBack(&que));

	system("pause");
	return 0;
}