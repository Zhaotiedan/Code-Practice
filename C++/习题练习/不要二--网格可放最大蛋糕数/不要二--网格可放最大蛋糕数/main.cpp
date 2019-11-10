#define _CRT_SECURE_NO_WARNINGS 1

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