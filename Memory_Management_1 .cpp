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
//1. ѡ���⣺
//ѡ�� : A.ջ B.�� C.���ݶ� D.�����
//globalVar�����__c__ staticGlobalVar�����_c___
//staticVar�����__c__ localVar�����__a__
//num1 �����__a__
//char2�����__a__ * char2�����_a__  //char2��һ�����飬����ջ�ϣ�*char2�൱�ڽ�������Ԫ�صĵ�ַ�����Ҳ��ջ��
//pChar3�����_a___ * pChar3�����_d___ //*pchar3��һ�������ַ���������ڴ������
//ptr1�����__a__ * ptr1�����__b__
//2. ����⣺
//sizeof(num1) = __40__;   //sizeof = int*10
//sizeof(char2) = __5__;  //����\0
//strlen(char2) = __4__;  //����\0�ͽ���
//sizeof(pChar3) = __4��8__;//ָ�����4��8     strlen(pChar3) = _1___; 
//sizeof(ptr1) = __4��8__;


//C++�Լ����ڴ����ʽ��
//ͨ��new��delete���������ж�̬�ڴ����

int main()
{
	//c ����
	int* p1 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int)*10);

	free(p1);
	free(p3);

	//C++  ������
	//int* p2 = new int;
	int* p2 = new int(10);//����һ��int 4���ֽڿռ䣬��ʼ����10
	int* p4 = new int[10];//�����Ǹ�int��40���ֽڿռ�

	delete p2;
	delete[] p4;

	return 0;
}


//��Ȼ�Ѿ�����malloc��free��new��delete���������
//1�����������������ͣ����ǵ�Ч����һ����
//2�������Զ������ͣ�Ч���Ͳ�һ����

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
	A* p3 = (A*)malloc(sizeof(A));//����ռ�
	A* p4 = new A;                //����ռ�+���캯����ʼ��

	free(p3);                     //�ͷſռ�
	delete p4;                    //��������+�ͷſռ�
	return 0;
}

//C++�н���ʹ��new��delete��Ϊmalloc�еĹ���new����