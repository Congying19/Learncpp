#include<iostream>
using std::cout;
#include"strngbad.h"

void callme1(StringBad&);//引用传递
void callme2(StringBad);//值传递

int main()
{
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		StringBad headline1("Celery Stalks an Midnight");//创建对象并初始化
		StringBad headline2("Lettuce Prey");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << endl;

		callme1(headline1);
		cout << "headline1: " << headline1 << endl;

		cout << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;

		cout << endl;
	}
	cout << "End of main()\n";
	return 0;
}

void callme1(StringBad& rsb)
{
	cout << "String passed by reference:\n";
	cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "String passed by value:\n";
	cout << "   \"" << sb << "\"\n";
}