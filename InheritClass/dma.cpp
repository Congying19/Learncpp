#include<cstring>
#include"dma.h"

baseDMA::baseDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	strcpy_s(label, std::strlen(l) + 1, l);
	rating = r;
}
//深拷贝构造函数
baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

//lacksDMA 方法：
lacksDMA::lacksDMA(const char* c, const char* l, int r) :baseDMA(l, r)
{
	strcpy_s(color, 39, c);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs):baseDMA(rs)
{
	strcpy_s(color,COL_LEN - 1, c);
	color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;//想利用基类中的重载运算符输出基类部分，需要将派生类引用强制转换为基类引用
	//派生类中的友元可以访问Color，但是想输出基类部分，就是使用基类的友元函数
	os << "Color: " << ls.color << std::endl;
	return os;
}

//hasDMA 方法：
hasDMA::hasDMA(const char* s, const char* l, int r) :baseDMA(l,r)
{
	style = new char[std::strlen(s) + 1];
	strcpy_s(style, std::strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs):baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	strcpy_s(style, std::strlen(s) + 1, s);
}

//hasDMA使用了new必须从新定义深拷贝：
hasDMA::hasDMA(const hasDMA& hs):baseDMA(hs)//派生类引用可以直接传给基类深拷贝
{
	style = new char[std::strlen(hs.style) + 1];
	strcpy_s(style, std::strlen(hs.style) + 1, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;//只需要析构自己的就行了
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);//使用作用域解析运算符以及函数调用方法进行基类赋值
	delete[] style;
	style = new char[std::strlen(hs.style) + 1];
	strcpy_s(style, std::strlen(hs.style) + 1, hs.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}