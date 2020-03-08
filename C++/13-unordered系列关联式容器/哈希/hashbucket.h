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


//哈希桶类的声明，由于HashBucket类在后面定义，避免迭代器类中找不到HashBucket类的定义
template<class T, class DF = DFDef<T>>
class HashBucket;

//封装迭代器
template <class T, class DF = DFDef<T>>
struct HBIterator
{
	typedef HashNode<T> Node;
	typedef HBIterator<T, DF> Self;

	HBIterator(Node* pNode = nullptr, HashBucket<T, DF>* pht = nullptr)
		:_pNode(pNode)
		,_pht(pht)
	{}

	//具有指针类似的操作
	//解引用
	T& operator*()
	{
		return _pNode->_data;
	}

	T* operator->()
	{
		return &(_pNode->data);
	}
	//移动,底层是单链表，只能++朝前走
	//前置++，返回类类型对象的引用
	Self& operator++()
	{
		Next();
		return *this;//下一个节点对应的迭代器
	}
	//后置++
	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}
	//比较 两个迭代器是否在同一个节点的位置
	bool operator!=(Self& s)const
	{
		return _pNode != s._pNode;
	}
	bool operator==(Self& s)const
	{
		return _pNode == s._pNode;
	}

	void Next()
	{
		//_pNode对应链表后序还有节点
		if (_pNode->_pNext)
		{
			_pNode = _pNode->_pNext;
		}

		//_pNode对应链表节点是最后一个节点，则找_pNode后序的第一个非空桶，
		//需要知道此时_pNode在哪个桶里面,通过哈希函数，就需要拿到当前迭代器对应的哈希表
		else
		{
			size_t bucketNum = _pht->HashFunc(_pNode->_data) + 1;//拿到pNode所在桶的下一个桶
			for (; bucketNum < _pht->_vtable.capacity(); bucketNum++)
			{
				if (_pht->_vtable[bucketNum])//当前哈希桶不为空
				{
					_pNode = _pht->_vtable[bucketNum];
					return;
				}
			}
			_pNode = nullptr;
		}
	}

	Node* _pNode;
	HashBucket<T, DF>* _pht;
};

/*迭代器如何与哈希桶类结合：
1.为该类定义一个新的迭代器类 HBIterator<T,DF>
2.在哈希桶类中给迭代器命名
3.增加begin/end
*/


//封装哈希桶
template<class T, class DF >
class HashBucket
{
	//友元类，为了能让迭代器类访问HashBucket中的成员
	friend struct HBIterator<T, DF>;

	typedef HashNode<T> Node;

	//给迭代器命名
	typedef HBIterator<T, DF> iterator;
public:
	HashBucket(size_t capacity = 10)
		:_size(0)
	{
		_vtable.resize(10/*GetNextPrime(10)*/);	
	}

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
	//迭代器方法
	iterator begin()
	{
		//找第一个非空桶
		for (size_t bucketNum = 0; bucketNum < _vtable.capacity(); bucketNum++)
		{
			if (_vtable[bucketNum])
			{
				return iterator(_vtable[bucketNum], this);
			}
		}
		//未找到非空
		return end();
	}
	iterator end()
	{
		return iterator(nullptr, this);
	}

	//测试
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
	//每个桶中都存储一个元素,此时继续插入一定会引起冲突
	void CheckCapacity()
	{
		if (_size == _vtable.capacity())
		{

		}
	}
	size_t HashFunc(const T& data)const
	{
		return DF()(data) % _vtable.capacity();
	}
private:
	vector<Node*> _vtable;//哈希表的每个哈希桶中存储的是节点的地址
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

	cout << "iterator test:" << endl;
	auto it = hb.begin();
	while (it != hb.end())
	{
		cout << *it << " ";
		it++;
	}

}
