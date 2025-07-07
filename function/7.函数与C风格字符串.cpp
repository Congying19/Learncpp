//C风格字符串是char类型指针 可以将其作为字符串处理函数的参数
#include<iostream>
using namespace std;
unsigned int c_in_str(const char* str, char ch);
char* buildstr(char c, int n);
int main() {
	char str1[20];
	cout << "请输入20字母以内的字符串：\n";
	cin >> str1;
	cout << "请输入你要查找的字母：\n";
	char ch;
	cin >> ch;
	cout << "这个字母一共出现了 " << c_in_str(str1, ch) << " 次\n";

	cout << "请输入你想要复制的字母：\n";
	char ch2;
	cin >> ch2;
	cout << "请输入你想要复制的次数：\n";
	int times;
	cin >> times;
	//cout << "复制结果为：" << buildstr(ch2, times) << endl;
	char* ps = buildstr(ch2, times);
	cout << "复制结果为：" << ps << endl;
	delete[] ps;//函数返回的是一个new创建的指针时，一定要定义一个指针指向new创建的内存 否则无法释放
	return 0;
}

//计算某个字母在字符串中出现的次数：
unsigned int c_in_str(const char* str, char ch)//不想改变字符串 用const修饰
{  //传递字符串不需要传递字符串长度 因为找到空字符就自动停下来
	unsigned int count = 0;
	while (*str)//str 表示第一个字符的地址 空字符为false就退出循环
	{
		if (*str == ch)
			count++;
		str++;//移动指针  处理字符串的标准方式
	}
	return count;
}

//返回一个字符串：函数无法返回一个字符串 但是可以返回字符串的地址 这样做的效率更高
char* buildstr(char c, int n) {
	char* pstr = new char[n + 1];//根据输入长度创建数组
	pstr[n] = '\0';//将结尾设置成空字符才是字符串
	while (n-- > 0)
		pstr[n] = c;//从后往前填充字母
	return pstr;
}