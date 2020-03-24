/*
问题描述 
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。 
输入格式 
　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。 
输出格式 
　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。 
样例输入 
3 3 
1 2 3 
4 5 6 
7 8 9 
样例输出 
1 4 7 8 9 6 3 2 5 
样例输入 
3 2 
1 2 
3 4 
5 6 
样例输出 
1 3 5 6 4 2
*/

#include<iostream>
using namespace std;
#include<vector>
#include<string.h>

#define N 200

int main()
{
	int row = 0;
	int col = 0;
	cin >> row >> col;

	////vector创建二维数组并输入
	//vector<vector<int>> vv;
	//vector<int> v;
	//int temp = 0;
	//for (int i = 0; i < row; i++)
	//{
	//	v.clear();
	//	for (int j = 0; j < col; j++)
	//	{
	//		cin >> temp;
	//		v.push_back(temp);
	//	}
	//	vv.push_back(v);
	//}
	int vv[N][N];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> vv[i][j];
		}
	}

	int flag[N][N];
	memset(flag, 0, sizeof(flag));

	int i = 0;
	int j = 0;
	int count = 0;
	while (count < row*col)
	{
		//向下
		while (i < row && 0 == flag[i][j])//注意要将flag判别条件放在后面，因为可能会有下标访问越界，放后面利用短路避开
		{
			cout << vv[i][j] << " ";
			flag[i][j] = 1;
			i++;
			count++;
		}
		//此时i=row，所以要-1，
		i--;
		j++;
		//向右
		while (j < col && 0 == flag[i][j])
		{
			cout << vv[i][j] << " ";
			flag[i][j] = 1;
			j++;
			count++;
		}
		j--;
		i--;
	    //向上
		while (i >= 0 && 0 == flag[i][j])
		{
			cout << vv[i][j] << " ";
			flag[i][j] = 1;
			i--;
			count++;
		}
		i++;
		j--;
	    //向左
		while (j >= 0 && 0 == flag[i][j])
		{
			cout << vv[i][j] << " ";
			flag[i][j] = 1;
			j--;
			count++;
		}
		j++;
		i++;
	}
	system("pause");
	return 0;
}
