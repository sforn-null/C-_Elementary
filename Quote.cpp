//����

#include<iostream>
using namespace std;

int main()
{
	int a = 1;
	int& ra = a;//ra��a�����ã�����Ҳ���Ǳ�����a��ȡ��һ������ra
	int& b = a;
	int& c = ra;

	c = 2;//c�ı��ˣ���ȫ���ı���
	
	return 0;
}

int main()
{
	int a = 1;
	//int& ra;//���ñ����ڶ���ʱ��ʼ��
	int& c = a;
	int d = 2;
	c = d; //����������c�����d�����ã����ǽ�d��ֵ��c��
	//�����d��ֵ����c��������c�����d������

	return 0;
}

int main()
{
	int a = 0;

	int& b = a;//b��������int

	const int c = 0;
	//int& d = c;//���벻ͨ����ԭ����c��ֻ����d��������int�ǿɶ���д��

	const int& i = c;//�����Ϳ�����

	int e = 1;
	int& f = e;
	const int& g = e;//�����ǿ��Եģ�e�ǿɶ���д��g��ֻ��
	//�ܽ�: ����ȡ����ʱ���������ʵ�Ȩ�޿�����С�������ܷŴ�

	double db = i;//��ʽ����ת�����൱�ڲ�����һ��double���͵���ʱ����
	//double& rdb = i;//�����ǲ��еģ���ʱ�����Ǿ��г��Եģ�Ȩ����ֻ����
	const double& rdb = i;//�������ǿ��Եģ�Ȩ�޶���ֻ���ģ����Կ���
	return 0;
}


//����������
void Swap_cpp(int& left, int& right) {
	int temp = left;
	left = right;
	right = temp;
}

void Swap_C(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//����������ֵ
int count1()
{
	static int n = 0;//��ֵ����
	n++;
	return n;        //����ʱ���᷵��n�����Ƿ���һ����ʱ����
}

int& count2()        //�����÷���
{
	static int n = 0;
	n++;
	return n;        //������൱�ڷ�����n
}

int& Add2(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int a = 1;
	int b = 2;
	Swap_C(&a, &b);
	Swap_cpp(a, b);

	int& ret = Add2(1, 2);
	Add2(3, 4);
	cout << "Add2(1,2) is:" << ret << endl;//�������7
	return 0;
}
//˵��������ر���C��һ���ֲ�����ʱ��
// ���÷���ʱ�ǲ���ȫ��
// 
// ��ʹ���ظ�ʹ��ͬһ������������������������ôԭ����ջ֡�ռ�ͻᱻ����
// ��˽�Ҫ���صı���ǰ����� static
// ��Ϊ����static֮��c�Ͳ���ջ�����ˣ�c�ھ�̬�������ݶΣ�֮��
// 
// �ܽ�:���һ������Ҫʹ�����÷��أ����ر���������������������򻹴���
// �Ϳ���ʹ�����÷��أ�����Ͳ���ȫ
// 
// ʹ�����÷��صĺô���
// �ٴ�������һ����ʱ�������Ч�ʣ������������ã��ں���ὲ
//



//��ֵ���ء������÷���Ч�ʱȽ�
#include <time.h>
struct A
{
	int a[10000];
};

A a;
A TestFunc1() 
{
	return a;
}

A& TestFunc2() 
{
	return a;
}

int main()
{
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1()-time:" << end1 - begin1 << endl;
	cout << "TestFunc2()-time:" << end2 - begin2 << endl;
}
//��ֵ�ʹ����õ�Ч��Ҳ������
//һ���������ñ��Ķ�����ָ����


//��������
void Swap1(int& x1, int& x2)
{
	int tmp = x1;
	x1 = x2;
	x2 = tmp;
}

//Ƶ������swap�������ĵ�
//��ν����1��c����ʹ�ú꺯�� 2��c++ʹ����������
//�������������ں���ǰ��Ӹ�inline
//�������������ÿռ任ʱ��
inline void Swap2(int& x1, int& x2)
{
	int tmp = x1;
	x1 = x2;
	x2 = tmp;
}

int main()
{
	int a = 1;
	int b = 2;
	Swap1(a, b);
	Swap2(a, b);
	return 0;
}