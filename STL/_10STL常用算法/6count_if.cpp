/*
	5.2.6 count_if

	功能描述：

	- 按条件统计元素个数

	函数原型：

	- count_if(iterator beg, iterator end, __pred);

	// 按条件统计元素出现次数
	// beg 开始迭代器
	// end 结束迭代器
	// __Pred 谓词
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool greaterThan3(int num) {
	return num > 3;
}

int main() {
	vector<int> v = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };

	// 统计大于3的元素个数
	int cnt = count_if(v.begin(), v.end(), greaterThan3);
	cout << "大于3的元素个数: " << cnt << endl;

	return 0;
}