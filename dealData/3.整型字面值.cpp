//介绍整型是二进制八进制十六进制怎么赋值
#include<iostream>
using namespace std;
int main() {
	int chest = 42;
	int waist = 0x42;//0x开头表示十六进制数  目的是已知十六进制数 便可以直接赋值 没必要转化为十进制再赋值
	int inseam = 042;//0开头表示八进制数

	//默认情况下 cout以十进制输出这些数 这些数在计算机内部以二进制保存
	cout << "chest = " << chest << endl;
	cout << "waist = " << waist << endl;
	cout << "inseam = " << inseam << endl;

	//如果想要输出八进制或者十六进制 可以使用iostream提供的控制符 就像使用endl一样
	cout << "chest = " << chest << endl;
	cout << hex;//告诉cout以十六进制输出
	cout << "waist = " << waist << endl;
	cout << oct; //以八进制输出
	cout << "inseam = " << inseam << endl;
	cout << dec;//切换回十进制
	return 0;
}