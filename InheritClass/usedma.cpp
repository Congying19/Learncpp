#include<iostream>
#include"dma.h"
int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabally", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "展示baseDMA对象：\n";
	cout << shirt << endl;
	cout << "展示lacksDMA对象：\n";
	cout << balloon << endl;
	cout << "展示hasDMA对象：\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);//测试复制
	cout << "lacksDMA 复制结果：\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "hasDMA 赋值结果：\n";
	cout << map2 << endl;

	return 0;
}