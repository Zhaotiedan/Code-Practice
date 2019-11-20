#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 void Get(int num, vector<int>& v) 
 {
	 for (int i = 2; i <= num/2; i++) {
		 if (num%i == 0) {
			 v.push_back(i);
			 if (num / i != i)
				 v.push_back(num / i);
		 }
	 }
 }

 int main() 
 {
	 int N, M;
	 while (cin >> N >> M) 
	 {
		 vector<int> res(M + 1, 0);
		 res[N] = 1;
		 for (int i = N; i <= M; i++) 
		 {
			 vector<int> v;

			 //位置i无法到达，跳过
			 if (res[i] == 0)
				 continue;
			 Get(i, v);//记录从起点到i的最小步数
			 for (int j = 0; j < v.size(); j++) 
			 {
				 //由点i出发能到达的点
				 if ((v[j] + i) <= M && res[v[j] + i] != 0)
					 //其它点也能到达，比较大小，记录最小步数
					 res[v[j] + i] = min(res[v[j] + i], res[i] + 1);
				 else if ((v[j] + i) <= M)
					 //到达点i的最小步数加1
					 res[v[j] + i] = res[i] + 1;
			 }
		 }
		 if (res[M] == 0)
			 cout << -1 << endl;
		 else
			 cout << res[M] - 1 << endl;
	 }
	 return 0;
 }