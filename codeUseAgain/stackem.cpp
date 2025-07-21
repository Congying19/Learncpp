#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.h"
using std::cin;
using std::cout;

int main()
{
	//显示提供类模版所需类型：
	Stack<std::string> st;//创建一个空栈
	char ch;
	std::string po;
	cout << "输入A可以添加一件物品，输入P可以处理一件物品，输入Q可以退出程序：\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "输入一个栈成员添加到顶部：";
			cin >> po;
			if (st.isfull())
				cout << "栈已经满了\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "栈是空的\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " 已经删除\n";
				break;
			}
		default:
			break;
		}
		cout << "输入A可以添加一件物品，输入P可以处理一件物品，输入Q可以退出程序：\n";
	}
	cout << "Bye\n";
	return 0;
}