#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
#define max(a, b)  (((a) > (b)) ? (a) : (b))

int main()
{
	int num1, num2 = 0;
	cin >> num1 >> num2;
	int ret = 0;
	int max = max(num1, num2);
	do
	{
		if (max%num1 == 0 && max%num2 == 0)
		{
			ret = max;
			break;
		}
		max++;
	} while (1);
	cout << ret << endl;
	system("pause");
	return 0;
}