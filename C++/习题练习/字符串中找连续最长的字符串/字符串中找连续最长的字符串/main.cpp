#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<string>

int main()
{
	string s;
	getline(cin, s);
	vector<char> v{ '0','1','2','3','4','5','6','7','8','9'};
	string store;
	string result;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (s[i] == v[j])
				{
					store.reserve(1);
					store += s[i];
					i++;
				}
			}
			if (store.size() > result.size())
			{
				result = store;
			}
		}
		store.clear();
	}
	cout << result << endl;
	system("pause");
	return 0;
}