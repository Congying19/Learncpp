//模版类vecter自动完成new 和delete 使用起来很方便，但是效率较低
//模版类array和数组一样，长度固定，也使用静态内存分配
#include<iostream>
#include<vector>//使用vector必须包含这个类
#include<array>
using namespace std;
int main() {
	//vector的定义：
	vector<int> vi;//vi初始长度可以为0，因为vector对象在插入或者添加时自动调整长度
	vi[0] = 1;
	vi[1] = 2;
	vi[2] = 3;
	vi[3] = 4;
	/*int n;
	cin >> n;
	vector<double> vd(n);*/

	//array的定义：
	array<int, 5> ai;
	array<double, 4> ad = { 0.1,0.2,0.3,0.4 };
	return 0;
}