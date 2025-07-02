#include<iostream>			//头文件 包含cin cout
#include<climits>			//头文件 包含整型限制信息
using namespace std;

int main() {
	int n_int = INT_MAX;	//命名规则：英文数字下划线、数字不能开头、下划线尽量不要开头、使用有意义的名字
	short n_short = SHRT_MAX; //创建完一个变量就要用“=”进行赋值
	long n_long = LONG_MAX;	// INT_MAX这些表示对应整型的最大值，包含在climits 头文件中
	long long n_llong = LLONG_MAX;	//一共分为四个整型

	cout << "int is " << sizeof(int) << " bytes." << endl;	//sizeof是内置运算符 ，返回变量或者类型的长度 ，单位是字节byte。
	//sizeof返回类型的语法 需要括号
	cout << "short is " << sizeof n_short << " bytes." << endl;	//sizeof 返回变量的语法 不需要括号
	cout << "long is " << sizeof n_long << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl;//字节依赖于实现，不同系统中整型字节可能不同

	cout << "Maximum value:" << endl;
	cout << "int:" << n_int << endl;
	cout << "short:" << n_short << endl;
	cout << "long:" << n_long << endl;
	cout << "long long:" << n_llong << endl;

	return 0;
}