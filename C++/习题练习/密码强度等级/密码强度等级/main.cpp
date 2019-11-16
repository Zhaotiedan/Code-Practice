#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s;
	getline(cin, s);
	int score = 0;
	//³¤¶È
	for (int i = 0; i < s.size(); i++)
	{
		if (s.length() <= 4)
		{
			score += 4;
		}
		if (s.length() >= 5 && s.length() <= 7)
		{
			score += 10;
		}
		if (s.length() >= 8)
		{
			score += 25;
		}
	}
	//×ÖÄ¸
	for (int j = 0; j < s.size(); j++)
	{
		if (s[j] < 'A' || s[j]>'z')
		{
			score += 0;
		}
		else if ((s[j] > 'a'&&s[j] < 'z')|| s[j] > 'A'&&s[j] < 'Z')
		{
			score += 10;
		}
		else
		{
			score += 20;
		}
	}
	//Êý×Ö


	if (score >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
	if (score >= 80)
	{
		cout << "SECURE" << endl;
	}
	if (score >= 70)
	{
		cout << "VERY_STRONG" << endl;
	}
	if (score >= 60)
	{
		cout << "STRONG" << endl;
	}
	if (score >= 50)
	{
		cout << "AVERAGE" << endl;
	}
	if (score >= 25)
	{
		cout << "WEAK" << endl;
	}
	if (score >= 0)
	{
		cout << "VERY_WEAK" << endl;
	}
	system("pause");
	return 0;
}