#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define StackMax 5

typedef int STDataType;
typedef struct Stack
{
	STDataType _a[StackMax];
	//STDataType* _a;

	STDataType _top; // Õ»¶¥
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);//ÈëÕ»

void StackPop(Stack* ps);//³öÕ»
STDataType StackTop(Stack* ps);//·µ»ØÕ»¶¥ÔªËØ
int StackEmpty(Stack* ps);//ÅÐ¿Õ
int StackSize(Stack* ps);
#endif // !_STACK_H_

