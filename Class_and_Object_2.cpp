#include<iostream>
using namespace std;

//class Date
//{
//public:
//	//this是谁调用这个成员函数，this就指向谁
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//隐含的this指针
//	// 编译器处理应该是下面这样，但是隐藏了
//	// void Print(Date* this)
//	// {
//	//	cout << this->_year << "-" <<this-> _month << "-" << this->_day << endl;
//	// }
//	// 看上去没有参数，其实有
//	//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2021, 5, 9);//d1.Init(&d1,2021,5,9)
//	d1.Print();//d1.Print(&d1)
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->PrintA();//这一行会引发什么？编译不通过？程序崩溃？正常运行？
//	//崩溃
//	p->Show();//这一行会引发什么？编译不通过？程序崩溃？正常运行？
//	//正常运行
//	return 0;
//}


//构造函数
// 
//class Date
//{
//public:
//	//构造函数->在对象构造时调用的函数，这个函数完成初始化工作
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	////这里利用重载，令对象构造时不传参也可以初始化
	//Date()
	//{
	//	_year = 0;
	//	_month = 1;
	//	_day = 1;
	//}
//
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021,5,9);//构建时就自动初始化了
//	d1.Print();
//
//	Date d2;//Date d2()，这里不能加括号
//	d2.Print();
//	return 0;
//}

////如果类中没有显式定义构造函数，
////则C++编译器会自动生成一个无参的默认构造函数，
////一旦用户显式定义编译器将不再生成。
////因此如果我们定义了带参的就要定义个不带参的
//class Date
//{
//public:
//	//我们没有显示定义构造函数
//	//这里编译器会生成一个无参的默认构造函数
//	//1、针对内置类型的成员变量没有做处理
//	//2、针对自定义类型的成员变量，调用它的构造函数初始化
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}*/
//	//每回都建两个很麻烦，那么有个更好的方式
//	//全缺省
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;//调用编译器生成的构造函数
//	d1.Print();
//
//	Date d2(2021,5,9);
//	d2.Print();
//	return 0;
//}


////析构函数

////在对象的生命周期到了之后会自动调用析构函数
////析构函数：与构造函数功能相反，析构函数不是完成对象的销毁，局部对象销毁工作是由编译器完成的。而
////对象在销毁时会自动调用析构函数，完成类的一些资源清理工作。
////其特征如下：
////1. 析构函数名是在类名前加上字符 ~。
////2. 无参数无返回值。
////3. 一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
////4. 对象生命周期结束时，C++编译系统系统自动调用析构函数。
//class Date
//{
//public:
//Date(int year = 0, int month = 1, int day = 1)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//
//void Print()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
////析构函数
//~Date()
//{
//	cout << "~Date()" << endl;
//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//class Stack
//{
//public:
//	//对象创建时自动调用完成初始化工作
//	Stack(int n = 10)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		_size = 0;
//		_capacity = n;
//	}
//	void Push(int x);
//	void Pop();
//	size_t Size();
//
//	//对象声明周期到了以后，完成清理工作 
//	~Stack()
//	{
//		free(_a);
//		_size = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{ 
//	//析构：对象声明周期到了之后，自动调用。
//	//完成对象里面的资源清理工作，不是完成d1和d2销毁
//	//例如，malloc开辟了空间，析构函数就能自动free
//	Stack s1;
//	Stack s2;
//	return 0;
//}



////拷贝构造函数
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date d2(d1)
//	//加上const可以避免写错了导致原来的对象被改变
//	Date(const Date& d)//直接传值的话，传参的过程会将d1拷贝给d
//	{            //那么就会再用拷贝构造函数，造成死循环
//				 //因此要传引用
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021, 5, 9);
//	Date d2(d1);//拷贝构造
//	Date d3 = d1;//这两种都是调用拷贝构造
//	//只要传参的参数是自定义类型，那么都会调用构造函数
//	return 0;
//}


////运算符重载
//
////想比较自定义类型的大小是没法用原本的运算符的
////C++为了增强代码的可读性引入了运算符重载，
//// 运算符重载是具有特殊函数名的函数，也具有其返回值类
////型，函数名字以及参数列表，
//// 其返回值类型与参数列表与普通的函数类似。
////函数名字为：关键字operator后面接需要重载的运算符符号。
////函数原型：返回值类型 operator操作符(参数列表)

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//当成成员函数之后，因为成员函数都有个this指针，因此只需要写一个传输就行
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//			return true;
//		else if (_year == d._year && _month > d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		else
//			return false;
//		/*else if (_year < d._year)
//		{
//			return false;
//		}
//		else
//		{
//			if (_month > d._month)
//			{
//				return true;
//			}
//			else if (_month < d._month)
//			{
//				return false;
//			}
//			else
//			{
//				if (_day > d._day)
//					return true;
//				else
//					return false;
//			}
//		}*/
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////这种方法
////成员变量得是公有的才能在外面使用
////bool operator==(const Date& d1, const Date& d2)
////{
////	return d1._year == d2._year
////		&& d1._month == d2._month
////		&& d1._day == d2._day;
////}
//
////自定义类型是不能用运算符的，要用就得实现重载函数，
////自定义类型用的时候等价于调用这个函数
//int main()
//{
//	Date d1(2021, 5, 9);
//	Date d2(2021, 5, 10);
//	d1 == d2;//这样就可以调用了
//	//用类外面实现的方法这里会编译会转换成operator == （d1，d2）;
//	//用成员函数的方法就会理应转换成d1.operato(&d1,d2);
//	//但this指针会隐藏，因此就是d1.operato(d2);
//	cout << (d1 > d2) << endl;
//	return 0;
//}