#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int main()
{
	int Decnum;
	cin >> Decnum;
	string strHex;
	if (0 == Decnum)
	{
		strHex = "0";
	}
	while (Decnum)
	{
		int res = Decnum % 16;
		if (res >= 10)
		{
			switch (res)
			{
			case 10:strHex += 'A';
				break;
			case 11:strHex += 'B';
				break;
			case 12:strHex += 'C';
				break;
			case 13:strHex += 'D';
				break;
			case 14:strHex += 'E';
				break;
			case 15:strHex += 'F';
				break;
			default:
				break;
			}
		}
		else
		{
			strHex += (res + '0');//注意数字需要转换为字符
		}
		Decnum /= 16;
	}
	reverse(strHex.begin(),strHex.end());
	cout << strHex;
	system("pause");
	return 0;
}
