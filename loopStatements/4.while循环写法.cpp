#include<iostream>
using namespace std;
int main() {
	int i = 0;
	while (i < 9) {//和for循环一样是入口条件循环 符合入口条件就循环 否则就跳出循环
		cout << i << "\t";
		i++;//改变循环变量 否则容易导致死循环
	}
	return 0;
}