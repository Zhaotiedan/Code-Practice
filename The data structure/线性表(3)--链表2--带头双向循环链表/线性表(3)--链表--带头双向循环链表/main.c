#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"
int main()
{
	List list;//定义一个结构体，里面只有一个指针为head
	ListInit(&list);

	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);

	system("pause");
	return 0;
}