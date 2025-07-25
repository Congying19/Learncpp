/*
	String类对全部6个关系运算符都进行了重载，每个关系运算符都有三种方式重载：
	1.string与string比较
	2.string与C风格字符串
	3.C风格与string比较
	比较方法：在机器排序中，如果一个对象位于另一个对象前面，则前者被视为小于后者
	如果机器排列序列为ASCII码，则：
	数字 < 大写字符，大写字符 < 小写字符
*/
/*
	size()和length()成员都能返回字符串长度
*/
/*
	find()所搜给定字符串或字符的四种重载：
	1.size_type find( const string& str, size_type pos = 0 ) const;
	从字符串的pos位置开始，查找子字符串str，如果找到，则返回该子字符串首次出现时首字符的索引；
	否则，返回string::npos

	string::npos是string类静态成员，它的值是string对象能存储的最大字符数，比最大索引大1

	2.size_type find( const char* s, size_type pos = 0) const 
	类似上面
	3.size_type find( const char* s, size_type pos =0 , size_type n)
	从字符串的pos位置开始，查找s的前n个字符组成的子字符串，如果找到，则返回该子字符串首次出现时首字符的索引；
	否则，返回string::npos
	4.size_type find( char ch, size_type pos = 0) const;
	从字符串的pos位置开始，查找字符ch，如果找到，则返回该字符首次出现的位置，否则，返回string::npos
	
	string类还提供了相关方法：rfind(),find_first_of(),find_last_of(),find_first_not_of(),
	find_last_not_of()，它们的重载函数特征标都与find()方法相同

	rfind()查找字符串或字符最后一次出现的位置
	find_first_of()在字符串中查找参数中任何一个字符首次出现的位置，取每个字符最早出现的最小值
	find_last_of()在字符串中查找参数中任何一个字符最后出现的位置，取每个字符最晚出现的最大值
	find_first_not_of()在字符串中查找第一个不包含在参数中的字符
	find_last_not_of()在字符串中查找最后一个不包含在参数中的字符

*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cctype>
/*
	拼字游戏：将一系列单词存储在一个string对象数组中，然后随机选择一个单词，让人猜测单词的字母
	如果猜错6次，玩家就输了。
	使用find()函数来检查玩家的猜测，使用+=运算符创建一个string对象来记录玩家的错误猜测
	创建一个单词，长度与被猜单词相同，但是包含连字符，玩家猜对字符时，将用该字符替换相应的连字符
*/
using std::string;
const int NUM = 26;
const string wordlist[NUM] = {
	"apple","bee","cow","duck","eat","food","god","holle","ice","joy",
	"kid","low","morden","nuke","open","queue","rest","stick","take",
	"union","very","water","xral","year","zoo"
};

int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	std::srand(std::time(0));
	char play;
	cout << "你要玩单词游戏吗？(y/n)";
	cin >> play;
	play = tolower(play);//变成小写
	while (play == 'y')
	{
		//随机选择被猜单词：
		string target = wordlist[std::rand() & NUM];
		int length = target.length();
		string attempt(length, '-');
		//记录错误字符,默认长度为0
		string badchars;
		int guesses = 6;
		cout << "猜吧，它有" << length << " 个字母，你一次猜一个。你有 " << guesses << " 次错误猜测\n";
		cout << "你的单词：" << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "猜一个字母：";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos) {
				cout << "你已经猜过这个了，换一个\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "错误猜测\n";
				--guesses;
				badchars += letter;
			}
			else {
				cout << "猜对了\n";
				attempt[loc] = letter;
				//把所有猜中的字母都替换
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "你的单词：" << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "错误的选择：" << badchars << endl;
				cout << "还剩 " << guesses << " 次机会\n";
			}
		}
		if (guesses > 0)
			cout << "对了！！！！！\n";
		else
			cout << "抱歉，单词是 " << target << "\n";
		cout << "你要再来一次吗(y/n)?";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye\n";
	return 0;
}
