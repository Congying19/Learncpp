/*
	（1）特殊的成员函数 ：默认构造函数，复制构造函数，复制赋值运算符 ，析构函数
						  移动构造函数，移动赋值运算符
		一般情况下，编译器会提供默认的以上函数。但是，如果存在复制或者移动，就不会提供另外一个

*/
/*
	（2）默认的方法和禁用的方法

	C++11可以更好地控制要使用的方法。假定要使用某个默认的函数，而这个函数因为其他原因不会自动创建。
	例如，提供了移动构造函数，则编译器不会自动创建默认的构造函数，复制构造函数。
	这种情况下，可以使用default显式地声明这些方法的默认版本：
	Someclass() = default;	//使用默认构造函数的默认版本
	Someclass( const Someclass & ) = default;	//使用复制构造函数的默认版本
	
	关键字delete可以禁止编译器使用特定的方法。例如要禁止复制对象，可以禁止复制构造函数和复制赋值运算符
	Someclass( const Someclass &) = delete;
	Someclass & operator= (const Someclass & ) = delete;

	default只能用于6个特殊成员函数，delete可以用于所有成员函数

	例如：
	void redo( double );
	void redo( int ) = delete;
	这时redo(5)就不允许，即使5能被提升为5.0
*/
/*
	（3）委托构造函数
	如果给类提供多个构造函数，可能重复编写相同的代码。
	C++11允许在一个构造函数的定义中使用另一个构造函数。这被称为委托。
	class Notes {
	int k;
	double x;
	std::string st;
public:
	Notes();
	Notes(int);
	Notes(int, double);
	Notes(int, double, std::string);
};

Notes::Notes(int kk, double xx, std::string stt) : k(kk),
	x(xx), st(stt) {/do stuff/}
Notes::Notes() : Notes(0, 0.01, "Oh") {/ do other stuff/ }
Notes::Notes(int kk) : Notes(kk, 0.01, "Ah") {/do yet other stuff/ }
Notes::Notes(int kk, double xx) : Notes(kk, xx, "Uh") {/ ditto/ }
*/

/*
	（4）继承构造函数：C++11提供了一种让派生类能够继承基类构造函数的机制
	经常用于构造函数：
		class BS
	{
		int q;
		double w;
	public:
		BS() : q(0), w(0) {}
		BS(int k) : q(k), w(100) {}
		BS(double x) : q(-1), w(x) {}
		BS(int k, double x) : q(k), w(x) {}
		void Show() const {std::cout << q <<", " << w << '\n';}
	};

	class DR : public BS
	{
		short j;
	public:
		using BS::BS;
		DR() : j(-100) {}
		// DR needs its own default constructor
		DR(double x) : BS(2*x), j(int(x)) {}
		DR(int i) : j(-2), BS(i, 0.5*i) {}
		void Show() const {std::cout << j << ", "; BS::Show();}
	};

	int main()
	{
		DR o1;    // use DR()
		DR o2(18.81);    // use DR(double) instead of BS(double)
		DR o3(10, 1.8); // use BS(int, double)
		...
	}
	由于没有构造函数DR(int,double)，因此将创建DR对象o3时，使用继承而来的BS(int ,double);
*/

/*
	（5）管理虚方法：override 和 final

	虚方法对实现多态类层次结构很重要，让基类引用或指针能够根据指向的对象类型调用相应的方法，
	但虚方法也带来了一些编程陷阱。例如，假设基类声明了一个虚方法，而您决定在派生类中提供不同的版本，
	这将覆盖旧版本。但正如第13章讨论的，如果特征标不匹配，将隐藏而不是覆盖旧版本：

		class Action
		{
			int a;
		public:
			Action(int i = 0) : a(i) {}
			int val() const {return a;}
			virtual void f(char ch) const { std::cout << val() << ch << "\n"; }
		};
		class Bingo : public Action
		{
		public:
			Bingo(int i = 0) : Action(i) {}
			virtual void f(char * ch) const { std::cout << val() << ch << "\n"; }
		};

		由于类Bingo定义的是f(char * ch)而不是f(char ch)，将对Bingo对象隐藏f(char ch)，
		这导致程序不能使用类似于下面的代码：

		Bingo b(10);
		b.f('@'); // works for Action object, fails for Bingo object

		在C++11中，可使用虚说明符override指出您要覆盖一个虚函数：
		将其放在参数列表后面。如果声明与基类方法不匹配，编译器将视为错误。
		因此，下面的Bingo::f()版本将生成一条编译错误消息：

		virtual void f(char * ch) const override { std::cout << val()
			<< ch << "\n"; }

	final说明符则表示禁止派生类覆盖特定的虚方法。

*/