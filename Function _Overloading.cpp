//函数重载

#include<iostream>

//函数重载:是函数的一种特殊情况，
// C++允许在同一作用域中声明几个功能类似的同名函数，
// 这些同名函数的形参列表(参数个数 或 类型 或 顺序)必须不同，
// 常用来处理实现功能类似数据类型不同的问题
//
// 
// 
// 返回值没有还要求
// 只有返回值不同不能构成重载
//

//int Add(int left, int right) 
//{
//	return left + right;
//}
//double Add(double left, double right) {
//	return left + right;
//}
//long Add(long left, long right) {
//	return left + right;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//
//	return 0;
//}


//extern"C"
// 主要就是为了c和c++的程序都能够用这个c++的（静态库/动态库）
// 因此在声明那个c要用的函数时，在声明前面加上extern"C"
// 
//有时候在C++工程中可能需要将某些函数按照C的风格来编译，
//在函数前加extern "C"，意思是告诉编译器，
//将该函数按照C语言规则来编译。
//比如：tcmalloc是google用C++实现的一个项目，
//他提供tcmallc()和tcfree
//两个接口来使用，但如果是C项目就没办法使用，
//那么他就使用extern “C”来解决。



//引用

#include<iostream>
using namespace std;

//int main()
//{
//	int a = 1;
//	int& ra = a;//ra是a的引用，引用也就是别名，a再取了一个名称ra
//	int& b = a;
//	int& c = ra;
//
//	c = 2;//c改变了，就全都改变了
//	
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	//int& ra;//引用必须在定义时初始化
//	int& c = a;
//	int d = 2;
//	c = d; //分析这里是c变成了d的引用？还是将d赋值给c？
//	//结果是d赋值给了c，而不是c变成了d的引用
//
//	return 0;
//}

int main()
{
	int a = 0;
	
	int& b = a;//b的类型是int

	const int c = 0;
	//int& d = c;//编译不通过，原因是c是只读，d的类型是int是可读可写的

	const int& i = c;//这样就可以了

	int e = 1;
	int& f = e;
	const int& g = e;//这样是可以的，e是可读可写，g是只读
	//总结: 引用取别名时，变量访问的权限可以缩小，但不能放大
	
	double db = i;//隐式类型转化，相当于产生了一个double类型的临时变量
	double& rdb = i;//这样是不行的，临时变量是具有常性的，权限是只读的
	const double& rdb = i;//这样就是可以的，权限都是只读的，所以可以
	return 0;
}