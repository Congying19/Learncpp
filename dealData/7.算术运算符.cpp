//加法减法乘法分别为+-*
//除法行为取决于操作数的类型，两个操作数都是整数，将执行整数除法，最后结果小数直接丢弃。如果有一个数是浮点数，最后结果就是浮点数
//展示求模运算符%
#include<iostream>
using namespace std;
int main() {
	const int Lbs_per_stn = 14;//1英石等于14镑
	int lbs;

	cout << "Enter your weight in pounds: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn; //获取整数 即整块石头
	int pounds = lbs % Lbs_per_stn;//获取剩余 即散的石头
	cout << lbs << " pounds are " << stone
		<< " stone, " << pounds << " pound(s).\n";
	return 0;
}