#pragma once
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include<iostream>
#include<cstdlib>

template<class T,int n>
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP(){}
	explicit ArrayTP(const T& v);//关闭自动复制
	virtual T& operator[](int i);
	virtual T operator[](int i)const;
};

template<class T,int n>
ArrayTP<T, n>::ArrayTP(const T& v)
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}
template<class T,int n>
T& ArrayTP<T,n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "出错：" << i << " 超出范围\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];//返回引用可以连续处理arr[][]就像cout<< <<
}

template<class T,int n>
T ArrayTP<T, n>::operator[](int i)const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "出错：" << i << " 超出范围\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}
#endif // !ARRAY_H_

