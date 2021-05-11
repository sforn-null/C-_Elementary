#include<iostream>
using namespace std;

//static成员
//设计一个类，可以计算这个类总计产生了多少对象


class A
{
public:
	A()
	{
		++n;
	}
	A(const A& a)
	{
		++n;
	}
	static int GetN()//没有this指针，函数中不能访问非静态的成员
	{
		//_a = 10 不能访问非静态的成员
		return n;
	}
private:
	static int n;//声明 不是属于某个对象，是属于类的所有对象，属于这个类
};

int A::n = 0;

A f1(A a)
{
	return a;
}

int main()
{
	A a1;
	A a2;
	f1(a1);
	//n = 1;//但是谁都可以对n进行修改
	f1(a2);
	//cout << n << endl;
	a1.GetN();
	A::GetN();
	//突破类域的两种方式

	return 0;

}

//1. 静态成员函数可以调用非静态成员函数吗？
// 不可以，静态的没有this指针
// 
// 
//2. 非静态成员函数可以调用类的静态成员函数吗？
// 可以，只要能突破类域就可以调用

class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	// C++11才支持这样
	// 声明时给缺省值，但不是初始化，初始化只能定义的时候才能做
	int _year = 0;
	int _month = 1;
	int _day = 1;

	//静态的却不能这么做
	static int i = 0;
	//这种静态的就不行了
};

int main()
{
	Date d1;
	d1.Print();
	return 0;
}