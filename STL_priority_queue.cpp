#include<iostream>
#include<queue>
#include<functional>
using namespace std;

//容器适配器都不支持迭代器遍历，因为他们通常都包含一些特殊的性质
//如果支持迭代器随便遍历，那么他们无法很好的保持他们的性质
void test_priority_queue1()
{
	//priority_queue<int> pq;//默认大的优先级高
	priority_queue<int,vector<int>,greater<int>> pq;
	//如果想变成小的优先级高，如何操作？仿函数
	pq.push(3);
	pq.push(1);
	pq.push(9);
	pq.push(4);
	pq.push(2);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main()
{
	test_priority_queue1();
	return 0;
}