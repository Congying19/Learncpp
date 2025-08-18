/*
	3.3.6 deque 数据存取

	功能描述：

	对deque中的数据的存取操作

	函数原型：

	at(int idx); 返回索引idx所指的数据
	operator[]; 返回索引idx所指的数据
	front(); 返回容器中第一个数据元素
	back(); 返回容器中最后一个数据元素
*/
#include <deque>
#include <iostream>
using namespace std;

void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "front:" << d.front() << endl;
    cout << "back:" << d.back() << endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}