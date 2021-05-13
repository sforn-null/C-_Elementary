#include<iostream>
#include<string>
using namespace std;

void test_string4()
{
	string s1 = ("hello world");
	string s2 = ("hello");
	cout << s1.size() << endl;
	cout << s2.size() << endl;

	cout << s1.length() << endl;
	cout << s2.length() << endl;
	//size��lengthûʲô����

	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;

	s1 += "111111";
	cout << s1.capacity() << endl;
	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;

}

void test_string5()
{
	string s;
	//s.reserve(100);
	//reserve���ǿ��ռ�
	s.resize(100);//resize�൱�����ַ�������100��Ĭ���ַ���0��
				  //����ռ䲻����������
				  //����ȱ���sizeС����ô�ͻ�Ѻ�����ַ�ɾ��
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	//���������ӣ�Խ��Խ��
}

void test_string6()
{
	/*string s;
	s.push_back('x');
	s.append("111111");
	s += "xxxxx";
	s += 'x';
	cout << s << endl;*/

	string s;
	s += '1';
	s += "3456";
	cout << s << endl;
	s.insert(s.begin(), '0');//����
	s.insert(2, "2");
	cout << s << endl;
	s.erase(2, 3);//��2��ʼɾ�������ַ�
	cout << s << endl;
}

void test_string7()
{
	string s1;
	//��ȡ�ַ������׵�ַ����c�ַ�������ʽ����
	const char* str = s1.c_str();
	while (*str)
	{
		cout << *str << " ";
		++str;
	}
	cout << endl;

	cout << s1 << endl;  //���õ�string���ص�operator<<
	//�������е������ַ������

	cout << s1.c_str() << endl;//ֱ�����const char*
	//����'/0'�ͻ�ͣ
}

void test_string8() 
{
	string s1("string.cpp");
	string s2("string.c");
	string s3("string.txt");

	//Ѱ�Һ���
	size_t pos1 = s1.find(".");//���û�ҵ��ͷ����޷������͵����ֵ
	if (pos1 != string::npos)
	{
		cout << s1.substr(pos1) << endl;
		//substr���Ǵ����λ�ÿ�ʼһֱȡ��β
	}

	//Э��    ����            ��Դ����
	//https://leetcode-cn.com/problems/first-unique-character-in-a-string/
	string url("https://leetcode-cn.com/problems/first-unique-character-in-a-string/");
	size_t i1 = url.find(":");
	if (i1 != string::npos)
	{
		cout << url.substr(0, i1) << endl;
		//�ڶ��������ǳ���
	}
	size_t i2 = url.find('/', i1 + 3);
	if (i2 != string::npos)
	{
		cout << url.substr(i1+3, i2 - i1 - 3) << endl;
	}
	cout << url.substr(i2 + 1) << endl;
}

void test_string9()
{
	string s1("hello");
	string ret1 = s1 + "world";
	string ret2 = s1 += "world";
	cout << ret1 << endl;
	cout << ret2 << endl;
	//��������ûʲô����ģ���Ϊ����ֵûʲô����
	//+�Ļ���s1�����ı䣬��+=�͸ı���

	string s2("abcd");
	string s3("bbcd");
	cout << (s2 < s3) << endl;
	cout << (s2 < "bbcd") << endl;
	cout << ("abcd" < s3) << endl;

}

int main()
{
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();
	//test_string8();
	test_string9();
	return 0;
}