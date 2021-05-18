#pragma once
#include<vector>

namespace shy
{
	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:

		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//ѡ�����Һ����д����һ��
				/*if (_con[child] > _con[parent])*/
				if (com(_con[parent] , _con[child]))
				{
					swap(_con[child] , _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDown(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//ѡ�����Һ����д����һ��
				if (child + 1 < _con.size() && com(_con[child] , _con[child+1]))
				{
					++child;
				}
				/*if (_con[child] > _con[parent])*/
				if(com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}


		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDown(0);
		}

		T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_priority_queue1()
	{
		priority_queue<int> pq;
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
}