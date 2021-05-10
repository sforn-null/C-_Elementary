#include<iostream>
using namespace std;

//对象调用const成员函数
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()const//这样修饰this指针指向的对象
	{                //指向的对象的权限就为只读了
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//const Date* p1 ->修饰的是*p1也就是说指向的对象
	//Date const* p2 ->修饰的是*p2也就是说指向的对象
	//Date* const p3 ->修饰的是 p3也就是说指针本身

private:
	int _year;
	int _month;
	int _day;
};

void f(const Date& d)//加上const之后就没法调用Print了
{                    //因为this指针的权限是可读可写
	d.Print();       //因此就在printf（）后面加上const
}

int main()
{
	Date d1(2021, 5, 10);
	f(d1);
	return 0;
}

//成员函数调用const成员函数
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void f1()
	{
		f2();
	}

	void f2()const
	{}

	void f3()
	{}

	void f4()const
	{
		f3();
	}
	//f1可以调用f2
	//f4不能调用f3

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1(2021, 5, 10);
	f(d1);
	return 0;
}

//取地址及const取地址操作符重载
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1;
	Date d2;
	const Date d3();//因为const对象调不了一般成员函数
	//因此会多重载一个const的operator&
	cout << &d1 << endl;
	cout << &d2 << endl;
	cout << &d3 << endl;
	return 0;
}

//只要成员函数中不直接或间接改变成员变量，
//那么每个成员函数的参数都加上const
//并且后面也要加上const