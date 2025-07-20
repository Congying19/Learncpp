#include"tabtenn0.h"
#include<iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn,const string & ln,bool ht):
	firstname(fn),lastname(ln),hasTable(ht){ }//初始化列表

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}


//派生类构造函数实现：派生类不能直接访问基类的私有成员，必须通过基类的方法实现。
//具体的说，派生类构造函数必须使用基类构造函数
RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
	:TableTennisPlayer(fn, ln, ht)//使用基类构造函数初始化:将接收到的fn,ln,ht作为实参传入TableTennisPlayer构造函数
	//TableTennisPlayer构造函数创建一个嵌套在RatedPlayer对象中的TableTennisPlayer对象，然后再进入RatedPlayer构造函数体，对新成员进行赋值
	//也就是说，继承类对象中包含一个基类对象
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
	:TableTennisPlayer(tp),rating(r)
{ }//由于tp类型为TableTennisPlayer& ，因此将调用基类的复制构造函数。这里是编译器自动提供的

//释放对象的顺序与创建对象的顺序相反，即先执行派生类的析构函数，再执行基类的析构函数