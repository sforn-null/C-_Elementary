//#include<iostream>
//using namespace std;
//
////ʵ��һ��������������
//class Date
//{
//public:
//	int GetMonthDay(int year, int month)
//	{
//		//��Ϊ�������ÿ�ζ�Ҫ���������Ҳ���Ҫ�䣬��ô�ʹ����ɾ�̬��
//		static int MonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		//����ÿ����һ�Σ�ÿ100�겻�򣬵�ÿ400����һ��
//		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		{
//			return 29;
//		}
//		return MonthDays[month];
//	}
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		if (year >= 0 && month >= 1
//			&& month <= 12 && day >= 1
//			&& day <= GetMonthDay(year, month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			_year = 0;
//			_month = 0;
//			_day = 0;
//			cout << "�Ƿ�����" << endl;
//		}
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//			return true;
//		else if (_year == d._year && _month < d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day < d._day)
//			return true;
//		else
//			return false;
//	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//	bool operator<=(const Date& d)
//	{
//		return *this < d || *this == d;
//	}
//
//	bool operator>(const Date& d)
//	{
//		return !(*this <= d);
//	}
//	bool operator>=(const Date& d)
//	{
//		return !(*this < d);
//	}
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	//�����Բ�
//	//Date operator+(int day)
//	//{
//	//	Date ret = *this;//��d1��������һ��ret
//	//	ret._day += day;
//	//	while (ret._day > GetMonthDay(ret._year, ret._month))
//	//	{
//	//		//������ڵ��첻�Ϸ�������Ҫ���½�λ
//	//		ret._day -= GetMonthDay(ret._year, ret._month);
//	//		ret._month++;
//	//		if (ret._month == 13)
//	//		{
//	//			ret._year++;
//	//			ret._month = 1;
//	//		}
//	//	}
//	//	return ret;
//	//}
//
//	Date operator+(int day)
//		{
//			Date ret = *this;
//			ret += day;
//			//����ֱ�ӵ���+=
//			return ret;
//		}
//
//	//d1+=10;
//	Date& operator+=(int day)
//	{
//		if (day < 0)
//		{
//			return *this -= (-day);
//			//���ܼӵ�һ����������ô�ͻ�����⣬�����Ҫ����һ���ж�
//		}
//
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			//������ڵ��첻�Ϸ�������Ҫ���½�λ
//			_day -= GetMonthDay(_year, _month);
//			_month++;
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//
//
//	//��Ϊ����������*this������ڣ���ô�Ϳ��Դ����÷���
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//
//	//d1-=10
//	Date operator-(int day)
//	{
//		Date ret = *this;
//		ret -= day;
//		
//		return ret;
//	}
//
//	//d1-10
//	Date& operator-=(int day)
//	{
//		if (day < 0)
//		{
//			return *this += (-day);
//		}
//		_day -= day;
//		while (_day <= 0)
//		{
//			_month--;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//	//++d1
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//
//	//d1++
//	Date operator++(int)//Ϊ�˹��ɺ�������������˸��β�
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;//���ؼ�֮ǰ��ֵ
//	}
//
//	Date& operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//
//	Date operator--(int)
//	{
//		Date tmp = *this;
//		*this -= 1;
//		return *this;
//	}
//
//	//���ڼ�����
//	int operator-(const Date& d)
//	{
//		int flag = 1;
//
//		Date max = *this;//��������
//		Date min = d;
//		if (min > max)
//		{
//			max = d;     //operator=
//			min = *this;
//			flag = -1;
//		}
//		int k = 0;
//		while (min != max)
//		{
//			++min;
//			++k;
//		}
//		return flag*k;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020,4,8);
//	d1.Print();
//
//	Date d2(2021, 5, 9);
//	d2.Print();
//
//	//cout << (d1 > d2) << endl;
//	//cout << (d1 == d2) << endl;
//	//cout << (d1 < d2) << endl;
//	//cout << (d1 >= d2) << endl;
//	//cout << (d1 <= d2) << endl;
//
//	////�Ƿ�Ҫ����һ������������������������Ƿ�������Ķ���������
//	//
//	//Date d3 = d1 + 10;
//	//d3.Print();
//
//	//d1 += 10;
//
//	////���������Ѿ������ҳ�ʼ�����ˣ�
//	////���������d2��ֵ����������d1
//	////��ô����=����ֵ�������
//
//	////������󻹲����ڣ�����ʱ����һ�������ʼ��
//	////��ô�õľ��ǿ��������Ա����
//	////��ʹ��ʼ����ʱ�����������=��Ҳ���õĿ�������
//
//	//d3 = d1;
//	//d3.Print();
//
//	//int i = 0, j = 1, k = 2;
//	//i = j = k;//������ֵ��j = k���з���ֵ�ģ�����ֵ��j
//	////��ô��Ҫ���Զ���ĸ�ֵ�����Ҳ��ʵ���������
//
//	///*d1 - 10;
//	//d1 -= 10;
//	//d1 - d1;*/
//	//d3 = d2 = d1;
//	//d3.Print();
//	//Date d4 = d2 - 129;
//	//d2.Print();
//	//d4.Print();
//	cout << (d2 - d1) << endl;
//
//	return 0;
//}
//
////�����ǲ�ʵ��ʱ�����������ɿ��������operator=��
////������ֽڵ�ֵ�Ŀ�����ǳ������
////Ҳ����˵��Щ�࣬����ʱ����Ҫȥʵ�ֿ��������operator=�ģ�
////��Ϊ������Ĭ�����ɾͿ����ã�����Date��������
//
////�����Լ�ȥд���������operator=����������
////��Ϊ���������ɵ�ֻ���ֽڵ�ֵ�Ŀ�����Ҳ����ǳ����