#include<iostream>
#include"mytime.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;//超过60就除60
	minutes %= 60;//算完小时之后再取余
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

//使用函数完成类对象加减：
Time Time::Sum(const Time& t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;//不能返回局部变量的引用，函数执行完毕之后局部变量会消失
}

//使用重载加法运算符的版本：
Time Time::operator+(const Time& t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;//不能返回局部变量的引用，函数执行完毕之后局部变量会消失
}

//使用减法重载运算符：
Time Time::operator-(const Time& t)const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

//使用重载乘法运算符：
Time Time::operator*(double mult)const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes  * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

//利用友元非成员函数重载乘法：反转操作数的顺序。友元函数定义不需要加friend
//Time operator*(double m, const Time& t)
//{
//	Time result;
//	long totalminutes = t.hours * m * 60 + t.minutes * m;
//	result.hours = totalminutes / 60;
//	result.minutes = totalminutes % 60;
//	return result;
//
//}

//使用函数完成类对象输出：
void Time::Show()const
{
	std::cout << hours << " hours, " << minutes << " minutes";
}
//使用<<重载运算符：
std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os<< t.hours << " hours, " << t.minutes << " minutes";//这条语句运行完返回ostream类对象os
	return os;//返回引用才能保证是同一个os
}