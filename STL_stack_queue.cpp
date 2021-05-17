#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//stack queue 叫做容器适配器

void test_stack()
{
	stack<int> st;
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

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	test_stack();
	test_queue();
	return 0;
}

// 4 + 13 / 5  中缀表达式
// 4 13 5 / +  后缀表达式（逆波兰表达式）
//特点：操作数顺序不变，操作符在操作数的后面，并且按优先级排列
//表达式的计算，两步走
// 1、中缀表达式转后缀表达式
// 2、后缀表达式进行运算 
//