#define _CRT_SECURE_NO_DEPRECATE 1

#include<iostream>
using namespace std;
#include<vector>

#define MAX 100
typedef struct EdgeNode//边表结点
{
	int adjvex;//与顶点相连的 邻接点的下标  
	struct EdgeNode* next;
}Edgenode;

typedef struct VexNode//顶点
{
	int data;
	EdgeNode* frist;//指向依附于该顶点的边 指针
}Vexnode;

typedef Vexnode Adjlist[MAX];//邻接表类型

typedef struct ALGraph
{
	Adjlist adjlist;//邻接表   == Vexnode adjlist[MAX];
	int vexnum;//顶点个数
	int edgenum;//边的个数
}ALGraph;

void Init(ALGraph& g, vector<int> vex, int edgenum, vector<vector<int>> edge)
{
	g.vexnum = vex.size();//顶点个数
	g.edgenum = edgenum;//边数
	//插入顶点信息
	for (int i = 0; i < vex.size(); i++)
	{
		g.adjlist[i].data = vex[i];
		g.adjlist[i].frist = NULL;
	}
	//插入边的信息
	for (int i = 0; i < edge.size(); i++)
	{
		for (int j = 0; j < edge[i].size(); j++)
		{
			//构造新节点
			Edgenode* p = (Edgenode*)malloc(sizeof(Edgenode));
			p->adjvex = edge[i][j];//下标
			p->next = NULL;
			//插入
			if (g.adjlist[i].frist == NULL)//判断该边表结点 是否为 顶点结点指向的第一条边对应结点
			{
				g.adjlist[i].frist = p;
			}
			else//若不是  采用头插法将新节点插入
			{
				p->next = g.adjlist[i].frist;
				g.adjlist[i].frist = p;
			}
		}
	}
}

bool Dvisited[MAX] = { false };//深度优先遍历 访问标记数组
void DFS(ALGraph g, int i)//对单个节点的深度优先遍历
{
	//1.看当前结点是否被访问
	if (Dvisited[i] == false)
	{
		cout << g.adjlist[i].data;
	}
	Dvisited[i] = true;//2.
	//3.
	Edgenode* p = g.adjlist[i].frist;//p指向当前顶点的边表结点
	while (p)
	{
		if (Dvisited[p->adjvex] == false)
		{
			DFS(g, p->adjvex);
		}
		p = p->next;
	}
}

void DFStravel(ALGraph g)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		if (Dvisited[i] == false)
		{
			DFS(g, i);
		}
	}
}

void Print(ALGraph g)
{
	cout << "顶点：" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cout << g.adjlist[i].data << " ";
	}
	cout << endl;
	cout << "边：" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cout << "顶点" << g.adjlist[i].data << "->";
		Edgenode* p = g.adjlist[i].frist;
		while (p != NULL)
		{
			cout << g.adjlist[p->adjvex].data << "->";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}


int main()
{
	ALGraph g;
	vector<int> vex = { 1,2,3,4,5 };//顶点
	vector<vector<int>> edge = { {1,4},{0},{3},{2,4},{0,3} };//边
	int edgenum = 7;//边的个数
	Init(g, vex, edgenum, edge);
	Print(g);

	cout << "深度优先遍历结果：";
	DFStravel(g);
	return 0;
}
