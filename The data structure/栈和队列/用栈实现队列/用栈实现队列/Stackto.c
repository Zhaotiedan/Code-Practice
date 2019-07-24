#define _CRT_SECURE_NO_WARNINGS 1

#include"Stackto.h"

void StackInit(Stack * ps)
{
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x) //入栈
{
	//判满
	if (StackSize == 0)
	{
		return;
	}
	else
	{
		ps->_a[ps->_top] = x;
		ps->_top++;
	}
}
void StackPop(Stack* ps)//出栈
{
	//判空
	if (StackEmpty(&ps) == 0)
	{
		return;
	}
	else
	{
		ps->_top--;
	}
}
STDataType StackTop(Stack* ps)//返回栈顶元素
{
	//判空
	if (StackEmpty)
	{
		return ps->_a[ps->_top - 1];
	}
	return 0;
}
int StackEmpty(Stack* ps)//判空
{
	if (ps->_top == 0)
	{
		return 0;
	}
	return 1;
}
int StackSize(Stack* ps)//判满
{
	if (ps->_top == StackMax - 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void QueuePush(SQueue *ps, STDataType data)//入队
{
	StackInit(&(ps->s1));
	StackInit(&(ps->s2));

	StackPush(&(ps->s1), data);
}
void QueuePop(SQueue *ps)//出队
{
	//栈p2为空,s1里还有元素时，,先把s1元素全压入s2,再把s2中元素出栈
	if (StackEmpty(&(ps->s2)))
	{
		while (!StackEmpty(&(ps->s1)))
		{
			StackPush(&(ps->s2), StackTop(&(ps->s1)));
			StackPop(&(ps->s1));
		}
	}
	//栈2为非空时，直接将栈2的栈顶元素弹出
	StackPop(&(ps->s2));
}
STDataType QueueFront(SQueue *ps)//获得队首元素
{
	if (StackEmpty(&(ps->s2)) == 0)
	{
		return (STDataType*)0;
	}
	return StackTop(&(ps->s2));
}
STDataType QueueBack(SQueue *ps)//获得队尾元素
{
	if (StackEmpty(&(ps->s1)) == 0)
	{
		return (STDataType*)0;
	}
	return StackTop(&(ps->s1));
}