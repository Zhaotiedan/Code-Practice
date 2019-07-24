#ifndef _STACKTO_H_
#define _STACKTO_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define StackMax 10

typedef int STDataType;

//栈结构体
typedef struct Stack
{
	STDataType _a[StackMax];
	STDataType _top;
}Stack;

//队列结构体
typedef struct
{
	Stack s1;//入队
	Stack s2;//出队

}SQueue;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);//入栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);//返回栈顶元素
int StackEmpty(Stack* ps);//判空
int StackSize(Stack* ps);

void QueuePush(SQueue *ps, STDataType data);//入队
void QueuePop(SQueue *ps);//出队
STDataType QueueFront(SQueue *ps);//获得队首元素
STDataType QueueBack(SQueue *ps);//获得队尾元素
#endif // !_STACKTO_H_

