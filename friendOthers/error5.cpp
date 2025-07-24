/*
	如果try块没有直接调用引发异常的函数，而是try块调用的函数里面调用的函数引发异常
	程序将从引发异常的函数跳到包含try块和处理程序的函数。
	函数由于出现异常而终止，则程序将释放栈中的内存，直到找到一个位于try块中的返回地址
	控制权将转到块尾的异常处理程序，而不是函数调用后面的第一条语句，这个过程称为栈解退。

	throw与函数返回不同的地方：
	1.函数返回到调用它的地方
	而throw返回到第一个这样的函数：包含能够捕获相应异常的try-catch组合
	2.函数返回值与返回类型有关
	而引发异常时编译器总是创建一个临时拷贝，throw返回这个拷贝，即使catch块中
	指定异常类型是引用。因为执行完函数，对象将不复存在，只能返回拷贝
	为什么返回副本还要用引用？：基类引用可以执行派生类对象。
	如果有处理派生类对象的异常处理，记得catch块的排列顺序与派生顺序相反，
	不然就被上一层基类引用捕捉

	如果不知道异常是什么，可以用省略号表示异常类型，从而捕获任何异常
	catch(...){}
	最好将捕获所有异常的catch放在最后，当最后方案
*/

#include<iostream>
#include<cmath>
#include<string>
#include"exc_mean.h"

class demo
{
private:
	std::string word;
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo: " << word << " created\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " destoryed\n";
	}
	void show()const
	{
		std::cout << "demo " << word << " lives\n";
	}
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "输入两个数字：";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y
					<< " is " << z << endl;
				cout << "Enter next pair: ";
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "Try again \n";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "Value used: " << hg.v1 << ", "
					<< hg.v2 << endl;
				cout << "Sorry,you don't get to play any more\n";
				break;
			}
		}
		d1.show();
	}
	cout << "Bye\n";
	cin.get();
	cin.get();
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean& bg)
	{
		bg.mesg();
		std::cout << "Caught in means()\n";
		throw;
		/*
		throw导致mean()终止执行，并将异常传递给main()函数。
		d2.show()没有执行表示means()函数提前终止，但还是调用了析构函数
		重要：程序进行栈解退以回到能够捕获异常的地方时，
		将释放栈中的自动存储型变量，如果变量是类对象，将为该对象调用析构函数
		*/
	}
	d2.show();
	return(am + hm + gm) / 3.0;
}