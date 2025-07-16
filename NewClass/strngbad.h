#pragma once
#include<iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
private:
	char* str;//后面用new分配空间
	int len;
	static int num_strings;//所有类成员共用一个静态成员，可以记录所创建对象的数目，在这个程序中可以帮我们指出潜在的变成问题
public:
	StringBad(const char* s);
	StringBad();
	StringBad(const StringBad& st);
	~StringBad();
	StringBad& operator=(const StringBad& st);
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};
#endif
