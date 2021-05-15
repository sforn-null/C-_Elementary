#include<iostream>
#include<vector>
using namespace std;

//vector不支持+=，而且没有\0
//string一般表示单项信息
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

	//遍历修改数据
	//operator[]+size
	for(size_t i = 0;i < v.size();++i)
	{
		cout << v[i] << "";
	}
	cout << endl;
	//迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//范围for
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//三种类型的迭代器
void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//普通正向迭代器 可读可写
	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/

	//const迭代器，只读
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//reverse  逆置
	//reserve  保留
	//逆向迭代器  可读可写
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

	//reserve()就可以直接开出你想要的空间，就没有增容的弊端了
	//resize（）就不光是开空间了，还初始化了
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
	//v[4] = 5;//越界了，断言错误
	//v.at(4) = 5;//可以捕获异常

}

void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//需要给的是迭代器的位置
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

	//知道5的位置删掉5
	/*v.erase(v.begin()+1);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/

	//不知道位置删除5
	//vector没有find
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	//这里的find是个算法，是个模板函数
	//别的类型也能用
	
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


//迭代器失效1
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
	v.push_back(7);//只push_back6的时候没事情，但是7的时候就崩溃了
	//增容会导致迭代器失效
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
	//要求删除容器中的所有偶数
	//删除it之后，it就失效了，这里的失效是it的位置不对了
	//再++it就不行了
	vector<int>::iterator it = v.begin();
	/*while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		++it;
	}*/
	//下面的就可以解决了
	//因为erase会返回被删的it的下一个位置的迭代器
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