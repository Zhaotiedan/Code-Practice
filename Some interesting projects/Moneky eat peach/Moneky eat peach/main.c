#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//µÝÍÆ
//int main()
//{
//	int n= 10;
//	int i = 0;
//	int s = 2;
//	for (i = 2; i<=n; i++)
//	{
//		s = (s + 2)*2;
//	}
//	printf("%d",s);
//	system("pause");
//
//	return 0;
//}

//µÝ¹é
int peach(int n)
{
	if (n == 1)
		return 2;
	else if (n > 1)
		return 2 * (peach(n - 1) + 2);
}

int main()
{
	int day= 10;
	printf("%d", peach(day));
	system("pause");
	return 0;
}