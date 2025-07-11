#include<iostream>
#include"1.coordin.h"//用双引号包含头文件 告诉编译器首先到当前工作目录或源代码目录寻找
using namespace std;

int main() {
	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}