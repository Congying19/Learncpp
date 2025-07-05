#include<iostream>
using namespace std;
int main() {
	int i;
	for (i = 0; i < 5; i++) {
		cout << i << endl;
	}//{}里面的内容称为语句块，语句块声明的变量只在语句块中存在
	//1.i = 0 循环初始化 只执行一次
	//2.i < 5 循环测试 可以是任意表达式 C++将结果强制转化为bool类型 true则继续 false则循环结束
	//3.i++   循环更新 在每轮循环体结束时进行

	for (int j = 0; j < 5; j++) {//可以在循环初始化定义变量 但是离开循环体就不能使用这个变量
		cout << j;
	}
	return 0;
}