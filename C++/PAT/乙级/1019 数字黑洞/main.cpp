给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个 (0,10^4 ) 区间内的正整数 N。

输出格式：
如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。注意每个数字按 4 位数格式输出。

输入样例 1：
6767
输出样例 1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例 2：
2222
输出样例 2：
2222 - 2222 = 0000

  
//牛客通过100%，PTA有一个2分测试用例过不了 
#include<iostream>
using namespace std;
#include<sstream>
#include<string>
#include<algorithm>

//得到对应字符串函数
void getString(string& s, string& s1, string& s2,int N)
{
	s = to_string(N);

	//输入数字未满4位时
	while (s.size() < 4)
	{
		s += '0';
	}
	s2 = s;
	sort(s2.begin(), s2.end());
	s1 = s2;
	reverse(s1.begin(), s1.end());
}

int main()
{
	int N = 0;
	cin >> N;
	
	//1.得到非递增排序s1，非递减排序s2
	string s, s1, s2;//s--N转换的字符串；s1--s递减；s2--s递增
	s = to_string(N);
	
	getString(s, s1, s2, N);


	//2.s1和s2分别转换为数字后进行相减
	if(s1 != s2)
	{
		int num1 = 0, num2 = 0;
		int res = 0;
		while (res != 6174)
		{
			num1 = stoi(s1);
			num2 = stoi(s2);
			res = num1 - num2;
			cout << s1 << " - " << s2 << " = " << res << endl;
			getString(s, s1, s2, res);
		}
	}

	else
	{
		cout << s1 << " - " << s2 << " = " << "0000" << endl;
	}
	

	//测试用例
	/*cout << "s:" << s << endl;
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	*/
	system("pause");
	return 0;
}
