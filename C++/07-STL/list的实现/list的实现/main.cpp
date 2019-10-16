#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

namespace List
{
	//List的节点类  
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(data)
		{}

		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _data;
	};

	//list的迭代器类 将节点类型的指针重新封装
	template<class T>
	class list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> self;
	public:
		//构造
		list_iterator(Node* pcur)
			:_pcur(pcur)
		{}
		//迭代器的一些应用
		T& operator*()
		{
			return _pcur->_data;
		}
		T* operator->()
		{
			return &(_pcur->_data);
		}
	private:
		Node* _pcur;
	};
	//list类  带头结点双向循环链表
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		//list的构造
		//无参
		list()
		{
			CreateHead();
		}
		//n个值拷贝
		list(int n, const T& data)
		{
			CreateHead();
			for (size_t i = 0; i < n; i++)
			{
				push_back(data);
			}
		}
		//区间构造，需要一个迭代器模板
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first < last)
			{
				push_back(*first);
				first++;
			}
		}
		//拷贝构造
		list(const list<T>& l)
		{
			CreateHead();
			Node* cur = l._phead->_next;
			while (cur != l._phead)
			{
				push_back(cur->_data);
				cur = cur->_next;
			}
		}

		//赋值运算符重载
		list<T>& operator=(const list<T>& l)
		{
			if (this != &l)
			{
				clear();
				Node* cur = l._phead->_next;
				while (cur != l._phead)
				{
					push_back(cur->_data);
					cur = cur->_next;
				}
			}
		}

		//析构
		~list()
		{
			clear();
			delete _phead;
		}

	public:
		//迭代器操作

		//容量操作
		size_t size()const
		{
			size_t count = 0;
			Node* cur = _phead->_next;
			while (cur != _phead)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}
		size_t empty()const
		{
			return _phead->_next = _phead;
		}
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				for (size_t i = oldsize; i < newsize; i++)
				{
					push_back(data);
				}
			}
			else
			{
				for (size_t i = newsize; i < oldsize; i++)
				{
					pop_back();
				}
			}
			
		}
		//元素访问
		T& front()
		{
			return _phead->_next->_data;
		}
		const T& front()const
		{
			return _phead->_next->_data;
		}
		T& back()
		{
			return _phead->_prev->_data;
		}
		const T& back()const
		{
			return _phead->_prev->_data;
		}
		//修改操作
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void pop_back()
		{
			end()--;
			erase(end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}
		//insert
		//erase
		void clear()
		{
			//头删
			Node* cur = _phead->_next;
			while (cur != _phead)
			{
				_phead->_next = cur->_next;
				delete cur;
				cur = _phead->_next;
			}
			//让头结点自己指自己，构成一个空list
			_phead->_next = _phead;
			_phead->_prev = _phead;
		}

		void swap(list<T>& l)
		{
			swap(_phead, l._phead);
		}

	private:
		void CreateHead()
		{
			_phead = new Node;
			_phead->_prev = _phead;
			_phead->_next = _phead;
		}
	private:
		Node* _phead;
	};
}

void Test1()
{
	List::list<int> l1(2, 10);
}
int main()
{
	Test1();
	system("pause");
	return 0;
}