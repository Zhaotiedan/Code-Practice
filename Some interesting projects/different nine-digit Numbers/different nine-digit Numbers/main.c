#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int panbie(int x, int y)
{
	int i, m, n;
	int a[10] = { 0 };
	for (i = 0; i <= 4; i++)
	{
		n = x % 10;
		a[n]++;
		x = x / 10;
	}
	for (i = 0; i <= 3; i++)
	{
		n = y % 10;
		a[n]++;
		y = y / 10;
	}

	for (i = 0; i <= 9; i++)
		if (a[i] >= 2)
			return 0;
	return 1;

}

int main()
{
	int wu, si, i;
	for (wu = 10000; wu < 100000; wu++)
		for (si = 1000; si < 10000; si++)
		{
			if (wu == (2 * si))
			{
				i = panbie(wu, si);
				//printf("%d\n", i);
				if (i == 1)
					printf("%d=2*%d\n", wu, si);
			}

		}
	system("pause");
	return 0;
}