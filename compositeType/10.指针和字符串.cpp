//在cout和多数C++表达式中，char数组名，char指针，以及用引号括起来的字符串常量都被解释为字符串第一个字符的地址。
//cout收到字符串第一个字符地址就会打印该处字符，并继续打印地址后面的字符，直到遇到空字符为止。
#include<iostream>
using namespace std;
int main() {
	char p1[10] = "world";
	const char* p2 = "hello";//字符串常量必须赋值给常量指针 不能修改指针指向的地址
	cout << p1 << endl;
	cout << p2 << endl;//这里打印的都是字符串，而不是地址。因为cout遇到char*类型指针会显示字符串。
	cout << (int*)p1 << endl;
	cout << (int*)p2 << endl;
	cin >> p1;
	cout << p1 << endl;
	return 0;
}