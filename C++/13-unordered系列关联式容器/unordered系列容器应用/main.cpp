//CSDN blog:https://blog.csdn.net/qq_42913794/article/details/105329213

#include<iostream>
using namespace std;
#include<unordered_map>
#include<string>
#include<unordered_set>

//unordered_map key---v
void Testunordered_map()
{
	unordered_map<string, string> m;
	//1.插入 
	   //通过pair结构体
	m.insert(pair<string, string>("小明", "18岁"));
	m.insert(pair<string, string>("小红", "19岁"));
	m.insert(pair<string, string>("小花", "17岁"));
	   //通过标准库全局函数make_pair
	m.insert(make_pair("小黑", "20岁"));

	//不能重复插入
	m.insert(make_pair("小明", "18岁"));

	//2.map的元素个数
	cout << "SIZE: " << m.size() << endl;  //--4
	//3.map中哈希桶的个数
	cout << "buket number: " << m.bucket_count() << endl; //--8
	//4.某号桶中的元素个数
	cout << "0号桶元素元素个数: " << m.bucket_size(0) << endl;//--0
	//5.某key对应的桶号
	cout << "小黑 所在的桶号: " << m.bucket("小黑") << endl; //--6

	//6.元素访问[]
	   //若key存在，直接返回key所对应的value值
	cout << m["小花"] << endl;  //--17岁
	cout << "SIZE: "<< m.size() << endl; // --4
	   //若key不存在，<key,默认value>会构成一个键值对，并插入容器，结果会返回默认的value，一般为空字符串
	cout << m["小牛"] << endl;  //" "
	cout << "SIZE: "<< m.size() << endl; //--5

	//7.删除
	m.erase("小牛");
	cout << "SIZE: " << m.size() << endl; //--4

	//8.清除
	m.clear();
	cout << "SIZE: " << m.size() << endl; //--0
}

void Testunordered_multimap()
{
	unordered_multimap<string, string> m;

	//重复插入元素
	m.insert(pair<string, string>("小明", "18岁"));
	cout << "SIZE: " << m.size() << endl; //---1
	m.insert(make_pair("小明", "18岁")); 
	cout << "SIZE: " << m.size() << endl; //--2

}
void Testunordered_set()
{
	unordered_set<string> s;

	//插入
	s.insert("小明");
	s.insert("小红");
	s.insert("小花");

	cout << s.size() << endl;

	//不能重复插入，size不会改变，该重复的key值也不会插入进去
	s.insert("小明");

	//迭代器
	unordered_set<string>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
}

void Testunordered_multiset()
{
	unordered_multiset<string> s;

	//插入
	s.insert("小明");
	s.insert("小红");
	s.insert("小花");

	cout << s.size() << endl;

	//可以重复插入
	s.insert("小明");
	cout << s.size() << endl;
	unordered_set<string>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
}

int main()
{
	Testunordered_map();
	Testunordered_multimap();
	Testunordered_set();
	Testunordered_multiset();
	system("pause");
	return 0;
}
