#pragma once
//运算符重载示例
#ifndef MYTIME_H_
#define MYTIME_H_
#include<iostream>
class Time
{
	//成员函数重载运算符解决 Time * m
	//非成员函数作为友元解决 m * Time:
	friend Time operator*(double m, const Time& t)
	{
		return t * m;//反转操作数
	}
	//这个函数虽然在类声明中，但不是成员函数，不能用成员运算符访问，但是它与成员函数访问权限相同
	
	//重载<<运算符：返回ostream类引用 即cout，实现cout<<a<<b<<endl;连续输出
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);  //调整时间
	void AddHr(int h);//调整时间
	void Reset(int h = 0, int m = 0);//重新设置时间
	Time Sum(const Time& t)const;//两个时间相加
	//使用重载加法运算符：
	Time operator+(const Time& t)const;//只需要将Sum()替换成operator+()之后就可以直接使用+
	//使用重载减法运算符：
	Time operator-(const Time& t)const;
	//使用重载乘法运算符：
	Time operator*(double n)const;
	void Show() const;//显示时间
};
#endif // !MYTIME_H_

