/*
	list成员函数：Alloc模版参数有默认值
	void merge(list<T,Alloc>& x)		将链表x与调用链表合并。两个链表必须已经排序。
				合并后的经过排序的链表存在调用链表中，而x变为空。复杂度为线性时间
	void remove(const T& val)			从链表中删除val的所有实例。复杂度为线性时间
	void sort()							使用<运算符对链表进行排序，复杂度为NlogN
	void splice(iterator pos, list<T,Alloc>x) 将链表x的内容插入到pos的前面，x变为空
								复杂度为固定复杂度
	void unique()				将连续的相同元素压缩为单个元素。复杂度为线性时间
*/
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>//包含copy()和for_each()

void outint(int n) { std::cout << n << " "; }

int main()
{
	using namespace std;
	//构造函数创建对象
	list<int> one(5, 2);//5个2

	int stuff[5] = { 1,2,4,8,6 };
	//默认构造函数
	list<int> two;
	//利用插入来赋值，将一个容器（数组）插入到另一个容器
	two.insert(two.begin(), stuff, stuff + 5);

	int more[6] = { 6,4,2,4,6,5 };
	//复制构造函数
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "List one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "List two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "List three: ";
	for_each(three.begin(), three.end(), outint);
	//删除2：
	three.remove(2);
	cout << endl << "List three minus 2s: ";//减去所有的2
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << endl << "List three after splice: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "List one: ";
	for_each(one.begin(), one.end(), outint);
	//合并连续相同的元素：
	three.unique();
	cout << endl << "List three after unique: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "List three after sort & unique: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "Sorted two merged int three : ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
	
	return 0;
}

