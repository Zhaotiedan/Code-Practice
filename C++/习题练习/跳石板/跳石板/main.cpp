#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
来源：牛客网
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)

输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
输入
4 24
输出
5*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//求约数
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
     {
		 cout << -1 << endl;
     }
     else
     {
		 cout << res[M] - 1 << endl;
     }
	 return 0;
 }