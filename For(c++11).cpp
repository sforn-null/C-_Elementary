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

	//c++11 ->��Χfor  �ص㣺д�����Ƚϼ��
	for (auto& e : array)
		//�൱�ڰ�array�����ÿ��Ԫ�ض�����e��
		//���������ʹ�����ã�ÿ�θı�Ķ���e�����������Ԫ��
	{
		e *= 2;
	}
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
}


//ָ���ֵnullptr(C++11)
//c�����г�ֵ����Ϊ
//int* p1 = NULL;

void fun(int n)
{
	cout << "����" << endl;
}

void fun(int* p)
{
	cout << "����ָ��" << endl;
}

int main()
{
	//c++11�У��Ƽ�����������ȥ��
	int* p2 = nullptr;
	fun(0);  //����
	fun(NULL);  //���ͣ�����Ӧ��������ָ�룬
	            //��ΪNULL���궨��Ϊ��0��������ʱ��������
	fun(nullptr); //����ָ�룬�����c++������nullptr
}
