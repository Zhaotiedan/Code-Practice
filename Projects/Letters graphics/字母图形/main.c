#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, j, k=0;
	int n, m=0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			k=abs(i-j);
				printf("%c",a[k]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}