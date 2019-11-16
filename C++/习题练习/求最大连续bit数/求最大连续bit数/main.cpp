#define _CRT_SECURE_NO_WARNINGS 1
/*链接：https://www.nowcoder.com/questionTerminal/4b1658fd8ffb4217bc3b7e85a38cfaf2
来源：牛客网

求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
    
输入: 一个byte型的数字
    
输出: 无
     
返回: 对应的二进制数字中1的最大连续数*/
#include<iostream>
using namespace std;
#include<string>

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		int maxcount = 0;
		while (num)
		{
			if (num & 1)
			{
				while (num & 1)
				{
					count++;
					num >>= 1;
				}
				if (count > maxcount)
				{
					maxcount = count;
				}
			}
			num >>= 1;
			count = 0;
		}
		cout << maxcount << endl;
	}
	system("pause");
	return 0;
}