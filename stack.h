#pragma once


namespace shy
{
	//template <class T,class Container>
	//但是库里面提高的不需要传第二个容器参数

	template <class T, class Container = deque<T>>
	//库里用的是deque，它是双端操作再加上随机访问
	//支持任意位置的插入删除，也支持随机访问
	
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		T&top()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

	void test_stack1()
	{
		//stack<int, vector<int>> st;
		stack<int, list<int>> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}

	
}