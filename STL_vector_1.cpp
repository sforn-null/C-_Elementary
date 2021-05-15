#include<iostream>
#include<vector>
using namespace std;

//vector��֧��+=������û��\0
//stringһ���ʾ������Ϣ
void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2(v1);
	for (size_t i = 0;i < v1.size();++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0;i < v2.size();++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);
	v3.push_back(40);
	v1 = v3;
	for (size_t i = 0;i < v1.size();++i)
	{
		cout << v1[i] << " ";
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

	//�����޸�����
	//operator[]+size
	for(size_t i = 0;i < v.size();++i)
	{
		cout << v[i] << "";
	}
	cout << endl;
	//������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��Χfor
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//�������͵ĵ�����
void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//��ͨ��������� �ɶ���д
	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/

	//const��������ֻ��
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//reverse  ����
	//reserve  ����
	//���������  �ɶ���д
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	//reserve()�Ϳ���ֱ�ӿ�������Ҫ�Ŀռ䣬��û�����ݵı׶���
	//resize�����Ͳ����ǿ��ռ��ˣ�����ʼ����
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v[4] = 5;//Խ���ˣ����Դ���
	//v.at(4) = 5;//���Բ����쳣

}

void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//��Ҫ�����ǵ�������λ��
	v.insert(v.begin(), 0);
	v.insert(v.begin(), -1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector7()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(4);
	v.push_back(2);
	v.push_back(9);
	v.push_back(50);
	v.push_back(5);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//֪��5��λ��ɾ��5
	/*v.erase(v.begin()+1);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/

	//��֪��λ��ɾ��5
	//vectorû��find
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	//�����find�Ǹ��㷨���Ǹ�ģ�庯��
	//�������Ҳ����
	
	if (pos != v.end())
	{
		v.erase(pos);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}


//������ʧЧ1
void test_vector8()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it = v.begin();
	v.push_back(6);
	v.push_back(7);//ֻpush_back6��ʱ��û���飬����7��ʱ��ͱ�����
	//���ݻᵼ�µ�����ʧЧ
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_vector9()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	//Ҫ��ɾ�������е�����ż��
	//ɾ��it֮��it��ʧЧ�ˣ������ʧЧ��it��λ�ò�����
	//��++it�Ͳ�����
	vector<int>::iterator it = v.begin();
	/*while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		++it;
	}*/
	//����ľͿ��Խ����
	//��Ϊerase�᷵�ر�ɾ��it����һ��λ�õĵ�����
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
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

int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	//test_vector7();
	//test_vector8();
	test_vector9();
	return 0;
}