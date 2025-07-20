#include<iostream>
#include"brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);//默认参数：最大贷款500，利率0.11125
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "往Hogg账户里面存1000：\n";
	Hoggy.Deposit(1000.00);
	cout << "Hogg当前存款：" << Hoggy.Balance() << endl;
	cout << "从Pigg账户里面取4200：\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg当前存款：" << Piggy.Balance() << endl;
	cout << "从Hogg账户里面取4200：\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();

	return 0;
}