//在名称空间中声明的函数名作用域为整个名称空间，因此定义和声明必须位于同一个名称空间中。利用名称空间的开放性。
#include<iostream>
#include"namesp.h"//通过包含头文件导入原来的名称空间

namespace pers
{
	using std::cout;
	using std::cin;//using 声明
	void getPerson(Person& rp)
	{
		cout << "Enter first name: ";
		cin >> rp.fname;
		cout << "Enter last name: ";
		cin >> rp.lname;
	}
	void showPerson(const Person& rp)
	{
		std::cout << rp.lname << ", " << rp.fname;
	}
}

namespace debts
{
	void getDebt(Debt& rd)
	{
		getPerson(rd.name);
		std::cout << "Enter debt: ";
		std::cin >> rd.amount;
	}
	void showDebt(const Debt& rd)
	{
		showPerson(rd.name);
		std::cout << ": $" << rd.amount << std::endl;
	}
	double sumDebts(const Debt ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i++)
			total += ar[i].amount;
		return total;
	}
}