#include<iostream>
#include<string>
#include"queuetp.h"

int main()
{
	using std::string;
	using std::cin;
	using std::cout;

	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "请输入你的名字: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "队列满了，开始处理\n";

	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "正在处理" << temp << "...\n";
	}
	return 0;
}