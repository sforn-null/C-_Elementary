#include<iostream>
using namespace std;

//����ģ�����
template<class T>
//template<typename T>
class A
{};

#define N 100

//���Ͳ���+������ģ�����
template<class T,int N>
//������ģ������Ǹ������������޸�
//�����Ͳ�����Ϊ������ģ�����
class Array
{
private:
	T _a[N];
};


int main()
{
	Array<int,100> a1;//100
	Array<int,1000> a2;//1000
	return 0;
}



//ģ����ػ�

template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}

//�ػ� �����ĳЩ���͵����⻯����
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left, right) == 0;
}

//ȫ�ػ� ȫ���Ĳ������ػ�

//ƫ�ػ� ֻ�ػ���һ���ֲ���
//�����ú�����Ҳ����Ϊƫ�ػ�
int main()
{
	int a = 0, b = 1;
	cout << IsEqual(a, b) << endl;

	const char* p1 = "hello";
	const char* p2 = "world";
	cout<< IsEqual(p1, p2) << endl;
	return 0;
}


//�������
//��Ŀ������һ�㽫��������������ŵ�.h��������������Ķ���ŵ�.cpp

//ΪʲôҪ��������أ�
//����鿴��ά��

//ģ�岻�ܷ������
//��������ʾ
#include"Fun.h"
int main()
{
	Func1();
	//���Ƿ������
	//func1û������
	//����func2ȴ����
	Func2(10);
	//��ͨ����ͺ������Է�����룬������ģ��ͺ���ģ�岻��
	return 0;
}

//Ϊʲôģ�岻�ܷ�����룿
//��Ϊ��ģ��û���õ���ʱ����ûʵ������