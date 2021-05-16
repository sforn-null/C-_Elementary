#pragma once
#include<assert.h>


namespace shy
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		//只读的迭代器

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0;i < sz;++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage = tmp + n;
				//_finish = tmp + size();
				////size()中的_finish是之前的_finish
				////_start是新的，因此减不了
				////capacity也是这样
				//_endfstorage = tmp + capacity();
			}
		}

		void resize(size_t n, const T& val = T())
								//这里就是T类型的缺省值
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (n > (_finish - _start))
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		
		//拷贝构造
		//v2(v1)
		/*vector(const vector<int>& v)
		{
			_start = new T[v.capacity()];
			_finish = _start;
			_endofstorage = _start + v.capacity();

			for (size_t i = 0;i < v.size();++i)
			{
				*_finish = v[i];
				++_finish;
			}
		}*/


		//第二种拷贝构造
		/*vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}*/

		//v1 = v3
		/*vector<T>& operator = (const vector<T>& v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[v.capacity()];
				
				memcpy(_start, v._start, sizeof(T) * v.size());
			}
			return *this;
		}*/

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		~vector()
		{
			delete[] _start;
			_start = _finish =_endofstorage = nullptr;
		}

		

		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;*/
			insert(end(), x);
		}

		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				//增容之后变成了新的空间
				//而pos还指向旧空间
				pos = _start + n;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

		iterator earse(iterator pos)
		{
			assert(pos < _finish);

			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish; 

			return pos;
		}

		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](const size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};



	void test_vector1()
	{
		vector<int> v;
		/*v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);*/

		cout << v.size() << endl;
		cout << v.capacity() << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.earse(it);
			}
			else
			{
				++it;
			}
		}
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v;
		v.reserve(10);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(4);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(8);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(12);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;
	}

	void test_vector4()
	{
		vector<int>v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int>v2(v1);
		for (size_t i = 0;i < v1.size();++i)
		{
			cout << v2[i] << " ";
		}
	}
}