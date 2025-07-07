//函数指针的作用：当一个函数想要调用其他函数时 不必一个一个写出来
#include<iostream>
using namespace std;
double betsy(int);
double pam(int);
double ppp(int);
//这两个函数类型一样 可以用同类型指针表示
void estimate(int lines, double (*pf)(int));
//声明函数指针时 必须声明指针指向的函数类型 而确定函数类型得知道：函数返回类型、函数参数列表（函数名不需要，每个人起的函数名不一样）
//double (*pf)(int)表示一个指向“返回类型为double,参数列表有一个Int”的函数的指针 和二维数组一样 括号不能少
//声明之后就可以把  (*pf)  当做函数名使用 或者把  pf  直接当做函数名使用
int main() {
	int code;
	cout << "How many lines of code do you need?";
	cin >> code;
	cout << "Here's Betsy's estimate:\n";
	estimate(code, betsy);//函数指针传入直接用函数名即可
	cout << "Here's Pam's estimate:\n";
	estimate(code, pam);

	//如果函数类型太长怎么办？使用auto自动判断类型
	auto p1 = betsy;
	cout << betsy(code) << endl;
	cout << p1(code) << endl;

	//函数指针数组声明：
	double (*pf[3])(int) = { betsy,pam,ppp };
	cout << pam(code) << endl;
	cout << pf[1](code) << endl;
	cout << (*pf[1])(code) << endl;
	return 0;
}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

double ppp(int lns) {
	return 0;
}

void estimate(int lines, double (*pf)(int)) {
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n";
}