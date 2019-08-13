#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c, d = 0;
	for (a = 1; a <= 4; a++)
		for (b = 1; b <= 4; b++)
			if (a != b)
				for (c = 1; c <= 4; c++)
					if ((c != a) + (c != b) == 2)
						for (d = 1; d <= 4; d++)
							if ((d != a) + (d != b) + (d != c) == 3)
								if((a==1)+(b==3)==1)
									if((c==1)+(d==4)==1)
										if((d==2)+(a==3)==1)
									
								printf("a,b,c,d的名次依次是：%d,%d,%d,%d\n", a, b, c, d);
	system("pause");
	return 0;
}