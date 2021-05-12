#include<iostream>
using namespace std;

//STL(standard template libaray - 标准模板库)：
// 是C++标准库的重要组成部分，不仅是一个可复用的组件库，
// 而且是一个包罗数据结构与算法的软件框架。

//string ->字符数组
#include<string>

int main()
{
	string s1;
	//无参构造

	string s2("hello");
	//带参构造

	string s3(s2);
	//拷贝构造

	string s4(10, 'a');
	//十个字符a

	string s5 = "hello";
	string s6 = s2;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	s1 = s2;//赋值
	cout << s1 << endl;

	return 0;
}


int main()
{
	//string s("12345");
	//s.push_back('6');//插入一个字符
	//s.append("78");//插入一个字符串

	//s += '1';//+=不论是一个字符还是一个字符串都能实现
	//s += "1111";//相当于用了append
	//cout << s << endl;


	//实现字符串转成整型
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


//1、4个默认成员函数
void test_string1()
{
	string s1;//重要
	string s2("hello");//重要
	string s3("hello", 2);
	string s4(s2);//重要
	string s5(s2, 1, 2);


	//以下三种都是取到尾
	//npos,其实npos也就是无符号整型最大值
	//不写取到哪,其实是有缺省值的，缺省值也就是最大值
	//取的长度超过字符串
	string s6(s2, 1, string::npos);
	string s7(s2, 1);
	string s8(s2, 1, 8);

	string s9(10, 'a');
	s1 = s7;//重要
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
}

//1.遍历
void test_string2()
{
	string s1("hello");
	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;

	//平时推荐用这个
	//写
	for (size_t i = 0;i < s1.size();++i)
	{
		s1[i] += 1;
	}

	//读
	for (size_t i = 0;i < s1.size();++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//迭代器
	//写
	//string::iterator it = s1.begin();
	//迭代器的类型也可以这么写
	auto it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}

	//读
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	
	//范围for
	//c++11 -> 原理是被替换成迭代器
	for (auto ch : s1)//将数组里面的东西取出来，并且自动++
	{
		cout << ch << " ";
	}
	cout << endl;
}

int string2int(const string& str)//stringtoint() 这俩是一样的
{
	int val = 0;
	//函数是const，就只能调用const的迭代器
	//const迭代器只能读不能写
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');
		++it;
	}
	return val;
}

//再看看其他迭代器
void test_string3()
{
	string s1("hello world");
	//倒着遍历
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