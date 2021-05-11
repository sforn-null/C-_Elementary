#include<iostream>
using namespace std;

//为什么有初始化列表这个东西
class Date
{
public:
	//Date(int year = 0, int month = 1, int day = 1)
	//{
	//	//函数体内赋值
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		//初始化列表
	}

private:
	int _year;
	int _month;
	int _day;
};


//类中包含以下成员，必须放在初始化列表位置进行初始化：
//引用成员变量
//const成员变量
//自定义类型成员(该类没有默认构造函数)

class A 
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};
class B {
public:
	B(int a, int ref)
		:_aobj(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	A _aobj; // 没有默认构造函数
	int& _ref; // 引用
	const int _n; // const 
	//因为这三类成员变量必须在定义的时候初试化
	//因此要用初始化列表
};

//尽量使用初始化列表初始化，
//因为不管你是否使用初始化列表，
//对于自定义类型成员变量，一定会先使用初始化列表初始化。


//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，
//与其在初始化列表中的先后次序无关
int main()
{
	return 0;
}



class Date
{
public:
	
	//explicit Date(int year)
	//如果加上这个关键字，那么就不能隐式类型转换了
	//这种是单个参数
	Date(int year,int month,int day)
		:_year(year)
	{
		//初始化列表
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1,2,3);   //构造
	Date d2 = 2;  //隐式类型的转换，构造出tmp(2)+再用tmp拷贝构造d2(tmp)，如果优化就是直接构造
	Date d3 = d1; //拷贝构造

	int i = 1;
	const double d = i; //隐式类型转换，会产生中间的临时变量
	
	Date d4 = { 1,2,3 };//这样也是隐式类型转换，但只有c++11才支持

	return 0;
}