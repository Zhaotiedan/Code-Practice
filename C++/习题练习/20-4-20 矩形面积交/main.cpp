/*问题描述
　　平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。
输入格式
　　输入仅包含两行，每行描述一个矩形。
　　在每行中，给出矩形的一对相对顶点的坐标，每个点的坐标都用两个绝对值不超过10^7的实数表示。
输出格式
　　输出仅包含一个实数，为交的面积，保留到小数后两位。
样例输入
1 1 3 3
2 2 4 4
样例输出
1.00
*/

//注意：这里控制输出小数位数用到了setprecision方法，包含头文件iomanip，并且要在该方法前输出一个fixed

#include<iostream>
using namespace std;
#include<iomanip>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double a1, b1, a2, b2 = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	//左下角横坐标a1与纵坐标a2，
  //横：先都找到最小的（最左方），再找这两个中最大的（最右方）
  //纵：先都找到最小的（最下方），再找这两个中最大的（最上方）
	a1 = max(min(x1, x2), min(x3, x4));
	b1 = max(min(y1, y2), min(y3, y4));

	//右上角横坐标a2与纵坐标b2，
  //横：先都找到最大的（最右方），再找这两个中最小的（最左方）
  //纵：先都找到最大的（最上方），再找这两个中最小的（最下方）
	a2 = min(max(x1, x2), max(x3, x4));
	b2 = min(max(y1, y2), max(y3, y4));

	if (a2 > a1&&b2 > b1)
	{
		cout << fixed<< setprecision(2) << (a2 - a1)*(b2 - b1);//注意不要忘记fixed
	}
	else
	{
		cout << fixed << setprecision(2) << 0.00;
	}
	system("pause");
	return 0;
}
