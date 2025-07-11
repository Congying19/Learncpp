//默认参数指的是：当函数调用中省略了实参时自动使用的一个值
//1.默认参数需要在函数原型中设置 函数定义不用
//2.对于带参数列表的函数，必须从右向左添加默认值，如果一个参数设置了默认值，它右边的所有参数都要设置默认值
#include<iostream>
using namespace std;
const int Asize = 80;
char* left(const char* str, int n = 1);
//1.想返回字符串就用char*
//2.不想修改字符串就用const char* str
//3.设置n默认值是1
int main() {
	char sample[Asize];
	cout << "请输入一串字符：\n";
	cin.get(sample, Asize);//如果直接用cin>>sample 就得手动输入空字符
	char* ps = left(sample, 4);//获取左边四个字符
	cout << ps << endl;
	delete[] ps;
	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
	return 0;
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