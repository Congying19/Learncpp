#include<iostream>
using namespace std;
int main() {
	int n;
	do {
		cin >> n;
		if (n < 10)
			cout << "Too low" << endl;
		else if (n > 10)
			cout << "Too high" << endl;
		else
			cout << "right" << endl;

	} while (n != 10);

	//if else 可以被?:表达式代替 ?:称为条件运算符
	int i = (5 > 2) ? 7 : 8;//这个表达式的意思是5>2? 正确则值为7 错误则值为8 
	return 0;
}