/*
	vector数据结构和数组非常相似，也称为单端数组

	区别：vector可以动态扩展，使用new。

	动态扩展：并不是在原有基础上扩展，而是找到更大的空间，然后将原数组拷贝到新空间，释放原来空间
*/
/*
	3.2.2 vector构造函数

	功能描述：

	创建vector容器

	函数原型：

	vector<T> v;    采用模板实现类实现，默认构造函数
	vector(v.begin(), v.end())    将v[begin(), end()]区间中的元素拷贝给本身
	vector(n, elem);    构造函数将n个elem拷贝给本身
	vector(const vector &vec);    拷贝构造函数
*/
#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    vector<int> v3(10, 100);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);
}

int main() {
    test01();
    system("pause");
    return 0;
}