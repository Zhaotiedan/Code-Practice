//16->10
#include<iostream>
using namespace std;
#include<string>
#include<math.h>

int main()
{
	string strHex;
	cin >> strHex;
	long long num = 0;
	for (int i = strHex.size() - 1, j = 0; i >= 0, j < strHex.size(); i--, j++)
	{
		//字母
		if (strHex[j] >= 65 && strHex[j] <= 70) 
		{
			switch (strHex[j])
			{
			case'A':num += 10*pow(16, i);
				break;
			case'B':num += 11 * pow(16, i);
				break;
			case'C':num += 12 * pow(16, i);
				break;
			case'D':num += 13 * pow(16, i);
				break;
			case'E':num += 14 * pow(16, i);
				break;
			case'F':num += 15 * pow(16, i);
				break;
			default:
				break;
			}
		}
		else
		{
			num += (strHex[j] - '0')*pow(16, i);
		}
	}
	cout << num;
	system("pause");
	return 0;
}
