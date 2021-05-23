#include<iostream>
using namespace std;
//���̳кͶ�̳й�ϵ���麯����


//���̳��е��麯����
class Base 
{
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base 
{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};
//�ڼ��Ӵ��ڿ����ǲ���ʾfunc3��func4�ģ��������е�

//��ӡ���
//void(*p)() ����һ������ָ�����
typedef void(*VF_PTR)();//����ָ������typedef
void PrintVFTable(VF_PTR* pTable)
{
	for (size_t i = 0;pTable[i] != 0;++i)
	{
		printf("vfTable[%d]:%p\n", i, pTable[i]);
	}
}

int main()
{
	Base b;
	Derive d;
	PrintVFTable((VF_PTR*)*(int*)&b);
	cout << endl;
	PrintVFTable((VF_PTR*)*(int*)&d);
	return 0;
}


//��̳�
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};