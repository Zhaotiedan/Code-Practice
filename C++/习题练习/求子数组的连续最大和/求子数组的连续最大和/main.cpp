#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

int main()
{
	int n, curSum = 0, maxSum = -1e5;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		curSum += v[i];
		if (curSum > maxSum) {
			maxSum = curSum;
		}
		if (curSum < 0) {
			curSum = 0;
		}
	}
	cout << maxSum << endl;
	system("pause");
	return 0;
}