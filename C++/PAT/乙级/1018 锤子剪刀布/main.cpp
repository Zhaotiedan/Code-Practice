大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

FigCJB.jpg

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10^5），即双方交锋的次数。
随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。
第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B


#include<iostream>
using namespace std;
#include<vector>
#include<fstream>


typedef struct people
{
	char jia;//甲的手势
	char yi;//乙的手势
}pe;


int main()
{
	int num = 0;//次数
	cin >> num;

	//读取num次游戏 甲乙的手势
	vector<pe> v(num);
  
  //文件读取数据
	ifstream in("data1018.txt", ios::in);
	if (!in.is_open())
	{
		cout << "open error!" << endl;
		exit(0);
	}
	int i = 0;
	while (!in.eof() && i < num)
	{
		in >> v[i].jia >> v[i].yi;
		i++;
	}
  
  /*
  实际PAT判题中不用文件输入，可以这样输入
   for (int i = 0; i < num; i++)
    {
        cin >> v[i].jia >> v[i].yi;
    }
   */ 

  
	//测试文件数据是否读入v数组
	/*for (int i = 0; i < num; i++)
	{
		cout << v[i].jia << " " << v[i].yi << endl;
	}*/

	int v1 = 0, l1 = 0, p1 = 0;//甲的胜，负，平的次数记录
	int C_time1 = 0, J_time1 = 0, B_time1 = 0;//记录甲获胜次数的手势次数
	int v2 = 0, l2 = 0, p2 = 0;//乙的胜，负，平的次数记录
	int C_time2 = 0, J_time2 = 0, B_time2 = 0;//记录乙获胜次数的手势次数

	for (int i = 0; i < num; i++)
	{
		//1.甲是锤头
		if (v[i].jia == 'C')
		{
			if (v[i].yi == 'J')//乙是剪刀，甲胜乙负
			{
				v1++;
				l2++;
				C_time1++;
			}
			else if (v[i].yi == 'B')//乙是布，乙胜甲负
			{
				v2++;
				l1++;
				B_time2++;
			}
			else//乙是锤头，平手
			{
				p1++;
				p2++;
			}
		}

		//2.甲是剪刀
		else if (v[i].jia == 'J')
		{
			if (v[i].yi == 'B')//乙是布，甲胜乙负
			{
				v1++;
				l2++;
				J_time1++;
			}
			else if (v[i].yi == 'C')//乙是锤头，乙胜甲负
			{
				v2++;
				l1++;
				C_time2++;
			}
			else//乙是剪刀，平手
			{
				p1++;
				p2++;
			}
		}

		//3.甲是布
		else
		{
			if (v[i].yi == 'C')//乙是锤头，甲胜乙负
			{
				v1++;
				l2++;
				B_time1++;
			}
			else if (v[i].yi == 'J')//乙是剪刀，乙胜甲负
			{
				v2++;
				l1++;
				J_time2++;
			}
			else//乙是布，平手
			{
				p1++;
				p2++;
			}
		}
	}

	//输出
	cout << v1 << " " << p1 << " " << l1 << endl;//甲的胜平负
	cout << v2 << " " << p2 << " " << l2 << endl;//乙的胜平负


//甲
	if ((B_time1 > C_time1 || B_time1 == C_time1) && (B_time1 > J_time1 || B_time1 == J_time1))
	{
		cout << "B" << " ";
	}
	//2.锤头>or=布；锤头>or等于剪刀
	else if ((C_time1 > B_time1 || C_time1 == B_time1) && (C_time1 > J_time1 || C_time1 == J_time1))
	{
		if (C_time1 == B_time1)
		{
			cout << "B" << " ";
		}
		else
		{
			cout << "C" << " ";
		}
	}
	//3.剪刀>or=锤头，剪刀>or=布
	else if ((J_time1 > C_time1 || J_time1 == C_time1) && (J_time1 > B_time1 || J_time1 == B_time1))
	{
		if (J_time1 == B_time1)
		{
			cout << "B" << " ";
		}
		else if (J_time1 == C_time1)
		{
			cout << "C" << " ";
		}
		else
		{
			cout << "J" << " ";
		}
	}

//乙
	//1.布>or=锤头；布>or=剪刀
	if ((B_time2 > C_time2 || B_time2 == C_time2) &&( B_time2 > J_time2|| B_time2== J_time2))
	{
		cout << "B" ;
	}
	//2.锤头>or=布；锤头>or等于剪刀
	else if ((C_time2 > B_time2 || C_time2 == B_time2) && (C_time2 > J_time2 || C_time2 == J_time2))
	{
	    if (C_time2 == B_time2)
		{
			cout << "B" ;
		}
		else
		{
			cout << "C" ;
		}
	}
	//3.剪刀>or=锤头，剪刀>or=布
	else if ((J_time2 > C_time2 || J_time2 == C_time2) && (J_time2 > B_time2 || J_time2 == B_time2))
	{
		if (J_time2 == B_time2)
		{
			cout << "B" ;
		}
		else if (J_time2 == C_time2)
		{
			cout << "C" ;
		}
		else
		{
			cout << "J" ;
		}
	}


	system("pause");
	return 0;
}

