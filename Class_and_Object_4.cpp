//#include<iostream>
//using namespace std;
//
////实现一个完整的日期类
//class Date
//{
//public:
//	int GetMonthDay(int year, int month)
//	{
//		//因为这个数组每次都要创建，并且不需要变，那么就创建成静态的
//		static int MonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		//闰年每四年一次，每100年不闰，但每400年润一次
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
//			cout << "非法日期" << endl;
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
//	//复用性差
//	//Date operator+(int day)
//	//{
//	//	Date ret = *this;//用d1拷贝构造一个ret
//	//	ret._day += day;
//	//	while (ret._day > GetMonthDay(ret._year, ret._month))
//	//	{
//	//		//如果日期的天不合法，就需要往月进位
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
//			//这里直接调用+=
//			return ret;
//		}
//
//	//d1+=10;
//	Date& operator+=(int day)
//	{
//		if (day < 0)
//		{
//			return *this -= (-day);
//			//可能加等一个负数，那么就会出问题，因此需要补充一个判断
//		}
//
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			//如果日期的天不合法，就需要往月进位
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
//	//因为出了作用域*this还会存在，那么就可以传引用返回
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
//	Date operator++(int)//为了构成函数重载特意加了个形参
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;//返回加之前的值
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
//	//日期减日期
//	int operator-(const Date& d)
//	{
//		int flag = 1;
//
//		Date max = *this;//拷贝构造
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
//	////是否要重载一个运算符，看的是这个运算符是否对这个类的对象有意义
//	//
//	//Date d3 = d1 + 10;
//	//d3.Print();
//
//	//d1 += 10;
//
//	////两个对象都已经存在且初始化好了，
//	////现在我想把d2赋值（拷贝）给d1
//	////那么就用=（赋值运算符）
//
//	////如果对象还不存在，构造时用另一个对象初始化
//	////那么用的就是拷贝构造成员函数
//	////即使初始化的时候代码里面有=，也是用的拷贝构造
//
//	//d3 = d1;
//	//d3.Print();
//
//	//int i = 0, j = 1, k = 2;
//	//i = j = k;//连续赋值，j = k是有返回值的，返回值是j
//	////那么需要让自定义的赋值运算符也能实现这个功能
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
////当我们不实现时，编译器生成拷贝构造和operator=，
////会完成字节的值的拷贝（浅拷贝）
////也就是说有些类，我们时不需要去实现拷贝构造和operator=的，
////因为编译器默认生成就可以用，例如Date就是这样
//
////我们自己去写拷贝构造和operator=的意义在哪
////因为编译器生成的只是字节的值的拷贝，也就是浅拷贝