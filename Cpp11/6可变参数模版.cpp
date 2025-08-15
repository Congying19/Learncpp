/*
	可变参数模板（variable template）让您能够创建这样的模板函数和模板类，即可接受可变数量的参数。
	例如，假设要编写一个函数，它可接受任意数量的参数，参数的类型只需是cout 能够显示的即可，
	并将参数显示为用逗号分隔的列表。请看下面的代码：

		int n = 14;
		double x = 2.71828;
		std::string mr = "Mr. String objects!";
		show_list(n, x);
		show_list(x*x, '1', 7, mr);

		这里的目标是，定义 show_list()，让上述代码能够通过编译并生成如下输出：

		14, 2.71828
		7.38905, 1, 7, Mr. String objects!

	要创建可变参数模板，需要理解几个要点：
	● 模板参数包（parameter pack）；
	● 函数参数包；
	● 展开（unpack）参数包；
	● 递归。
*/
/*
	（1）模版和模版参数包

	为理解参数包的工作原理，首先来看一个简单的模板函数，它显示一个只有一项的列表：

	template<typename T> 
	void show_list0(T value) 
	{ 
		std::cout << value << ", ";
	}

	在上述定义中，有两个参数列表。
	模板参数列表只包含 T，而函数参数列表只包含 value。

	下面的函数调用将模板参数列表中的 T 设置为 double，将函数参数列表中的 value 设置为 2.15：
	show_list0(2.15);

	------------------------------------------------------

	C++11 提供了一个用省略号表示的元运算符（meta-operator），
	让您能够声明  表示模板参数包的标识符，模板参数包基本上是一个类型列表。
	同样，它还让您能够声明  表示函数参数包的标识符，而函数参数包基本上是一个值列表。
	其语法如下：

	template<typename... Args> // Args is a template parameter pack模版参数包
	void show_list1(Args... args) // args is a function parameter pack函数参数包
	{
	...
	}

	其中，Args 是一个模板参数包，而 args 是一个函数参数包。
	与其他参数名一样，可将这些参数包的名称指定为任何符合 C++标识符规则的名称。
	Args 和 T 的差别在于，T 与一种类型匹配，而 Args 与任意数量（包括零）的类型匹配。

	请看下面的函数调用：
	show_list1('S', 80, "sweet", 4.5);
	在这种情况下，参数包 Args 包含与函数调用中的参数匹配的类型：char、int、const char * 和 double。

	同样，下面的代码指出 args 的类型为 Args：
	void show_list1(Args... args) // args is a function parameter pack
	更准确地说，这意味着函数参数包 args 包含的值列表与模板参数包 Args 包含的类型列表匹配
	——无论是类型还是数量。在上面的示例中，args 包含值‘S’、80、“sweet”和 4.5。

	这样，可变参数模板 show_list1() 与下面的函数调用都匹配：

	show_list1();
	show_list1(99);
	show_list1(88.5, "cat");
	show_list1(2,4,6,8, "who do we", std::string("appreciate"));

	就最后一个函数调用而言，模板参数包 Args 包含类型 int、int、int、const char * 和 std::string，
	而函数参数包 args 包含值 2、4、6、8、“who do we”和 std::string("appreciate")。
*/

