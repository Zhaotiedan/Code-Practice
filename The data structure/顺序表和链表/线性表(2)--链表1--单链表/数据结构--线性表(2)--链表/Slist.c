#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

void SListInit(SListNode **pphead)
{
	*pphead = NULL;
}
void SListDestory(SListNode **pphead)//砍脖子，不停往后删。头删，剁头,不能销毁循环链表
{
	if (*pphead==NULL)
	{
		return;
	}
	while ((*pphead)->next)
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);
	*pphead = NULL;
}
SListNode *BuySListNode(SLTDataType x)//做一个新的节点
{
	SListNode *tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void SListPushFront(SListNode **pphead, SLTDataType x)//头插
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = (*pphead);
	(*pphead) = tmp;
}
void SListPopFront(SListNode **pphead)//头删--头不能为空
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	(*pphead) = tmp;
}
SListNode *SListFind(SListNode *phead, SLTDataType x)// 找x
{
	SListNode *tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;

}
void SListInsertAfter(SListNode *pos, SLTDataType x)// 在pos的后面进行插入
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void SListEraseAfter(SListNode *pos)//删除pos后面的节点，把pos的地址传进来，改变pos指向的空间
{
	SListNode *tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	tmp = NULL;
}
void SListRemove(SListNode **pphead, SLTDataType x)//只删一个
{
	SListNode *tmp;
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
		return;
	}
	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if(tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListRemoveall(SListNode **pphead, SLTDataType x)
{
	SListNode *tmp;
	if (*pphead == NULL)
	{
		return;
	}
	while (*pphead&&(*pphead)->data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

//逆序单链表的两种方法    方法剖析见CSND:https://blog.csdn.net/qq_42913794/article/details/97621521
void SListReverse1(SListNode **pphead)
{
	SListNode *head = *pphead;//每次循环中始终指向当前链表的头
	SListNode *tmp = head->next;//每次循环中始终指向被删的节点
	SListNode *oldhead = *pphead;//每次循环中始终指向被删的前一个节点

	while (tmp)//tmp为空，代表逆序结束。旧头成新尾
	{
		oldhead->next = tmp->next;//架空tmp（后删）的一部分
		tmp->next = head;//让tmp变成新头（头插）
		head = tmp;//换头
		tmp = oldhead->next;//让tmp变成下一次循环中待删除的节点
	}
	*pphead = head;
}

void SListReverse2(SListNode **pphead)
{
	SListNode *pre = *pphead;//被执行操作的前一个节点
	SListNode *cur= pre->next;//被执行操作的节点
	SListNode *next = cur;//被执行操作的后一个节点,暂时指在cur，在循环开始的时候跳转到其后一个节点

	pre->next = NULL;//此时的头，将会成为尾，所以要设置尾节点 
	while (next)
	{
		next = next->next;//放前面避免next为空。
		cur->next = pre;//改变箭头方向
		pre = cur;//循环节点依次后移
		cur = next;
	}
	*pphead = pre;//循环跳出时，cur和next都指向空，此时的头为pre
}

//找两个链表的公共节点
SListNode *getPublicPoint(SListNode *headA, SListNode *headB)//寻找单链表的相交节点
{
	int lenA = 0;
	int lenB = 0;
	int gap = 0;
	int i = 0;
	SListNode *cur;
	SListNode *longerlist = headA;
	SListNode *shortlist = headB;
	for (cur = headA; cur; cur = cur->next)
	{
		lenA++;
	}
	for (cur = headB; cur; cur = cur->next)
	{
		lenB++;
	}
	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		longerlist = headB;
		shortlist = headA;
	}
	for (; i < gap; i++)//右对齐
	{
		longerlist = longerlist->next;
	}
	for (; longerlist&&shortlist; longerlist = longerlist->next, shortlist = shortlist->next)
	{
		if (longerlist->data == shortlist->data)
		{
			return longerlist;
		}
	}
	return NULL;
}

//判断链表是否有环
SListNode *JugdeCircle(SListNode *head)
{
	SListNode *fast = head;
	SListNode *slow = head;
	while (fast&&slow&&fast->next)//避免找不到fast的next的next
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)//右对齐，找到相遇点，则说明有环
		{
			return fast;
		}
	}
	return NULL;
}

SListNode *detectCircle(SListNode *head)
{
	//先判环,找两个节点，一个一次跳两次，一个一次跳一次
	SListNode *fast = head;
	SListNode *slow = head;
	while (fast&&slow&&fast->next)//避免找不到fast的next的next
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)//找到相遇点，右对齐
		{
			break;
		}
	}
	for (; fast&&fast->next; fast = fast->next,head = head->next)//两个节点中fast和head一起走，找到的公共节点就是环入口
	{
		if (fast->data == head->data)
		{
			return fast;
		}
	}
	return NULL;
}

//找链表的倒数第k个节点
SListNode *FindK(SListNode *head, SLTDataType k)
{
	if (head == NULL)
	{
		return;
	}
	SListNode *fast = head;
	SListNode *slow = head;
	while (k)
	{
		if (fast == NULL)
		{
			return;
		}
		fast = fast->next;
		k--;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void SListPrint(SListNode *phead)
{
	SListNode *tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
}