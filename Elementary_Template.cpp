#include<iostream>
using namespace std;
#include<assert.h>

//泛型编程
//模板
//写跟类型无关的代码
//模板分为函数模板和类模板

//template<class T>
template<typename T>  //这两种都行没区别  模板类型参数
void Swap(T& x1, T& x2)
{
	T x = x1;
	x1 = x2;
	x2 = x;
}

//下面调用的是否是同一个函数？
//不是
//这里我们不能调用函数模板，
//调用的是函数模板实例化生成的对应类型的函数
//实例化发生在预处理阶段

//模板的原理是什么：编译器根据调用的函数模板和类模板的类型
 实例化出对应的函数和类
 我们写了模板，编译器通过模板实例出对应的函数或类
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


//类模板
template<class T>
class Stack
{
public:
	Stack(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	// 使用析构函数演示：在类中声明，在类外定义。
	~Stack();

	void PushBack(const T& data);
		void PopBack()；
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
	// Stack类名，Stack<int>才是类型
	Stack<int> s1;
	Stack<double> s2;
}

template<class T>
class vector //顺序表   动态增长的数组
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
	//类里面声明
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

//类外面定义
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
		//[]读
		cout << v[i] << " ";//[]的重载就是为了这里可以直接遍历数组
	}

	for (size_t i = 0;i < v.size();++i)
	{
		//[]写
		//我们刚刚写的operator[]的返回方式是传值返回
		//我们*=时是*=到临时对象上了，并且临时对象具有常性
		//因此我们应该使用传引用返回
		
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
	//隐式实例化（T的类型是编译器自己推导的）
	Add(a1, a2);
	Add(d1, d2);

	//这样编译器就没法自己推导了
	//Add(a1, d1);
	//那么有两种方式可以解决
	Add(a1, (int)d1);

	//显示实例化（指定T的类型）
	Add<int>(a1, d1);
	return 0;
}

// 专门处理int的加法函数
int Add(int left, int right) 
{
	return left + right;
}

// 通用加法函数
template<class T> T Add(T left, T right) 
{
	return left + right;
}

int main()
{
	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
	
	Add<int>(1, 2); // 调用编译器特化的Add版本

	return 0;
}