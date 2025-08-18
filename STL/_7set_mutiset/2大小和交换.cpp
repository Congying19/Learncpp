/*
	# 3.8.3 set大小和交换

	功能描述：

	- 统计set容器大小以及交换set容器

	---

	## 函数原型：

	- size()： //返回容器中元素的数目  
	- empty()： //判断容器是否为空  
	- swap(st)： //交换两个集合容器
*/
#include <iostream>
#include <set>
using namespace std;

//大小
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    if (s1.empty())
    {
        cout << "s1为空" << endl;
    }
    else
    {
        cout << "s1不为空" << endl;
        cout << "s1的大小为: " << s1.size() << endl;
    }
}

//交换
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    set<int> s2;
    s2.insert(100);
    s2.insert(300);
    s2.insert(200);

    cout << "交换前:" << endl;
    cout << "s1: ";
    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "s2: ";
    for (auto it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    s1.swap(s2);

    cout << "交换后:" << endl;
    cout << "s1: ";
    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "s2: ";
    for (auto it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    cout << "测试set大小功能:" << endl;
    test01();

    cout << "\n测试set交换功能:" << endl;
    test02();

    return 0;
}