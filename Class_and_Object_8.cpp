#include<iostream>
using namespace std;

//��Ԫ
//��Ԫ��Ϊ��Ԫ��������Ԫ��


//��Ԫ����һ�������������˽�еĻ򱣻��ĳ�Ա����
class Date
{
	friend void f(Date& d);//˵�������������������Ԫ����
	                       //����������������������˽�еĳ�Ա������
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;

};

void f(Date& d)
{
	d._year = 10;
	cout << d._year << endl;
}

int main()
{
	Date d1;
	d1.Print();
	f(d1);
	return 0;
}


//��������Ԫ�ĳ���
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//��Ϊthisһ���ǵ�һ��������������������Ͳ���д����������
	//����������ʹ����Ԫ
	/*void operator<<(ostream& out)
	{
		out << _year << "/" << _month << "/" << _day << endl;
	}*/
private:
	int _year;
	int _month;
	int _day;

};

ostream& operator<<(ostream& out, const Date& d)
{
	out <<d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}

//cout->ostream
//cin->istream

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

int main()
{
	Date d1;
	d1.Print();
	cout << d1;
	//����õ��ǳ�Ա����
	//�����Ͳ�֧��
	//d1.operator<<(cout);//�����Ϳ���
	//d1 << cout;//�����ֶ�����
	//��Ϊ����operator<<�Ĳ���˳�򲻶�

	Date d2(2021, 5, 11);
	Date d3(2021, 5, 12);
	cout << d2 << d3 << 1 << endl;;
	//������û����������
	//�����Ҫ��֮ǰ��operator<<��������һ������ֵ

	/*int i = 0, j = 1;
	cout << i << j << endl;*/

	cin >> d2 >> d1;
	cout << d2 << d1;

	int x = 1;
	double y = 1.11;
	cout << x << endl;
	cout << y << endl;

	return 0;
}

//��Ԫ��
class Date; // ǰ������
class Time
{
	friend class Date; // ����������Ϊʱ�������Ԫ�࣬
	//�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_t._hour = 1;
	}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	return 0;
}

//�ڲ���
//������һ�����ж���һ����
//һ���������Ĵ��ھ���Ϊ���õ�һ����ʹ�õ�ʱ��Ż�ʹ���ڲ���
//�ڲ�������������Ԫ
//����Ҫ���ⲿʹ���ڲ����ʱ���������A::B������