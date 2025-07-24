//依靠返回值检查确实可以避免程序错误输入，但这项工作不是程序员经常做的。
// 可以使用异常机制来处理错误：
/*
	异常定义：异常是对程序运行过程中发生的异常情况的一种响应。异常提供了
	将控制权从程序的一个部分传递到另一个部分的途径。

	异常的处理有3个组成部分：
	1.引发异常
	throw语句实际上是跳转，即命令程序跳到另一条语句。
	throw关键字表示引发异常，紧随其后的值指出了异常的特征。

	2.使用处理程序捕获异常
	程序使用异常处理程序来捕获异常，异常处理程序位于要处理问题的程序中。
	catch关键字表示捕获异常。

	3.使用try块

*/
#include<iostream>
double hmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "输入两个数字：";
	while (std::cin >> x >> y)
	{
		/*
			try块标识其中特定的异常可能被激活的代码块，它后面跟一个或多个catch块。
			try块是由关键字try指示的，关键字try的后面是一个由花括号括起的代码块，
			表明需要注意这些代码引发的异常。
		*/
		try {
			z = hmean(x, y);
		}//给可能出错的异常 括起来
		/*
			处理程序以关键字catch开头，随后是位于括号中的类型声明，它指出了异常处理
			程序要响应的异常类型；然后是一个用花括号括起的代码块，指出要采取的措施。
			catch关键字和异常类型用作标签，指出当异常被引发时，程序应跳到这个位置执行
			异常处理程序也被称为catch块
		*/
		catch (const char* s)
		//由于hmean()中引发异常的是if(a==-b)中的字符串"bad..."所以这里异常类型是字符串类型
		{
			std::cout << s << std::endl;
			std::cout << "重新输入一对数字：";
			continue;
		}
		std::cout << x << " 和 " << y
			<< " 的调和平均数是 " << z << std::endl;
		std::cout << "输入下一轮数字（q to quit）: ";
	}
	std::cout << "Bye\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw "bad hmean() arguments : a = -b not allowed";
	/*
		执行throw语句类似于执行返回语句，因为它也将终止函数的执行
		但throw不是将控制权返回给调用程序而是导致程序沿着函数调用序列后退
		直到找到包含try块的函数。这个程序中throw将控制权返回给main()，
		程序将在main()中寻找与引发的异常类型匹配的异常处理程序（位于try后面）
		如果函数引发了异常，但是没有try块或没有匹配的处理程序时，将会在默认情况下，
		调用abort()函数
	*/
	return 2.0 * a * b / (a + b);
}