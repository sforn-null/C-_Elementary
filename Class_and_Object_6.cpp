#include<iostream>
using namespace std;

//Ϊʲô�г�ʼ���б��������
class Date
{
public:
	//Date(int year = 0, int month = 1, int day = 1)
	//{
	//	//�������ڸ�ֵ
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		//��ʼ���б�
	}

private:
	int _year;
	int _month;
	int _day;
};


//���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ����
//���ó�Ա����
//const��Ա����
//�Զ������ͳ�Ա(����û��Ĭ�Ϲ��캯��)

class A 
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};
class B {
public:
	B(int a, int ref)
		:_aobj(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	A _aobj; // û��Ĭ�Ϲ��캯��
	int& _ref; // ����
	const int _n; // const 
	//��Ϊ�������Ա���������ڶ����ʱ����Ի�
	//���Ҫ�ó�ʼ���б�
};

//����ʹ�ó�ʼ���б��ʼ����
//��Ϊ�������Ƿ�ʹ�ó�ʼ���б�
//�����Զ������ͳ�Ա������һ������ʹ�ó�ʼ���б��ʼ����


//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳��
//�����ڳ�ʼ���б��е��Ⱥ�����޹�
int main()
{
	return 0;
}



class Date
{
public:
	
	//explicit Date(int year)
	//�����������ؼ��֣���ô�Ͳ�����ʽ����ת����
	//�����ǵ�������
	Date(int year,int month,int day)
		:_year(year)
	{
		//��ʼ���б�
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1,2,3);   //����
	Date d2 = 2;  //��ʽ���͵�ת���������tmp(2)+����tmp��������d2(tmp)������Ż�����ֱ�ӹ���
	Date d3 = d1; //��������

	int i = 1;
	const double d = i; //��ʽ����ת����������м����ʱ����
	
	Date d4 = { 1,2,3 };//����Ҳ����ʽ����ת������ֻ��c++11��֧��

	return 0;
}