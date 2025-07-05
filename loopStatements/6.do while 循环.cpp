//do while循环是出口条件循环 先执行一遍循环体 再判断条件
//请求用户输入时，程序必须先获得输入，再进行测试，此时用do while
#include<iostream>
using namespace std;
int main() {
	int n;
	do {
		cin >> n;
	} while (n != 7);
	cout << "nice try\n";
	return 0;
}