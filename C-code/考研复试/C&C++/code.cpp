#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


int  main()
{
	//printf("%d",0);

	//char x = 0xFFFF;
	//printf("%d\n", x--);

	/*char c = 'A';
	if ('0' <= c <= '9') printf("YES");
	else printf("NO");*/

	/*
	int a = 10;
	printf("%d\n", a);
	printf("%6d\n", a);*/

	/*double a = 0;
	float b = 0;
	printf("%6.2f\n", a);
	printf("%lf\n", b);*/

	/*long long a = 123456789;
	printf("%d\n", a);
	printf("%ld", a);*/

	//int x = 8, y = -7, z = 9;
	//if (x < y)
	//	if (y < 0)
	//		z = 0;
	//	else//与最近的if配套
	//		z = -1;
	//printf("%d\n", z);

	int i, j, m = 0;
	for (i = 1; i <= 15; i += 4)
		for (j = 3; j <= 19; j += 4)
			m++;
	printf("%d\n", m);
	
	int y = 9;
	for (; y > 0; y--)
	{
		if (y % 3 == 0)
		{
			printf("%3d", --y);
			//continue;
		}
	}
	
	int i;
	int x[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	for (i = 0; i < 4; i++) 
		printf("%3d", x[i][3 - i]);
	
	system("pause");
	return 0;
}

