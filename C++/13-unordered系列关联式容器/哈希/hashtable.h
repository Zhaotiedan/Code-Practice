#pragma once

#include"Prime.h"

#include<iostream>
#include<vector>
using namespace std;
#include<string>

//规定：哈希表不能插入相同元素
enum STATE{EMPTY,EXIST,DELETE};//对应状态

/*封装元素结构体*/
template <class T>
struct Elem
{
	Elem(const T& data=T())
		:_data(data)
		,_state(EMPTY)
	{}
	T _data;
	STATE _state;
};

/*类模板，兼容非整型的对象也能使用哈希查找*/

//默认转化方式，int  short   long
template <class T>
class DFDef
{
public:
	T operator()(const T& data)
	{
		return data;
	}
};

//将string类型对象转化为int类型
class DFStr
{
public:
	//仿函数
	size_t operator()(const string& s)
	{
		return BKDRHash(s.c_str());
	}
private:
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch; 
		}
		return hash;
	}
};


/*封装哈希表*/
//T：元素的类型
//DF：将T类型对象转化为整型对象的方法的类型,默认为整型转换方法
//isLine：非模板类型参数，代表是否选择线性探测来解决哈希冲突，是--线性探测，否--二次探测
template<class T, class DF = DFDef<T>, bool isLine = true>
class HashTable
{
public:
	HashTable(size_t capacity=10)
		: _size(0)
	{
		_vtable.resize(10);
	}

	//插入
	bool Insert(const T& data)
	{
		//先检测是否需要扩容
		CheckCapacity();

		//a.通过哈希函数计算元素在哈希表中的位置
		size_t hashAddr = HashFunc(data);

		size_t i = 0;//代表二次探测的探测次数

		//b.如果当前位置状态不为empty：
		while (_vtable[hashAddr]._state != EMPTY)
		{
			//(1)状态为exist，且当前位置数值与插入元素数值相同，即元素已经存在，直接退出
			if (_vtable[hashAddr]._state == EXIST && _vtable[hashAddr]._data == data)
			{
				return false;
			}
			//(2)状态为delete或为exist，且元素不存在，则继续探测

			//线性探测，依次往后遍历查找
			if (isLine)
			{
				hashAddr++;
				if (hashAddr == _vtable.capacity())//地址下标走到末尾
				{
					hashAddr = 0;
				}
			}
			//二次探测
			else
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _vtable.capacity();//保证每次是不同的位置
			}

		}
		//c.(循环结束，肯定已经找到空位置)插入元素
		_vtable[hashAddr]._data = data;
		_vtable[hashAddr]._state = EXIST;
		_size++;
		return true;
	}

	//查找
	int Find(const T& data)
	{
		//a.通过哈希函数计算元素在哈希表中的位置
		size_t hashAddr = HashFunc(data);

		size_t i = 0;//代表二次探测的探测次数

		//b.如果当前状态不为empty：
		while (_vtable[hashAddr]._state != EMPTY)
		{
			//(1)如果状态为EXIST且元素相同，返回当前下标
			if (_vtable[hashAddr]._state == EXIST && _vtable[hashAddr]._data == data)
			{
				return hashAddr;
			}
			//(2)如果状态为EXIST且data不同 或者 状态为DELETE，继续往后探测
			
			//线性探测
			if (isLine)
			{
				hashAddr++;
				if (hashAddr == _vtable.capacity())//地址下标走到末尾
				{
					hashAddr = 0;
				}
			}
			//二次探测
			else
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _vtable.capacity();//保证每次是不同的位置
			}
		}
		return -1;//未找到
	}

	//删除
	bool Erase(const T& data)
	{
		size_t pos = HashFunc(data);
		if (pos != -1)
		{
			_vtable[pos]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}

	//求当前元素个数
	size_t GetSize()const
	{
		return _size;
	}

	void Swap(HashTable<T, DF, isLine>& ht)
	{
		_vtable.swap(ht._vtable);//vector中的swap交换，直接交换vector底层的三个指针，比常规的swap(v1,v2)开辟临时空间效率要高很多
		swap(_size, ht._size);
	}

private:
	//扩容
	void CheckCapacity()
	{
		//if (_size * 10 / _vtable.capacity() >= 7)删除位置可以插入元素
		if (_total * 10 / _vtable.capacity() >= 7)//删除位置不能插入元素
		{
			//1.创建一个新哈希表
			HashTable<T, DF, isLine> NewHt(GetNextPrime(_vtable.capacity()));
			//2.将旧表中转态为EXIST的元素放入新表
			for (auto e : _vtable)
			{
				if (e._state == EXIST)
				{
					NewHt.Insert(e._data);
				}
			}
			//3.交换新表和旧表结构体的内容
			Swap(NewHt);
		}
	}
	//设计的哈希函数
	size_t HashFunc(const T& data)
	{
		//DF df;
		//return df(data) % 10;//df不是函数，是一个对象名，调用类中重载的()方法
		return DF()(data) % _vtable.capacity();//DF()是一个对象，仿函数
	}
private:
	vector<Elem<T>> _vtable; 
	size_t _size;//哈希表中存储的有效元素的个数

	//由于存在限制条件，删除后的元素位置不能再插入元素，所以扩容的时候不能再使用size作为判断条件
	size_t _total;//哈希表中已经存储的元素个数，=有效元素+删除元素之和
};

/*测试*/

//1.测试哈希表的插入，查找，删除等接口
void TestHashTable1()
{
	vector<int> v = { 21,67,112,99,5,13,44 };
	HashTable<int> ht;
	for (int i = 0; i < v.size(); i++)
	{
		ht.Insert(v[i]);
	}
	cout << ht.GetSize() << endl;


	ht.Insert(87);
	ht.Insert(77);
	cout << ht.GetSize() << endl;


	if (ht.Find(87) != -1)
	{
		cout << "87 in" << endl;
	}
	else
	{
		cout << "87 not in" << endl;
	}

	cout << "before erase 67" << endl;
	if (ht.Find(67) != -1)
	{
		cout << "67 in" << endl;
	}
	else
	{
		cout << "67 not in" << endl;
	}
	ht.Erase(67);
	cout << "after erase 67" << endl;
	if (ht.Find(67) != -1)
	{
		cout << "67 in" << endl;
	}
	else
	{
		cout << "67 not in" << endl;
	}
	//看看87还在不在
	if (ht.Find(87) != -1)
	{
		cout << "87 in" << endl;
	}
	else
	{
		cout << "87 not in" << endl;
	}
}

//2.测试是否可以放入string类型的对象
void TestHashTable2()
{
	HashTable<string, DFStr, false> ht;
	ht.Insert("I love HashTable!");
}
