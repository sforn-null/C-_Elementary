#include<iostream>
using namespace std;
#include"priority_queue.h"

//struct less
//{
//	bool operator()(int x1, int x2)
//	{
//		return x1 < x2;
//	}
//};

//仿函数 对象可以像函数那样使用
namespace shy
{
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 < x2;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};
}


int main()
{
	shy::test_priority_queue1();
	return 0;
}