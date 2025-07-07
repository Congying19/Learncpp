//int n; cin>>n; 当用户输入的不是数字时，将发生四种情况：n的值保持不变，不匹配的输入留在队列中，cin对象中的一个错误标记被设置，
//对cin方法的调用返回false
//利用这四个情况，可以设置读取数字的循环：
#include<iostream>
using namespace std;
const int Max = 5;
int main() {
	//目标：设置一个数组 让用户输入 当用户输入字母时 结束输入
	double fish[Max];
	cout << "Please enter the weights of your fish.\n";
	cout << "You may enter up to " << Max
		<< " fish <q to terminate>.\n"; //用户交互语言提示
	cout << "fish #1:";
	int i = 0;
	while (i<Max && cin >> fish[i]) {  //判断了数组是否越界 让用户进行输入且判断是否结束 
		//cin>>fish[i]实际上是一个cin方法的调用 该函数返回cin 如果cin位于测试条件中 则被转换为bool类型 成功为true 失败为false
		if (++i < Max) {//前置++ 先加后判断
			cout << "fish #" << i + 1 << ":";//由于数组从0开始计数 这里要i+1 只改变输出值 不改变i的值 不能用i++
		}
	}
	for (int j = 0; j < Max; j++) {
		cout << fish[j] << "\t";
	}
	cout << endl;

	//如果遇到错误输入之后还想继续输入应该进行：1.重置cin以接收新的输入 2.删除错误输入 3.提示用户再输入
	double fish2[Max];
	cout << "Please enter the weights of your fish.\n";
	cout << "You may enter up to " << Max
		<< " fish <q to terminate>.\n"; //用户交互语言提示
	int k;
	for (k = 0; k < Max; k++) {
		cout << "fish #" << k + 1 << ": ";
		while (!(cin >> fish2[k])) {//错误输入返回false 利用!false可以进入循环 从而删除
			cin.clear();//重置cin
			while (cin.get() != '\n') {//一个一个读取行尾之前所有的输入 达到删除目的
				continue;//跳过当前循环
			}
			cout << "Please enter a number: ";
		}
	}
	for (int j = 0; j < Max; j++) {
		cout << fish2[j] << "\t";
	}
	return 0;
}