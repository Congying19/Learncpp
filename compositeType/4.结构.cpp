//结构是用户自定义类型 可以存储不用类型的数据
#include<iostream>
using namespace std;
//结构声明：
struct inflatable
{
	char name[20];
	float volume;
	double price;
};//结构末尾自带分号
//该结构声明在main()外部，称为外部声明，外部声明可以被后面所有函数使用。相反，内部声明只能被所属函数使用
int main() {
	inflatable guest =
	{
		"Mark",
		3.12,
		29.99
	};//利用结构创建变量 并初始化

	//利用句点运算符访问结构变量成员：
	cout << "guest's name is " << guest.name << endl;

	//结构数组
	inflatable guesta[2] = {
		{"mary",5,48.9},
		{"Jack",7.8,844}
	};
	return 0;

}