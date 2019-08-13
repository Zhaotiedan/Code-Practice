#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
																																															
BTNode* BinaryTreeCreate(BTDataType* a)//还原树
{
	BTNode *cur;
	static int i = 0;
	if (a[i] == ENGTAG)
	{
		i++;
		return NULL;
	}
	else
	{
		cur = (BTNode*)malloc(sizeof(BTNode));
		cur->_data = a[i];
		i++;
		cur->_left = BinaryTreeCreate(a);
		cur->_right = BinaryTreeCreate(a);
		return cur;
	}
}
void BinaryTreeDestory(BTNode* root)//本质为前序遍历
{
	BTNode *left;
	BTNode *right;
	if (root)
	{
		left = root->_left;
		right = root->_right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
	}
}
// 遍历
void BinaryTreePrevOrder(BTNode* root)//前序
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode* root)//中序
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root)//后序
{
	if (root != NULL)
	{  
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	//先将A节点push进去，打印。后面可以通过它找到后面的节点，往里面压一个个的节点，此节点的data类型为BTNode*
	Queue myqueue;
	QueueInit(&myqueue);
	QueuePush(&myqueue, root);
	
	//获得根部节点，打印。再找到左右孩子，判断是否为空，不空就压进去
	while (QueueEmpty(&myqueue))
	{
		QueueNode *tmp = BuyQueueNode(QueueFront(&myqueue));
		printf("%c", tmp->_data->_data);
		//QueuePop(&myqueue);
		if (tmp->_data->_left)
		{
			QueuePush(&myqueue, tmp->_data->_left);
		}
		if (tmp->_data->_right)
		{
			QueuePush(&myqueue, tmp->_data->_right);
		}
		//出队(出头)
		QueuePop(&myqueue);
	}
	/*Queue myqueue;
	QueueInit(&myqueue);
	QueuePush(&myqueue, root);
	while (QueueEmpty(&myqueue))
	{
		Bdata cur = QueueFront(&myqueue);
		printf("%c", cur->_data);
		if (cur->_left)
		{
			QueuePush(&myqueue, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&myqueue, cur->_right);
		}
		QueuePop(&myqueue);
	}*/
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	//1.如果有右孩子，无左孩子，直接return
	//2.一个节点右孩子为空，剩下的节点全是叶子节点，如果出现了非叶子节点，直接return
	Queue myqueue;
	QueueInit(&myqueue);
	QueuePush(&myqueue, root);
	int leaveflag = 0;
	while (QueueEmpty(&myqueue))
	{
		QueueNode *tmp = BuyQueueNode(QueueFront(&myqueue));//tmp=QueueFront(&myqueue)
		printf("%c", tmp->_data->_data);
		QueuePop(&myqueue);
		if (leaveflag)//判断2，遍历出队后队首元素的左孩子和右孩子
		{
			if (tmp->_data->_left || tmp->_data->_right)
				return 0;
			else
			{
				continue;
			}
		}
		if (tmp->_data->_left&&tmp->_data->_right)//右在左在
		{
			QueuePush(&myqueue, tmp->_data->_left);
			QueuePush(&myqueue, tmp->_data->_right);
		}
		else if (tmp->_data->_right && !(tmp->_data->_left))//右在左不在
		{
			return 0;
		}
		else//右不在,置标签
		{
			leaveflag = 1;
			if (tmp->_data->_left)//左在
			{
				QueuePush(&myqueue, tmp->_data->_left);
			}
		}
	}
	return 1;
}
void BinaryTreePrevOrderNonR(BTNode* root)//前序非递归
{
	//1.打印根节点。2.看是否有右子树，有就将右子树压栈，再看是否有左孩子，有则进入到左孩子。3.当没有左孩子时，cur重新遍历到栈顶元素的位置，出栈
	Stack mystack;
	Bdata cur = root;
	StackInit(&mystack,50);
	while (cur || !StackEmpty(&mystack))
	{
		putchar(cur->_data);
		if (cur->_right)
		{
			StackPush(&mystack, cur->_right);
		}
		if (cur->_left)
		{
			cur = cur->_left;
		}
		else//左右皆空
		{
			cur = StackTop(&mystack);
			StackPop(&mystack);
		}
	}
}
void BinaryTreeInOrderNonR(BTNode* root)//中序非递归
{
	//1.将自己压栈。2.看是否有左孩子，有进入左孩子，左孩子压栈，直到左孩子没有为止。3.没有右子树时，打印栈顶，cur指向栈顶，出栈，进入右孩子
	Stack mystack;
	Bdata cur = root;
	StackInit(&mystack,50);
	while (cur || !StackEmpty(&mystack))//cur(正在遍历的节点)为空，栈为空(即将要遍历的节点)时跳出
	{
		for (; cur; cur = cur->_left)//把当前根和所有的左孩子压栈，一直到找不到左孩子为止
		{

			StackPush(&mystack, cur);
		}

		if (!StackEmpty(&mystack))//栈不为空
		{
			//左孩子遍历完，第一个没有左孩子的节点就是第一个出栈的节点。
			//当右孩子为空，栈里是下一个要访问的节点。不为空，就是以这个右子树为根的第一个没有左孩子的节点
			cur = StackTop(&mystack);
			putchar(cur->_data);
			StackPop(&mystack);
			cur = cur->_right;//左子树和根遍历结束，开始遍历右子树。根变为右子树。cur为空时，for循环不会进入
		}
	}

}

void BinaryTreePostOrderNonR(BTNode* root)//后序非递归
{
	//1.先访问左到底，左为空时，标记左边已经访问过。2.标记完，右有，遍历右，再打印。没有右，且标记过，直接打印。
	Stack mystack;
	Bdata cur = root;
	StackInit(&mystack,50);
	int tag[32] = { 0 };//tag的上限为树的层数

	while (cur || !StackEmpty(&mystack))
	{
		for (; cur; cur=cur->_left)//类似中序，将左孩子入栈
		{
			StackPush(&mystack, cur);//size+1
			tag[mystack.size] = 0;//左孩子遍历标签
		}
		while (!StackEmpty(&mystack) && tag[mystack.size] == 1)//左右子树都访问完成时
			//确保了只有左右子树都遍历完成时，才进入这个while
		{
			cur = StackTop(&mystack);
			putchar(cur->_data);
			StackPop(&mystack);//pop一次size-1
			cur = NULL;//循环可以正常跳出
		}
		if (!StackEmpty(&mystack))
		{
			tag[mystack.size] = 1;//证明左子树遍历完毕，根置1
			cur = StackTop(&mystack)->_right;//进入右子树继续遍历
		}
	}
}

void QueueInit(Queue* pq)
{
	pq->_front = (QueueNode*)malloc(sizeof(QueueNode));
	if (pq->_front == NULL)
	{
		return;
	}
	else
	{
		pq->_rear = pq->_front;
		pq->_front->_next = NULL;
	}
}
QueueNode * BuyQueueNode(Bdata x)
{
	QueueNode *cur = (QueueNode*)malloc(sizeof(QueueNode));
	if (cur != NULL)
	{
		cur->_data = x;
		cur->_next = NULL;
		return cur;
	}
	else
	{
		return NULL;
	}
}
void QueuePush(Queue* pq, Bdata x)//入队--尾插
{
	QueueNode  *tmp = BuyQueueNode(x);
	if (pq->_front->_next == NULL)
	{
		pq->_front->_next = tmp;
		pq->_rear = tmp;
	}
	else
	{
		pq->_rear->_next = tmp;
		pq->_rear = tmp;
	}
}
void QueuePop(Queue* pq)//出队--头删
{
	if (QueueEmpty(&pq) == 0)
	{
		return;
	}
	QueueNode*tmp = pq->_front->_next;
	if (tmp->_next == NULL)
	{
		pq->_rear = pq->_front;
	}
	pq->_front->_next = tmp->_next;
	free(tmp);
	tmp = NULL;
}
Bdata QueueFront(Queue* pq)//获得队头元素
{
	if (QueueEmpty(&pq) == 0)
	{
		return (Bdata)0;
	}
	return pq->_front->_next->_data;
}
int QueueEmpty(Queue* pq)//判空
{
	if (pq->_front == pq->_rear)
	{
		return 0;
	}
	return 1;
}

void StackInit(Stack * ps, size_t capacity)
{
	ps->_a = (QUDataType *)calloc(capacity, sizeof(QUDataType));
	ps->capacity = capacity;
	ps->size = 0;
}

void StackPush(Stack* ps, STDataType  x) //入栈
{
	//判满
	if (ps->size==ps->capacity)
	{
		ps->capacity *= 2;	
		ps->_a = (STDataType*)realloc(ps->_a, ps->capacity * sizeof(STDataType));
	}
	else
	{
		ps->_a[ps->size] = x;
		ps->size++;
	}

}
void StackPop(Stack* ps)//出栈
{
	//判空
	if (ps->size==0)
	{
		return;
	}
	else
	{
		ps->size--;
	}
}
STDataType StackTop(Stack* ps)//返回栈顶元素
{
	//判空
	if (ps->size != 0)
	{
		return ps->_a[ps->size - 1];
	}
	return 0;
}
int StackEmpty(Stack* ps)//判空
{
	return ps->size == 0;
}