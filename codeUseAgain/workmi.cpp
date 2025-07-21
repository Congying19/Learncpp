#include<iostream>
#include<cstring>
#include"workermi.h"
const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	//抽象基类可以创建指针不能创建对象
	Worker* lolas[SIZE];
	
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "输入雇员的类别：\n"
			<< "w:服务员   s:歌手   "
			<< "t:唱歌的服务员   q:退出\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
			//返回choice在字符串"wstq"第一次出现的地址，如果没有说明输入有误
		{
			cout << "请输入w,s,t或者q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
			lolas[ct] = new Waiter;
			break;
		case 's':
			lolas[ct] = new Singer;
			break;
		case 't':
			lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
	return 0;
}