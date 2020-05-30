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
