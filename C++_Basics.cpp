#include<iostream>
//在日常练习中，不在乎跟库命名冲突，就可以将std全展开
using namespace std;
//c++库中所有东西都是放到std命名空间中
//这样写就是将std命名空间里的所有东西全展开后面都可以用


//常用的库里面一些对象或者类型可以展出来
//工程项目中通常比较推荐这种用法
using std::cout;//这就是将std里面的cout展开
using std::endl;//这就是将std里面的endl展开
//这样之后写的代码就可以直接用cout和endl了

int main()
{
	std::cout << "hello world\n";
	//std::代表count是std里面的，如果前面没有展开，那么
	//在这里就得用这个
	//在c++中可以用\n换行
	//但是一般常用
	std::cout << "hello world" << std::endl;
	//这个不是end1（一）而是endl（L）
	int i = 1;
	double d = 1.11;

	std::cin >> i >> d;
	//cin就是输入，同样可以自动识别类型

	std::cout << i << " " << d << std::endl;
	//cout就是输出，可以自动识别类型
	return 0;
}