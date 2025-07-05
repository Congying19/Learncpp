//存储数据时有三种属性：1.信息存储在何处 2.存储的值为多少 3.存储的信息类型是什么
//策略一：定义一个简单变量（指出值的类型，并且起了一个名字，用这个名字跟踪信息存储内存）
//在这个策略中，值是指定的量，地址是派生量，用&作用于变量就可以获得变量地址
//策略二：定义一个指针（指针存储一个地址，利用地址存储或修改变量）
//在这个策略中，地址是指定的量，值是派生量，用*作用于地址可以获取该地址存储的变量。

//指针声明时必须指出指针指向变量的类型，变量类型不同，内部格式不同。
#include<iostream>
using namespace std;
int main() {
	//指针声明：
	int* p_int;//理解：int *p_int 说明*p_int是int型变量，而*是解引用操作。说明p_int是指向int型变量的指针。
	int* p_int2, int3;//这里int3是int型变量，因为没有*
	cout << "the size of p_int is " << sizeof p_int << endl;
	cout << "the size of p_int2 is " << sizeof p_int2 << endl;//不管是什么类型的指针，地址长度都是八个字节。
	cout << "the size of int3 is " << sizeof int3 << endl;

	//指针初始化,初始化操作是必须的。
	//方法一：
	int hight1 = 30;
	int* p_hight1=&hight1;//这里不能把*p_hight1理解成一个Int型变量，是给p_hight1变量赋值，要用&
	cout << *p_hight1 << "  " << p_hight1 << endl;


	return 0;
}