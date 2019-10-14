#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<assert.h>

namespace Vector
{
	//1.类函数成员实现

	template<class T>

	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		//构造

		//无参构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		//用n个data值构造
		vector(int n, const T& data)
			:_start(new T[n])
		{
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = data;
			}
			_finish = _start + n;
			_endofstorage = _finish;
		}
		//区间构造 [first,last)
		//如果使用iterator做迭代器,该区间只能是vector类型的迭代器，
		//需要重新定义迭代器，该区间可以为任意容器的迭代器
		template<class Iteractor>
		vector(Iteractor first, Iteractor last)
		{
			//先获取区间元素个数
			size_t n = 0;
			auto it = first;
			while (it != last)
			{
				n++;
			}
			//开辟空间
			_start = new T[n];
			//放置区间元素
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = *first;
				first++;
			}
			_finish = _start + n;
			_endofstorage = _finish;
		}

		//拷贝构造
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			//1.给新v开辟空间
			reserve(v.capacity());
			//2.用迭代器同时遍历新旧v，拷贝元素
			iterator it = begin();
			const_iterator cit = v.cbegin();
			while (cit != v.cend())
			{
				*it = *cit;
				it++;
				cit++;
			}
			//3.更新finish和endofstorage指针
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}

		//运算符重载
		vector<T>& operator=(const vector<T> v)
		{
			swap(v);
			return *this;
		}

		//销毁
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		/*接口实现*/

	//2、迭代器 普通类型和const类型
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}

		//3.容量操作
		size_t size() const//成员变量不能被改
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}
		bool empty()const
		{
			return _start == _finish;
		}


		// T():
		// 如果T代表内置类型，T()--->0
		// 如果T代表自定义类型，T()---> 调用该类的无参构造函数
		void resize(size_t newsize,const T& data = T())
		{
			size_t oldsize = size();
			//newsize先与oldsize比较，大于则进行下一步
			if (newsize > oldsize)
			{
				size_t oldcapacity = capacity();
				//再与oldcapacity比较，大于则扩容
				if (newsize > oldcapacity)
				{
					reserve(newsize);
				}
				//最后填充剩余空间
				for (; oldsize < newsize; oldsize++)
				{
					*_finish = data;
					_finish++;
				}

			}
			//newsize小于oldsize则直接缩小,直接更新finish就ok，而大于到后面也要更新finish
			_finish = _start + newsize;
		}
		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				//1.申请新空间
				T* temp = new T[newcapacity];
				//2.拷贝元素  不能再用迭代器访问，申请了新空间，迭代器会失效
				size_t n = size();
				if (_start)
				{
					for (size_t i = 0; i < n; i++)
					{
						temp[i] = _start[i];
					}
					//3.释放旧空间
					delete[] _start;
				}
				//4.更新三个指针
				_start = temp;
				_finish = _start + n;
				_endofstorage = _start + newcapacity;
			}
		}

		//4.访问
		//[]重载 普通与const类型
		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}
		const T& operator[](size_t index) const
		{
			assert(index < size());
			return _start[index];
		}
		//首元素
		T& front()
		{
			return *_start;
		}
		const T& front()const
		{
			return *_start;
		}
		//尾元素
		T& back()
		{
			return *(_finish - 1);
		}
		const T& back()const
		{
			return *(_finish - 1);
		}

		//5.修改操作

		void push_back(const T& data)
		{
			//检测是否要扩容
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);//+3：第一次插入数据的时候capacity为0，乘以2还是为0，避免无效扩容
			}
			*_finish = data;
			_finish++;
		}
		void pop_back()
		{
			_finish--;
		}
		//要返回新插入元素的位置，所以返回值类型为迭代器
		iterator insert(iterator pos, const T& data)
		{
			//1.检测是否需要扩容
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}
			//2.将[pos,finish)之间的元素都向后移一位
			//必须从前往后移
			auto it = _finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}
			//3.放入新元素，并返回它的位置
			*pos = data;
			_finish = _start + size();
			return pos;
		}
		//要返回删除元素后填充pos位置的元素
		iterator erase(iterator pos)
		{
			assert(pos <= _finish);
			if (pos == end())
			{
				return pos;
			}
			//it代表待搬移元素的位置
			auto it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}

	private:
		T* _start;//起始指针
		T* _finish;//终止指针  求size
		T* _endofstorage;//求capacity
	};
}

void Test1()
{
	Vector::vector<int> v1;
	Vector::vector<int> v2(4, 7);
	Vector::vector<int> v3(v2);

	auto it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : v3)
	{
		cout << e << " ";
	}
}

void Test2()
{
	Vector::vector<int> v1(2, 7);
	cout << v1.size() << endl;
	v1.resize(1);
	cout << v1.size() << endl;
	v1.resize(10, 6);
	cout << v1.size() << endl;


	cout << v1.back() << endl;
	cout << v1.front() << endl;

	v1.push_back(1);
	v1.push_back(2);
	cout <<"v1 fornt"<< v1.back() << endl;
	v1.pop_back();
	cout << v1.back() << endl;

	v1.insert(v1.begin(), 100);
	cout << v1.front() << endl;

	v1.erase(v1.begin());
	cout << v1.front() << endl;

	v1.clear();
	for (auto e : v1)
	{
		cout << e << " ";
	}
}
int main()
{
	Test1();
	cout << endl;
	Test2();
	system("pause");
	return 0;
}