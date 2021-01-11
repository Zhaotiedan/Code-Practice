本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string A;
	int B = 0;
	string Q;//商
	int R = 0;//余数
	cin >> A >> B;
	int exnum = A[0] - '0';//字符转换过来的数字  
	int i = 1;
	while (i < A.size())
	{
		int nextexnum = A[i] - '0'; //指向下一个字符
		int temp = 0;//小除数
		int res = 0;//小商
		if (exnum < B)
		{
			temp = exnum * 10 + nextexnum;  
			res = temp / B;
			exnum = temp % B;//5
			i++;
		}
		else
		{
			res = exnum / B;
			exnum = exnum % B;
		}
		Q += res + '0';
		R = exnum;
	}
	cout << Q<<" " << R;

	system("pause");
	return 0;
}
