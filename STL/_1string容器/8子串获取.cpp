/*
	### 3.1.9 string子串

功能描述：

- 从字符串中获取想要的子串
- 函数原型：
  - string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
*/
#include<iostream>
using namespace std;
#include <string>
//子串
void test01()
{
    string str = "abcdefg";
    string subStr = str.substr(0, 3);
    cout << "subStr = " << subStr << endl;

    string email = "hello@sina.com";
    int pos = email.find("@");
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;
}
int main()
{
    test01();
    system("pause");
}