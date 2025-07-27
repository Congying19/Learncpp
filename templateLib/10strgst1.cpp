/*
	string类虽然不是STL的组成部分，但设计时考虑到了STL。它包含begin(),end(),rbegin(),rend()等成员
	因此可以使用STL接口
*/
/*
	下面程序用STL显示使用一个词的字母可以得到的所有排列组合
	next_permutation()算法将区间内容转换为下一种排列方式
	对于字符串，排列方式按照字母递增的顺序进行
	如果成功，该算法返回true；如果区间已经处于最后的序列中，则该算法返回false
	要得到全部排列组合，应从最初的顺序开始，为此先用sort()
*/
#include<iostream>
#include<string>
#include<algorithm>

int main()
{
	using namespace std;
	string letters;
	cout << "Enter the letter grouping( quit to quit): ";
	while (cin >> letters && letters != "quit")
	{
		cout << "Permutation of " << letters << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))
			cout << letters << endl;
		cout << "Enter next sequence (quit to quit): ";
	}
	cout << "Done\n";
	return 0;
}