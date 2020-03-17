#define _CRT_SECURE_NO_WARNINGS 1
/*给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数*/


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

int main()
{
	int num, change = 0;
	cin >> num >> change;
	vector<int> v;
	int i = 0;
	if (num == 0 && (change < 2 || change>16))
	{
		cout << num << endl;
	}
	if (change <= 9)
	{
		while (num)
		{
			//v.reserve(1);
			v.resize(i + 1);
			v[i] = num % change;
			i++;
			num /= change;
		}
		for (int i = v.size() - 1; i >= 0; i--)
		{
			cout << v[i];
		}
	}
	else
	{
		vector<char> v1{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
		while (num)
		{
			//v.reserve(1);
			v.resize(i + 1);
			v[i] = v1[num % change];
			i++;
			num /= change;
		}
		for (int i = v.size() - 1; i >= 0; i--)
		{
			cout << v[i];
		}
	}

	system("pause");
	return 0;
}
