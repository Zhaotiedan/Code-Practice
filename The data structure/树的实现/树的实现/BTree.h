#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define ENGTAG '#'

typedef char BTDataType;
typedef char QUDataType;

//树节点结构体
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode* Bdata;

//队节点结构体
typedef struct QueueNode
{
	struct QueueNode* _next;
	Bdata _data;
}QueueNode;

//队列结构体
typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _rear; // 队尾
}Queue;

//栈结构体

typedef BTNode* STDataType;

typedef struct Stack
{
	//STDataType _a[StackMax];
	STDataType* _a;

	size_t size;
	size_t capacity; 
}Stack;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a);//不确定a是否是字符串,只要字符串正确，就一定能还原出来树结构，且自动退出

void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 遍历(递归遍历)
void BinaryTreePrevOrder(BTNode* root);//前序
void BinaryTreeInOrder(BTNode* root);//中序
void BinaryTreePostOrder(BTNode* root);//后序


void BinaryTreeLevelOrder(BTNode* root);// 层序遍历(非递归遍历)

int BinaryTreeComplete(BTNode* root);// 判断二叉树是否是完全二叉树

void BinaryTreePrevOrderNonR(BTNode* root);//前序非递归
void BinaryTreeInOrderNonR(BTNode* root);//中序非递归
void BinaryTreePostOrderNonR(BTNode* root);//后序非递归


//队列
void QueueInit(Queue* pq);//初始化
QueueNode * BuyQueueNode(Bdata x);//获得一个队的新节点
void QueuePush(Queue* pq, Bdata x);//入队
void QueuePop(Queue* pq);//出队

Bdata QueueFront(Queue* pq);//获得队首元素
int QueueEmpty(Queue* pq);//判空

//栈
void StackInit(Stack* ps);
void StackPush(Stack* ps, STDataType x);//入栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);//返回栈顶元素
int StackEmpty(Stack* ps);//判空

#endif // !_BTREE_H_