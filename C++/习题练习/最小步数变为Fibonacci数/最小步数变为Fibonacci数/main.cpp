#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<time.h>

bool Jugde(int number)
{
	vector<int> v(number*2);
	v[0] = 0;
	v[1] = 1;
	if (number == 1 || number == 0)
	{
		return true;
	}
	for (int i = 2; i < 2*number; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		if (v[i] == number)
		{
			return true;
		}
	}
	return false;
}
int main()
{
int number = 0;
	cin >> number;
	int count1 = 0;
	int count2 = 0;
	int temp = number;
	while (!Jugde(number))
	{
		number++;
		count1++;
	}
	while (!Jugde(temp))
	{
		temp--;
		count2++;
	}
	if (count1 < count2)
	{
		cout << count1 << endl;
	}
	else
	{
		cout << count2 << endl;
	}
	system("pause");
	return 0;
}