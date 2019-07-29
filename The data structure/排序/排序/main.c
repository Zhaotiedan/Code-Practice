#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

#define ARRARY(A) sizeof(a)/sizeof(a[0])

int main()
{
	int a[] = { 1,3,5,7,2,3,4 };
	//πÈ≤¢≈≈–Ú
	MergeSort(a, ARRARY(a));
	print(a, ARRARY(a));

	system("pause");
	return 0;
}