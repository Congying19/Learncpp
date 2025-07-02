//书写浮点数，方法一：直接写3.1415926、8.0、0.8  
// 方法二：E表示法 3.45E5表示3.45*10^5科学计数法 数字和e/E之间不能有空格隔开 0.6E-9
//浮点类型有三种：float, double, long double  按照有效数位和允许指数最小范围来区分
//有效位是数字中有意义的位 例如14759有效位是5， 14000有效位是2，其他只是占位符。有效位不依赖小数点的位置，14.729有效位还是5
//通常float为32位 double64位 long double 80、96或者128位
#include<iostream>
using namespace std;
int main() {
	cout.setf(ios_base::fixed, ios_base::floatfield); //调用setf 迫使用定点表示法输出 防止程序将较大的数转化为科学计数法
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;

	cout << "tub= " << tub;
	cout << ", a million tubs = " << million * tub; //对于float 程序只能保证6个有效位 如果运算涉及到7位及以上 则结果不精确
	cout << ", \nand ten million tubs=";
	cout << 10 * million * tub << endl;

	cout << "mint= " << mint << " and a million mints = ";//double能保证15位
	cout << million * mint << endl;

	return 0;
}