#include<iostream>
using namespace std;
//auto�ؼ���


//auto������Ϊ������Ҳ������������
int main()
{
	int a = 0;
	auto b = a;//b�������Ǹ���a�������Ƶ���int

	cout << typeid(a).name() << endl;
	//���Կ�����������
	cout << typeid(a).name() << endl;

	return 0;
}