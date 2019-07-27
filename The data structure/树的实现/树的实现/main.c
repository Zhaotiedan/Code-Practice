#define _CRT_SECURE_NO_WARNINGS 1

#include"BTree.h"

int main()
{
	BTNode* mytree = BinaryTreeCreate("ABD##E#H##CF##G##");//前序+#确定一棵唯一的二叉树

	printf("前序\n");
	BinaryTreePrevOrder(mytree);
	printf("\n");
	printf("中序\n");
	BinaryTreeInOrder(mytree);
	printf("\n");
	printf("后序\n");
	BinaryTreePostOrder(mytree);

	printf("\n");
	printf("层序\n");
	BinaryTreeLevelOrder(mytree);

	printf("\n");
	printf("前序非递归\n");
	BinaryTreePrevOrderNonR(mytree);
	printf("\n");
	printf("中序非递归\n");
	BinaryTreeInOrderNonR(mytree);
	printf("\n");
	printf("后序非递归\n");
	BinaryTreePostOrderNonR(mytree);

	printf("\n");
	printf("判断是否是完全二叉树:\n");
	int result= BinaryTreeComplete(mytree);
	printf("%d", result);
	system("pause");

	return 0;
}