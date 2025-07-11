//静态持续变量：由于静态变量的数目在程序运行期间是不变的，因此程序不需要使用特殊的装置（如栈）来管理它们。程序会给它们分配固定的内存。
//如果没有显式地初始化静态变量，编译器将把它设置为0。
#include<iostream>
using namespace std;

int global = 1000;//链接性为外部的静态持续性变量，可以在同目录下的其他文件使用，例如分文件编写时
//也称为外部变量 全局变量 可以被定义在其后面的所有函数使用
//单定义规则：变量只能有一次定义。为此C++有两种声明：
//1.定义声明（简称定义）：给变量分配存储空间
//2.引用声明（简称声明）：不给变量分配空间，因为它引用已有的变量。使用extern,且不初始化。
//例如：extern int blem;  在多个文件中使用外部变量，只需在一个文件中包含该变量的定义，但是在使用这个变量的所有文件中都必须使用关键字extern声明它。

static int one_file = 50;//链接性为内部的静态持续性变量，只能在当前文件使用
//作用：在文件一中定义了一个外部变量global，但是在文件二中也想用这个名称，可以使用static int global = 900; 表示在文件二中共享global = 900;而不是
//global = 1000；这样不会违反单定义的规则，因为两个变量虽然同名，但是链接性不同。


void funct1(int n);

int main() {
	cout << "In main(),global is " << global << " in " << &global << endl;
	funct1(2);
	funct1(2);
	int b = 20;
	funct1(2);
	int a = 10;
	int c = 20;
	funct1(2);
	return 0;
}

void funct1(int n)
{
	static int count = 0;//无链接性的静态持续性变量，只能在这个函数内部使用，但是函数即使没有被执行 count变量也留在内存中。
	//因此两次函数调用之间，静态局部变量的值保持不变。而且程序只在启动时进行一次初始化，以后再调用函数也不会初始化。
	count++;
	cout << "第 " << count << " 次调用函数funct1()\n";
	int global = 20*count;//函数里定义的和全局变量同名的变量被视为自动变量 会隐藏全局变量
	cout << "In funct1(),global is " << global << " in " << &global << endl;
}