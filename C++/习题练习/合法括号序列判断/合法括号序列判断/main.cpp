#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		auto it = A.begin();
		while (it != A.end())
		{
			if (*it != '(' && *it != ')')
			{
				return false;
			}
			it++;
		}
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == '(')
			{
				count1++;
			}
			else
			{
				count2++;
			}
		}
		if (count1 == count2)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	string s;
	int length;
	getline(cin, s);
	cin >> length;
	Parenthesis p;
	cout << p.chkParenthesis(s, length) << endl;
	system("pause");
	return 0;
}