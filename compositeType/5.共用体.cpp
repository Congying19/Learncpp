//共用体可以存储不同类型的变量，但是一次只能存储一个。定义跟结果体一样
#include<iostream>
using namespace std;
union one4all {
	int int_val;
	long long_val;
	double double_val;
};
int main() {
	one4all pail;
	pail.int_val = 15;
	cout << pail.int_val << endl;
	pail.double_val = 19.9;
	cout << pail.double_val << endl;//这样的好处是节省内存 有些变量有多种形式 例如品牌名称 有字符也有数字
	return 0;
}