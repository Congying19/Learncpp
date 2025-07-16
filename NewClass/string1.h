#pragma once
#pragma once
#include<iostream>
#ifndef STRNG1_H_
#define STRNG1_H_
using std::ostream;
using std::istream;
class String
{
private:
	char* str;//后面用new分配空间
	int len;
	static int num_strings;//所有类成员共用一个静态成员，可以记录所创建对象的数目，在这个程序中可以帮我们指出潜在的变成问题
	static const int CINLIM = 80;//静态const可以在类声明里面定义 cin input limit
public:
	String(const char* s);
	String();
	String(const String& st);
	~String();
	int length()const
	{
		return len;
	}

	String& operator=(const String& st);
	String& operator=(const char*);//利用字符串赋值
	char& operator[](int i);//下标运算符重载
	const char& operator[](int i)const;

	//比较运算符重载
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, const String& st);

	static int HowMany();//静态成员函数
};
#endif
