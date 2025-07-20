#include<iostream>
#include"brass.h"
#include<string>
const int CLIENTS = 4;
//想要同时管理Brass 和Brass账户，创建对象数组行不通，但是可以创建基类指针数组。
//因为基类指针既可以指向基类对象，也可以指向派生类对象，这就是多态性
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass* p_clients[CLIENTS];
	std::string temp;//临时名称
	long tempnum;//临时账户
	double tempbal;//临时存款
	char kind;//账户类型

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "输入客户姓名：";
		getline(cin, temp);
		cout << "输入客户账号：";
		cin >> tempnum;
		cout << "输入当前存款：";
		cin >> tempbal;
		cout << "Brass类型输入1，BrassPlus类型输入2：";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "输入1或2：";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "输入透支上限：";
			cin >> tmax;
			cout << "输入利率：";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
		//编译器对虚方法使用动态联编：在运行阶段才知道执行哪个函数
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
		//不使用delete[] p_clients原因：部分元素是派生类对象
		//基类把析构函数声明为虚的原因：调用相应对象类型的析构函数，因此最好有虚析构函数
	}
	cout << "Done\n";
	return 0;
}