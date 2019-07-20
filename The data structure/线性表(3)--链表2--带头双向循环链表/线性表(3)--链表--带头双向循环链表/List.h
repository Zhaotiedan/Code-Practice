#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);// 在pos的前面进行插入

void ListInsertFront(ListNode* pos, LTDataType x);//
void ListInsertafter(ListNode* pos, LTDataType x);// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListDistinct(List* plist);//去重
List* ListMerger(List* plist1, List* plist2);//合并

void ListPrint(List* plist);


#endif /*_LIST_H_*/

