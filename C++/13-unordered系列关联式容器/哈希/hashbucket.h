#pragma once

#include<iostream>
using namespace std;
#include<vector>

#include"Prime.h"

//节点结构体
template <class T>
struct HashNode
{
public:
	HashNode(const T& data = T())//T为内置类型--T()=0; T为自定义类型---调用T内的无参构造函数
		:_pNext(nullptr)
		,_data(data)
	{}
	HashNode<T>* _pNext;
	T _data;
};

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


template<class T, class DF = DFDef<T>>
class HashBucket
{
	typedef HashNode<T> Node;
public:
	HashBucket(size_t capacity = 10)
		:_size(0)
	{
		_vtable.resize(10/*GetNextPrime(10)*/);	

	}
        
        //插入
	bool Insert(const T& data)
	{
		//1.计算桶号
		size_t bucketNum = HashFunc(data);
		//2.检测当前元素是否存在
		Node* pcur = _vtable[bucketNum];
		while (pcur)
		{
			if (pcur->_data == data)
			{
				return false;
			}
			pcur = pcur->_pNext;
		}
		//3.说明已有空位置，插入元素--头插
		pcur = new Node(data);
		pcur->_pNext = _vtable[bucketNum];
		_vtable[bucketNum] = pcur;
		_size++;
		return true;
	}

        //删除
	bool Erase(const T& data)
	{
		//1.计算桶号
		size_t bucketNum = HashFunc(data);
		//2.寻找节点
		Node* pcur = _vtable[bucketNum];
		Node* pre = nullptr;
		while (pcur)
		{
			if (pcur->_data == data)
			{
				//删除节点
				//if (pre == nullptr)//删除的是第一个节点
				if (_vtable[bucketNum] == pcur)//删除的是第一个节点

				{
					_vtable[bucketNum] = pcur->_pNext;
				}
				else
				{
					//删除非第一个节点
					pre->_pNext = pcur->_pNext;
				}
				delete pcur;
				_size--;
				return true;

			}
			else
			{
				pre = pcur;
				pcur = pcur->_pNext;
			}
		}
		return false;
	}

	//查找
	Node* Find(const T& data)const
	{
		//1.计算桶号
		size_t bucketNum = HashFunc(data);
		//2.寻找节点
		Node* pcur = _vtable[bucketNum];
		while (pcur)
		{
			if (pcur->_data == data)
			{
				return pcur;
			}
			else
			{
				pcur = pcur->_pNext;
			}
		}
		return nullptr;
	}

	//当前哈希桶中的元素
	size_t Size()
	{
		return _size;
	}
	//当前哈希桶元素是否为空
	bool Empty()
	{
		return _size == 0;
	}

	void PrintHashBucket()
	{
		for (int bucketNum = 0; bucketNum < _vtable.capacity(); bucketNum++)
		{
			Node* pcur = _vtable[bucketNum];
			cout << "table[" << bucketNum << "]:";
			while (pcur)
			{
				cout << pcur->_data << "-->";
				pcur = pcur->_pNext;
			}
			cout << "NULL" << endl;
		}
	}
private:
	size_t HashFunc(const T& data)const
	{
		return DF()(data) % _vtable.capacity();
	}
private:
	vector<Node*> _vtable;//链表中存储的是节点的地址
	size_t _size;//有效元素个数
};

void TestHashBucket()
{
	HashBucket<int> hb;
	vector<int> v{ 1,4,7,9,6,5 };
	for (auto e : v)
	{
		hb.Insert(e);
	}
	cout <<"hb.size:"<< hb.Size() << endl;//6
	hb.PrintHashBucket();

	hb.Insert(44);
	hb.Insert(54);
	cout << "hb.size:" << hb.Size() << endl;//8
	hb.PrintHashBucket();

	hb.Erase(44);
	if (hb.Find(44))
	{
		cout << "44 is in HashBucket" << endl;
	}
	else
	{
		cout << "44 is not in HashBucket" << endl;
	}
	cout << "hb.size:" << hb.Size() << endl;//7
	hb.PrintHashBucket();

}
