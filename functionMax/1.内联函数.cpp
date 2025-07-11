//程序正常调用函数时：从main()开始编译 遇到函数调用时 就跳转到函数位置
//内联函数：将函数插入到main() 就不用跳转到别的地方节省时间
//内联函数代码不能太长 通常只有一两行
//内联函数不能递归
#include<iostream>
using namespace std;

inline double square(double x) { return x * x; }
//在函数定义前面加一个inline  即为内联函数
//内联函数通常省略函数原型 直接把定义放在前面
int main() {
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << "a = " << a << " ,b = " << b << "\n";
	cout << "c = " << c;
	cout << ",c squared = " << square(c++) << endl; //后置++ 先传入c=13 再c++
	cout << "Now c = " << c << endl;
	return 0;
}