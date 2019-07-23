#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"
int main()
{
	//测试函数功能
	List list;//定义一个结构体，里面只有一个指针为head
	List list1;
	List list2;
	List list3;

	ListInit(&list);
	ListInit(&list1);
	ListInit(&list2);


	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPushBack(&list, 6);



	ListPopBack(&list);

	ListPushFront(&list, 4);
	ListPopFront(&list, 4);

	ListInsertFront(ListFind(&list, 3), 10);
	ListInsertafter(ListFind(&list,3), 10);

	ListErase(ListFind(&list, 3));
	//ListRemove(&list, 10);
//2.去重：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
	ListDistinct(&list);
	ListPrint(&list);
//2.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//库函数实现方式：库函数将链表2合并至链表1
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 2);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 4);
	ListPushBack(&list1, 5);
	ListPrint(&list1);

	ListPushBack(&list2, 2);
	ListPushBack(&list2, 4);
	ListPushBack(&list2, 6);
	ListPushBack(&list2, 7);
	ListPushBack(&list2, 9);
	ListPrint(&list2);
	
	ListPrint(ListMerger(&list1,&list2));
	system("pause");
	return 0;
}