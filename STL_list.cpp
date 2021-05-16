#include<iostream>
#include<list>
using namespace std;

//一般不会用const迭代器，一般是函数内需要传参的时候用
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
	//带头双向循环链表
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
	//只要一个容器支持迭代器，就可以使用范围for的操作
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

//支持的操作借口的角度分迭代器的类型:
//单向（forword_liat）、双向（list）、随机（vector）
//从使用的场景的角度分迭代器的类型:（正向迭代器、反向迭代器）+const迭代器

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

//在3前面插入30
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
	
	//list不支持这样的操作，vector支持
	//lt.insert(lt.begin() + 3, 30);

	list<int>::iterator pos = find(lt.begin(),lt.end(),3);
	if (pos != lt.end())
	{
		lt.insert(pos, 30);
		lt.erase(pos);   
		//这里insert以后pos失效了么？
		// list这里没问题，指针位置不变，也不存在增容的问题
		// 
		//如果是vector，这里失效了么
		//vector会失效，是底层的物理结构导致的
		//因为pos指针的位置会改变，而且增容之后指针指向的还是旧空间
	}
	print_list(lt);
}

//迭代器失效，insert是不会失效的
void test_list4()
{
	list<int> lt;
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(1);
	lt.push_back(5);
	lt.push_back(4);
	lt.push_back(6);

	//删除所有偶数
	//这里迭代器就会失效
	/*list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			lt.erase(it);
		}
		++it;
	}*/
	//因此我们跟之前一样
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