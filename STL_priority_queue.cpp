#include<iostream>
#include<queue>
#include<functional>
using namespace std;

//��������������֧�ֵ�������������Ϊ����ͨ��������һЩ���������
//���֧�ֵ���������������ô�����޷��ܺõı������ǵ�����
void test_priority_queue1()
{
	//priority_queue<int> pq;//Ĭ�ϴ�����ȼ���
	priority_queue<int,vector<int>,greater<int>> pq;
	//�������С�����ȼ��ߣ���β������º���
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