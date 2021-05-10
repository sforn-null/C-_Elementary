#include<iostream>
using namespace std;

//�������const��Ա����
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()const//��������thisָ��ָ��Ķ���
	{                //ָ��Ķ����Ȩ�޾�Ϊֻ����
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//const Date* p1 ->���ε���*p1Ҳ����˵ָ��Ķ���
	//Date const* p2 ->���ε���*p2Ҳ����˵ָ��Ķ���
	//Date* const p3 ->���ε��� p3Ҳ����˵ָ�뱾��

private:
	int _year;
	int _month;
	int _day;
};

void f(const Date& d)//����const֮���û������Print��
{                    //��Ϊthisָ���Ȩ���ǿɶ���д
	d.Print();       //��˾���printf�����������const
}

int main()
{
	Date d1(2021, 5, 10);
	f(d1);
	return 0;
}

//��Ա��������const��Ա����
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void f1()
	{
		f2();
	}

	void f2()const
	{}

	void f3()
	{}

	void f4()const
	{
		f3();
	}
	//f1���Ե���f2
	//f4���ܵ���f3

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1(2021, 5, 10);
	f(d1);
	return 0;
}

//ȡ��ַ��constȡ��ַ����������
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1;
	Date d2;
	const Date d3();//��Ϊconst���������һ���Ա����
	//��˻������һ��const��operator&
	cout << &d1 << endl;
	cout << &d2 << endl;
	cout << &d3 << endl;
	return 0;
}

//ֻҪ��Ա�����в�ֱ�ӻ��Ӹı��Ա������
//��ôÿ����Ա�����Ĳ���������const
//���Һ���ҲҪ����const