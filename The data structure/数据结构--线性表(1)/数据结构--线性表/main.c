#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"//include作用：把seqlist.h里面的所有函数和头文件复制黏贴上去，先展开.h引用的头文件，再展开里面的函数内容


int main()
{

	SeqList test;
	SeqListInit(&test, 10);

	 SeqListPushBack(&test, 10);
	 SeqListPushBack(&test, 9);
	// SeqListPopBack(&test,);
	// SeqListPushFront(SeqList* psl, SLDataType x);
	// SeqListPopFront(SeqList* psl);
	//SeqListFind(SeqList* psl, SLDataType x);
	// SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
	// SeqListErase(SeqList* psl, size_t pos);//擦除数据
	// SeqListRemove(SeqList* psl, SLDataType x);//移除数据,移除所有值为x的元素 O(N)
	// SeqListModify(SeqList* psl, size_t pos, SLDataType x);//修改，把pos的值改成x O(1)
	// SeqListPrint(SeqList* psl);//O(N)	// SeqListBubbleSort(SeqList* psl);	//SeqListBinaryFind(SeqList* psl, SLDataType x);
	//// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
	//void SeqListRemoveAll1(SeqList* psl, SLDataType x);//O(n) 空间复杂O(1)	//void SeqListRemoveAll2(SeqList* psl, SLDataType x)//时间复杂O(n)  空间复杂O(n)

	 SeqListPrint(&test);
	//SeqListDestory(&test);
	system("pause");
	return 0;
}
