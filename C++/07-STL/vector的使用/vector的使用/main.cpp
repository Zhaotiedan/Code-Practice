#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


void Print(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//1.构造函数
void Test1()
{
	//无参构造
	vector<int> v1;
	//构造并初始化n个值
	vector<int> v2(4, 100);
	//拷贝构造
	vector<int> v3(v2);
	//迭代器初始化构造
	vector<int> v4(v2.begin(), v2.end());

	int array[] = { 1,2,3,4,5,6,7 };
	vector<int> v5(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v6{ 1,2,3,4,5,6,7 };

	cout << "v1:";
	Print(v1);
	cout << "v2:";
	Print(v2);
	cout << "v3:";
	Print(v3);
	cout << "v4:";
	Print(v4);
	cout << "v5:";
	Print(v5);
	cout << "v6:";
	Print(v6);
}

//2.迭代器操作
void Test2()
{
	vector<int> v1{ 1,2,3 };

	//1.用迭代器进行遍历打印
	//vector<int>::iterator it = v1.begin(); c++98仅支持方式
	auto it = v1.begin();  //begin和end可以换成rbegin和rend  反向迭代器
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//2.用迭代器进行修改
	it = v1.begin();
	while (it != v1.end())
	{
		*it *= 2;
		it++;
	}
	Print(v1);
}

//3.容量操作
void Test3()
{
	vector<int> v1{ 1,2,3,4,5,6,7 };
	cout << "size:" << v1.size() << endl;
	cout << "capacity" << v1.capacity() << endl;

	//扩容
	vector<int> v2;
	//v2[0] = 1;崩溃，还无法访问元素
	size_t sz = v2.capacity();
	for (int i = 0; i < 100; i++)
	{
		v2.push_back(i);
		if (sz != v2.capacity())
		{
			sz = v2.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}

	cout << endl;

	//提前加reserve
	vector<int> v3;
	v3.reserve(100);
	//v3[0] = 1;崩溃
	//不能用v3.resize(100); 因为j=0时是从100个有效元素后面开始放入，就是第101个，会发生150，225扩容
	size_t szz = v3.capacity();
	for (int j = 0; j < 100; j++)
	{
		v3.push_back(j);
		if (szz != v3.capacity())
		{
			szz = v3.capacity();
			cout << "capacity changed:" << szz << endl;
		}
	}
}

//4.增删改查和元素访问
void Test4()
{
	vector<int> v1{ 1,2,3,4,5,6,7 };
	Print(v1);

	v1.push_back(1);//尾插
	Print(v1);
	v1.pop_back();//尾删
	Print(v1);

	// find / insert / erase

	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v1.begin(), v1.end(),3);

	// 在pos位置之前插入30
	v1.insert(pos, 30);
	Print(v1);

	// 删除pos位置的数据
	pos = find(v1.begin(), v1.end(), 3);//必须将pos重新定位,会迭代器失效，后面有
	v1.erase(pos);
	Print(v1);

	// operator[]+index 和 C++11中vector的新式for+auto的遍历
	//通过[]读取第0个位置
	v1[0] = 100;
	Print(v1);

	//swap:交换两个vector的数据空间
	vector<int> v2{ 1,2,3 };
	v1.swap(v2);
	Print(v1);
	Print(v2);
}

//5.迭代器失效  
// 迭代器：类似是指针的一种类型，可以将迭代器定义的对象当成指针的方式进行应用
// 作用：帮助用户透明的(用户可以不用知道该容器的底层数据结构)遍历容器中的元素
void Test5()
{
	vector<int> v1{ 1,2,3,4,5 };

	//1.使用find查找3所在位置的iterator
	auto pos = find(v1.begin(), v1.end(), 3);
	//2.删除pos位置的数据，导致pos迭代器失效。
	v1.erase(pos);
	//cout << *pos << endl;//非法访问

	//同理，在pos前插入数据，也会导致迭代器失效，如Tset4里的例子
	//insert，push_back,会导致增容，而pos还指向原来的空间，但是增容会开辟新空间，释放原来空间
	//resize，reserve，assgin


	//解决方式：给迭代器重新赋值
	int arr[] = { 1,2,3,4,5,6,7 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//删除v2中所有的偶数，错误方式
	//vector<int>::iterator it = v2.begin();
	//while (it != v2.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v2.erase(it);
	//	}
	//	it++;//erase导致it失效，再++导致程序崩溃
	//}
	//改善后：
	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		if (*it % 2 == 0)
		{
			it = v2.erase(it);//erase会返回当前删除位置的下一个位置
		}
		it++;
	}
	Print(v2);
}

//6.引用失效
void Test6()
{
	vector<int> v1{ 1,2,3 };
	int& rv = v1[0];
	rv = 100;
	Print(v1);

	v1.push_back(1);//新空间
	rv = 10;//但是rv引用的原来的空间已经失效
	Print(v1);
	cout << rv << endl;//所以rv里面放的是随机值

	//解决
	rv = v1[0];
	rv = 10;
	Print(v1);
	cout << rv << endl;
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	system("pause");
	return 0;
}