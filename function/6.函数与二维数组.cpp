#include<iostream>
using namespace std;
int sum(int (*arr)[4], int size);
//int (*arr)[4] 表示一个指向“由4个int组成的数组”的指针
//int *arr[4]表示一个“由4个指向int的指针”组成的数组
int main() {
	int data[3][4] = {
		{1,2,3,4},
		{2,5,4,6},
		{4,5,2,5}
	};
	cout << "sum = " << sum(data, 3) << endl;
	return 0;
}

int sum(int (*arr)[4], int size)//也可以写成int sum(int arr[][4],int size) 4是列数 固定 不需要传递
{
	int total = 0;
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < 4; c++)
			total += arr[r][c];//使用的时候直接把arr看成数组名即可
	}
	return total;
}