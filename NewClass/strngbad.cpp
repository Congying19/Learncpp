#include<cstring>
#include"strngbad.h"
using std::cout;

int StringBad::num_strings = 0;//初始化静态成员变量,需要指出类型，不需要static。不能在类声明中初始化。

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1,s);//new创建 再复制 刚刚好
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\"object created\n";//展示对象创建信息
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str,4, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\"object created\n";
}

StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	cout << num_strings << ": \"" << str
		<< "\" object created\n";
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\"object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;//防止自己给自己赋值
	delete[] str;//要把之前的动态内存给释放掉，不然就浪费了
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}