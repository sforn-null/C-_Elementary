#include<iostream>
using namespace std;

//��������������ֵת��

class Person
{
protected:
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};
class Student : public Person
{
public:
	int _No; // ѧ��
};
void Test()
{
	Person p;
	Student s;
	//���������֮��ĸ��Ƽ��ݹ���
	//1�����������Ը�ֵ���������/ ָ��/����
	p = s;
	Person* ptr = &s;
	Person& ref = s;
	//ֻ�ḳֵ�����и������һ���֣�������ǲ��ֻᱻ�г���
	//���ǽ����������Ƭ
	
	//���಻�ܸ�ֵ������
	//s = p;
	//Student* s = &p;
	//Student& ref = p;
	//���ǲ��е�

	//�������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	Student* sptr = (Student*)ptr;

}

class Person
{
protected:
	string _name = "С����"; // ����
	int _num = 111; // ���֤��
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 999; // ѧ��
};
//�����������ͬʱ��ͬ����Աʱ�������Ա�����˸���ĳ�Ա
//��Ȼ���ᱨ�������������ȷ�������ģ���Ϊ�ͽ�ԭ��
//�����ȵ��Լ������ң�Ȼ����ȥ����
//ָ���������ʱ�򣬾Ϳ��Է��ʸ��׵³�Ա��


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

//����fun������ʲô��ϵ
// A ���� B ��д C�ض��� D���벻ͨ�������϶����ԣ�
// C

//��������������͸�������������ṹ�����أ�
//��Ϊ����������������������destructor
//���Ҳ���Ҫ��ʽ���ø����������������
//��Ϊ������������Զ����ø���ģ�
//��Ϊ�������ܱ�֤���������������������