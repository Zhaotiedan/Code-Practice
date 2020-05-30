问题描述
　　从前，有一只吃包子很厉害的猴子，它可以吃无数个包子，但是，它吃不同的包子速度也不同；肉包每秒钟吃x个；韭菜包每秒钟吃y个；没有馅的包子每秒钟吃z个；现在有x1个肉包，y1个韭菜包，z1个没有馅的包子；问：猴子吃完这些包子要多久？结果保留p位小数。
输入格式
　　输入1行，包含7个整数，分别表示吃不同包子的速度和不同包子的个数和保留的位数。
输出格式
　　输出一行，包含1个实数，表示吃完所有包子的时间。
样例输入
4 3 2 20 30 15 2
样例输出
22.50


#include<iostream>
using namespace std;
#include<iomanip>

int main()
{
	double x = 0, y = 0, z = 0;//肉包每秒钟吃x个；韭菜包每秒钟吃y个；没有馅的包子每秒钟吃z个
	double x1 = 0, y1 = 0, z1 = 0;//x1个肉包，y1个韭菜包，z1个没有馅的包子
	cin >> x >> y >> z >> x1 >> y1 >> z1;
	double time = x1 / x + y1 / y + z1 / z;
	cout << setiosflags(ios::fixed) << setprecision(2)<< time << endl;

	system("pause");
	return 0;
}
