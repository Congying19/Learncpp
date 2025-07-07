//创建自己的函数时 必须提供三个方面：定义 原型 调用
#include<iostream>
using namespace std;

void simple(); //函数原型：函数头+分号; 放在main()之前 告诉编译器有simple()这样一个函数 防止报错
//也可以直接把函数定义放在前面 这样就不需要函数声明了
//函数原型参数列表里可以只有变量类型 无需变量名 变量名只是一个占位符 可以跟函数头不一样
int main() {
	cout << "main() will call the function :\n";
	simple();//函数调用：函数名+传入变量
	cout << "main() id finished with the simple() function.\n";
	return 0;
}

void simple() {//函数定义：完整的函数 void表示返回为空 
	cout << "I'm but a simple function.\n";
	//如果有返回值 就要写return语句 返回类型也要写
}