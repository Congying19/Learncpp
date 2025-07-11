//函数重载：可以有多个同名函数 完成相同的工作 但是使用不同的参数列表
//函数重载的关键是函数的参数列表——函数特征标  （函数特征标不用看函数名）
//函数重载的条件是特征标不同 即参数类型和数目不同 类型
// 引用和类型本身视为同一个特征标
//返回类型不一样 特征标一样的函数不能重载 编译器区分不了
//返回类型不一样 特征标也不一样的函数可以重载 编译器能区分

//函数重载场景：函数功能一样 参数不一样时

//例如找出一串数字左边部分
#include<iostream>
using namespace std;
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);
int main() {
	const char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}
	return 0;
}

unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)//临时变量n 用来消耗
		digits++;//计算位数
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}

char* left(const char* str, int n)//不需要设置默认值
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];//使用new创建动态数组 个数记得加上空字符
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';//把剩余部分设置为0
	return p;
}