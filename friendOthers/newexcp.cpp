//对于new导致的内存分配问题，C++的最新处理方式是让new引发bad_alloc异常
//头文件new包含了bad_alloc类的声明，它是从exception类公有派生而来的
#include<iostream>
#include<new>
#include<cstdlib>//for exit() , EXIT_FAILURE
using namespace std;
struct Big
{
	double  stuff[20000];
};

void test();

int main()
{
	Big* pb;
	try {
		cout << "Trying to get a big block of memory: \n";
		pb = new Big[1000];
		cout << "Got past the new request:\n";
	}
	catch (bad_alloc& ba)
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;
		//返回std::bad_alloc
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[]pb;
	return 0;
}

void test()
{
	/*
		C++标准提供了一种在失败时返回空指针的new，其用法如下：
		int* pi= new (std::nothrow) int ;
		int* pa= new (std::nowthrow) int[500];
	*/

	//上述核心代码可用下列代码替换
	Big* pb;

	pb = new (std::nothrow) Big[5000];
	if (pb == 0)
	{
		cout << "Could not allocate memory.Bye\n";
		exit(EXIT_FAILURE);
	}
}