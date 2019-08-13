#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

#define ARRSIZE(a)  (sizeof(a)/sizeof(a[0]))
int main()
{
	int a[] = { 1,6,3,9,8,7 };
	Heap hp;
	printf("初始化：\n");
	HeapInit(&hp, a, ARRSIZE(a));
	HeapPrint(&hp);
	printf("\n");

	printf("将100入堆\n");
	HeapPush(&hp, 100);
	HeapPrint(&hp);
	printf("\n");

	printf("出堆\n");
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("\n");

	printf("获得堆顶元素\n");
	HPDataType ret = HeapTop(&hp);
	printf("%d", ret);
	printf("\n");

	printf("堆排序\n");
	HeapSort(&hp);
	HeapPrint(&hp);
	printf("\n");

	system("pause");
	return 0;
}