#include<iostream>
using namespace std;

//��̳�

//���̳У�
// һ������ֻ��һ��ֱ�Ӹ���ʱ������̳й�ϵΪ���̳�
// 
//��̳У�
// һ������������������ֱ�Ӹ���ʱ������̳й�ϵΪ��̳�
// 
//���μ̳У�
//���μ̳��Ƕ�̳е�һ�����������
// 
// 
// ���μ̳е����⣺������Ķ����Աģ�͹��죬
//���Կ������μ̳�����������Ͷ����Ե����⡣
// ��Assistant�Ķ�����Person��Ա�������ݡ�
//


class Person
{
public:
	string _name; // ����
};
class Student : public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
void Test()
{
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	a._name = "peter";

	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}

//Ҫ������������Ҫ�õ���̳�virtual

//ʵ���в����򲻵��ѣ���Ҫ����Ĺ�ϵ��Ƴ����μ̳�

//�̳к����


class A{};

class B : public A
{};
//A��B �Ǽ̳�


class C{};

class D
{
	C c;
};

//C��D�����

//����������εĸ���
//�̳���һ�ְ��临�ã���������������͸���ģ�
//һ���̶����ƻ��˸���ķ�װ

//�����һ�ֺ��临�ã�C��D�ǲ�͸���ģ�C���������ķ�װ