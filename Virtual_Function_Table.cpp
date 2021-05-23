#include<iostream>
using namespace std;
//单继承和多继承关系的虚函数表


//单继承中的虚函数表
class Base 
{
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base 
{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};
//在监视窗口看，是不显示func3和func4的，但是是有的

//打印虚表
//void(*p)() 定义一个函数指针变量
typedef void(*VF_PTR)();//函数指针类型typedef
void PrintVFTable(VF_PTR* pTable)
{
	for (size_t i = 0;pTable[i] != 0;++i)
	{
		printf("vfTable[%d]:%p\n", i, pTable[i]);
	}
}

int main()
{
	Base b;
	Derive d;
	PrintVFTable((VF_PTR*)*(int*)&b);
	cout << endl;
	PrintVFTable((VF_PTR*)*(int*)&d);
	return 0;
}


//多继承
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};