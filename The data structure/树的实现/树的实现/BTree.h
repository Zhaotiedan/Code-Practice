#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<stdlib.h>

#define ENGTAG '#'

typedef char BTDataType;
typedef char QUDataType;


typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode* Bdata;

//节点结构体
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
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void QueueInit(Queue* pq);//初始化
QueueNode * BuyQueueNode(Bdata x);//获得一个队的新节点
void QueuePush(Queue* pq, Bdata x);//入队
void QueuePop(Queue* pq);//出队

Bdata QueueFront(Queue* pq);//获得队首元素
int QueueEmpty(Queue* pq);//判空
#endif // !_BTREE_H_

