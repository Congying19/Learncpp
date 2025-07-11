//引用：给变量起一个别名
#include<iostream>
using namespace std;
int main() {
	int rats = 101;
	//引用变量创建：
	int& rodents = rats;//int &和int *一样 表示rodents是指向int的引用
	cout << "rats = " << rats << " at "<<&rats<<endl;
	cout << "rodents = " << rodents << " at " << &rodents << endl;
	rodents++;
	cout << "rats = " << rats << endl;
	cout << "rodents = " << rodents << endl;

	//引用和指针的区别：1.引用必须初始化 2.不能改为其他变量的别名，这样做只是普通的赋值，就像rodents = 10这样，并不能改变引用
	int rats2 = 200;
	rodents = rats2;
	cout << "rats = " << rats << endl;
	cout << "rodents = " << rodents << endl;
	
	return 0;
}