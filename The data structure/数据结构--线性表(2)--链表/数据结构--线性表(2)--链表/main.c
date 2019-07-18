#define _CRT_SECURE_NO_WARNINGS 1

#include"Slist.h"

int main()
{
	SListNode *phead=NULL;
	int value = 0;

	SListInit(&phead);//讲头指针这个变量（只是里面放置的是它所指向的内容）设置为NULL


	SListPushFront(&phead, 6);

	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 6);


	SListPrint(phead);

	SListRemove(&phead, 6);
	SListPrint(phead);
	/*SListPopFront(&phead, 4);
	SListPopFront(&phead, 3);*/

	value = SListFind(phead, 1);
    printf("%d\n", value);

	SListInsertAfter(SListFind(phead,2), 10);
	SListPrint(phead);


	SListEraseAfter(SListFind(phead, 2));
	SListPrint(phead);

	SListDestory(&phead);
	SListPrint(phead);
	system("pause");
	return 0;
}

//约瑟夫环测试
//int main()
//{
//	int i = 0;
//	int n = 0;//数的数字
//	int m = 0;//数数的人数
//	SListNode* phead;
//	SListNode* plast=NULL;
//	SListNode* cur=NULL;
//	scanf("%d %d", &n, &m);
//	SListInit(&phead);
//	//先把最大的数放进去
//	SListPushFront(&phead, m);
//	plast = phead;
//	//依次放入数，形成链表
//	for (i = m - 1; i >=1; i--)
//	{
//		SListPushFront(&phead, i);
//	}
//
//	plast->next = phead;//形成一个环
//	cur = plast;
//
//	for (; m > 1; m--)
//	{
//		for (i = 1; i < n; i++)	//数数
//		{
//			cur = cur->next;
//		}
//		SListEraseAfter(cur);
//	}
//	printf("%d", cur->data);
//	free(cur);
//	system("pause");
//	return 0;
//}


//反转一个单链表
//int main()
//{
//	SListNode *phead = NULL;
//	SListNode *tmp;
//	SListInit(&phead);
//
//	SListPushFront(&phead, 1);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//	SListPrint(phead);
//
//	//SListReverse1(&phead);
//	SListReverse2(&phead);
//	SListPrint(phead);
//	system("pause");
//	return 0;
//}