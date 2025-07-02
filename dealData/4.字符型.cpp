//介绍字符型变量char
#include<iostream>
using namespace std;
int main() {
	char ch;    //声明一个变量
	cout << "Enter a characher: " << endl;
	cin >> ch;//cin将键盘输入的字母M 按照ASCII表转化为对应的数字77 存在ch中
	//即使键盘输入数字也会被看成字符读取 例如5看成字符"5" 再转换成对应变量类型存储
	cout << "you put " << ch << endl; //cout将77转化为字符M,cin\cout的行为是由变量类型引导的，如果变量是int 则输出77

	char ch2 = 'M'; //在c++中书写字符字面值用单引号
	int i = ch2; //ch2是整数可以赋值给整型变量
	cout << "The ASCII code for M is " << i << endl;
	
	ch2 = ch2 + 1;//字符变量也可以计算
	i = ch2;//再次将字符数值存在i中
	cout << "The ASCII code for " << ch2 << " is " << i << endl;

	//可以使用成员函数cout.put()输出单个字符
	cout.put(ch2);
	return 0;
}