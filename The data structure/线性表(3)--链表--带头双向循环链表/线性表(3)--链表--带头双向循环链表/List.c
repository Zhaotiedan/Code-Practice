#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));//plist->_head相当于*pphead
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}
void ListDestory(List* plist)
{
	while (plist->_head != plist->_head)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}
void ListPushBack(List* plist, LTDataType x)//后插--本质双链表唯一的插入方式
{
	ListInsertafter(plist->_head, x);
}
void ListPopBack(List* plist)//尾删
{
	ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDataType x)//头插
{
	ListInsertafter(plist->_head, x);
}
void ListPopFront(List* plist)//头删
{
	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)// 在pos的前面进行插入
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur == x)
		{
			return cur;
		}
	}
	return NULL;
}
void ListInsertafter(ListNode* pos, LTDataType x)// 删除pos位置的节点
{
	//pos后面进行 后插
	ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_next;
	cur->_data = x;

	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
}

void ListErase(ListNode* pos)//删掉pos位置的节点
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListRemove(List* plist, LTDataType x)
{
	ListNode* cur = ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
void ListPrint(List* plist)
{
	//双链表的遍历头
	ListNode * cur;
	for (cur = plist->_head->_next; cur!= plist->_head; cur = cur->_next)
	{
		printf("%d->", plist->_head->_data);
	}
}