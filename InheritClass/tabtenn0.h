#pragma once
//从一个类派生出另一个类时，原始类称为基类，继承类称为派生类。
//派生类的作用就是添加基类没有的数据或者功能
#ifndef TABTENN0_H_
#define TABTENN0_H_
#include<string>
//俱乐部为了跟踪乒乓球会员，先设计一个简单的乒乓球球员类
using std::string;
//simple base class
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable; //是否有球桌
public:
	TableTennisPlayer(const string& fn = "none", const string& ln = "none", bool ht = false);//基类构造函数以及默认值
	void Name()const;
	bool HasTable() const { return hasTable; }//接口
	void ResetTable(bool v) { hasTable = v; }//重新设置会员
};


//如果俱乐部有人去参加竞标赛，希望设计一个类记录成员比赛得分，重新设计很麻烦，可以直接继承基类
//
class RatedPlayer :public TableTennisPlayer
//1.上述声明表示TableTennisPlayer是一个公有基类，这种派生称为公有派生。
//2.派生类对象包含基类对象
//3.使用公有派生，基类的公有成员将成为派生类的公有成员；
//4.基类的私有部分也称为派生类的一部分，但是只能通过 基类的公有 和保护方法访问
{
	//上述代码完成以下工作：
	//1.派生类对象存储了基类的数据成员
	//2.派生类对象可以使用基类的方法

	//派生类还要有自己的部分：
private:
	unsigned int rating;//添加一个数据成员——得分
public:
	//构造函数必须给新成员（如果有的话）和继承的成员提供数据：
	RatedPlayer(unsigned int r = 0, const string& fn = "none", const string& ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
	//第二种构造函数使用了TableTennisPlayer参数，已经包括基类所有继承的数据
	unsigned int Rating() const { return rating; }//添加两个简单实现
	void ResetRating(unsigned int r) { rating = r; }
};



#endif