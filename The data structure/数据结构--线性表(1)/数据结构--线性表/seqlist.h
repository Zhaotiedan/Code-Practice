
#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

// 顺序表的动态存储
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int SLDataType;//方便改变类型

typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	size_t size; // 有效数据个数
	size_t capacity; // 容量空间的大小
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity);

void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);//每进行一次操作都要进行判断
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插
void SeqListPopBack(SeqList* psl);//尾删
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);//擦除数据
void SeqListRemove(SeqList* psl, SLDataType x);//移除数据,移除所有值为x的元素 O(N)
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//修改，把pos的值改成x O(1)
void SeqListPrint(SeqList* psl);//O(N)void SeqListBubbleSort(SeqList* psl);int SeqListBinaryFind(SeqList* psl, SLDataType x);

void SeqListRemoveAll1(SeqList* psl, SLDataType x);//时间复杂O(n) 空间复杂O(1)void SeqListRemoveAll2(SeqList* psl, SLDataType x);//时间复杂O(n)  空间复杂O(n)#endif