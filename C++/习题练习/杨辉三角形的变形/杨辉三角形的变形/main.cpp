#define _CRT_SECURE_NO_WARNINGS 1

/*题目描述：
            1
         1  1  1
      1  2  3  2  1
   1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。

输入n(n <= 1000000000)
输入一个int整数
输出返回的int值
示例1:
输入
4
输出
3*/
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n = 0;
	int flag = 1;
	cin >> n;
	vector<vector<int>> vv(n, vector<int>(2 * n - 1, 0));//2*n-1是最长行的空间
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j <2*i+1; j++)//j与i（行号）关系：2*i+1
		{
			if (i == 0 || j == 0)
			{
				vv[i][j] = 1;
			}
			else if (j == 1)//第二列只有两个数相加
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
			else
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j -2];
			}
		}
	}
	for (int k = 0; k < vv[n-1].size(); k++)
	{
		if (vv[n-1][k] % 2 == 0)
		{
			cout << k + 1 << endl;
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << -1 << endl;
	}
	system("pause");
	return 0;
}