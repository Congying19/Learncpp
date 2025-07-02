//字符串处理方式二：利用string 变量
//使用string 变量必须包含头文件string
//1.可以使用C风格字符串来初始化string对象
//2.可以直接cin将键盘输入存储到string对象中
//3.cout可以直接输出
//4.可以利用数组下标访问存储在string内的字符

//string的操作：
//1.赋值 例如str2 = str1
//2.拼接 str2+str1
//3.附加 str1+=str2

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main() {
	//string 拼接
	string str1 = "hello";
	string str2 = " world";
	cout << str1 + str2<<endl;

	//计算string长度
	cout << "The size of " << str1 << " is " << str1.size()<<endl;

	
	//getline()读取string对象
	string str3;
	getline(cin, str3);//这里将cin作为参数 表示要到哪里去查找输入 另外不用定义输入长度 string根据输入自动调整大小
	cout << str3 << endl;

}