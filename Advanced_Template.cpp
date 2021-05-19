#include<iostream>
using namespace std;

//类型模板参数
template<class T>
//template<typename T>
class A
{};

#define N 100

//类型参数+非类型模板参数
template<class T,int N>
//非类型模板参数是个常量，不能修改
//浮点型不能作为非类型模板参数
class Array
{
private:
	T _a[N];
};


int main()
{
	Array<int,100> a1;//100
	Array<int,1000> a2;//1000
	return 0;
}



//模板的特化

template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}

//特化 （针对某些类型的特殊化处理）
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left, right) == 0;
}

//全特化 全部的参数都特化

//偏特化 只特化了一部分参数
//解引用和引用也能作为偏特化
int main()
{
	int a = 0, b = 1;
	cout << IsEqual(a, b) << endl;

	const char* p1 = "hello";
	const char* p2 = "world";
	cout<< IsEqual(p1, p2) << endl;
	return 0;
}


//分离编译
//项目工程中一般将函数或类的声明放到.h，将函数或者类的定义放到.cpp

//为什么要分离编译呢？
//方便查看和维护

//模板不能分离编译
//下面是演示
#include"Fun.h"
int main()
{
	Func1();
	//都是分离编译
	//func1没有问题
	//但是func2却不行
	Func2(10);
	//普通的类和函数可以分离编译，但是类模板和函数模板不行
	return 0;
}

//为什么模板不能分离编译？
//因为在模板没被用到的时候，是没实例化的