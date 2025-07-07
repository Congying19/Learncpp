#include<iostream>
using namespace std;
int main() {
	int choice;
	cin >> choice;
	while (choice < 5) {
		switch (choice) { //choice 必须是一个结果为整数值的表达式
		case 1://case 后面的值 是表达式可能得结果
			cout << "情况一\n";
			break;//break确保只执行特定部分语句，没有break就会执行下一个case 
			//break用于switch是跳过switch , 不是跳出switch所在的循环
			//continue只能用于循环中 跳过这一轮剩余的代码
		case 2:
			cout << "情况二\n";
			break;
		case 3:
			cout << "情况三\n";
			break;
		case 4:
			cout << "情况四\n";
			break;
		default:
			cout << "没有这个情况\n";
			break;
		}
		cin >> choice;
	}
	return 0;
}