#include<iostream>
#include<list>
using namespace std;

//һ�㲻����const��������һ���Ǻ�������Ҫ���ε�ʱ����
void print_list(const list<int>& L)
{
	list<int>::const_iterator it = L.begin();

	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test_list1()
{
	//��ͷ˫��ѭ������
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_front(0);
	L.push_front(-1);

	list<int>::iterator it = L.begin();

	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = L.rbegin();

	while (rit != L.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<int> L2(L);
	print_list(L2);

	list<int> L3;
	L3.push_back(10);
	L3.push_back(20);
	L3.push_back(30);
	L3.push_back(40);

	L = L3;
	//ֻҪһ������֧�ֵ��������Ϳ���ʹ�÷�Χfor�Ĳ���
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::reverse_iterator ritl = L.rbegin();
	while (ritl != L.rend())
	{
		cout << *ritl << " ";
		++ritl;
	}
	cout << endl;
}

//֧�ֵĲ�����ڵĽǶȷֵ�����������:
//����forword_liat����˫��list���������vector��
//��ʹ�õĳ����ĽǶȷֵ�����������:������������������������+const������

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(0);
	lt.push_front(-1);

	print_list(lt);

	lt.pop_back();
	lt.pop_front();
	print_list(lt);
}

//��3ǰ�����30
void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	print_list(lt);
	
	//list��֧�������Ĳ�����vector֧��
	//lt.insert(lt.begin() + 3, 30);

	list<int>::iterator pos = find(lt.begin(),lt.end(),3);
	if (pos != lt.end())
	{
		lt.insert(pos, 30);
		lt.erase(pos);   
		//����insert�Ժ�posʧЧ��ô��
		// list����û���⣬ָ��λ�ò��䣬Ҳ���������ݵ�����
		// 
		//�����vector������ʧЧ��ô
		//vector��ʧЧ���ǵײ������ṹ���µ�
		//��Ϊposָ���λ�û�ı䣬��������֮��ָ��ָ��Ļ��Ǿɿռ�
	}
	print_list(lt);
}

//������ʧЧ��insert�ǲ���ʧЧ��
void test_list4()
{
	list<int> lt;
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(1);
	lt.push_back(5);
	lt.push_back(4);
	lt.push_back(6);

	//ɾ������ż��
	//����������ͻ�ʧЧ
	/*list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			lt.erase(it);
		}
		++it;
	}*/
	//������Ǹ�֮ǰһ��
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			it = lt.erase(it);
		}
		else
		{
			++it;
		}
		
	}
}

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	test_list4();
	return 0;
}