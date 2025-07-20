#include<iostream>
#include"brass.h"
using std::cout;
using std::endl;
using std::string;

//formatting stuff 格式化内容：
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass methods 
Brass::Brass(const string& s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "存款不能是负数，存款行为取消\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "取款不能为负数，取款行为取消\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "取款数目 " << amt << " 超过你的存款，取款行为取消\n";
	restore(initialState, prec);
}

double Brass::Balance()const
{
	return balance;
}

void Brass::ViewAcct()const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "客户：" << fullName << endl;
	cout << "账号：" << acctNum << endl;
	cout << "结余：$" << balance << endl;
	restore(initialState, prec);//restore original format恢复原来的格式
}

//BrassPlus Methods
BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r)
	:Brass(s, an, bal)//派生类构造函数在初始化基类私有数据时，采用的是成员初始化列表法
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

//redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();//直接调用展示基类数据，注意这里是用类名调用，表明是基类的函数而不是自己
	cout << "最大贷款：$" << maxLoan << endl;
	cout << "欠银行：$" << owesBank << endl;
	cout.precision(3);//###.### format
	cout << "利息：" << 100 * rate << "%\n";
	restore(initialState, prec);
}

//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)//取款小于存款，正常取即可
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)//取款小于额度，大于存款，需要付利息
	{
		double advance = amt - bal;//超出部分
		owesBank += advance * (1.0 + rate);
		cout << "银行垫款：$" << advance << endl;
		cout << "财务费用（利息）：$" << advance * rate << endl;
		Deposit(advance);//银行垫款相当于帮客户存进去
		Brass::Withdraw(amt);//存完之后就可以正常取款了
	}
	else
		cout << "超出额度，交易取消\n";
	restore(initialState, prec);
}

format setFormat()
{
	//set up ###.## format
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}//设置定点表示法 并返回以前的标记位置

void restore(format f, precis p)//重置格式和精度
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}