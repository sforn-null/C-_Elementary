#include<iostream>
using namespace std;

int main()
{
	int array[] = { 1,2,3,4,5 };
	for (int i = 0;i < sizeof(array) / sizeof(int);i++)
	{
		array[i] *= 2;
	}
	for (int i = 0;i < sizeof(array) / sizeof(int);i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	//c++11 ->范围for  特点：写起来比较简洁
	for (auto& e : array)
		//相当于把array里面的每个元素都给了e，
		//但是如果不使用引用，每次改变的都是e而不是数组的元素
	{
		e *= 2;
	}
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
}


//指针空值nullptr(C++11)
//c语言中初值定义为
//int* p1 = NULL;

void fun(int n)
{
	cout << "整型" << endl;
}

void fun(int* p)
{
	cout << "整型指针" << endl;
}

int main()
{
	//c++11中，推荐像下面这样去用
	int* p2 = nullptr;
	fun(0);  //整型
	fun(NULL);  //整型，本来应该是整型指针，
	            //因为NULL被宏定义为了0，所以有时候会出问题
	fun(nullptr); //整型指针，因此在c++尽量用nullptr
}
