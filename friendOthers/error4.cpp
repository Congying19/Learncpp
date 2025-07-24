#include<iostream>
#include<cmath>
#include"exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "输入两个数字：";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << x << " 和 " << y
				<< " 的调和平均数是 " << z << endl;
			cout << x << " 和 " << y << " 的几何平均数是" << gmean(x, y) << endl;
			cout << "输入下一轮数字（q to quit）: ";
		}
		catch (bad_hmean& bg)
		{
			bg.mesg();
			cout << "再试一次\n";
			continue;
		}
		catch (bad_gmean& hg)
		{
			cout << hg.mesg();
			cout << "使用了 " << hg.v1 << " 和 " << hg.v2 << endl;
			cout << "你不能再尝试了\n";
			break;
		}
	}
	cout << "Bye\n";
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
	if (a<0||b<0)
		throw bad_gmean(a, b);
	return std::sqrt(a*b);
}