//函数模版：当函数算法相同 只是变量类型不同时 可以用函数模版简化编程 但是实际生成的可执行程序没有缩短
#include<iostream>
using namespace std;
//模版原型：
template<typename T>//不用加分号 也可以写成class <typename T>  
void Swap(T& a, T& b);//写完模版原型之后就可以把模版当成变量正常使用

//当函数算法不一样时 可以重载函数模版
template<typename T>//要开始使用模版啦
void Swap(T* a, T* b, int n);
void Show(int a[]);
const int Lim = 8;
int main() {
	int i = 10;
	int j = 20;
	cout << "i,j = " << i << "," << j << ".\n";
	cout << "After swap\n";
	Swap(i, j);//根据传入的参数是int 生成Swap(int &a, int &b)函数
	cout << "Now i,j = " << i << "," << j << ".\n";

	double x = 14.5;
	double y = 20.6;
	cout << "x,y = " << x << "," << y << ".\n";
	cout << "After swap\n";
	Swap(x, y);//根据传入的参数是int 生成Swap(int &a, int &b)函数
	cout << "Now x,y = " << x << "," << y << ".\n";

	int a1[Lim] = { 1,2,3,4,6,7,8,5 };
	int a2[Lim] = { 4,5,2,7,4,8,6,1 };
	Show(a1);
	Show(a2);
	cout << "After swap\n";
	Swap(a1, a2, Lim);
	Show(a1);
	Show(a2);
	return 0;
}

//函数模版定义：
template<typename T>//告诉编译器下面要开始使用模版了
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//交换数组
template<typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	for (int i = 0; i < Lim; i++)
	{
		cout << a[i];
	}
	cout << endl;
}