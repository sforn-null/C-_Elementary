//引用

#include<iostream>
using namespace std;

int main()
{
	int a = 1;
	int& ra = a;//ra是a的引用，引用也就是别名，a再取了一个名称ra
	int& b = a;
	int& c = ra;

	c = 2;//c改变了，就全都改变了
	
	return 0;
}

int main()
{
	int a = 1;
	//int& ra;//引用必须在定义时初始化
	int& c = a;
	int d = 2;
	c = d; //分析这里是c变成了d的引用？还是将d赋值给c？
	//结果是d赋值给了c，而不是c变成了d的引用

	return 0;
}

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
	//double& rdb = i;//这样是不行的，临时变量是具有常性的，权限是只读的
	const double& rdb = i;//这样就是可以的，权限都是只读的，所以可以
	return 0;
}


//引用做参数
void Swap_cpp(int& left, int& right) {
	int temp = left;
	left = right;
	right = temp;
}

void Swap_C(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//引用做返回值
int count1()
{
	static int n = 0;//传值返回
	n++;
	return n;        //返回时不会返回n，而是返回一个临时变量
}

int& count2()        //传引用返回
{
	static int n = 0;
	n++;
	return n;        //这里就相当于返回了n
}

int& Add2(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int a = 1;
	int b = 2;
	Swap_C(&a, &b);
	Swap_cpp(a, b);

	int& ret = Add2(1, 2);
	Add2(3, 4);
	cout << "Add2(1,2) is:" << ret << endl;//输出的是7
	return 0;
}
//说明如果返回变量C是一个局部变量时，
// 引用返回时是不安全的
// 
// 即使不重复使用同一个函数，调用其他函数，那么原本的栈帧空间就会被覆盖
// 因此将要返回的变量前面加上 static
// 因为加上static之后c就不在栈里面了，c在静态区（数据段）之中
// 
// 总结:如果一个函数要使用引用返回，返回变量出了这个函数的作用域还存在
// 就可以使用引用返回，否则就不安全
// 
// 使用引用返回的好处？
// 少创建拷贝一个临时对象，提高效率，还有其他作用，在后面会讲
//



//传值返回、传引用返回效率比较
#include <time.h>
struct A
{
	int a[10000];
};

A a;
A TestFunc1() 
{
	return a;
}

A& TestFunc2() 
{
	return a;
}

int main()
{
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1()-time:" << end1 - begin1 << endl;
	cout << "TestFunc2()-time:" << end2 - begin2 << endl;
}
//传值和传引用的效率也有区别
//一般能用引用表达的都能用指针表达


//内联函数
void Swap1(int& x1, int& x2)
{
	int tmp = x1;
	x1 = x2;
	x2 = tmp;
}

//频繁调用swap是有消耗的
//如何解决：1、c语言使用宏函数 2、c++使用内联函数
//内联函数就是在函数前面加个inline
//内联函数就是用空间换时间
inline void Swap2(int& x1, int& x2)
{
	int tmp = x1;
	x1 = x2;
	x2 = tmp;
}

int main()
{
	int a = 1;
	int b = 2;
	Swap1(a, b);
	Swap2(a, b);
	return 0;
}