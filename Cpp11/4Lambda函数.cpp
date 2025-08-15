/*
	（1）比较函数指针、函数符和Lambda函数
	来看一个示例，它使用三种方法给 STL 算法传递信息：函数指针、函数符和 lambda。
	出于方便的考虑，将这三种形式通称为函数对象，以免不断地重复"函数指针、函数符或 lambda"。
	假设您要生成一个随机整数列表，并判断其中多少个整数可被 3 整除，多个少整数可被 13 整除。

1.使用函数指针：使用 vector<int>存储数字，并使用 STL 算法 generate() 在其中填充随机数：

	#include <vector>
	#include <algorithm>
	#include <math>

	...
	std::vector<int> numbers(1000);
	std::generate(vector.begin(), vector.end(), std::rand);

	函数 generate() 接受一个区间（由前两个参数指定），并将每个元素设置为第三个参数返回的值，
	而第三个参数是一个不接受任何参数的函数对象。
	在上述示例中，该函数对象是一个指向标准函数 rand() 的指针。

	通过使用算法 count_if()，很容易计算出有多少个元素可被 3 整除。与
	函数 generate() 一样，前两个参数应指定区间，而第三个参数应是一个返回 true 或 false 的函数对象。
	函数 count_if() 计算这样的元素数，即它使得指定的函数对象返回 true。为判断元素能否被 3 整除，
	可使用下面的函数定义：

	bool f3(int x) {return x % 3 == 0;}

	同样，为判断元素能否被 13 整除，可使用下面的函数定义：

	bool f13(int x) {return x % 13 == 0;}

	定义上述函数后，便可计算复合条件的元素数了，如下所示：
	int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";


2.使用函数符：
第16章介绍过，函数符是一个类对象，并非只能像函数名那样使用它，这要归功于类方法operator()()。
就这个示例而言，函数符的优点之一是，可使用同一个函数符来完成这两项计数任务。下面是一种可能的定义：

	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) : dv(d) {}
		bool operator()(int x) {return x % dv == 0;}
	};

	这为何可行呢？因为可使用构造函数创建存储特定整数值的f_mod对象：
	f_mod obj(3); // f_mod.dv set to 3

	而这个对象可使用方法operator()来返回一个bool值：
	bool is_div_by_3 = obj(7); // same as obj.operator()(7)

	构造函数本身可用作诸如count_if()等函数的参数：
	count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
	这里f_mod(3)整体就相当于一个函数名，即可以f_mod(3)(7)

	参数 f_mod(3)创建一个对象，它存储了值 3；而 count_if()使用该对象来调用 operator()(), 
	并将参数 x 设置为 numbers 的一个元素。
	要计算有多少个数字可被 13（而不是 3）整除，只需将第三个参数设置为 f_mod(13)。


3.使用Lambda函数：
名称 lambda 来自 lambda calculus（λ 演算）——一种定义和应用函数的数学系统。
这个系统让您能够使用匿名函数——即无需给函数命名。
在 C++11 中，对于接受函数指针或函数符的函数，可使用匿名函数定义（lambda）作为其参数。
	与前述函数 f3()对应的 lambda 如下：

	[](int x) {return x % 3 == 0;}

	这与 B()的函数定义很像：

	bool f3(int x) {return x % 3 == 0;}

	差别有两个：
		i.使用[]替代了函数名（这就是匿名的由来）；
		ii.没有声明返回类型。返回类型相当于使用 decltype 根据返回值推断得到的，这里为 bool。
		如果 lambda 不包含返回语句，推断出的返回类型将为 void。

	就这个示例而言，您将以如下方式使用该 lambda：

	count3 = std::count_if(numbers.begin(), numbers.end(),
	[](int x) {return x % 3 == 0;});
	也就是说，使用整个 lambda 表达式替换函数指针或函数符构造函数。

	仅当 lambda 表达式完全由一条返回语句组成时，自动类型推断才管用；否则，需要使用新增的返回类型后置语法：
	[](double x) -> double {int y = x; return x - y;} // return type is double

	《示例3》
*/

/*
	（2）为什么使用lambda?

	1.距离：lambda的定义和使用是在同一个地方进行的，不用翻阅多页的源代码

	2.简洁：
		从简洁的角度看，函数符代码比函数和 lambda 代码更繁琐。
		函数和 lambda 的简洁程度相当，一个显而易见的例外是，需要使用同一个 lambda 两次：

		count1 = std::count_if(n1.begin(), n1.end(),
			[](int x) {return x % 3 == 0;});

		count2 = std::count_if(n2.begin(), n2.end(),
			[](int x) {return x % 3 == 0;});

		但并非必须编写 lambda 两次，而可给 lambda 指定一个名称，并使用该名称两次：

		auto mod3 = [](int x) {return x % 3 == 0;}; // mod3 a name for the lambda
		count1 = std::count_if(n1.begin(), n1.end(), mod3);
		count2 = std::count_if(n2.begin(), n2.end(), mod3);

		您甚至可以像使用常规函数那样使用有名称的 lambda：
		bool result = mod3(z); // result is true if z % 3 == 0

	3.效率：函数指针不能内联，函数符和lambda方法可以

	4.功能：
		最后，lambda 有一些额外的功能。
		具体地说，lambda 可访问作用域内的任何动态变量；
		要捕获要使用的变量，可将其名称放在中括号内。
		i.如果只指定了变量名，如[z]，将按值访问变量；
		ii.如果在名称前加上&，如[&count]，将按引用访问变量。[&]让您能够按引用访问所有动态变量，
		iii.而[=]让您能够按值访问所有动态变量。
		iiii.还可混合使用这两种方式，例如，[ted, &ed]让您能够按值访问 ted 以及按引用访问 ed，
			[&, ted]让您能够按值访问 ted 以及按引用访问其他所有动态变量，
			[=, &ed]让您能够按引用访问 ed 以及按值访问其他所有动态变量。
		
	在程序清单 18.4 中，可将下述代码：

	int count13;
	...
	count13 = std::count_if(numbers.begin(), numbers.end(),
		[](int x) { return x % 13 == 0; } );

	替换为如下代码：

	int count13 = 0;
	std::for_each(numbers.begin(), numbers.end(),
		[&count13](int x) { count13 += x % 13 == 0; } );

	[&count13]让 lambda 能够在其他代码中使用 count13。
	由于 count13 是按引用捕获的，因此在 lambda 对 count13 所做的任何修改都将影响原始 count13。
	如果 x 能被 13 整除，则表达式 x % 13 == 0 将为 true，添加到 count13 中时，true 将被转换为 1。
	同样，false 将被转换为 0。
	因此，for_each()将 lambda 应用于 numbers 的每个元素后，count13 将为能被 13 整除的元素数。

	通过利用这种技术，可使用一个 lambda 表达式计算可被 3 整除的元素数和可被 13 整除的元素数：
	int count3 = 0;
	int count13 = 0;
	std::for_each(numbers.begin(), numbers.end(),
		[&](int x) { count3 += x % 3 == 0; count13 += x % 13 == 0; } );

	《示例4》
*/