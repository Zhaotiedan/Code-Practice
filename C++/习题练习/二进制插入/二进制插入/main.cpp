#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/30c1674ad5694b3f8f0bc2de6f005490?toCommentId=145988
来源：牛客网

有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。

给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。

测试样例：
1024，19，2，6
返回：1100*/

#include<iostream>
using namespace std;

int GetBinInsert(int n, int m, int j, int i)
{
	m <<= j;
	return n | m;
}
int main()
{
	int m, n, j, i = 0;
	cin >> n >> m >> j >> i;
	cout << GetBinInsert(n, m, j, i) << endl;
	system("pause");
	return 0;
}