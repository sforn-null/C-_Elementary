#include<iostream>
using namespace std;
#include<assert.h>

//���ͱ��
//ģ��
//д�������޹صĴ���
//ģ���Ϊ����ģ�����ģ��

//template<class T>
template<typename T>  //�����ֶ���û����  ģ�����Ͳ���
void Swap(T& x1, T& x2)
{
	T x = x1;
	x1 = x2;
	x2 = x;
}

//������õ��Ƿ���ͬһ��������
//����
//�������ǲ��ܵ��ú���ģ�壬
//���õ��Ǻ���ģ��ʵ�������ɵĶ�Ӧ���͵ĺ���
//ʵ����������Ԥ����׶�

//ģ���ԭ����ʲô�����������ݵ��õĺ���ģ�����ģ�������
 ʵ��������Ӧ�ĺ�������
 ����д��ģ�壬������ͨ��ģ��ʵ������Ӧ�ĺ�������
int main()
{
	int a = 0, b = 0;
	Swap(a, b);

	double c = 1.11, d = 2.22;
	Swap(c, d);

	char e = 'a', f = 'b';
	Swap(e, f);

	return 0;
}


//��ģ��
template<class T>
class Stack
{
public:
	Stack(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	// ʹ������������ʾ�������������������ⶨ�塣
	~Stack();

	void PushBack(const T& data);
		void PopBack()��
		// ...

	size_t Size() 
	{ 
		return _size; 
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T* _a;
	size_t _size;
	size_t _capacity;
};

int main()
{
	// Stack������Stack<int>��������
	Stack<int> s1;
	Stack<double> s2;
}

template<class T>
class vector //˳���   ��̬����������
{
public:
	vector()
		:_a(nullptr)
		,_size(0)
		,_capacity(0)
	{}
	vector(size_t n)
		:_a(new T[n])
		, _size(0)
		, _capacity(n)
	{}
	~vector()
	{
		delete[]_a;
		_a = nullptr;
		_size = _capacity;
	}
	//����������
	void push_back(const T& x);
	//void pop_back();

	size_t size()
	{
		return _size;
	}

	T& operator[](size_t i)
	{
		assert(i < _size);
		return _a[i];
	}

private:
	T* _a;
	size_t _size;
	size_t _capacity;
};

//�����涨��
template<class T>
void vector<T>::push_back(const T& x)
{
	if (_size == _capacity)
	{
		size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
		T* tmp = new T[newcapacity];
		if (_a)
		{
			memcpy(tmp, _a, sizeof(T) * _size);
			delete[]_a;
		}
		_a = tmp;
		_capacity = newcapacity;
	}
	_a[_size] = x;
	++_size;
}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0;i < v.size();++i)
	{
		//[]��
		cout << v[i] << " ";//[]�����ؾ���Ϊ���������ֱ�ӱ�������
	}

	for (size_t i = 0;i < v.size();++i)
	{
		//[]д
		//���Ǹո�д��operator[]�ķ��ط�ʽ�Ǵ�ֵ����
		//����*=ʱ��*=����ʱ�������ˣ�������ʱ������г���
		//�������Ӧ��ʹ�ô����÷���
		
		v[i] *= 2;
	}

	return 0;
}


template<class T>
T Add(const T& left, const T& right) 
{
	return left + right;
}

int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	//��ʽʵ������T�������Ǳ������Լ��Ƶ��ģ�
	Add(a1, a2);
	Add(d1, d2);

	//������������û���Լ��Ƶ���
	//Add(a1, d1);
	//��ô�����ַ�ʽ���Խ��
	Add(a1, (int)d1);

	//��ʾʵ������ָ��T�����ͣ�
	Add<int>(a1, d1);
	return 0;
}

// ר�Ŵ���int�ļӷ�����
int Add(int left, int right) 
{
	return left + right;
}

// ͨ�üӷ�����
template<class T> T Add(T left, T right) 
{
	return left + right;
}

int main()
{
	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	
	Add<int>(1, 2); // ���ñ������ػ���Add�汾

	return 0;
}