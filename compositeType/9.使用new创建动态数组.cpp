//静态联编：在编译时给数组分配内存，即使运行时不使用这个数组。必须在编写程序时确定数组大小。
//动态联编：使用new，在运行时需要就创建。程序将在运行时确定数组长度。
#include<iostream>
using namespace std;
int main() {
	//1.使用new 创建数组：
	int* psome = new int[3];//将元素类型和数目告诉new，new运算符返回第一个元素的地址给psome

	//使用动态数组：把指针当做数组名来使用：
	psome[0] = 1;
	psome[1] = 2;
	psome[2] = 4;
	cout << psome[0] << endl;
	cout << psome[1] << endl;
	cout << psome[2] << endl;

	//指针算术：指针变量+1后，增加的量是它指向类型的字节数
	cout << " psome is " << psome << " . *psome is " << *psome << endl;
	cout << " psome+1 is " << (psome + 1) << " . *(psome+1) is " << *(psome + 1) << endl;

	//C++将数组名解释为第一个元素的地址
	int p1[3] = { 1,2,3 };
	cout << "p1 is " << p1 << endl;
	cout << "&p1[0] is " << &p1[0] << endl;//一个元素的地址，即一个4字节内存块的地址
	cout << "&p1[0]+1 is " << &p1[0]+1 << endl;
	cout << "&p1 is " << &p1 << endl;//整个元素的地址，即一个12字节内存块的地址
	cout << "&p1+1 is " << &p1 + 1 << endl;

	//数组表示法：指针psome[1],数组名p1[1]    在编译器中看作是*(psome+1) *(p1+1)  两种表示方法都可以
	//二者区别1：指针可以修改 数组名是常量，不能修改
	//二者区别2：sizeof作用于数组得到的是数组长度，作用于指针得到的是指着长度。
	cout << "sizeof p1 is " << sizeof p1 << endl;//数组长度=数组个数*变量字节
	cout << "the number of p1 is " << sizeof p1 / sizeof p1[0] << endl;
	cout << "sizeof psome is " << sizeof psome << endl;
	delete[] psome;//[]告诉程序应该释放整个数组而不是指针指向的元素。
	return 0;
}
