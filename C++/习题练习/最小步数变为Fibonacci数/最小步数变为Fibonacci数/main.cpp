#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
void Jugde(int number, int* max, int* min)
{
	vector<int> v(number * 2);
	v[0] = 0;
	v[1] = 1;
	if (number == 1 || number == 0)
	{
		*max = number;
		*min = number;
		return;
	}
	for (int i = 2; i < 2 * number; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		if (v[i] >= number)
		{
			*max = v[i];
			*min = v[i - 1];
			break;
		}
	}
}
int main()
{
	int number = 0;
	cin >> number;
	int count1 = 0;
	int count2 = 0;
	int max = 0;
	int min = 0;
	Jugde(number, &max, &min);
	count1 = max - number;
	count2 = number - min;
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