#include<iostream>
using namespace std;

//多继承

//单继承：
// 一个子类只有一个直接父类时称这个继承关系为单继承
// 
//多继承：
// 一个子类有两个或以上直接父类时称这个继承关系为多继承
// 
//菱形继承：
//菱形继承是多继承的一种特殊情况。
// 
// 
// 菱形继承的问题：从下面的对象成员模型构造，
//可以看出菱形继承有数据冗余和二义性的问题。
// 在Assistant的对象中Person成员会有两份。
//


class Person
{
public:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _num; //学号
};
class Teacher : public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void Test()
{
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	a._name = "peter";

	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}

//要解决这个问题需要用到虚继承virtual

//实际中不到万不得已，不要把类的关系设计成菱形继承

//继承和组合


class A{};

class B : public A
{};
//A和B 是继承


class C{};

class D
{
	C c;
};

//C和D是组合

//都完成了类层次的复用
//继承是一种白箱复用，父类对子类基本是透明的，
//一定程度上破坏了父类的封装

//组合是一种黑箱复用，C对D是不透明的，C保持着他的封装