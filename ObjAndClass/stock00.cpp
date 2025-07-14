#include<iostream>
#include"stock00.h"
//写成员函数时需要用作用域运算符指出函数所属的类
void Stock::acquire(const std::string& co, long n, double pr)
{
	company = co;
	if (n < 0)//再给数据成员设置值之前要判断是否符合实际
	{
		std::cout << "Number of shares can't be negative;"
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();//私有函数 计算总价格
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative."
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;//计算购买之后的股票数量
		share_val = price;
		set_tot();//重新计算总价格
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0) {
		cout<<"Number of shares sold can't be negative."
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have!"
			<< "Transaction is aborted.\n";//“交易终止”
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{//股票价格变动就重新计算总价格
	share_val = price;
	set_tot();
}

void Stock::show()const
{
	std::cout << "Company: " << company
		<< " Shares:" << shares << '\n'
		<< " Share Price: $" << share_val
		<< " Total Worth: $" << total_val << '\n';
}

//构造函数定义：和acquire()函数一样 区别在于 声明对象时自动调用构造函数
Stock::Stock(const std::string& m_company, long m_shares , double m_share_val )//参数名字可以和数据成员相似 但不能一样。函数定义里面不能带有默认值，否则就重定义了
{
	company = m_company;
	if (m_shares < 0)//再给数据成员设置值之前要判断是否符合实际
	{
		std::cout << "Number of shares can't be negative;"
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = m_shares;
	share_val = m_share_val;
	set_tot();//私有函数 计算总价格
}

//默认构造函数定义：
Stock::Stock() {
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::~Stock()
{
	std::cout << "Bye, " << company << "!\n";
}

//交换函数定义：
const Stock& Stock::topval(const Stock& s)const
{
	if (s.total_val > total_val)//成员函数可以直接使用调用对象的数据成员total_val
		return s;
	else
		return *this;
	//this指针指向用来调用成员函数的对象（this被作为隐藏参数传递给函数）
	//所有类方法都将this指针设置为调用它的对象的地址。
	//返回*this即为返回调用对象本身
}