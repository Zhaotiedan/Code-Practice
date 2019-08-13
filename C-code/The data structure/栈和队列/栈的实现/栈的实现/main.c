#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

int main()
{
	Stack mystack;
	StackInit(&mystack);
	StackPush(&mystack, 1);
	StackPush(&mystack, 2);
	StackPush(&mystack, 3);
	StackPush(&mystack, 4);
	StackPush(&mystack, 5);

	printf("%d\n", StackTop(&mystack));
	StackPop(&mystack);
	printf("%d\n", StackTop(&mystack));
	StackPop(&mystack);
	printf("%d\n", StackTop(&mystack));

	system("pause");
	return 0;
}