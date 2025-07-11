//当变量类型不好确定时可以使用decltype关键字 例如xyp=T1+T2;T1,T2都是待定，则xyp不好确定
//decltype语法：decltype(expression) var;
//第一步，expression是没有括号的标识符，则var与标识符类型相同
//第二步，expression是函数调用，则var与expression返回类型相同，注意只是查看函数原型 并没有真正调用函数
//第三步，expression本身有括号，var为指向expression类型的引用
//第四步，前三个都不是，则var与expression类型相同
#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T1,typename T2>
void test1(T1 x, T2 y);

template<typename T1, typename T2>
auto test2(T1 x, T2 y) -> decltype(x + y);

int main() {
	int t1 = 10;
	double t2 = 10.2;
	//第一步
	decltype(t1) t11;
	cout << "Type of t11 is " << typeid(t11).name() << endl;

	//第三步
	decltype((t2)) t22=t2;
	cout << "Type of t22 is " << typeid(t22).name() << endl;

	//第四步
	decltype(10 + 20.2) t33;
	cout << "Type of t33 is " << typeid(t33).name() << endl;

	test1(t1, t2);
	cout << "test2 = " << test2(t1, t2) << endl;
	cout << "Type of test2 is " << typeid(test2(t1, t2)).name() << endl;
	return 0;
}

template<typename T1,typename T2>
void test1(T1 x, T2 y)
{
	typedef decltype(x + y) xytype;//给x+y这个变量类型起一个别名 xytype
	xytype xpy = x + y;//用这个别名定义一个变量
	cout << "Type of xpy is " << typeid(xpy).name() << endl;
}

//如果想返回x+y怎么办？
template<typename T1, typename T2>
auto test2(T1 x,T2 y) ->decltype(x+y)//后置返回类型
{
	return x + y;
}

