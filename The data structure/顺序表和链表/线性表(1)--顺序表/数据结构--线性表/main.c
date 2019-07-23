#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"//include作用：把seqlist.h里面的所有函数和头文件复制黏贴上去，先展开.h引用的头文件，再展开里面的函数内容


int main()
{

	SeqList test;
	SeqListInit(&test, 10);

	 SeqListPushBack(&test, 10);
	 SeqListPushBack(&test, 9);
	 SeqListPushBack(&test, 8);
	 SeqListPushBack(&test, 8);
	 SeqListPushBack(&test, 8);

	 SeqListPushBack(&test, 7);
	 SeqListPushBack(&test, 6);


	 SeqListPopBack(&test, 6);

	 SeqListPushFront(&test, 6);
	 SeqListPopFront(&test, 6);

	 SLDataType ret1 = SeqListFind(&test, 10);
	 printf("元素10的下标是：%d\n", ret1);

	 SeqListInsert(&test, SeqListFind(&test,8), 15);
	 SeqListPrint(&test);
	 //SeqListErase(&test, SeqListFind(&test, 15));
	 SeqListRemove(&test,15);
	 SeqListPrint(&test);

	 SeqListModify(&test, SeqListFind(&test, 8), 18);
	 SeqListPrint(&test);

	 SeqListBubbleSort(&test);

	 SeqListPrint(&test);
	 SLDataType ret2 = SeqListBinaryFind(&test, 10);
	 printf("10的下标是：%d\n", ret2);

	 //SeqListRemoveAll1(&test, 8);
	 SeqListRemoveAll2(&test, 8);
	 SeqListPrint(&test);

	 SeqListDestory(&test);
	 SeqListPrint(&test);
	system("pause");
	return 0;
}
