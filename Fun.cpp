#include"Fun.h"

void Func1()
{
	cout << "shy1" << endl;
}

template<class T>
inline void Func2(const T& x)
{
	cout << "shy2" << endl;
}

//解决模板不能分离编译的方法：
//1、显式实例化
template
void Func2<int>(const int& x);
//但是但凡换了类型，就链接不上了
//因此这种方法不常用，因为不方便

//2、不要分离编译了