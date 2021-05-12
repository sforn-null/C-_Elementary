#include<iostream>
using namespace std;

//operator new和operator delete函数

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = (A*)operator new(sizeof(A));
	//operator new和malloc的区别是什么
	//结论：使用方式都一样，处理错误的方式不一样

	size_t size = 2;
	void* p4 = malloc(size * 1024 * 1024 * 1024);
	cout << p4 << endl;//失败返回0
	

	try
	{
		void* p5 = operator new(size * 1024 * 1024 * 1024);
		cout << p5 << endl;//失败抛异常（面向对象处理错的方式）
		operator delete(p5);
	}
	catch(exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}


int main()
{
	//malloc/free
	// 
	//operator new/operator delete
	// malloc+失败抛异常
	// 
	//new/delete
	//operator new + 调用构造函数初始化
	//相当于operator new其实就是为了new才出现的
	//operator delete 和free没区别，都是释放空间失败直接终止进程
	
	return 0;
}

int main()
{
	A* p1 = new A;
	delete p1;

	A* p2 = (A*)operator new(sizeof(A));
	//对已经存在的一块空间调用构造函数初始化，定位new/replacement new
	new(p2)A(10);

	p2->~A();
	operator delete(p2);
}

//C++ 独有的问题: 内存泄漏 Java就轻松很多，因为它有垃圾回收机制


int main()
{
	char* p = new char[1021 * 1024 * 1024];

	//内存泄漏：p指向的空间不使用了，
	//忘记或其他原因没有释放p指向的空间，就内存泄漏了
	// 
	//内存泄漏的危害：长期运行的程序，
	//出现内存泄漏危害恩达和。
	//或者设备的内存本身很小也有危害。
	return 0;
}