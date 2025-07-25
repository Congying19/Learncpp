/*
	对于C风格字符串，有三种输入方式：
	char info[100];
	cin>>info;
	cin.getline(info, 100 ,':');//读取但抛弃':'(默认是换行符)
	cin.get(info, 100);//留下换行符

	对于string对象，有2两种：
	string stuff;
	cin>>stuff;
	getline(stuff,':')//读到':'，但是抛弃':'，默认是换行符
	//如果指定分界符之后，换行符将被视为常规字符

	区别：1.string会自动调整大小
	2.读取C风格字符串的函数是istream类方法，而string版本是独立的函数。
	因此对于C风格字符串，cin是调用对象：cin.operator>>(fname)
	对于string类对象，cin是一个函数参数：operator>>(cin,lname)

	两个限制：
	1.string对象允许的最大长度由常量string::npos指定，通常是最大的unsigned int值
	2.程序可以使用的内存量

	string版本的getline()函数从输入中读取字符，并存储到目标string中，直到发生下面三种情况：
	1.到达文件尾，输入流的eofbit将被设置，意味着fail()和eof()都返回true
	2.遇到分界字符(默认为\n)，这种情况下，将把分界字符从输入流中删除，但不存储它。
	3.读取的字符数达到最大允许值，这种情况下，将设置输入流为failbit，意味着fail()将返回true
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

int main() {
	using namespace std;
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "Can't open file.Bye\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();
	return 0;
}