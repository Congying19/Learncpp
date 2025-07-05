//循环最重要最常见的任务：逐字符地读取来自文件或者键盘的文本。
#include<iostream>
using namespace std;
int main() {
	char ch = 0;
	int count = 0;
	cout << "Enter characters;enter # to quit:\n";
	cin >> ch;
	while (ch != '#') {//从键盘读取输入 遇到#就停止
		cout << ch;
		count++;
		cin >> ch;//可以一次性输入abcdefg# 每次循环从输入读取一个直到遇见#
	}
	cout << endl << count << "characters read\n";

	return 0;
}