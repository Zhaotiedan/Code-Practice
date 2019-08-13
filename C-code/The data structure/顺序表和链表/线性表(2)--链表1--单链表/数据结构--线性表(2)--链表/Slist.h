#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//无头单向非循环链表
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode *next;
}SListNode;

void SListInit(SListNode **phead);//写void不写返回值，暂时不需要报错，一旦需要报错，则改写成为int
void SListDestory(SListNode **pphead);
SListNode *BuySListNode(SLTDataType x);//做一个新的节点
void SListPushFront(SListNode **phead, SLTDataType x);//头插
void SListPopFront(SListNode **phead);//头删
SListNode *SListFind(SListNode *phead, SLTDataType x);// 在pos的后面进行插入
void SListInsertAfter(SListNode *pos, SLTDataType x);// 在pos的前面进行插入
void SListEraseAfter(SListNode *pos);
void SListRemove(SListNode **phead, SLTDataType x);
void SListRemoveall(SListNode **phead, SLTDataType x);

void SListPrint(SListNode *phead);

void SListReverse1(SListNode **pphead);//逆置
void SListReverse2(SListNode **pphead);

SListNode *getPublicPoint(SListNode *headA, SListNode *headB);//找公共节点
SListNode *JugdeCircle(SListNode *head);//判断是否有环
SListNode *detectCircle(SListNode *head);//找环的入口
SListNode *FindK(SListNode *head, SLTDataType k);//找链表的倒数第k个节点

#endif /*_SLIST_H_*/