/*
	（2）展开参数包

	但函数如何访问这些包的内容呢？索引功能在这里不适用，即您不能使用 Args[2]来访问包中的第三个类型。
	相反，可将省略号放在函数参数包名的右边，将参数包展开。
	
	例如，请看下述有缺陷的代码：

	template<typename... Args> // Args is a template parameter pack
	void show_list1(Args... args) // args is a function parameter pack
	{
		show_list1(args...); // passes unpacked args to show_list1()
	}
	这是什么意思呢？为何说它存在缺陷？假设有如下函数调用：
			show_list1(5,'L',0.5);
	这将把 5、'L'和 0.5 封装到 args 中。在该函数内部，下面的调用：
			show_list1(args...);
	将展开成如下所示：
			show_list1(5,'L',0.5);
	也就是说，args 被替换为三个存储在 args 中的值。
	因此，表示法 args...展开为一个函数参数列表。
	不幸的是，该函数调用与原始函数调用相同，因此它将使用相同的参数不断调用自己，导致无限递归（这存在缺陷）。
*/
/*
	（3）在可变参数模版函数中使用递归：

	虽然前面的递归让 show_list1() 成为有用函数的希望破灭，但正确使用递归为访问参数包的内容提供了
	解决方案。
	
	这里的核心理念是，将函数参数包展开，对列表中的第一项进行处理，再将余下的内容传递给
	递归调用，以此类推，直到列表为空。
	
	与常规递归一样，确保递归将终止很重要。这里的技巧是将模板头改为如下所示：
		template<typename T, typename... Args>
		void show_list3(T value, Args... args)

	对于上述定义，show_list3()的第一个实参决定了T 和 value 的值，而其他实参决定了 Args 和args 的值。
	这让函数能够对 value 进行处理，如显示它。
	然后，可递归调用 show_list3()，并以 args...的方式将其他实参传递给它。
	每次递归调用都将显示一个值，并传递缩短了的列表，直到列表为空为止。

	
	演示：
	//variadicl.cpp -- using recursion to unpack a parameter pack
	#include <iostream>
	#include <string>
	// definition for 0 parameters -- terminating call
	void show_list3() {}

	// definition for 1 or more parameters
	template<typename T, typename... Args>
	void show_list3(T value, Args... args)
	{
		std::cout << value << ", ";
		show_list3(args...);
	}

	int main()
	{
		int n = 14;
		double x = 2.71828;
		std::string mr = "Mr. String objects!";
		show_list3(n, x);
		show_list3(x*x, '!!', 7, mr);
		return 0;
	}

	1. 程序说明

	请看下面的函数调用：
	show_list3(x*x, '!', 7, mr);
	第一个实参导致 T 为 double，value 为 x*x。
	其他三种类型（char、int 和 std::string）将放入 Args 包中，
	而其他三个值（‘!’、7 和 mr）将放入 args 包中。

	接下来，函数 show_list3() 使用 cout 显示 value（大约为 7.38905）和字符串"，"。


	接下来是下面的调用：
	show_list3(args...);

	考虑到 args...的展开作用，这与如下代码等价：
	show_list3('!', 7, mr);

	前面说过，列表将每次减少一项。
	这次 T 和 value 分别为 char 和 ‘!’，
	而余下的两种类型和两个值分别被包装到 Args 和 args 中，下次递归调用将处理这些缩小了的包。
	最后，当 args 为空时，将调用不接受任何参数的 show_list3()，导致处理结束。

	程序清单 18.9 中两个函数调用的输出如下：
	14, 2.71828, 7.38905, !, 7, Mr. String objects!,

2. 改进
	可对 show_list3() 做两方面的改进。当前，该函数在列表的每项后面显示一个逗号，
	但如果能省去最后一项后面的逗号就好了。

	i.为此，可添加一个处理一项的模板，并让其行为与通用模板稍有不同：
	// definition for 1 parameter
	template<typename T>
	void show_list3(T value)
	{
		std::cout << value << '\n';
	}

	这样，当 args 包缩短到只有一项时，将调用这个版本，而它打印换行符而不是逗号。
	另外，由于没有递归调用 show_list3()，它也将终止递归。


	ii.另一个可改进的地方是，当前的版本按值传递一切。
	对于这里使用的简单类型来说，这没问题，但对于 cout 可打印的大型类来说，这样做的效率很低。
	在可变参数模板中，可指定展开模式（pattern）。为此，可将下述代码：

	show_list3(Args... args);

	替换为如下代码：
	show_list3(const Args&... args);

	这将对每个函数参数应用模式 const &。
	这样，最后分析的参数将不是 std::string mr，而是 const std::string& mr。

	《示例6》
*/