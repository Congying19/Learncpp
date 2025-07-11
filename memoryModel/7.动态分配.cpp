//1.使用new运算符初始化：
//方法一：括号语法：int *pi = new int (6);
//方法二：大括号语法：
// struct where{double x,double y,double z};
// where *one = new where{2.5,3.3,4.6};

//2.定位new运算符
//通常，new负责在堆中找到一个足以能够满足要求的内存块。
//new还有一种变体，被称为定位new运算符，可以指定要使用的位置。
#include<iostream>
#include<new>//使用定位new运算符必须包含这个头文件。
using namespace std;
const int BUF = 512;
const int N = 5;
char buffer[BUF];
int main() {
	double* pd1, * pd2;
	int i;
	cout << "Calling new and placement new:\n";
	pd1 = new double[N];//在堆里面找位置
	pd2 = new (buffer) double[N];//直接在buffer数组里找位置
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "Memory addresses:\n" << " heap:" << pd1
		<< " static:" << (void*)buffer << endl;//对char类型数组强制转换
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete[] pd1;//只能释放常规new分配的内存 不能释放定位new运算符创建的变量
}