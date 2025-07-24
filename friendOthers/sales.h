#pragma once
/*
	Sales类 用于存储一个年份和一个包含12个月的销售数据的数组
	LabeledSales类 新增用于存储数据标签的成员
*/
#include<stdexcept>
#include<string>

class Sales
{
public:
	enum{MONTHS=12};//相当于一个常量
	class bad_index :public std::logic_error
		//从logic_error类派生出来可以存储和报告数组索引的超界值out-of-bounds value 
	{
	private:
		int bi;//bad index value 错误的索引值
	public:
		explicit bad_index(int ix,
			const std::string& s = "Index error in Sales object\n");
		//explicit强制显式转换，禁止隐式转换
		int bi_val()const { return bi; }
		virtual ~bad_index() {}
		//后面加throw()使用了异常规范，C++98中的exception的虚构造函数使用了异常规范，C++11没有
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales(){}
	int Year()const { return year; };
	virtual double operator[](int i)const;
	virtual double& operator[](int i);
private:
	double gross[MONTHS];//总收入
	int year;
};

class LabeledSales :public Sales
{
public:
	class nbad_index :public Sales::bad_index
	{
	private:
		std::string lbl;
	public:
		nbad_index(const std::string& lb, int ix,
			const std::string& s = "Index error in LabeledSales object\n");
		const std::string& label_val()const { return lbl; }
		virtual ~nbad_index(){}
	};
	explicit LabeledSales(const std::string& lb = "none", int yy = 0);
	LabeledSales(const std::string& lb, int yy, const double* gr, int n);
	virtual ~LabeledSales(){}
	const std::string& Label()const { return label; };
	virtual double operator[](int i)const;
	virtual double& operator[](int i);
private:
	std::string label;
};