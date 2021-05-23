#include<iostream>
using namespace std;
//多态

//virtual关键字，可以修饰成员函数，为了完成虚函数的重写
//满足多态的条件之一

//可以再菱形继承中，去完成虚继承，解决数据冗余和二义性

//两个地方使用了同一个关键字，但是他们互相之间没有一点关联


//多态的两个条件
//1.虚函数的重写
//2.父类对象的指针或者引用去调用虚函数

//满足多态:跟指向对象有关，指向哪个对象调用就是他的虚函数
//不满足多态:跟调用对象的类型有关，类型是什么调用的就是谁的虚函数

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() {
		cout << "买票-半价" << endl;
	}
	};

	void Func(Person& p)
	{
		p.BuyTicket();
	}
int main()
{
	Person ps;
	Student st;

	Func(ps);
	Func(st);
	return 0;
}
//构成多态还有两个条件：
//1. 必须通过基类的指针或者引用调用虚函数
//2. 被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写

//多态的例外
//1. 协变(基类与派生类虚函数返回值类型不同)
//派生类重写基类虚函数时，与基类虚函数返回值类型不同。
//即基类虚函数返回基类对象的指针或者引
//用，派生类虚函数返回派生类对象的指针或者引用时，
//称为协变。

//以下程序输出结果是什么（）
class A {
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};
class B : public A {
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	return 0;
}

//A: A->0 B : B->1 C : A->1 D : B->0 E : 编译出错 F : 以上都不正确

//选b
//因为重写是先继承函数，只是函数的实现不一样，因此子类的func
//与父类的一样，缺省值都是val = 1



//final
//final：修饰虚函数，表示该虚函数不能再被继承


//override
//override : 检查派生类虚函数是否重写了基类某个虚函数，
//如果没有重写编译报错。


//抽象类：含有纯虚函数的类，不能实例化出对象
//纯虚函数
class Car
{
public:
	virtual void Drive() = 0;//不需要实现，纯虚函数
	//抽象类不能实例化出对象
};
class C : public Car
{
public:
};

int main()
{
	Car car;//不能实例化出对象
	C c;   //继承下来的类也不能实例化，除非重写
}

//纯虚函数的作用：
//1.强制子类去完成重写
//2.表示抽象的类型。抽象就是在现实中没有对应的实体的

// 这里常考一道笔试题：sizeof(Base)是多少？
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};

//32位下是8，64位下是16

//虚函数表指针:简称虚表指针
//虚函数表其实就是一个指针数组（虚函数指针）