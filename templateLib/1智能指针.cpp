/*
	问题：使用new分配动态内存时忘记释放内存，如果指针也能像类对象一样，再消亡时，不仅自身
	占据的内存被释放，指向的内存也被释放就好了
	解决：3个智能指针（auto_ptr,unique_ptr和shared_ptr)都定义了类似指针的对象
	1.可以将new获得的地址直接或间接赋给这种对象，其析构函数将使用delete来释放内存。
	就无需记住稍后释放这些内存，在智能指针过期后这些内存将自动释放

	使用：
	1.包含头文件memory

	2.使用通常的模版语法来实例化所需类型的指针
		auto_ptr<double> pd(new double);
		unique_ptr<double> pdu(new double);
		shared_ptr<double> pds(new double);
	new double 是new 返回的指针，指向新分配的内存块。

	3.所有智能指针类都有一个explicit构造函数，即禁止隐式转换，强制显式转换
	shared_ptr<double> pd;
	double *p_reg = new double;
	pd = p_red;//错误
	pd = shared_ptr<double>(p_reg)//正确，强制转换

	4.不能把指向非能存堆的指针赋值给智能指针：
	string vacation("I am alone");
	shared_ptr<string> pvac(&vacation);//错误，程序会把delete用于非内存堆
*/
#include<iostream>
#include<string>
#include<memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s):str(s)
	{
		std::cout << "Object created!\n";
	}
	~Report() { std::cout << "Object deleted!\n"; }
	void comment()const { std::cout << str << "\n"; }
};

//test01()：智能指针的使用语法
void test01();
//test02():测试不同的智能指针
void test02();
//test03():使用shared_ptr代替auto_ptr
void test03();

int main()
{
	//test01();

	//test02();

	test03();
	return 0;
}

void test01()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
}

/*
	为什么要摒弃auto_ptr?
	auto_ptr<string> ps(new string("I am alone"));
	auto_ptr<string> vocation;
	vocation = ps;
	这样会导致一个对象释放两次

	解决方法：
	1.定义深拷贝复制
	2.建立所有权概念，对于特定的对象，只有一个智能指针可以拥有它，只有拥有对象的智能指针的构造函数
	会删除该对象。然后，赋值的操作可以转让所有权，这就是auto_ptr和unique_ptr采取的方法，但是
	unique_ptr更加严格
	3.创建智能更高的指针，跟踪引用特定对象的智能指针数，这成为引用计数。赋值时，计数将加1，指针过期时
	计数将减1.仅当最后一个指针过期时，才调用delete，这就是shared_ptr
	
*/
void test02() {
	using namespace std;
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Eggs"))
	};
	auto_ptr<string> pwin;
	pwin = films[2];//将所有权转让给pwin，films[2]不再引用该字符串，是空指针

	cout << "循环打印：\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << endl;
	cin.get();
}

void test03()
{
	using namespace std;
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("Fowl Balls")),
		shared_ptr<string>(new string("Duck Walks")),
		shared_ptr<string>(new string("Chicken Runs")),
		shared_ptr<string>(new string("Turkey Errors")),
		shared_ptr<string>(new string("Goose Eggs"))
	};
	shared_ptr<string> pwin;
	pwin = films[2];//将所有权转让给pwin，films[2]不再引用该字符串，是空指针

	cout << "循环打印：\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << endl;
	//先创立的后释放，pwin和films[2]指向同一个对象，引用计数从1增至2
	//pwin先调用其析构函数，将引用计数降低到1
	//films[2]再调用析构函数时，引用计数降低到0就会delete
	cin.get();
}

/*
	为什么unique_ptr比auto_ptr好：
	1.
	auto_ptr<string> pwin;
	pwin = films[2];
	//这里编译时不会报错，但是运行时如果再访问films[2]就会报错。因为films[3]不再指向有效的数据
	2.
	unique_ptr<string> pwin;
	pwin = films[2];
	编译时就会直接报错，因为unique_ptr不允许留下悬挂指针（不指向任何有效数据），除非这个悬挂指针
	很快被销毁，即没有机会使用它访问无效数据时，编译不会报错
	例如：
	函数返回unique_ptr时，创建临时变量，返回完毕就立刻销毁
	unique_ptr<string> pu;
	pu = unique_ptr<string>(new string "Yo");
	这种构造函数创建的临时对象也会在转让所有权之后被销毁。

	3.可以使用std::move()完成上述操作，记得将悬挂指针重新赋值
	ps2 = move(ps1);
	ps1 = demo(" and more");

	4.unique_ptr优点：可用于创建动态数组，另外两个都不行
	stdd::unique_ptr<double []> pda(new double(5));
*/

/*
	选择智能指针：
	选择shared_ptr:
	有一个指针数组，并有辅助指针来识别特定元素
	两个对象包含都指向第三个对象的指针
	STL容器包含指针

	选择unique_ptr:
	不需要多个指针指向同一个对象
	函数使用new分配内存，并返回指向该内存的指针，将返回类型声明为unique_ptr

	unique_ptr为右值时可以赋给shared_ptr
*/