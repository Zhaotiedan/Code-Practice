#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include "math.h"

//根据用户输入的行列数，生成二维矩阵A L U D 向量 b x y ，并全部初始化为0
double **A, *b, *x, *y, **L, **U, **D;
double calculate_e = 0.0001;//默认精度为10^-4
unsigned int RANK = 4;
unsigned int makematrix()
{
	unsigned int r, c;

	printf("请输入矩阵行列数，用空格隔开：");
	scanf_s("%d %d", &r, &c);

	A = (double**)malloc(sizeof(double*)*r);//创建一个指针数组，把指针数组的地址赋值给a ,*r是乘以r的意思
	for (int i = 0; i < r; i++)
		A[i] = (double*)malloc(sizeof(double)*c);//给第二维分配空间
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			A[i][j] = 0.0;
	}

	b = (double*)malloc(sizeof(double)*r);
	for (int i = 0; i < r; i++)
	{
		b[i] = 0.0;
	}
	x = (double*)malloc(sizeof(double)*c);
	for (int i = 0; i < c; i++)
	{
		x[i] = 0.0;
	}

	L = (double**)malloc(sizeof(double*)*r);//创建一个指针数组，把指针数组的地址赋值给a ,*r是乘以r的意思
	for (int i = 0; i < r; i++)
		L[i] = (double*)malloc(sizeof(double)*c);//给第二维分配空间
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			L[i][j] = 0.0;
	}
	U = (double**)malloc(sizeof(double*)*r);//创建一个指针数组，把指针数组的地址赋值给a ,*r是乘以r的意思
	for (int i = 0; i < r; i++)
		U[i] = (double*)malloc(sizeof(double)*c);//给第二维分配空间
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			U[i][j] = 0.0;
	}
	D = (double**)malloc(sizeof(double*)*r);//创建一个指针数组，把指针数组的地址赋值给a ,*r是乘以r的意思
	for (int i = 0; i < r; i++)
		D[i] = (double*)malloc(sizeof(double)*c);//给第二维分配空间
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			D[i][j] = 0.0;
	}
	y = (double*)malloc(sizeof(double)*c);
	for (int i = 0; i < c; i++)
	{
		y[i] = 0.0;
	}
	return r;
}
//提示用户输入一个方阵的内容 还有常数向量 计算精度
void getmatrix(void)//输入矩阵并呈现
{
	printf("请按行从左到右依次输入系数矩阵A，不同元素用空格隔开\n");
	for (int i = 0; i < RANK; i++)
	{
		for (int j = 0; j < RANK; j++)
		{
			scanf_s("%lf", &A[i][j]);
		}
	}
	printf("系数矩阵如下\n");
	for (int i = 0; i < RANK; i++)
	{
		for (int j = 0; j < RANK; j++)
		{
			printf("%g\t", A[i][j]);
		}
		printf("\n");
	}
	printf("请按从上到下依次输入常数列b，不同元素用空格隔开\n");
	for (int i = 0; i < RANK; i++)
	{
		scanf_s("%lf", &b[i]);
	}
	printf("常数列如下\n");
	for (int i = 0; i < RANK; i++)
	{
		printf("%g\t", b[i]);
	}printf("\n");
	printf("请输入计算精度：（例如：0.0001）\n");
	scanf_s("%lf", &calculate_e);
	printf("计算结果的精度为：%g\n", calculate_e);
}

bool Jacobi_calculation(void)//Jacobi迭代法解线性方程组
{
	double get_add = 0.0, get_e = 0.0;
	printf("利用以上A与b组成的增广阵进行Jacobi迭代法法计算方程组\n");
	for (int i = 0; i < RANK; i++) //初始迭代值为0
	{
		x[i] = 0.0;
		y[i] = 0.0;
	}
	for (int k = 0; k < 100; k++)//最大迭代100次，认为发散
	{
		for (int i = 0; i < RANK; i++)//存上一次的值 用于求误差
		{
			x[i] = y[i];
		}
		for (int i = 0; i < RANK; i++)//迭代一遍
		{
			get_add = 0;
			for (int j = 0; j < RANK; j++)
			{
				get_add = get_add + A[i][j] * x[j];
			}
			y[i] = (-get_add + A[i][i] * x[i] + b[i]) / A[i][i];
		}
		get_add = 0;
		for (int i = 0; i < RANK; i++)//求无穷大范数
		{
			get_add = (fabs(x[i] - y[i]) > get_add) ? fabs(x[i] - y[i]) : get_add;
		}
		if (fabs(get_add) <= calculate_e)
		{
			printf("迭代次数为：%d", k + 1);
			break;
		}
		if (k == 99)//失效
		{
			return false;
		}
	}
	for (int i = 0; i < RANK; i++) //交换xy
	{
		double temp;
		temp = x[i];
		x[i] = y[i];
		y[i] = temp;
	}
	printf("求解x，解得：\n");
	for (int i = 0; i < RANK; i++)
	{
		printf("x%d = %g\n", i + 1, x[i]);
	}
}

bool Gusse_Seidel_calculation(void)//Gausse_Seidel迭代法解线性方程组
{
	double get_add = 0.0, get_e = 0.0;
	printf("利用以上A与b组成的增广阵进行Gausse_Seidel迭代法法计算方程组\n");
	for (int i = 0; i < RANK; i++) //初始迭代值为0
	{
		x[i] = 0.0;
		y[i] = 0.0;
	}
	for (int k = 0; k < 100; k++)//最大迭代100次，认为发散
	{
		for (int i = 0; i < RANK; i++)//存上一次的值 用于求误差
		{
			y[i] = x[i];
		}
		for (int i = 0; i < RANK; i++)//迭代一遍
		{
			get_add = 0;
			for (int j = 0; j < RANK; j++)
			{
				get_add = get_add + A[i][j] * x[j];
			}
			x[i] = (-get_add + A[i][i] * x[i] + b[i]) / A[i][i];
		}
		get_add = 0;
		for (int i = 0; i < RANK; i++)//求无穷大范数
		{
			get_add = (fabs(x[i] - y[i]) > get_add) ? (x[i] - y[i]) : get_add;
		}
		if (fabs(get_add) <= calculate_e)
		{
			printf("迭代次数为：%d", k + 1);
			break;
		}
		if (k == 99)//失效
		{
			return false;
		}
	}
	printf("求解x，解得：\n");
	for (int i = 0; i < RANK; i++)
	{
		printf("x%d = %g\n", i + 1, x[i]);
	}
}

int main()
{
	bool retry;

_again:
	RANK = makematrix();
	getmatrix();
	retry = Jacobi_calculation();
	if (retry == false)
	{
		printf("Jacobi迭代法失效，以下使用Gausse_Seidel迭代法计算\n");
	}
	retry = Gusse_Seidel_calculation();
	if (retry == false)
	{
		printf("Gausse_Seidel迭代法失效\n");
	}

	printf("计算完成，按回车退出程序或按1重新输入矩阵\n");
	getchar();
	if ('1' == getchar())	goto _again;
	return 0;
}
