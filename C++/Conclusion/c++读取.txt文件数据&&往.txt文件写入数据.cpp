/*源代码：计算2592个数据分成54块，每块对应位置元素相加得平均值保存至新数组*/

#include <iostream>
#include<fstream>
#include<vector>
#include <iomanip>
using namespace std;

#define N 2592


double average(const vector<double> &arr)
{
	double sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	return sum / arr.size();
}



int main()
{
	//读入数据文件
	ifstream in("datadata.txt", ios::in);
	if (!in.is_open())
	{
		cout << "open error!" << endl;
		exit(0);
	}
	//讲数据文件数据放入数组
	int i = 0;
	vector<double> v1(N);
	while (!in.eof() && i < N)
	{
		in >> v1[i];
		i++;
	}

	vector<double> av(48);
	int time = 1;
	while (time <= 48)
	{
		//0,48,96...依次写入
		int k = 0;
		int count = 0;//计数器
		int temp = time-1;//当前对应v1下标
		vector<double> sum(54);
		while (k < 54)
		{
			sum[k] = v1[temp];
			count++;
			temp = time - 1 + 48 * count;
			k++;
		}
		//计算平均值写入av
		av[time - 1] = average(sum);

		time++;
	}

	//测试打印
	for (int i = 0; i < av.size(); i++)
	{
		cout << i << ":" << fixed << setprecision(8) << av[i] << endl;
	}

	//将结果写入文件
	ofstream outfile;
	outfile.open("xiaoqun.txt", ios::in);

	for (int i = 0; i < av.size(); i++)
	{
		outfile << i+1 << "  " << fixed << setprecision(8) << av[i] << endl;
	}

	outfile.close();

	////测试是否将数据读入v1
  
	//int count = 0;//计数器
	//for (int i = 0; i < v1.size(); i++)
	//{
	//	cout << v1[i] << " ";
	//	count++;
	//	if (count == 48)
	//	{
	//		count = 0;
	//		cout << endl;
	//	}
	//}
  
	system("pause");
	return 0;
}



//转换：
参考博客：https://blog.csdn.net/qq_42913794/article/details/116269481?spm=1001.2014.3001.5501
