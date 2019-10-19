#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Judge
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		int index = 0;
		int outdex = 0;
		stack<int> s;
		while (outdex < popV.size())
		{
			while (s.empty() || s.top() != popV[outdex])
			{
				if (index < pushV.size())
				{
					s.push(pushV[index]);
					index++;
				}
				else//入栈序列走到尽头，栈顶元素和当前出栈元素还是不相等
				{
					return false;
				}
			}
			s.pop();
			outdex++;
		}
		return true;
	}
};
int main()
{
	vector<int> pushV{ 1,2,3,4,5 };
	vector<int> popV1{ 5,4,3,2,1 };
	vector<int> popV2{ 4,3,5,1,2 };

	Judge j;
	cout << j.IsPopOrder(pushV, popV1) << endl;
	cout << j.IsPopOrder(pushV, popV2) << endl;

	system("pause");
	return 0;
}