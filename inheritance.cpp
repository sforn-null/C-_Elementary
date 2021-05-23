#include<iostream>
using namespace std;

//基类和派生类对象赋值转换

class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号
};
void Test()
{
	Person p;
	Student s;
	//父类和子类之间的复制兼容规则
	//1、子类对象可以赋值给父类对象/ 指针/引用
	p = s;
	Person* ptr = &s;
	Person& ref = s;
	//只会赋值子类中父类的那一部分，父类的那部分会被切出来
	//我们将这个叫做切片
	
	//父类不能赋值给子类
	//s = p;
	//Student* s = &p;
	//Student& ref = p;
	//这是不行的

	//这种情况转换时虽然可以，但是会存在越界访问的问题
	Student* sptr = (Student*)ptr;

}

class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111; // 身份证号
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999; // 学号
};
//当父类和子类同时有同名成员时，子类成员隐藏了父类的成员
//虽然不会报错，但是它会优先访问子类的，因为就近原则
//会优先到自己的类找，然后再去父类
//指定作用域的时候，就可以访问弗雷德成员了


class A {
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A {
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};

//两个fun构成了什么关系
// A 重载 B 重写 C重定义 D编译不通过（以上都不对）
// C

//子类的析构函数和父类的析构函数会构成隐藏，
//因为编译器会把析构函数处理成destructor
//并且不需要显式调用父类的析构函数，，
//因为析构完子类会自动调用父类的，
//因为这样才能保证先析构子类再析构父类的