#include<iostream>
using namespace std;
struct person {
	char name[20];
	int age;
};//先正常定义结构体

int main() {
	//将结构看成正常变量类型使用new创建即可
	person* p1 = new person;
	//由于不知道变量名字， 只知道变量指针名p1
	//利用指针访问结构成员把句点运算符"."替换成"->"箭头成员运算符即可
	cout << "请输入p1的年龄：";
	cin >> p1->age;
	cout << "请输入p1的名字：";
	cin >> p1->name;
	cout << p1->age<<endl;
	cout << p1->name;
	return 0;
}