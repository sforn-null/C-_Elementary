#pragma once
#include<assert.h>

//实现 string

//namespace shy
//{
//	/*面试题：实现一个简单的string ->深浅拷贝问题*/
//	class string
//	{
//	public:
//		//string()
//		//	:_str(new char[1])
//		//{
//		//	_str[0] = '\0';
//		//}
//		////string(char* str)
//		////	:_str(str)
//		////{}
//		////因为hello字符串是常量字符串，所以不能用char*
//		//string(const char* str)
//		//	:_str(new char[strlen(str)+1])
//		//	//需要多开一个空间给'\0'
//		//{
//		//	strcpy(_str, str);
//		//}
//
//		//如果要将无参和有参合二为一，
//		//那么不能将str的缺省值设为nullptr，而是""这个
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//			//需要多开一个空间给'\0'
//		{
//			strcpy(_str, str);
//		}
//
//		//string s2(s1)
//		//深拷贝
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		
//
//		~string()
//		{
//			delete[]_str;
//			_str = nullptr;
//		}
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//		//在没有写拷贝构造的时候，
//		//这块返回值会使用默认的拷贝构造
//		//默认拷贝是浅拷贝
//
//		string& operator=(const string& s)
//		{
//			/*delete[]_str;
//			_str = (new char[strlen(s._str) + 1]);
//			strcpy(_str, s._str);
//			return *this;*/
//			//万一是将自己赋值给自己，这里就会把自己删除掉了，就有问题了
//			
//			if (this != &s)
//			{
//				char* tmp = (new char[strlen(s._str) + 1]);
//				strcpy(tmp, s._str);
//				delete[]_str;
//				_str = tmp;
//			}
//			return *this;
//		}
//	private:
//		char* _str;
//	};
//	void test_string1()
//	{
//		string s1("hello");
//		string s2;
//		for (size_t i = 0;i < s1.size();++i)
//		{
//			s1[i] += 1;
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//	}
//	void test_string2()
//	{
//		string s1("hello");
//		string s2(s1);
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//		//在没有写拷贝构造的时候，
//		//c_str返回时会使用默认的拷贝构造
//		//默认拷贝是浅拷贝
//		//两个指针会指向同一个空间，在输出的时候没什么问题
//		//但是在用完之后会调用析构函数
//		//析构的时候同一个空间会被释放两次
//
//		string s3("world");
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//		//赋值也是一样的，如果不自己写，都是浅拷贝
//	}
//
//}


namespace shy
{
	//实现一个支持增删查改的string
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			//这里为什么_capacity会少一个呢？
			//因为'\0'不是有效字符
			strcpy(_str, str);
		}

		//迭代器
		//迭代器的类型不一定，这里是指针
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//拷贝构造和赋值

		size_t size() const
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}

		//为了能让const对象访问
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size;i < n;++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len >= (_size - pos))
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[pos] = _str[i];
					++pos;
					++i;
				}
				_size -= len;
			}
			return *this;
		}

		void push_back(char ch)//单个字符插入
		{
			////空间满了则进行增容
			//if (_size == _capacity)
			//{
			//	size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
			//	reserve(newcapacity);
			//	
			//}
			//_str[_size] = ch;
			//++_size;
			//_str[_size] = '\0';
			insert(_size, ch);
		}
			
		void append(const char* str)//字符串插入
		{
			/*size_t len = strlen(_str);
			if (_size + len > _capacity)
			{
				size_t newcapacity = _size + len;
				reserve(newcapacity);
			}
			strcpy(_str + _size, str);
			_size += len;*/
			insert(_size, str);
		}

		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos;i < _size;++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			char* p = strstr(_str, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
				_capacity = newcapacity;
			}

			int end = _size;
			while (end >= (int)pos)
			{
				_str[end+1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			 {
				size_t newcapacity = _size + len;
				reserve(newcapacity);
				_capacity = newcapacity;
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}
			for (int i = 0;i < len;++i)
			{
				_str[pos++] = str[i++];
			}
			_size += len;
			return *this;
		}

		bool operator<(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}

		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}


	private:
		char* _str;
		size_t _size;    //已经有多少有效字符
		size_t _capacity; //能存多少个有效字符，'\0'不是有效字符
		
		static size_t npos;
	};

	size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0;i < s.size();++i)
		{
			out << s[i];
		}
		return out;
	}

	//输入重载，这个函数空格之后的就没法输入了
	//这时候可以用getline，getline就是
	//将ch == ' ' || ch == '\n'变成ch == '\n'
	istream& operator>>(istream& in, string& s)
	{
		/*while (1)
		{
			char ch;
			in >> ch;
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}*/
		//这种的in >> ch遇到' '和'\n'就停了，没法获取它
		while (1)
		{
			char ch;
			ch = in.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return in;
	}

	void test_string1()
	{
		string s1;
		string s2("hello");
		s2.push_back(' ');
		s2.append("world");
		cout << s1 << endl;
		cout << s2.c_str() << endl;//这两种一般是一样的
	
		//想支持范围for
		//那么需要支持iterator，begin(),end()
		//并且必须是标准格式，
		//因为范围for会被编译器替换成迭代器
	}

	void test_string3()
	{
		string s1("hello");
		/*s1.insert(1, 'x');
		s1.insert(1, "xyz");*/
		s1.insert(0, "shy");
		cout << s1 << endl;
		/*s1.erase(2, 100);
		cout << s1 << endl;*/
	}

	void test_string4()
	{
		string s1("abcdabcdef");
		cout << s1.find("cde") << endl;
		cout << s1.find("cdex") << endl;
	}

	void test_string5()
	{
		string s1;
		cin >> s1;
		cout << s1 << endl;
	}
}


namespace shy_copy
{
	//C++的一个常见的面试题是让你实现一个string类，
	//闲余时间，不可能要求具备std::string的功能，但至少要求能正确管理资源
	//构造+析构+拷贝构造+赋值
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//传统深拷贝的赋值
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[]_str;
				_str = tmp;
			}

			return *this;
		}*/

		//现代写法
		//s1 = s2
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(_str, tmp._str);
			}
			return *this;
		}*/

		//还可以写成下面这样
		//因为用的是传值，所以会拷贝构造一个临时变量
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		//传统的深拷贝
		//string s2(s1)
		/*string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}*/

		//深拷贝 - 现代写法
		//string s2(s1)
		//相当于拷贝构造一个tmp，然后用交换函数把tmp和_str交换
		//将_str的初始值置为空
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}


		~string()
		{
			delete[]_str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
}
