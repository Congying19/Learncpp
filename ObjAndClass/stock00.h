#pragma once
#ifndef STOCK00_H_
#define STOCK00_H_

#include<string>
//将一个公司的股票当成一个类
class Stock//类声明，这个声明让我们可以声明Stock类型的变量——称为对象或者实例
{
private://私有权限 只能通过公有成员函数来访问对象的私有成员。不写private也可以，因为类默认为private
	//结构体默认访问限制是public 这是和类唯一的区别
	//防止程序直接访问数据被称为数据隐藏。数据隐藏不仅防止直接访问数据，还让开发者无需了解数据是如何被表示的。
	std::string company;
	//类的数据项一般都放在私有部分，通过公有接口访问
	long shares;//公司持有股票数量
	double share_val;//每股的价格
	double total_val;//股票总价格

	//私有成员函数通常处理不属于公有接口的实现
	void set_tot() {
		total_val = shares * share_val;
	}//定义在类声明中的函数自动称为内联函数

public://公有权限 使用类对象的程序都可以直接访问公有部分
	//公有成员函数是程序和对象的私有成员之间的接口。
	void acquire(const std::string& co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;//在show()后面加上const 保证函数不会修改调用对象

	//使用构造函数能够让类对象进行初始化，就像标准变量类型一样
	Stock(const std::string& m_company, long m_shares = 0, double m_share_val = 0.0);//后面两个参数有默认值
	//1.构造函数名字与类名一致 2.构造函数没有返回类型，也不是void 3.构造函数放在公有部分

	//默认构造函数：1.给构造函数所有参数提供默认值 2.重载定义另一个构造函数——一个没有参数的构造函数：
	Stock();
	//如果类没有构造函数 编译器会提供一个默认构造函数 这个默认构造函数不做任何工作
	//如果类有构造函数 编译器就不会提供默认构造函数 必须自己添加

	//析构函数：在类对象过期时，程序自动调用，用于完成清理工作，尤其是delete
	~Stock();//1.名称和类名一样，前面有~ 2.没有参数

	//比较函数：比较两个股票的大小，并返回大的股票
	const Stock& topval(const Stock& s)const;//引用传递类对象节省空间 返回引用也方便 加上const修饰 不改变类对象
};

#endif

