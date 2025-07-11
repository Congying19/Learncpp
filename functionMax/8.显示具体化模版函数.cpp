//1.对于给定的函数名，可以有 非模版函数、模版函数、显示具体化模版函数以及三者的重载版本
//2.显示具体化的原型和定义以template<>打头，并通过名称来指出类型
//3.具体化优先于常规模版  非模版函数优先于具体化和常规函数
#include<iostream>
using namespace std;
//常规模版
template<typename T>
void Swap(T& a, T& b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

//具体化模版
template<> void Swap<job>(job& j1, job& j2);//具体化模版原型
void Show(job& j);

int main() {
	cout.precision(2);//设定输出小数点后2位
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j = " << i << ", " << j << ".\n";
	cout << "使用常规模版\n";
	Swap(i, j);//根据提供的int参数生成int的模版实例 称为隐式实例化
	Swap<int>(i,j);// 显式实例化 。
	//显式实例化 隐式实例化 显式具体化都称为具体化
	cout << "Now i,j = " << i << ", " << j << ".\n";

	job sue = { "Susan",73000.60,7 };
	job sidney = { "Sidney",78060.72,9 };
	cout << "交换前：\n";
	Show(sue);
	Show(sidney);
	cout << "交换后：\n";
	Swap(sue, sidney);
	Show(sue);
	Show(sidney);
	return 0;
}

template<typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<> void Swap<job>(job& j1, job& j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job& j)
{
	cout << j.name << ":  $" << j.salary
		<< " on floor " << j.floor << endl;
}