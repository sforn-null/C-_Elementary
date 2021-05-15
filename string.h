#pragma once
#include<assert.h>

//ʵ�� string

//namespace shy
//{
//	/*�����⣺ʵ��һ���򵥵�string ->��ǳ��������*/
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
//		////��Ϊhello�ַ����ǳ����ַ��������Բ�����char*
//		//string(const char* str)
//		//	:_str(new char[strlen(str)+1])
//		//	//��Ҫ�࿪һ���ռ��'\0'
//		//{
//		//	strcpy(_str, str);
//		//}
//
//		//���Ҫ���޲κ��вκ϶�Ϊһ��
//		//��ô���ܽ�str��ȱʡֵ��Ϊnullptr������""���
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//			//��Ҫ�࿪һ���ռ��'\0'
//		{
//			strcpy(_str, str);
//		}
//
//		//string s2(s1)
//		//���
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
//		//��û��д���������ʱ��
//		//��鷵��ֵ��ʹ��Ĭ�ϵĿ�������
//		//Ĭ�Ͽ�����ǳ����
//
//		string& operator=(const string& s)
//		{
//			/*delete[]_str;
//			_str = (new char[strlen(s._str) + 1]);
//			strcpy(_str, s._str);
//			return *this;*/
//			//��һ�ǽ��Լ���ֵ���Լ�������ͻ���Լ�ɾ�����ˣ�����������
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
//		//��û��д���������ʱ��
//		//c_str����ʱ��ʹ��Ĭ�ϵĿ�������
//		//Ĭ�Ͽ�����ǳ����
//		//����ָ���ָ��ͬһ���ռ䣬�������ʱ��ûʲô����
//		//����������֮��������������
//		//������ʱ��ͬһ���ռ�ᱻ�ͷ�����
//
//		string s3("world");
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//		//��ֵҲ��һ���ģ�������Լ�д������ǳ����
//	}
//
//}


namespace shy
{
	//ʵ��һ��֧����ɾ��ĵ�string
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			//����Ϊʲô_capacity����һ���أ�
			//��Ϊ'\0'������Ч�ַ�
			strcpy(_str, str);
		}

		//������
		//�����������Ͳ�һ����������ָ��
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//��������͸�ֵ

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

		//Ϊ������const�������
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

		void push_back(char ch)//�����ַ�����
		{
			////�ռ��������������
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
			
		void append(const char* str)//�ַ�������
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
		size_t _size;    //�Ѿ��ж�����Ч�ַ�
		size_t _capacity; //�ܴ���ٸ���Ч�ַ���'\0'������Ч�ַ�
		
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

	//�������أ���������ո�֮��ľ�û��������
	//��ʱ�������getline��getline����
	//��ch == ' ' || ch == '\n'���ch == '\n'
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
		//���ֵ�in >> ch����' '��'\n'��ͣ�ˣ�û����ȡ��
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
		cout << s2.c_str() << endl;//������һ����һ����
	
		//��֧�ַ�Χfor
		//��ô��Ҫ֧��iterator��begin(),end()
		//���ұ����Ǳ�׼��ʽ��
		//��Ϊ��Χfor�ᱻ�������滻�ɵ�����
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
	//C++��һ��������������������ʵ��һ��string�࣬
	//����ʱ�䣬������Ҫ��߱�std::string�Ĺ��ܣ�������Ҫ������ȷ������Դ
	//����+����+��������+��ֵ
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//��ͳ����ĸ�ֵ
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

		//�ִ�д��
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

		//������д����������
		//��Ϊ�õ��Ǵ�ֵ�����Ի´������һ����ʱ����
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		//��ͳ�����
		//string s2(s1)
		/*string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}*/

		//��� - �ִ�д��
		//string s2(s1)
		//�൱�ڿ�������һ��tmp��Ȼ���ý���������tmp��_str����
		//��_str�ĳ�ʼֵ��Ϊ��
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
