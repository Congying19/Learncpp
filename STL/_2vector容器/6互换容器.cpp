/*
	3.2.7 vector互换容器

	功能描述：

	实现两个容器内元素进行互换

	函数原型：

	swap(vec); 将vec与本身的元素互换
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

    vector<int> v2;
    for (int i = 10; i > 0; i--) {
        v2.push_back(i);
    }
    printVector(v2);

    //互换容器
    cout << "互换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

void test02()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }
    cout << "v的容量为: " << v.capacity() << endl;
    cout << "v的大小为: " << v.size() << endl;

    v.resize(3);

    cout << "v的容量为: " << v.capacity() << endl;
    cout << "v的大小为: " << v.size() << endl;

    //swap()的用途，如果一开始设置v的容量很大，即使重新resize()也只能改变大小，而不能改变容量
    //这时候可以使用swap()
    //vector<int>(v) ;
    // 这句话创建一个匿名对象，并利用v进行拷贝构造，由于v的size是3，则匿名对象的size也是3
    //vector<int>(v).swap(v);
    //这句话将匿名对象和v互换，此时匿名对象的容量是1000000，而v的容量变为3。匿名对象由编译器管理，不用管

    //收缩内存
    vector<int>(v).swap(v); //匿名对象

    cout << "v的容量为: " << v.capacity() << endl;
    cout << "v的大小为: " << v.size() << endl;
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}