#include<iostream>
#include"tabtenn0.h"
void Show(const TableTennisPlayer& rt);

int main(void)
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table .\n";
	else
		cout << ": hasn't a table .\n";

	RatedPlayer rplayer1(1212, player1);
	cout << "Name: ";
	//1.派生类对象可以使用基类的非私有方法：
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;

	//2.基类指针（引用）可以在不进行显式类型转换的情况下指向（引用）派生类对象
	// 但是基类指针和引用只能用于调用基类方法，不能调用派生类新增的方法，相当于指向（引用）嵌套其中的基类对象
	//反过来，基类对象和地址不能赋给派生类对象
	TableTennisPlayer& rt = rplayer1;
	rt.Name();
	TableTennisPlayer* pt = &rplayer1;
	pt->Name();
	
	return 0;
}

//基类指针应用：对于基类引用定义的函数或指针参数可用于基类对象或派生类对象
void Show(const TableTennisPlayer& rt)
{
	using std::cout;
	cout << "Name: ";
	rt.Name();
	cout << "\nTable: ";
	if (rt.HasTable())
		cout << "yes\n";
	else
		cout << "no\n";
}