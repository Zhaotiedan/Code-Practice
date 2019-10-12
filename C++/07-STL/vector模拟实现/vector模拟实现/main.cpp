#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


template<class T>

class vector
{
public:
	//构造
	vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endofstorage(nullptr)
	{}

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
	//销毁
private:
	T* _start;//起始指针
	T* _finish;//终止指针  求size
	T* _endofstorage;//求capacity
};
int main()
{
	system("pause");
	return 0;
}