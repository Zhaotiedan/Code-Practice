#define _CRT_SECURE_NO_DEPRECATE 1

#include<iostream>
using namespace std;
#include<vector>

#define MAX 100
typedef struct MGraph
{
	char vex[MAX];//顶点数组
	int edge[MAX][MAX];//存储边的信息
	int vexnum;//顶点个数
	int edgenum;//边的个数
}MGraph;

void Init(MGraph& g, vector<char> vex, vector<vector<int>> edge)
{
	g.vexnum = vex.size();
	g.edgenum = edge.size();
	//顶点存入
	for (int i = 0; i < vex.size(); i++)
	{
		g.vex[i] = vex[i];
	}

	//初始化
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.vexnum; j++)
		{
			g.edge[i][j] = 0;
		}
	}
	//边的存入
	for (int i = 0; i < edge.size(); i++)
	{
		int n1 = edge[i][0];//横坐标--起点
		int n2 = edge[i][1];//纵坐标--终点
		g.edge[n1][n2] = 1;
	}
}

//计算出度为0的顶点个数 
int OutDegreeCount(MGraph g)
{
	int count = 0;
	for (int i = 0; i < g.vexnum; i++)
	{
		int flag = 1;//代表出度为0 为真
		for (int j = 0; j < g.vexnum; j++)
		{
			if (g.edge[i][j] == 1)
			{
				flag = 0;//出度一定不为0
				break;
			}
		}
		if (flag == 1)//代表出度为0
		{
			count++;
		}
	}
	return count;
}

void Print(MGraph g)
{
	//打印顶点信息
	cout << "顶点：" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cout << g.vex[i] << " ";
	}
	cout << endl;
	//打印边的信息
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.vexnum; j++)
		{
			cout << g.edge[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	MGraph g;
	vector<char> vex = { 'A','B','C','D' };//顶点
	//vector<vector<int>> edge = { {0,1,1,0},{0,0,0,0},{0,0,0,1},{1,0,0,0} };
	vector<vector<int>> edge = { {0,1},{0,2},{2,3},{3,0} };

	Init(g, vex, edge);
	Print(g);

	cout << "出度为0的顶点个数：";
	int count = OutDegreeCount(g);
	cout << count;
	return 0;
}
