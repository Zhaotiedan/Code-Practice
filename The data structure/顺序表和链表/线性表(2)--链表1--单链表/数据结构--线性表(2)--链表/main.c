#define _CRT_SECURE_NO_WARNINGS 1

#include"Slist.h"
//1、函数测试
//int main()
//{
//	SListNode *phead=NULL;
//	int value = 0;
//
//	SListInit(&phead);//讲头指针这个变量（只是里面放置的是它所指向的内容）设置为NULL
//
//
//	SListPushFront(&phead, 6);
//
//	SListPushFront(&phead, 1);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//	SListPushFront(&phead, 6);
//
//
//	SListPrint(phead);
//
//	SListRemove(&phead, 6);
//	SListPrint(phead);
//	/*SListPopFront(&phead, 4);
//	SListPopFront(&phead, 3);*/
//
//	value = SListFind(phead, 1);
//    printf("%d\n", value);
//
//	SListInsertAfter(SListFind(phead,2), 10);
//	SListPrint(phead);
//
//
//	SListEraseAfter(SListFind(phead, 2));
//	SListPrint(phead);
//
//	SListDestory(&phead);
//	SListPrint(phead);
//	system("pause");
//	return 0;
//}

////2.约瑟夫环测试 详见CSDN：https://mp.csdn.net/mdeditor/98895581
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
//
//	//依次放入数，形成链表
//	for (i = m - 1; i >=1; i--)
//	{
//		SListPushFront(&phead, i);
//	}
//	plast->next = phead;//形成一个环
//
//	cur = plast;//只有第一个跳的个数不一样，这样可以保证第一次的正确
//
//	for (; m > 1; m--)
//	{
//		for (i = 1; i < n; i++)	//数数，跳n-1后删
//		{
//			cur = cur->next;
//			printf("%d号报%d\n", cur->data, i);
//		}
//		printf("%d号出圈\n", cur->next->data, i);
//		SListEraseAfter(cur);
//	}
//	printf("%d号胜利\n", cur->data);
//	free(cur);
//	system("pause");
//	return 0;
//}


//3.反转一个单链表
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

//4.求两个单链表的第一个公共节点
//右对齐，长的先走差值步，再一起遍历
//int main()
//{
//	int i = 0;
//	int j = 0;
//	SListNode* phead1;
//	SListNode* phead2;
//	SListInit(&phead1);
//	SListInit(&phead2);
//
//	SListPushFront(&phead1, 5);
//	SListPushFront(&phead1, 4);
//	SListPushFront(&phead1, 8);
//	SListPushFront(&phead1, 1);
//	SListPushFront(&phead1, 4);
//
//	SListPushFront(&phead2, 5);
//	SListPushFront(&phead2, 4);
//	SListPushFront(&phead2, 8);
//	SListPushFront(&phead2, 1);
//	SListPushFront(&phead2, 0);
//	SListPushFront(&phead2, 5);
//
//
//	SListNode* ret=getPublicPoint(phead1, phead2);
//	if (ret==NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		printf("%d\n", ret->data);
//	}
//	system("pause");
//
//	return 0;
//}

//5.如何判断链表是否有环
//找一个节点一次跳两次，一个跳一次。如果能相遇，则一定是环，跑到尽头，则没环
//int main()
//{
//	SListNode *phead;
//	SListNode *plast = NULL;
//	SListInit(&phead);
//
//	SListPushFront(&phead, 1);
//	plast = phead;
//
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//
//	plast->next = phead;
//	SListNode * ret = JugdeCircle(phead);
//	printf("%d\n", ret->data);
//	system("pause");
//	return 0;
//}

//6.给定一个链表，判断环，返回链表开始入环的第一个节点，无环返回NULL
//如果头结点是环入口，一个节点一次跳两步，一次跳一步，则头结点是环入口
//如果头结点不是环入口，则多余的部分到环入口的长度和相遇点到环入口的长度相同，
//所以让两个节点从头结点一快一慢开始走，找到相遇点，这就相当于完成了右对齐。
//然后两个节点中fast和head一起走，找到的公共节点就是环入口
//int main()
//{
//	SListNode *phead;
//	SListNode *plast=NULL;
//
//	SListInit(&phead);
//
//	SListPushFront(&phead, 1);
//	plast = phead;
//
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//
//	plast->next = phead;
//
//	SListNode *ret = detectCircle(phead);
//	printf("%d", ret->data);
//	SListPrint(phead);
//	system("pause");
//	return 0;
//}

int main()
{
	SListNode *phead;
	SListInit(&phead);

	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SLTDataType k = 0;
	scanf("%d", &k);
	SListNode *ret = FindK(phead, k);
	printf("%d", ret->data);
	system("pause");
	return 0;
}

