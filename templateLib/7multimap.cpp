#include<iostream>
#include<string>
#include<map>
#include<algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
	using namespace std;
	MapCode codes;
	codes.insert(Pair(415, "San Francisco1"));
	codes.insert(Pair(510, "San Francisco2"));
	codes.insert(Pair(718, "San Francisco3"));
	codes.insert(Pair(718, "San Francisco4"));
	codes.insert(Pair(415, "San Francisco5"));
	codes.insert(Pair(510, "San Francisco6"));

	cout << "Number of cities with area code 415: " << codes.count(415) << endl;
	cout << "Number of cities with area code 510: " << codes.count(510) << endl;
	cout << "Number of cities with area code 718: " << codes.count(718) << endl;
	cout << "Area Code	City\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << "		" << (*it).first << "    " << (*it).second << endl;
	//将pair模版里面两个值都设为迭代器，就能接收equal_range的返回值
	pair<MapCode::iterator, MapCode::iterator> range
		= codes.equal_range(718);
	cout << "Cities with area code 718:\n";
	for (it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;
	return 0;
}