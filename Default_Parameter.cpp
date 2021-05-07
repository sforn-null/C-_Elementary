//缺省参数

#include<iostream>
using namespace std;


//缺省参数就是在函数中加个参数
//意思就是一个备用参数，备胎参数
void Func(int a = 0)
{
	cout << a << endl;
}

//缺省参数分为全缺省和半缺省

//全缺省
void Func1(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//半缺省（缺省部分参数）
//半缺省就不能一个都不传了
// 半缺省必须从右往左连续缺省
// 调用时，如果要传参必须从左往右连续传参，不能空缺
//

int main()
{
	Func(10);//如果传参了，就用传的参数
	Func();//如果没传参，那么就用缺省参数

	Func1();
	Func1(1);
	Func1(1, 2);
	Func1(1, 2, 3);
	return 0;
}