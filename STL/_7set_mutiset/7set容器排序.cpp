//### 3.8.8 set容器排序
//
//学习目标：
//
//- set容器默认排序规则为从小到大，掌握如何改变排序规则
//主要技术点：
//
//- 利用仿函数，可以改变排序规则

#include <iostream>
#include <set>
using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2) const {
        return v1 > v2;
    }
    //这个错误是因为仿函数的operator()需要被声明为const成员函数，
    // 因为set在排序时会使用const对象调用比较函数。
    // 解决方法是在operator()后面添加const修饰符，表示这个函数不会修改对象状态。
};

void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);

    //默认从小到大
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //指定排序规则
    set<int, MyCompare> s2;
    //set模版里面要放数据类型，不能放函数名，所以把仿函数operator()放在MyCompare里面
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);

    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

class comparePerson
{
public:
    bool operator()(const Person& p1, const Person& p2) const
    {
        //按照年龄进行排序
        return p1.m_Age > p2.m_Age;
    }
};

void test02()
{
    set<Person, comparePerson> s;

    Person p1("刘备", 23);
    Person p2("关羽", 27);
    Person p3("张飞", 25);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
}

int main() {
    test01();
    test02();
    return 0;
}