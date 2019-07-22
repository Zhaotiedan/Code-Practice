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
void ListPushBack(List* plist, LTDataType x)//尾插--本质双链表唯一的插入方式
{
	ListInsertFront(plist->_head, x);
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
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
void ListInsertFront(ListNode* pos, LTDataType x)//前插
{
	ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_prev;//记录原始值  pos指向会发生变化
	cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next= cur;
	cur->_prev = tmp;
}
void ListInsertafter(ListNode* pos, LTDataType x)// 后插
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
void ListRemove(List* plist, LTDataType x)//删除第一个值为x的节点
{
	ListNode* cur = ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
void ListDistinct(List* plist)
{
	ListNode*cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev;)//cur != plist->_head->_next不比较头的无用情况
	{
		if (cur->_data == cur->_next->_data)
		{
			ListErase(cur->_next);//这里不能删掉cur这个节点，因为删除后在if里面就不能访问cur->next了
		}
		else
		{
			cur = cur->_next;
		}
	}
}
List* ListMerger(List* plist1, List* plist2)//合并
{
	ListNode * cur1 = plist1->_head->_next;//cur1和cur2是两个链表的第一个数据
	ListNode * cur2 = plist2->_head->_next;
	ListNode * tmp1;
	ListNode * tmp2;

	while (cur1 != plist1->_head && cur2 != plist2->_head)
	{
		if (cur1->_data > cur2->_data)//链表1当前的值大于链表2当前的值，则链表2的值插在链表1的值的前面
		{
			tmp1 = cur1->_prev;//备份，cur1->_prev会被修改
			tmp2 = cur2->_next;//备份，cur2->_next会被修改

			//ListInsertFront(cur1, cur2->_data);//错误，这个会申请一个新节点插到cur1前面，而不是原来的节点

			cur1->_prev = cur2;	
			cur2->_next = cur1;
			tmp1->_next = cur2;
			cur2->_prev = tmp1;/*让cur2插在cur1和tmp1(cur1的上一个节点）之间*/

			cur2 = tmp2;//cur2找到它的下一个节点
		}
		else
		{
			cur1 = cur1->_next;
		}
	}
	if (cur1==plist1->_head)//遍历结束时，list1到末尾，list2还没结束，且list2剩下的节点值都比list1大，所以要把list2剩下的节点值挂在cur1后面
	{
		tmp2 = plist2->_head->_prev;//记录list2要挂的最后一个节点，cur2是第一个要挂的节点，tmp2是最后一个要挂的

		cur2->_prev = cur1->_prev;//cur2前拉list1的最后一个节点，此时cur1==plist1->_head，所以这个节点就是cur1的prev
		cur1->_prev->_next = cur2;//list1尾节点后拉cur2.此此时cur2挂在list1的尾部

		tmp2->_next = cur1;
		cur1->_prev = tmp2;//tmp2成为了list1的尾节点
	}
	return plist1;
	//遍历结束list2到末尾时，则list2元素全进list1中了
	free(plist2->_head);//释放list2仅剩的头部
}

void ListPrint(List* plist)
{
	//双链表的遍历头
	ListNode * cur;
	printf("head->");
	for (cur = plist->_head->_next; cur!= plist->_head; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("head\n");
}