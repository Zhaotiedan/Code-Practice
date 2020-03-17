/*问题描述
给定n个十六进制正整数，输出它们对应的八进制数。

输入格式
输入的第一行为一个正整数n （1<=n<=10）。
接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

输出格式
输出n行，每行为输入对应的八进制正整数。

【注意】
输入的十六进制数不会有前导0，比如012A。
输出的八进制数也不能有前导0。

样例输入
2
39
123ABC

样例输出
71
4435274  */

方法：
先将十六进制数转换成二进制数，再由二进制数转换成八进制。
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//16->8

int main()
{
	int n = 0;
	cin >> n;
	string strHex;//16进制字符串

	//1.  16转2进制
	for (int i = 0; i < n; i++)
	{
		cin >> strHex;
		string strBin = "";//2进制字符串
		for (int j = 0; j < strHex.size(); j++)
		{
			switch (strHex[j])
			{
			case'0':strBin += "0000";
				break;
			case'1':strBin += "0001";
				break;
			case'2':strBin += "0010";
				break;
			case'3':strBin += "0011";
				break;
			case'4':strBin += "0100";
				break;
			case'5':strBin += "0101";
				break;
			case'6':strBin += "0110";
				break;
			case'7':strBin += "0111";
				break;
			case '8':strBin += "1000"; 
				break;
			case '9':strBin += "1001"; 
				break;
			case 'A':strBin += "1010";
				break;
			case 'B':strBin += "1011";
				break;
			case 'C':strBin += "1100";
				break;
			case 'D':strBin += "1101";
				break;
			case 'E':strBin += "1110";
				break;
			case 'F':strBin += "1111";
				break;
			default:
				break;
			}
		}

		//2.  2进制转8进制
		int num = 0;
		//先使得strBin中0和1总和个数为3的倍数 16进制数053977，转换成2进制001 010 011 100 101 110 111
		//2进制转换为八进制，可得8进制数为1234567。
		if (strBin.size() % 3 == 1)
		{
			strBin = "00" + strBin;//注意一定要将00加到strBin的前面
		}
		else if (strBin.size() % 3 == 2)
		{
			strBin = "0" + strBin;
		}
		int flag = 0;
		for (int i = 0; i <= strBin.size() - 3; i+=3)//注意要加=strBin.size(),不然会漏掉最后一个数字
		{
			num = (strBin[i] - '0') * 4 + (strBin[i + 1] - '0') * 2 + (strBin[i + 2] - '0') * 1;
			//注意这里需要用flag的原因：只有第一个num为0的时候才不输出，后面num为0时需要输出
			if (num)
			{
				flag = 1;
			}
			if (flag)
			{
				cout << num;
			}
		}
		cout << endl;

	}
	system("pause");
	return 0;
}

