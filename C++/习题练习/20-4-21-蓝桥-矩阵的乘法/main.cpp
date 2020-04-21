/*问题描述
　　给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
　　例如：
　　A =
　　1 2
　　3 4
　　A的2次幂
　　7 10
　　15 22
输入格式
　　第一行是一个正整数N、M（1<=N<=30, 0<=M<=5），表示矩阵A的阶数和要求的幂数
　　接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值
输出格式
　　输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开
样例输入
2 2
1 2
3 4
样例输出
7 10
15 22
*/

#include<iostream>
using namespace std;
#define MAX 50
#include<string.h>

int main()
{
	int n = 0, m = 0;//阶数和幂数
	int arr[MAX][MAX];
	int arr2[MAX][MAX];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}
	while (m>1)
	{
		int temp[MAX][MAX];
		memset(temp, 0, sizeof(temp));

		/*核心*/
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					temp[i][j] += arr[i][k] * arr2[k][j];
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = temp[i][j];
			}
		}
		m--;
	}
	//0次幂
	if (m == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = 0;
				}
			}
		}
	}
	//打印
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
