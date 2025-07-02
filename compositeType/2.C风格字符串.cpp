//字符串是存储在内存的连续字节中的一系列字符。

//c++处理字符串方式一：C风格字符串：一系列字符可以理解为储存在char数组中。
// C风格字符串特点：以空字符"\0"结尾 ，例如：
//char dog[8] = { 'b','a','d','b','a','w','a','0'};不是字符串 直接cout<<dog 会超出数组范围,直到碰见空字符 只能循环遍历输出
//char cat[8] = { 'b','a','d','b','a','w','a', '\0' };是字符串 可以直接cout<<cat
//一个字母一个字母的赋值太麻烦 可以直接char fish[]="Bubbles" 这种方式隐式地包含空字符 计算数组长度记得加上
//字符串拼接 由空白字符（空格，制表符和换行符）隔开的字符串可以自动拼接在一块
//面向行输入：getline()读取整行通过回车键输入的换行符来确定输入结尾。它不保存换行符
//			利用cin.getline()包含两个参数：1.数组名称 2.读取字符数量，例如20，就读取19个字符 剩下一个给空字符
//面向行输入：get()参数和getline()一样 但是get会把换行符留在输入队列中 再次使用就会读到换行符
#include<iostream>
#include<cstring>//包含strlen()可以计算字符长度 不包括空字符
using namespace std;
int main() {
	char dog[8] = { 'b','a','d','b','a','w','a','0'};
	char cat[8] = { 'b','a','d','b','a','w','a', '\0' };
	cout << cat<<endl;

	////字符串拼接：
	cout << "hello" "world\n";
	cout << "hello"	"world\n";
	cout << "hello"
		"world\n";

	////C风格字符串的使用
	char name1[15];
	char name2[15] = "c++owboy";
	cin >> name1;//从键盘直接输入 但是不能超过长度
	cout << "your name has " << strlen(name1) << " words.\n";
	name2[3] = '\0';//手动将第四个元素设置为空字符 只输出前三个
	cout << name2;

	//getline()使用：
	char name3[15];
	cin.getline(name3, 8);
	cout << name3 << endl;

	//get()的不同：
	char name4[15];
	cin.get(name4, 8);
	cout << name4 << endl;
	cin.getline(name4, 8);//读取到get留下来的换行符直接结束
	cout << name4 << endl;
	
	//getline()的特殊用法：
	cin.getline(name3, 8).getline(name4,8);
	cout << name3 << endl << name4 << endl;

	//数字和字符串混合输入：
	int age;
	char name5[15];
	(cin >> age).get();//cin输入年龄 返回cin对象继续调用get()读取留下来的回车符
	cin.getline(name5, 7);
	cout << age << endl << name5 << endl;
	return 0;
}