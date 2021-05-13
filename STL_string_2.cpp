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
	//size和length没什么区别

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
	//reserve就是开空间
	s.resize(100);//resize相当于让字符个数到100，默认字符是0，
				  //如果空间不够还会增容
				  //如果比本身size小，那么就会把后面的字符删掉
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
	//按倍数增加，越来越慢
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
	s.insert(s.begin(), '0');//插入
	s.insert(2, "2");
	cout << s << endl;
	s.erase(2, 3);//从2开始删除三个字符
	cout << s << endl;
}

void test_string7()
{
	string s1;
	//获取字符数组首地址，用c字符串的形式遍历
	const char* str = s1.c_str();
	while (*str)
	{
		cout << *str << " ";
		++str;
	}
	cout << endl;

	cout << s1 << endl;  //调用的string重载的operator<<
	//将对象中的所有字符都输出

	cout << s1.c_str() << endl;//直接输出const char*
	//遇到'/0'就会停
}

void test_string8() 
{
	string s1("string.cpp");
	string s2("string.c");
	string s3("string.txt");

	//寻找函数
	size_t pos1 = s1.find(".");//如果没找到就返回无符号整型的最大值
	if (pos1 != string::npos)
	{
		cout << s1.substr(pos1) << endl;
		//substr就是从这个位置开始一直取到尾
	}

	//协议    域名            资源名称
	//https://leetcode-cn.com/problems/first-unique-character-in-a-string/
	string url("https://leetcode-cn.com/problems/first-unique-character-in-a-string/");
	size_t i1 = url.find(":");
	if (i1 != string::npos)
	{
		cout << url.substr(0, i1) << endl;
		//第二个参数是长度
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
	//这样看是没什么区别的，因为返回值没什么区别
	//+的话是s1本身不改变，而+=就改变了

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