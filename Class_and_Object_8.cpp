#include<iostream>
using namespace std;

//友元
//友元分为友元函数和友元类


//友元就是一种在类外面访问私有的或保护的成员变量
class Date
{
	friend void f(Date& d);//说明这个函数是这个类的友元函数
	                       //这个函数就能在类外面访问私有的成员变量了
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;

};

void f(Date& d)
{
	d._year = 10;
	cout << d._year << endl;
}

int main()
{
	Date d1;
	d1.Print();
	f(d1);
	return 0;
}


//必须用友元的场景
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//因为this一定是第一个参数，所以这个函数就不能写在类里面了
	//因此这个必须使用友元
	/*void operator<<(ostream& out)
	{
		out << _year << "/" << _month << "/" << _day << endl;
	}*/
private:
	int _year;
	int _month;
	int _day;

};

ostream& operator<<(ostream& out, const Date& d)
{
	out <<d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}

//cout->ostream
//cin->istream

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

int main()
{
	Date d1;
	d1.Print();
	cout << d1;
	//如果用的是成员函数
	//这样就不支持
	//d1.operator<<(cout);//这样就可以
	//d1 << cout;//这两种都可以
	//因为传给operator<<的参数顺序不对

	Date d2(2021, 5, 11);
	Date d3(2021, 5, 12);
	cout << d2 << d3 << 1 << endl;;
	//这样就没法连续用了
	//因此需要在之前的operator<<函数加上一个返回值

	/*int i = 0, j = 1;
	cout << i << j << endl;*/

	cin >> d2 >> d1;
	cout << d2 << d1;

	int x = 1;
	double y = 1.11;
	cout << x << endl;
	cout << y << endl;

	return 0;
}

//友元类
class Date; // 前置声明
class Time
{
	friend class Date; // 声明日期类为时间类的友元类，
	//则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_t._hour = 1;
	}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	return 0;
}

//内部类
//就是在一个类中定义一个类
//一般在这个类的存在就是为了让第一个类使用的时候才会使用内部类
//内部类天生就是友元
//并且要在外部使用内部类的时候得像这样A::B才能用