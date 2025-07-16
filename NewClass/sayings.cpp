#include<iostream>
#include"string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
	{
		using std::cin;
		using std::endl;
		using std::cout;
		String name;
		cout << "Hi,what's your name?\n>>";
		cin >> name;

		cout << name << ",please enter up to " << ArSize
			<< " short sayings <empty line to quit>:\n";
		String sayings[ArSize];
		char temp[MaxLen];
		int i;
		for (i = 0; i < ArSize; i++)
		{
			cout << i + 1 << ": ";
			cin.get(temp, MaxLen);
			while (cin && cin.get() != '\n')
				continue;
			if (!cin || temp[0] == '\0')
				break;//将输入先放在一个临时变量里面 判断之后再放入对象数组 可以减少意外报错
			else
				sayings[i] = temp;
		}
		int total = i;

		if (total > 0)
		{
			cout << "Here are your sayings:\n";
			for (i = 0; i < total; i++)
				cout << sayings[i][0] << ": " << sayings[i] << endl;

			int shortest = 0;
			int first = 0;
			for (i = 1; i < total; i++)
			{
				if (sayings[i].length() < sayings[shortest].length())
					shortest = i;//找最短
				if (sayings[i] < sayings[first])
					first = i;//找最大
			}
			cout << "Shortest saying:\n" << sayings[shortest] << endl;
			cout << "First alphabetically:\n" << sayings[first] << endl;
			cout << "This program used " << String::HowMany()//使用类名调用静态成员函数
				<< " String objects.Bye\n";
		}
		else
			cout << "No input!Bye\n";
	}
	std::cout << "This program used\n" << String::HowMany() << std::endl;
	return 0;

}