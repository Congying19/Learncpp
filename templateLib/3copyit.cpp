#include<iostream>
#include<iterator>
#include<vector>

int main()
{
	using namespace std;

	int casts[10] = { 5,6,7,5,1,4,2,3,9,8 };
	vector<int> dice(10);
	//复制到另一个容器：
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast\n";
	ostream_iterator<int, char> out_char(cout, " ");
	copy(dice.begin(), dice.end(), out_char);
	cout << endl;
	cout << "反转：\n";
	copy(dice.rbegin(), dice.rend(), out_char);
	cout << endl;
	cout << "直接使用反转迭代器：\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << " ";
	cout << endl;
	return 0;
}