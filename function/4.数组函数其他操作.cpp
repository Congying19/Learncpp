//由于函数接受数组名参数访问的是原始数组 而不是其副本 因此可以通过调用该函数将值赋给数组元素
#include<iostream>
using namespace std;
int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revalue(double factor,double arr[], int n);
const int Max = 5;
int main() {
	double properties[Max];//创建数组
	int size = fill_array(properties, Max);//填充数组 并记录数组长度
	show_array(properties, size);
	if (size > 0) {
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
	cin.get();//获取上一个回车键
	cin.get();//让程序暂停等待输入回车键
	return 0;
}

//填充数组元素的函数
int fill_array(double arr[], int limit)
{
	double temp;//临时变量 先用临时变量判断是否符合要求 再放入数组
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ":";
		cin >> temp;
		if (!cin)//错误输入需要重置并重新输入 这里cin就是上一行cin>>temp的cin
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input;input process terminated.\n";//错误输入就会终止填充
			break;//跳出外层for循环
		}
		else if (temp < 0)//将输入负数作为结束标志
			break;
		arr[i] = temp;
	}
	return i;//循环最后一项工作时将i加1 因此i比索引大1 表示元素数目 返回元素数目可以知道填充了多少元素
}

//显示数组元素的函数 这个函数目的是显示 而不是修改元素 应该尽量避免修改
void show_array(const double arr[], int n)//const 修饰数组名 意味着在这个函数中arr[]数组不能修改 并不意味着数组元素必须时常量
{
	for (int i = 0; i < n; i++) {
		cout << "Property #" << (i + 1) << ": $";
		cout << arr[i] << endl;
	}
}

//修改数组元素的函数 将数组每个元素乘以一个因子
void revalue(double r, double arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] *= r;
}