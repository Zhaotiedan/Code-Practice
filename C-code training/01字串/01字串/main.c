#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c, d, e;
	for (a = 0; a <= 1; a++)
		for (b = 0; b <= 1; b++)
			for (c = 0; c <= 1; c++)
				for (d = 0; d <= 1; d++)
					for (e = 0; e <= 1; e++)
						printf("%d%d%d%d%d\n", a, b, c, d, e);
	return 0;
}