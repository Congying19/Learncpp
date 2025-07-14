#include<iostream>
#include<cctype>
#include"stack.h"
//测试栈，模拟售货员的行为，使用栈后进先出的方式，从购物筐最上面开始处理购物清单
int main() {
	using namespace std;
	Stack st;//创建空栈对象
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO,or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')//toupper()将小写字母转换为大写字母
	{
		while (cin.get() != '\n')//清空行输入
			continue;
		if (!isalpha(ch))//判断字符是不是字母
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else {
				st.pop(po);
				cout << "PO #" << po << " popped\n";
			}
			break;
		default:
			break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO,or Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}