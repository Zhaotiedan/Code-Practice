#define _CRT_SECURE_NO_WARNINGS 1

#include"BTree.h"

int main()
{
	BTNode* mytree = BinaryTreeCreate("ABD##E#H##CF##G##");

	printf("«∞–Ú\n");
	BinaryTreePrevOrder(mytree);
	printf("\n");
	printf("÷––Ú\n");
	BinaryTreeInOrder(mytree);
	printf("\n");
	printf("∫Û–Ú\n");
	BinaryTreePostOrder(mytree);

	printf("\n");
	printf("≤„–Ú\n");
	BinaryTreeLevelOrder(mytree);
	system("pause");
	return 0;
}