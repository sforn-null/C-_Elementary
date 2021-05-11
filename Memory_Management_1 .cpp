#include<iostream>
using namespace std;

int globalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}
//1. 选择题：
//选项 : A.栈 B.堆 C.数据段 D.代码段
//globalVar在哪里？__c__ staticGlobalVar在哪里？_c___
//staticVar在哪里？__c__ localVar在哪里？__a__
//num1 在哪里？__a__
//char2在哪里？__a__ * char2在哪里？_a__  //char2是一个数组，存在栈上，*char2相当于解引用首元素的地址，因此也在栈上
//pChar3在哪里？_a___ * pChar3在哪里？_d___ //*pchar3是一个常量字符串，因此在代码段上
//ptr1在哪里？__a__ * ptr1在哪里？__b__
//2. 填空题：
//sizeof(num1) = __40__;   //sizeof = int*10
//sizeof(char2) = __5__;  //还有\0
//strlen(char2) = __4__;  //遇到\0就结束
//sizeof(pChar3) = __4或8__;//指针就是4或8     strlen(pChar3) = _1___; 
//sizeof(ptr1) = __4或8__;


//C++自己的内存管理方式：
//通过new和delete操作符进行动态内存管理。

int main()
{
	//c 函数
	int* p1 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int)*10);

	free(p1);
	free(p3);

	//C++  操作符
	//int* p2 = new int;
	int* p2 = new int(10);//申请一个int 4个字节空间，初始化成10
	int* p4 = new int[10];//申请是个int的40个字节空间

	delete p2;
	delete[] p4;

	return 0;
}


//既然已经有了malloc和free，new和delete的意义何在
//1、对于上面内置类型，他们的效果是一样的
//2、对于自定义类型，效果就不一样了

class A
{
public:
	A()
	{
		_a = 0;
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
	A* p3 = (A*)malloc(sizeof(A));//申请空间
	A* p4 = new A;                //申请空间+构造函数初始化

	free(p3);                     //释放空间
	delete p4;                    //析构函数+释放空间
	return 0;
}

//C++中建议使用new和delete因为malloc有的功能new都有