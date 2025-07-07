#include<iostream>
using namespace std;
const int ArSize = 8;
int sum_arr(int arr[], int n);
int main() {
	int cookies[ArSize] = { 10,20,14,66,85,12,54,11 };
	int sum = sum_arr(cookies, ArSize);
	//cookies是第一个元素地址 则为int指针 即类型是int* 函数声明时参数应该是int* arr 说明int* arr和int arr[]都是正确的。
	//只有在函数头或者函数原型中int* arr 和int arr[]含义才是相同的
	cout << "Total cookies eaten: " << sum << endl;
	cout << "size of cookies is " << sizeof cookies << endl;
	//函数只能通过第二个参数得知数组元素个数 因此可以对函数说谎
	int sum2 = sum_arr(cookies + 4, 4);//计算后四位
	cout << "The last four cookies eaten: " << sum2 << endl;
	return 0;
}

int sum_arr(int arr[], int n) {//这里形参接收数组地址 只是拷贝了一份地址 没有拷贝一份数组
	//函数头里面的int n是显式传递数组长度 
	//在函数中无法利用sizeof arr/sizeof arr[0]来获得数组长度，因为sizeof arr只是指针长度，sizeof cookies 才是数组长度，即使arr = cookies
	cout << "size of arr is " << sizeof arr<<endl;
	int total = 0;
	for (int i = 0; i < n; i++)
		total = total + arr[i];
	return total;
}