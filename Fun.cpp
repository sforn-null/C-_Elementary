#include"Fun.h"

void Func1()
{
	cout << "shy1" << endl;
}

template<class T>
inline void Func2(const T& x)
{
	cout << "shy2" << endl;
}

//���ģ�岻�ܷ������ķ�����
//1����ʽʵ����
template
void Func2<int>(const int& x);
//���ǵ����������ͣ������Ӳ�����
//������ַ��������ã���Ϊ������

//2����Ҫ���������