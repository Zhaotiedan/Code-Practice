#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
来源：牛客网

二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。*/
#include<iostream>
using namespace std;

int a[1000][1000];

int main()
{
	int row, col,res = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] == 0)
			{
				res++;
				if ((i + 2) < row)
				{
					a[i + 2][j] = -1;
				}
				if ((j + 2) < col)
				{
					a[i][j + 2] = -1;
				}
			}
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}