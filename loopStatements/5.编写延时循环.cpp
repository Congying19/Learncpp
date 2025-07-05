//while循环可以实现让程序等待一段时间
#include<iostream>
#include<ctime>//包含clock()函数 和clock_t别名
using namespace std;
int main() {
	cout << "Enter the delay time , in seconds:";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;//CLOCKS_PER_SEC表示每秒钟包含的系统时间单位数，将秒转化为系统时间
	cout << "starting\a\n";
	clock_t start = clock();//clock()返回程序开始执行后的系统时间
	while (clock() - start < delay);
	cout << "done\a\n";
	return 0;
}