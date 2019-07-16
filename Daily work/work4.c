//1.打印一个菱形
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*方法一：循环法
详情步骤思路见CSDN博客*/
int main()
{
	int line = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	scanf("%d", &line);
	//正金字塔：上半部分+最中间的部分
	for (i = 1; i < =line; i++)
	{

		for (j = 1; j < line-i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <2*i-1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	/*for (i = 1; j < line + i; j++)
	{
		putchar(j < line - i ? ' ': '*');
	}*/

	//下半部分
	for (i = line-1; i >0; i--)
	{
		for (j = 1; j < line - i; j++)
		{
			printf(" ");
		}
		for (k = 1; k < 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

/*方法二：字符移动法
比较死板，但是好玩*/
int main()
{
	char arr1[] = "      *      ";
	char arr2[] = "*************";
	char arr3[] = "             ";
	int left = 0;
	int right = strlen(arr1) - 1;
	int i = 0;
	while (i <= 6)
	{
		int mid = left + (right - left) / 2;
		arr3[mid - i] = arr2[mid - i];
		arr3[mid + i] = arr2[mid + i];
		i++;
		printf("%s\n", arr3);

	}
	while (left < right)
	{
		arr2[right] = arr1[right];
		arr2[left] = arr1[left];
		left++;
		right--;
		printf("%s\n", arr2);
	}
	system("pause");
	return 0;
}

//2.求0~999之间的水花数
//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。 
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
/*153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3。
370 = 3 ^ 3 + 7 ^ 3 + 0 ^ 3。
371 = 3 ^ 3 + 7 ^ 3 + 1 ^ 3。
407 = 4 ^ 3 + 0 ^ 3 + 7 ^ 3。*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i = 0;
	int a, b, c = 0;
	for (i = 100; i <= 999; i++)
	{
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		if(i==a*a*a+b*b*b+c*c*c)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//深化一下  非三位数?假如不是三位数，要定义计数器先判断位数，再几次方
int main()
{
	//判断几位数

	int i = 0;
	for (i = 0; i < 99999; i++)//求0~9999之间的
	{
		int sum = 0;//sum不能放在外面，每一次计算完要归0
		int tmp = i;//tmp也是
		int count = 0;//count也是
		while (tmp != 0)//123 12 1 0
		{
			count++;
			tmp /= 10;
		}
		tmp = i;

		//判断几位数：
		int modflag = 1;
		if (i%modflag == 0)
		{
			count++;
			modflag *= 10;
		}
		//求各位数的数字
		while (tmp != 0)
		{
			sum += pow((double)(tmp % 10), count);
			tmp = tmp / 10;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}

//3.求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和.例如：2+22+222+2222+22222 

//公式：an=an-1*10+a
#include<stdio.h>
#include<stdlib.h>

//优化循环
int main()
{
	int n = 0;
	int i = 0;
	int a = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d%d", &a, &n);
	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}