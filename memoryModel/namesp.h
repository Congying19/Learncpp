#pragma once
#include<string>

//create the pers and debts namespaces
namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void getPerson(Person&);
	void showPerson(const Person&);
}

namespace debts
{
	using namespace pers;//使用pers里面全部名称
	struct Debt
	{
		Person name;
		double amount;
	};
	void getDebt(Debt&);
	void showDebt(const Debt&);
	double sumDebts(const Debt ar[], int n);
}
