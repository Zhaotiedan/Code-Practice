#define _CRT_SECURE_NO_WARNINGS 1
/*链接：https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9
来源：牛客网

有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。

给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。

测试样例：
2，3
返回：1*/
#include<iostream>
using namespace std;
#include<string>
#include<vector>

class LCA {
public:
	int getLCA(int a, int b) {
		int A = a;
		int B = b;
		vector<int> va;
		vector<int> vb;
		
		if (a == b)
		{
			return a / 2;
		}
		else if (2 * a + 1 == b)
		{
			return a;
		}
		else if (2 * b + 1 == a)
		{
			return b;
		}
		else
		{
			for (int i = 0; A; i++)
			{
				va.resize(i+1);
				A /= 2;
				va[i] = A;
			}
			for (int j = 0; B; j++)
			{
				vb.resize(j+1);
				B /= 2;
				vb[j] = B;
			}
		}
		for (int k = 0; k < va.size(); k++)
		{
			for (int t = 0; t < vb.size(); t++)
			{
				if (va[k] == vb[t])
				{
					return va[k];
				}
			}
		}
		
	}
};
int main()
{
	LCA l;
	cout << l.getLCA(9, 7) << endl;
	system("pause");
	return 0;
}