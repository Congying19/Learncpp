#include<iostream>
using namespace std;
int main() {
	enum spectrum{red , orange ,yellow};
	//1.让spectrum称为新类型的名称 spectrum称为枚举
	//2.将red orange yellow 作为符号常量 默认对应0 1 2 这些常量叫做枚举量
	spectrum band = red;//只能将枚举量赋值给枚举类型的变量
	cout << band << endl;

	enum spectrum2{red2=10,orange2=19,yellow2};
	//可以手动赋值 后面如果没有赋值 就比前面大1 第一个没有赋值就为0
	spectrum2 band2 = yellow2;
	cout << band2;
	return 0;
}