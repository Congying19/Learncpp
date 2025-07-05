#include<iostream>
using namespace std;
int main() {
	//1.如果for有很多条件 可以用逗号隔开，逗号相当于一个顺序点，先执行前面的
	//2.逗号表达式的值是第二部分的值：
	int i=10, j=20;
	int c = (i, j);
	cout << "c = "<<c << endl;
	//3.逗号在所有运算符中优先级最低
	int d;
	d = 30, 22;
	cout << "d = " << d << endl;
	
	return 0;
}