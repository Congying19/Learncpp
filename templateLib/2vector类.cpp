/*
	STL在头文件vector中定义了一个vector模版

	使用：
	1.利用<type>表示法指出要使用的类型
	2.vector模版使用动态内存分配，可以用初始化参数指出需要多少矢量：
	vector<int> ratings(5);
	3.运算符[]被重载，因此创建vector对象后，可以使用通常的数组表示法访问各个元素
	ratings[2];

	分配器：各种STL容器模版都接受一个可选的模版参数，该参数指定使用哪个分配器对象来管理内存
	vector模版的开头与下面类似
	template <class T, class Allocator = allocator<t> >
		class vector{...
	容器版本默认使用allocator<T>类，这个类使用new和delete
*/
#include<iostream>
#include<string>
#include<vector>

const int NUM = 5;
void test01();

//vector类一些方法：
void test02();
//将title和rating放在一个结构里方便管理
struct Review {
	std::string title;
	int rating;
};
bool FillReview(Review& rr);
void ShowReview(const Review& rr);

int main() {
	//test01();
	test02();
	return 0;
}

void test01()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;

	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << "输入 " << NUM << " 本书的标题和你给的分数。\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << "输入标题#" << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "输入分数（0-10）：";
		cin >> ratings[i];
		cin.get();
	}
	cout << "你输入如下：\n";
	for (i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}
}

/*
	vector模版类也包含只有某些STL容器才有的方法：
	push_back()将元素添加到矢量末尾，无需了解元素的数目，只要能够取得足够内存，就可以添加
	erase()删除给定区间的元素，第一个迭代器指向区间的起始处，第二个迭代器位于区间终止处的后一个位置
	insert()接受三个参数，第一个参数指定新元素的插入位置，第二个和第三个迭代器承诺书定义了被插入区间
		该区间通常是另一个容器对象的一部分
		这时如果第一个参数是超尾元素，即end(),则可以把区间查到最后一个元素的后面
*/
bool FillReview(Review& rr)
{
	std::cout << "Enter book title(quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	//去掉输入行的其余部分：
	while (std::cin.get() != '\n')
		continue;
	return true;
}
void ShowReview(const Review& rr)
{
	std::cout << rr.rating << "\t" << rr.title<< std::endl;
}

void test02()
{
	using std::cout;
	using std::vector;
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	//push_back()将元素添加到矢量末尾，无需了解元素的数目，只要能够取得足够内存，就可以添加
	int num = books.size();//添加完再求元素数目
	if (num > 0)
	{
		cout << "Thank you.You entered the following:\n"
			<< "Rating\tBool\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);
		cout << "show again:\n"
			<< "Rating\tBook\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books);//复制构造函数
		if (num > 3)
		{
			//移走两个元素：
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "After erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			//插入一个元素：
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "After erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		//交换两个向量：
		books.swap(oldlist);
		cout << "Swapping oldlist with books:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "Nothing entered ,nothing gained\n";
}
/*
	程序员通常要对数组执行很多操作，如搜索、排序和随机排序等。
	矢量模版类没有包含执行这些常见操作的方法。
	STL从更广泛的角度定义了非成员函数来执行这些操作。
	除非类特定算法的效率比通用算法高
	因此vector的成员函数swap()效率比非成员函数swap()高
	但是非成员函数能够交换两个类型不同的容器的内容

	介绍三个代表性STL函数：

	---------for_each()函数：---------
	1.接受三个参数：前两个是定义容器中区间的迭代器，最后一个是指向函数的指针（函数对象）
	2.功能：将被指向的函数应用于容器区间中的各个元素，但是不能修改容器元素的值
	3.使用范围：任何容器类
	for_each()函数可以代替for循环：
	vector<Review>::iterator pr;
	for(pr = books.begin(); pr != books.end();pr++)
		ShowReview(*pr)
	替换为：for_each(books.begin(),books.end(),ShowReview);

	基于范围for循环是为STL设计的：
	for(auto x: books) ShowReview(x);
	这条语句就相当于上面的for_each()
	范围for循环完成两件事：1.声明一个类型与容器存储元素内容相同的变量，利用auto完成
	2.指出容器名称

	---------Random_shuffle()函数：------
	1.接受两个参数：接受两个指定区间的迭代器参数
	2.功能：随机排列该区间的元素
	3.使用范围：容器类允许随机访问
	random_shuffle(books.begin(),books.end());

	---------sort()函数-----------------
	使用范围：容器类允许随机访问
	1.两个版本：
	第一个版本：接受两个定义区间的迭代器参数，并使用为存储在容器中的类型元素定义的<运算符
	对区间的元素进行操作。例如对coolstuff按升序排列：
	vector<int> coolstuff;
	sort(coolstuff.begin(),coolstuff.end());
	第二个版本：接受三个参数：前两个是定义区间的迭代器参数，最后一个是指向要使用的函数的指针
	而不是按照operator<排列

*/