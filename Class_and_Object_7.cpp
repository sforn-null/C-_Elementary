#include<iostream>
using namespace std;

//static��Ա
//���һ���࣬���Լ���������ܼƲ����˶��ٶ���


class A
{
public:
	A()
	{
		++n;
	}
	A(const A& a)
	{
		++n;
	}
	static int GetN()//û��thisָ�룬�����в��ܷ��ʷǾ�̬�ĳ�Ա
	{
		//_a = 10 ���ܷ��ʷǾ�̬�ĳ�Ա
		return n;
	}
private:
	static int n;//���� ��������ĳ������������������ж������������
};

int A::n = 0;

A f1(A a)
{
	return a;
}

int main()
{
	A a1;
	A a2;
	f1(a1);
	//n = 1;//����˭�����Զ�n�����޸�
	f1(a2);
	//cout << n << endl;
	a1.GetN();
	A::GetN();
	//ͻ����������ַ�ʽ

	return 0;

}

//1. ��̬��Ա�������Ե��÷Ǿ�̬��Ա������
// �����ԣ���̬��û��thisָ��
// 
// 
//2. �Ǿ�̬��Ա�������Ե�����ľ�̬��Ա������
// ���ԣ�ֻҪ��ͻ������Ϳ��Ե���

class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	// C++11��֧������
	// ����ʱ��ȱʡֵ�������ǳ�ʼ������ʼ��ֻ�ܶ����ʱ�������
	int _year = 0;
	int _month = 1;
	int _day = 1;

	//��̬��ȴ������ô��
	static int i = 0;
	//���־�̬�ľͲ�����
};

int main()
{
	Date d1;
	d1.Print();
	return 0;
}