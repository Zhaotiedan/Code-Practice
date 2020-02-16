#pragma once

#include<iostream>
#include<vector>
using namespace std;

//规定：哈希表不能插入相同元素
enum STATE{EMPTY,EXIST,DELETE};//对应状态

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

template<class T>
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
		//a.通过哈希函数计算元素在哈希表中的位置
		size_t hashAddr = HashFunc(data);
		//b.如果当前位置状态不为empty：
		while (_vtable[hashAddr]._state != EMPTY)
		{
			//(1)状态为exist，且当前位置数值与插入元素数值相同，直接返回
			if (_vtable[hashAddr]._state == EMPTY && _vtable[hashAddr]._data == data)
			{
				return;
			}
			//(2)状态为delete或为exist，则都线性探测，依次往后遍历查找，知道找到empty的位置为止
			hashAddr++;
			if (hashAddr == _table.capacity())//地址下标走到末尾
			{
				hashAddr = 0;
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
		//b.如果当前状态不为empty：
		while (_vtable[hashAddr]._state != EMPTY)
		{
			//(1)如果状态为EXIST且元素相同，返回当前下标
			if (_vtable[hashAddr]._state == EXIST && _vtable[hashAddr]._data == data)
			{
				return hashAddr;
			}
			//(2)如果状态为EEXIST且data不同 或者 状态为DELETE，继续往后探测
			hashAddr++;
			if (hashAddr == _vtable.capacity())//走到末尾
			{
				hashAddr = 0;
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
	size_t GetSize()cosnt;
	{
		return _size;
	}
private:
	//设计的哈希函数
	size_t HashFunc(const T& data)
	{
		return data % 10;
	}
private:
	vector<Elem<T>> _vtable; 
	size_t _size;
};

void TestHashTable()
{
	vector<int> v = { 21,67,112,99,5,13,44 };
	HashTable<int> ht;
	for (int i = 0; i < v.size(); i++)
	{
		ht.Insert(v[i]);
	}
}

