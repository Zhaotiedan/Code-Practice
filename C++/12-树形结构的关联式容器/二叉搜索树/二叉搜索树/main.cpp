#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTree.h"

void TestBSTree()
{
	BSTree<int> tree;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto e : arr)
	{
		tree.Insert(e);
	}
	//1.中序遍历，看是否是有序序列
	tree.Inorder();
}
int main()
{
	TestBSTree();
	system("pause");
	return 0;
}