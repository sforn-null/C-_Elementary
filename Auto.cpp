#include<iostream>
using namespace std;
//auto关键字
//auto


//auto不能作为参数，也不能用于数组
int main()
{
	int a = 0;
	auto b = a;//b的类型是根据a的类型推导出int

	cout << typeid(a).name() << endl;
	//可以看变量的类型
	cout << typeid(a).name() << endl;

	return 0;
}
