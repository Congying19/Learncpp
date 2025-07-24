//调用abort()：位于头文件cstdlib，向标准错误流发送消息，然后终止程序

#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;

void myQuit()
{
	//打印消息：
	cout << "Terminating due to uncaught exception\n";
	//设置退出值：
	exit(5);
}

//求两个数的调和平均数：
double hmean(double a, double b);

int main()
{
	set_terminate(myQuit);
	double x, y, z;

	std::cout << "输入两个数字：";
	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << x << " 和 " << y << " 的调和平均数是 " << z << std::endl;
		std::cout << "输入下一轮数字（q to quit）: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "参数不适合函数hmean()\n";
		//std::abort();//abort v使..中止
		throw;
	}
	return 2.0 * a * b / (a + b);
}