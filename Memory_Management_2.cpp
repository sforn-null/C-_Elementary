#include<iostream>
using namespace std;

//operator new��operator delete����

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
	//operator new��malloc��������ʲô
	//���ۣ�ʹ�÷�ʽ��һ�����������ķ�ʽ��һ��

	size_t size = 2;
	void* p4 = malloc(size * 1024 * 1024 * 1024);
	cout << p4 << endl;//ʧ�ܷ���0
	

	try
	{
		void* p5 = operator new(size * 1024 * 1024 * 1024);
		cout << p5 << endl;//ʧ�����쳣������������ķ�ʽ��
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
	// malloc+ʧ�����쳣
	// 
	//new/delete
	//operator new + ���ù��캯����ʼ��
	//�൱��operator new��ʵ����Ϊ��new�ų��ֵ�
	//operator delete ��freeû���𣬶����ͷſռ�ʧ��ֱ����ֹ����
	
	return 0;
}

int main()
{
	A* p1 = new A;
	delete p1;

	A* p2 = (A*)operator new(sizeof(A));
	//���Ѿ����ڵ�һ��ռ���ù��캯����ʼ������λnew/replacement new
	new(p2)A(10);

	p2->~A();
	operator delete(p2);
}

//C++ ���е�����: �ڴ�й© Java�����ɺܶ࣬��Ϊ�����������ջ���


int main()
{
	char* p = new char[1021 * 1024 * 1024];

	//�ڴ�й©��pָ��Ŀռ䲻ʹ���ˣ�
	//���ǻ�����ԭ��û���ͷ�pָ��Ŀռ䣬���ڴ�й©��
	// 
	//�ڴ�й©��Σ�����������еĳ���
	//�����ڴ�й©Σ������͡�
	//�����豸���ڴ汾���СҲ��Σ����
	return 0;
}