#pragma once
#ifndef BRASS_H_
#define	BRASS_H_
#include<string>
//Brass Account Class基本支票账户
class Brass
{
private:
	std::string fullName;//客户姓名
	long acctNum;//账号数字
	double balance;//当前结余
public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);//存款
	virtual void Withdraw(double amt);//取款
	//函数声明之前加上virtual，称为虚方法
	double Balance() const;
	virtual void ViewAcct() const;//查看账户信息
	virtual ~Brass(){}
};

//Brass Plus Account Class
class BrassPlus : public Brass
{
private:
	double maxLoan;//最大透支上限,超过存款仍然想取
	double rate;//贷款收取利息
	double owesBank;//所欠银行金额
public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0,
		double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct()const;
	//对于虚方法，继承类中要重新声明，继承类中virtual可以省略，最好写出来
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif // !BRASS_H_

//如果方法是通过引用或者指针而不是对象调用的，它将确定使用哪一种方法。
//如果使用了virtual，程序将根据引用或者指针指向的对象的类型来选择方法。
//方法的行为应取决于调用该方法的对象，这种复杂的行为称为多态。