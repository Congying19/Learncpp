#include<iostream>
#include"string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()//静态成员函数
{
	return num_strings;//静态成员函数属于整个类，不能用对象调用它，静态成员函数甚至不能使用this指针。如果静态成员函数声明在公有部分，可以使用类名调用
	//静态成员函数只能使用静态数据成员
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);//new创建 再复制 刚刚好
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];//一个元素也当数组 为了与后面适配
	str[0] = '\0';//设置成空字符串
	num_strings++;
	
}

String::String(const String& st)
{
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);//new创建 再复制 刚刚好
	num_strings++;
}

String::~String() {
	--num_strings;
	delete[] str;
}


String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;//防止自己给自己赋值
	delete[] str;//要把之前的动态内存给释放掉，不然就浪费了
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}//利用字符串赋值

char& String::operator[](int i)//下标运算符重载
{
	return str[i];
}
const char& String::operator[](int i)const
{//仅供const String变量使用
	return str[i];
}

//比较运算符重
bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st, const String& st2)
{
	return st2 < st;//反转操作数
}

bool operator==(const String& st, const String& st2)
{
	return (std::strcmp(st.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, const String& st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)//文件尾或者空行为false
		st == temp;
	while (is && is.get() != '\n')//丢弃多余的字符
		continue;
	return is;
}

