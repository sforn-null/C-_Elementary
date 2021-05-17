#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//stack queue ��������������

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

// 4 + 13 / 5  ��׺���ʽ
// 4 13 5 / +  ��׺���ʽ���沨�����ʽ��
//�ص㣺������˳�򲻱䣬�������ڲ������ĺ��棬���Ұ����ȼ�����
//���ʽ�ļ��㣬������
// 1����׺���ʽת��׺���ʽ
// 2����׺���ʽ�������� 
//