#define _CRT_SECURE_NO_WARNINGS 1

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//构造函数
		:_year(year)
		, _month(month)
		, _day(day)
	{
		//在构造函数体内判断所给初始日期是否合法

	}
	
	Date(const Date& d);//拷贝构造函数
	Date& operator=(const Date& d);//=重载
	Date operator+(int days);//+重载，计算当前天的第多少天后
	Date operator-(int days);//计算当前天的第多少天前
	int operator-(const Date& d);//计算两个日期相差多少天
	Date& operator++();//前置++
	Date& operator++(int);//后置++
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
private:
	int _year;
	int _month;
	int _day;
};