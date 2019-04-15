1./*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c, d, e = 0;
	for (a = 1; a <= 5; a++)
		for (b = 1; b <= 5; b++)
			if (a != b)
				for (c = 1; c <= 5; c++)
					if ((c != a) + (c != b) == 2)
						for (d = 1; d <= 5; d++)
							if ((d != c) + (d != b) + (d != a) == 3)
								for (e = 1; e <= 5; e++)
									if ((e != d) + (e != c) + (e != b) + (e != a) == 4)
										if ((b == 2) + (a == 3) == 1)
											if ((b == 2) + (e == 4) == 1)
												if ((c == 1) + (d == 2) == 1)
													if ((c == 5) + (d == 3) == 1)
														if ((e == 4) + (a == 1) == 1)
															printf("A,B,C,D,E的名次依次为：%d %d %d %d %d\n", a, b, c, d, e);
	system("pause");
	return 0;
}

2./*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
嫌疑犯的一个。以下为4个嫌疑犯的供词。
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x = 0;
	for (x = 'a'; x <= 'd'; x++)
		if ((x != 'a') + (x == 'c') + (x == 'd') + (x != 'd') == 3)
			printf("%c is the thief", x);
	system("pause");
	return 0;
}


//3.打印杨辉三角
#include<stdio.h>
#include<stdlib.h>
#define max 100
int main()
{
	int i, j = 0;
	int n = 0;
	int a[max][max];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		a[i][0] = a[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

