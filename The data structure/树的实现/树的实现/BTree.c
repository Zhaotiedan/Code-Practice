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
void BinaryTreeDestory(BTNode** root)
{

}
int BinaryTreeSize(BTNode* root)
{

}
int BinaryTreeLeafSize(BTNode* root)
{

}
int BinaryTreeLevelKSize(BTNode* root, int k)
{

}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{

}
// 遍历
void BinaryTreePrevOrder(BTNode* root)
{

}
void BinaryTreeInOrder(BTNode* root)
{

}
void BinaryTreePostOrder(BTNode* root)
{

}
// 非递归遍历
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{

}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{

}
void BinaryTreePrevOrderNonR(BTNode* root)
{

}
void BinaryTreeInOrderNonR(BTNode* root)
{

}
void BinaryTreePostOrderNonR(BTNode* root)
{

}