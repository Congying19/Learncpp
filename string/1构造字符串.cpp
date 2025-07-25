/*
	string类由头文件string支持，不是string.h，也不是cstring
*/
#include<iostream>
#include<string>
//介绍string类的7个构造函数：
int main()
{
	using namespace std;
	string one("Lottery Winner!");
	//string(const char* s);
	//将string对象初始化为s指向的NBTS
	// （null-terminated string，即以空字符结尾的字符串，C风格字符串） 
	cout << one << endl;

	string two(20, '$');
	/*
		string(size_type n, char c);
		创建一个包含n个元素的string对象，其中每个元素都被初始化为字符c
	*/
	cout << two << endl;

	string three(one);
	/*
		string(const string& str);
		复制构造函数：将一个string对象初始化为string对象str
	*/
	cout << three << endl;

	one += " Oops!";//重载运算符+=
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';

	string four;
	/*
		string()
		默认构造函数：创建一个默认的string对象，长度为0
	*/
	four = two + three;//重载运算符=,+
	cout << four << endl;

	char alls[] = "All's well that ends well";
	string five(alls, 20);
	/*
		string(const char* s, size_type n);
		将string 对象初始化为s指向的NBTS的前n个字符，即使超过了NBTS的结尾
	*/
	cout << five << "!\n";
	
	string six(alls + 6, alls + 10);
	/*
		template<class Iter>
		string(Iter begin, Iter end);
		将string 对象初始化为区间[begin, end)内的字符,begin和end的行为就像指针，用于指定位置
	*/
	cout << six << ", ";
	string seven(&five[6], &five[10]);
	//同上，区别是指针法和数组法,但是string是类，five是对象名，对象不会被看作是对象的地址
	//因此不能five+6，five不是地址
	cout << seven << ", ";

	string eight(four, 7, 16);
	/*
		string(const string & str, string size_type pos =0 ,size_type n = npos)
		将string对象初始化为对象str中从位置pos开始到结尾的字符，或者从pos开始的n个字符
	*/
	cout << eight << " in motion " << endl;

	//C++11新增：
	/*
		string(string && str)noexcept;
		移动构造函数：将string对象初始化为str，并可能修改str
	*/
	/*
		string(initializer_list<char> il)
		将一个string对象初始化为初始化列表il中的字符
	*/
	string comp_lang{ 'L','i','s','p' };
	cout << comp_lang << endl;
	return 0;
}