#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
来源：牛客网

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int midlength = numbers.size() / 2;
		vector<int> count(numbers.size()*2);
		for (int i = 0; i < numbers.size(); i++)
		{
			count[numbers[i]]++;
		}
		for (int j = 0; j < count.size(); j++)
		{
			if (count[j] > midlength)
			{
				return j;
			}
		}
		return 0;
	}
};
int main()
{
	//vector<int> v{ 1,2,3,2,2,2,5,4,2,1,1,1,1,1,1,1,1,1,1,1 };
	vector<int> v{ 1 };

	Solution s;
	int ret=s.MoreThanHalfNum_Solution(v);
	cout << ret << endl;
	system("pause");
	return 0;
}