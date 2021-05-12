#include<iostream>
using namespace std;

//STL(standard template libaray - ��׼ģ���)��
// ��C++��׼�����Ҫ��ɲ��֣�������һ���ɸ��õ�����⣬
// ������һ���������ݽṹ���㷨�������ܡ�

//string ->�ַ�����
#include<string>

int main()
{
	string s1;
	//�޲ι���

	string s2("hello");
	//���ι���

	string s3(s2);
	//��������

	string s4(10, 'a');
	//ʮ���ַ�a

	string s5 = "hello";
	string s6 = s2;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	s1 = s2;//��ֵ
	cout << s1 << endl;

	return 0;
}


int main()
{
	//string s("12345");
	//s.push_back('6');//����һ���ַ�
	//s.append("78");//����һ���ַ���

	//s += '1';//+=������һ���ַ�����һ���ַ�������ʵ��
	//s += "1111";//�൱������append
	//cout << s << endl;


	//ʵ���ַ���ת������
	string s("12345");
	int val = 0;
	for (size_t i = 0;i < s.size();++i)
	{
		val *= 10;
		val += (s[i] - '0');
	}
	cout << val << endl;

	return 0;
}


//1��4��Ĭ�ϳ�Ա����
void test_string1()
{
	string s1;//��Ҫ
	string s2("hello");//��Ҫ
	string s3("hello", 2);
	string s4(s2);//��Ҫ
	string s5(s2, 1, 2);


	//�������ֶ���ȡ��β
	//npos,��ʵnposҲ�����޷����������ֵ
	//��дȡ����,��ʵ����ȱʡֵ�ģ�ȱʡֵҲ�������ֵ
	//ȡ�ĳ��ȳ����ַ���
	string s6(s2, 1, string::npos);
	string s7(s2, 1);
	string s8(s2, 1, 8);

	string s9(10, 'a');
	s1 = s7;//��Ҫ
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
}

//1.����
void test_string2()
{
	string s1("hello");
	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;

	//ƽʱ�Ƽ������
	//д
	for (size_t i = 0;i < s1.size();++i)
	{
		s1[i] += 1;
	}

	//��
	for (size_t i = 0;i < s1.size();++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//������
	//д
	//string::iterator it = s1.begin();
	//������������Ҳ������ôд
	auto it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}

	//��
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	
	//��Χfor
	//c++11 -> ԭ���Ǳ��滻�ɵ�����
	for (auto ch : s1)//����������Ķ���ȡ�����������Զ�++
	{
		cout << ch << " ";
	}
	cout << endl;
}

int string2int(const string& str)//stringtoint() ������һ����
{
	int val = 0;
	//������const����ֻ�ܵ���const�ĵ�����
	//const������ֻ�ܶ�����д
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');
		++it;
	}
	return val;
}

//�ٿ�������������
void test_string3()
{
	string s1("hello world");
	//���ű���
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	string nums("12345");
}

int main()
{
	//test_string1();
	//test_string2();
	test_string3();
	return 0;
}