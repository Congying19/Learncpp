#include<iostream>
using namespace std;
int main() {
	int age = 80;
	const int* pt = &age;//这里pt指向const int 因此不能通过pt来修改这个值 
	//对pt而言 它指向的值是常量 但是age不是const 可以用age来修改age的值
	cout << "age is " << age << endl;
	cout << "*pt is " << *pt << endl;
	cout << "After change age \n";
	age += 90;
	cout << "age is " << age << endl;
	cout << "*pt is " << *pt << endl;//age的值修改 *pt自然也会修改 间接达到目的

	//const 数据或者非const数据的地址可以赋值给const指针。
	//非const指针只能接收非const数据的地址
	//pt指向const int 可以改变pt的值 即指向别的值 但是仍然不能用*pt修改值
	int age2 = 88;
	pt = &age2;
	cout << "now *pt is " << *pt << endl;

	int sloth = 9;
	int* const pt2 = &sloth;//这里const pt2指向sloth 说明pt2的值不能变 但是可以通过pt2改变sloth的值
	*pt2 += 20;
	cout << "*pt2 is " << *pt2 << endl;
	return 0;
}