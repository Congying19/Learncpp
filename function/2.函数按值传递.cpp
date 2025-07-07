#include<iostream>
using namespace std;
long double probability(unsigned numbers, unsigned picks); //unsigned int 简称unsigned
//计算从numbers中抽picks个 抽中奖的概率
int main() {
	double total, choice;
	cout << "输入卡片总数和你要抽取的数量：\n";
	while (cin >> total >> choice && choice <= total) {//把cin>>放入测试条件即可输入 又可以判断是否符合
		cout << "你中奖的概率是：\n";
		cout << 1/probability(total, choice)<<endl;
		cout << "再次输入两个数字（输入q可以退出）：\n";
	}
	return 0;
}

long double probability(unsigned numbers, unsigned picks)//用于接收传递值的变量称为形参 形参改变时 实参不会改变
{
	long double result = 1.0;//函数里面声明的局部变量 只在函数里面起作用 和别的地方变量没有关系 即使名字一样
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; p--, n--) {
		result = result * n / p;//采用乘一个除一个方法 避免先乘后除时中间数过大超出范围
	}
	return result;//返回值类型 必须和函数头一致
}
