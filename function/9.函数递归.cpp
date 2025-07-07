//函数可以调用自己 这种功能称为递归
#include<iostream>
using namespace std;
void countdown(int n);
//递归常用于将一项工作不断分为两项较小的、类似的工作 有时候也被称为分而治之策略
void subdivide(char arr[], int low, int high, int level);
const int Len = 88;
const int Divs = 5;
int main() {
	countdown(4);

	//细分尺子
	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++) {
		ruler[i] = ' ';
	}
	ruler[Len - 1] = '\0';//设置为字符串
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	cout << ruler << endl;
	for (i = 1; i <= Divs; i++) {
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		for (int j = 1; j < Len - 2;j++)
			ruler[j] = ' ';//重新设置尺子
	}
	return 0;
}

void countdown(int n)
{
	cout << "Counting down ..." << n <<"(n at "<<&n<<")" << endl;//每次调用都会产生新的n 地址不一样
	if (n > 0)//1.要有if终止条件
		countdown(n - 1);//2.要改变传入的参数
	cout << n << ": Kaboom!" << "(n at " << &n << ")" << endl;
}

//将一把尺子不断细分
void subdivide(char arr[], int low, int high, int level)
{
	if (level == 0)
		return;//if终止条件
	int mid = (high + low) / 2;
	arr[mid] = '|';//找到中间值
	subdivide(arr, low, mid, level - 1);//上半部分继续分
	subdivide(arr, mid, high, level - 1);//下半部分继续分
}