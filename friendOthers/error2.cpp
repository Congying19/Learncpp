//abort()是直接终止程序，而不是返回到main()
//为了避免异常终止，程序应在调用hmean()函数之前检查x和y的值
//然而，依靠程序员来执行这种检查是不安全的。
// 更灵活的方式是使用函数的返回值来指出问题

#include<iostream>
#include<cstdlib>
/*
	函数：hmean()
	功能：通过指针或者引用参数将值返回给调用程序，而返回值用来指出成功还是失败
*/
bool hmean(double a, double b, double* ans);

int main()
{
	double x, y, z;

	std::cout << "输入两个数字：";
	while (std::cin >> x >> y)
	{
		if (hmean(x, y, &z))
			std::cout << x << " 和 " << y
			<< " 的调和平均数是 " << z << std::endl;
		else
			std::cout << "一个数不能是另一个数的负数，再试一次：\n";
		std::cout << "输入下一轮数字（q to quit）: ";
	}
	std::cout << "Bye\n";
	return 0;
}

bool hmean(double a, double b, double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}