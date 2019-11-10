#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
bool IsPri(string& s)
{
	string temp = s;
	reverse(s.begin(), s.end());
	if (temp == s)
	{
		return true;
	}
	return false;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int count = 0;
	for (int i = 0; i < s1.size()+1; i++)
	{
		string tmp = s1;
		string s3 = tmp.insert(i, s2);
		if (IsPri(s3))
		{
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}