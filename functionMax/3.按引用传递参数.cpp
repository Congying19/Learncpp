#include<iostream>
using namespace std;
void swap1(int& a, int& b);
void swap2(int* a, int* b);
void swap3(int a, int b);
double cube(const double& a);//使用引用但是不修改变量 这看起来跟值传递类似 但是在处理数据大的变量时 不需要拷贝副本 因此很有用

int main() {
	int wallet1 = 200;
	int wallet2 = 300;
	cout << "按引用传递交换：\n";
	swap1(wallet1, wallet2);
	cout << "wallet1 = " << wallet1 << endl;
	cout << "wallet2 = " << wallet2 << endl;

	cout << "按地址传递交换：\n";
	swap2(&wallet1, &wallet2);
	cout << "wallet1 = " << wallet1 << endl;
	cout << "wallet2 = " << wallet2 << endl;
	
	cout << "按值传递交换：\n";
	cout << "wallet1 = " << wallet1 << endl;
	cout << "wallet2 = " << wallet2 << endl;

	double a = 3.0;
	cout << cube(a) << " = cube of " << a << endl;
	//对于const引用 即只传递信息 不改变值的时候 编译器会在两种情况下创建临时变量：
	//1.实参类型正确，但不是左值，是一些表达式等等
	//2.实参类型不正确，但是可以转换为正确类型
	//临时变量只在函数调用时存在 随后编译器可以随意删除
	long b = 5L;
	cout << cube(b) << " = cube of " << b << endl;
	cout << cube(4.2 + 1.8) << " = cube of " << 4.2 + 1.8 << endl;
	//尽可能使用const,因为：
	//1.使用const可以避免无意中修改数据的编程错误
	//2.使用const使函数能够处理const和非const实参，否则只能接收非const实参
	
	return 0;
}

void swap1(int& a, int& b)//这里形参在函数调用处初始化为实参
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap3(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

double cube(const double& a)
{
	return a * a * a;
}