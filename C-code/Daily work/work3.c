//1.将两个长度相同的数组的值互换

#include<stdio.h>
#include<stdlib.h>

/*学会写函数
void show(int arr[],int len) 数组名代表数组的首地址，用数组接收 int *arr也可以。*/

int main()
{
	int a[5] = { 0 };
	int b[5] = { 0 };
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &b[j]);
	}
	for (i = 0; i < 5; i++)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	for (i = 0; i < 5; i++)
		printf("%d", a[i]);//*（arr）指针的加法
	printf("\n");
	for (j = 0; j < 5; j++)
		printf("%d", b[j]);
	system("pause");
	return 0;
}

//2.计算一串特殊分数的值.计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。

/*方法1：设一个标志t为1和-1*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int flag = 1;
	double sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		sum = sum + flag * 1.0 / i;// t 和i为都不能为整型?错，flag可以为int和double，i不能为double
		flag *= -1;
	}
	printf("%.8lf\n", sum);//保留8位小数
	system("pause");
	return 0;
}


/*方法二：分为奇数和偶数法*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	float i = 0;
	float j = 0;
	double sum1 = 0;
	double sum2 = 0;
	for (i = 1; i <= 99; i += 2)
	{
		sum1 += 1 / i;
	}
	for (j = 2; j <= 100; j += 2)
	{
		sum2 += 1 / j;
	}
	printf("%lf\n", sum1 - sum2);
	system("pause");
	return 0;
}

//3.计算1~100的数字中，9出现的次数
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i / 10 == 9)//两个if是并列关系 都会执行， 且两个条件框里的东西不相冲突
			count++;
		if (i % 10 == 9)
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}