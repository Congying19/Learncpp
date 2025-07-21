#include"workermi.h"
#include<iostream>
#include<string>//包括getline()原型
using std::cout;
using std::cin;
using std::endl;

//Worker类方法：
Worker::~Worker(){}

//保护方法：
void Worker::Data()const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "输入员工ID: ";
	cin >> id;
	//清空多余输入
	while (cin.get() != '\n')
		continue;
}

//Waiter方法：
void Waiter::Set()
{
	cout << "输入服务员的名字：";
	Worker::Get();//处理虚基类继承的数据成员
	Get();//处理新增数据成员
}

void Waiter::Show()const
{
	cout << "类型：服务员\n";
	Worker::Data();
	Data();
}

void Waiter::Data()const
{
	cout << "华丽级别：" << panache << endl;
}

void Waiter::Get()
{
	cout << "输入服务员华丽级别：";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

//Singer方法：
std::string Singer::pv[Singer::Vtypes] = { "other","alto","contralto",
"soprano","bass","baritone","tenor" };

void Singer::Set()
{
	cout << "输入歌手姓名：";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "类别：歌手\n";
	Worker::Data();
	Data();
}

void Singer::Data()const
{
	cout << "声音范围：" << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "输入歌手声音范围：\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout << "输入歌手服务员的名字：";
	Worker::Get();
	Get();
}

void SingingWaiter::Show()const
{
	cout << "类型：歌手服务员\n";
	Worker::Data();
	Data();
}