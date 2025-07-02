//介绍无符号整型变量以及整数溢出现象
#include<iostream>
#include<climits>
#define ZERO 0   //1.定义常量语法 2.define表示预处理，将后面所有ZERO都“替换”成0 3.常量一般都用大写字母表示
using namespace std;
int main() {
	short sam = SHRT_MAX;	//初始化一个变量,默认有符号
	unsigned short sue = sam; //1.sam已经定义了可以赋值给别人 2.无符号变量只需要前面加一个unsigned
	
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl	//一句话分两行写
		<< "Add $1 to each account." << endl << "Now ";
	sam = sam + 1;         //有符号型范围是-32768到32767
	sue = sue + 1;			//无符号型范围是0到65535   如果超过限制就会回到0再来一轮
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited.\nPoor Sam!" << endl;	// \n相当于endl换行符
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl;
	cout << "Take $1 from each account." << endl << "Now ";
	sam = sam - 1;
	sue = sue - 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
	return 0;

}