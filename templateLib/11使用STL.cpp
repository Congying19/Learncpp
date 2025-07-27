/*
	假设要编写一个程序，让用户输入单词。
	希望最后得到一个按输入顺序排列的单词列表和一个按字母顺序排列的单词列表（忽略大小写）
	1.输入和保存单词列表：创建vector<string>对象并用push_back()函数
	2.得到按字母顺序排列：创建set<string>对象，将矢量中的单词复制到集合中，利用集合自动对其内容
		排序，因此无需调用sort()；集合中键只能出现一次，也无需调用unique()
	3.忽略大小写：使用transform()将矢量中的数据复制到集合中，并利用转换函数将字符串转换成小写
	4.转换大小写：将tolower()用于字符串每一个元素
	5.要获得输入次数：使用count()函数，将一个区间和一个值作为参数，返回这个值在区间出现的次数
	6.如何关联单词和次数：将单词作为键只出现一次，将次数作为值，存进map对象
		map可以用数组表示法（将键用作索引）来访问存储的值：wordmap["the"];
*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cctype>
using namespace std;

//tolower原型是int tolower(int )因此要将它转换为字符
char toLower(char ch) { return tolower(ch); }
string& ToLower(string& st);
void display(const string& s);

int main() {
	vector<string> words;
	cout << "Enter words(enter quit to quit):\n";
	string input;
	while (cin >> input && input != "quit")
		words.push_back(input);

	cout << "You entered the following word:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	set<string> wordset;
	transform(words.begin(), words.end(),
		insert_iterator<set<string>>(wordset,wordset.begin()),ToLower);
	cout << "\nAlphabetic list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);
		//又存键又存值，而且还一一对应

	cout << "\nWord frequency:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ": " << wordmap[*si] << endl;

	return 0;
}

string& ToLower(string& st)
{
	//将string视为容器：
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const string& s)
{
	cout << s << " ";
}