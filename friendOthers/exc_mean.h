#pragma once
#include<iostream>

/*
	通常引发异常的函数将传递一个对象。
	重要优点：可以使用不同的异常类型来区分不同的函数在不同的情况下引发的异常
	另外，对象可以携带信息，程序员可以根据这些信息来确定引发异常的原因。
	同时,catch块可以根据这些信息来决定采取什么样的措施
*/
class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(int a=0,int b=0):v1(a),v2(b){}
	void mesg();
};
//传递信息：
inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): " << "invalid arguments: a = -b\n";
}

//另一个异常处理程序：计算乘积的平方根，要求不能为负
class bad_gmean 
{
public:
	double v1;
	double v2;
	bad_gmean(double a =0,double b=0):v1(a),v2(b){}
	const char* mesg();
};

inline const char* bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0 \n";
}