/*
* （1）

	所有容器都定义了表 G.1 列出的类型。
	在这个表中，x 为容器类型，如 vector<int>；T 为存储在容器中的类型，如 int。
	表 G.1 中的示例阐明了含义

	表 G.1				 为所有容器定义的类型
	x::value-type        T, 元素类型
	x::reference         T &
	x::const_reference   const T &
	x::iterator          指向 T 的迭代器类型，行为与 T*相似
	x::const_iterator    指向 const T 的迭代器类型，行为与 const T *相似
	x::different_type    用于表示两个迭代器之间距离的符号整型，如两个指针的差
	x::size_type         无符号整型 size_type 可以表示数据对象的长度、元素数目和下标

	类定义使用 typedef 定义这些成员。可以使用这些类型来声明适当的变量。

	例如，下面的代码使用返回的方式，将由 string 对象组成的矢量中的第一个 "bonus" 替换为 "bogus"，
	以演示如何使用成员类型来声明变量。

		using namespace std;
		vector<string> input;
		string temp;
		while (cin >> temp && temp != "quit")
			input.push_back(temp);
		vector<string>::iterator want=
				find(input.begin(), input.end(), string("bonus"));
		if (want != input.end())
		{
			vector<string>::reference r = *want;
			r = "bogus";
		}

	上述代码使 r 成为一个指向（want 指向的）input 中元素的引用。
	同样，继续前面的例子，可以编写下面这样的代码：

	vector<string>::value_type s1 = input[0]; // s1 is type string
	vector<string>::reference s2 = input[1]; // s2 is type string &
	这将导致 s1 为一个新 string 对象，它是 input[0] 的拷贝；而 s2 为指向 input[1] 的引用。

	在这个例子中，由于已经知道模板是基于 string 类型的，因此编写下面的等效代码将更简单：
	string s1 = input[0]; // s1 is type string
	string & s2 = input[1]; // s2 is type string &

-----------------------------------------------------------------------------------------------

	然而，还可以在更通用的代码中使用表 G1 中较精致（其中容器和元素的类型是通用的）的类型。

	例如，假设希望 min() 函数将一个指向容器的引用作为参数，并返回容器中最小的项目。

	这假设为用于实例化模板的值类型定义了<运算符，
		而不想使用 STL_min_element() 算法，这种算法使用迭代器接口。

	由于参数可能是 vector<int>, list<string> 或 deque<double>，
		因此需要使用带模板参数（如 Bag）的模板来表示容器
	（也就是说，Bag 是一个模板类型，可能被实例化为 vector<int>, list<string> 或其他一些容器类型）。

	因此，函数的参数类型应为 const Bag & b。
	返回类型是什么呢？应为容器的值类型，即 Bag::value_type。
	然而，在这种情况下，Bag 只是一个模板参数，编译器无法知道 value_type 成员实际上是一种类型。
	但可以使用 typename 关键字来指出，类成员是 typedef：

		vector<string>::value_type st; // vector<string> a defined class
		typename Bag::value_type m; // Bag an as yet undefined type

	对于上述第一个定义，编译器能够访问 vector 模板定义，
	该定义指出，value_type 是一个 typedef：

	对于第二个定义，typename 关键字指出，无论 Bag 将会是什么，Bag::value_type 都将是类型的名称。

	这些考虑因素导致了下面的定义：
		template<typename Bag>
		typename Bag::value_type min(const Bag & b)
		{
			typename Bag::const_iterator it;
			typename Bag::value_type m = *b.begin();
			for (it = b.begin(); it != b.end(); ++it)
				if (*it < m)
					m = *it;
			return m;
		}

	这样，便可以这样使用该模板函数：

	vector<int> temperature;
	// input temperature values into the vector
	int coldest = min(temperatures);

temperatures 参数将使得 Bag 被谓词为 vector<int>,
而 typename Bag::value-type 被谓词为 vector<int>::value_type, 进而为 int。

————————————————————————————————————————————————————

（2）

	所有的容器都还可以包含表 G2 列出的成员函数或操作。
	其中，X 是容器类型，如 vector<int>；而 T 是存储在容器中的类型，如 int。
	另外，a 和 b 是类型为 X 的值；
	u 是标识符；
	r 是类型为 X 的非 const 值；
	rv 是类型为 X 的非 const 右值，而移动操作是 C++11 新增的。

	表 G.2      为所有容器定义的操作
	X u;        // 创建一个名为 u 的空对象
	X();        // 创建一个空对象
	X(a);       // 创建对象 x 的拷贝
	X u(a);     // u 是 a 的拷贝（复制构造函数）
	X u = a;    // u 是 a 的拷贝（复制构造函数）
	r = a;      // r 等于 a 的值（复制赋值）
	X u(rv);    // u 等于 rv 的原始值（移动构造函数）
	X u = rv;   // u 等于 rv 的原始值（移动构造函数）
	a = rv;     // u 等于 rv 的原始值（移动赋值）
	(&a)->~X(); // 对 a 的每个元素执行析构函数
	begin();    // 返回一个指向第一个元素的迭代器
	end();      // 返回一个指向超尾的迭代器
	cbegin();   // 返回一个指向第一个元素的 const 迭代器
	cend();     // 返回一个指向超尾的 const 迭代器
	size();     // 返回元素数目
	max_size(); // 返回容器的最大可能长度
	empty();    // 如果容器为空，则返回 true
	swap();     // 交换两个容器的内容
	==;         // 如果两个容器的长度相同，包含的元素相同且元素排列的顺序相同，则返回 true
	!=;         // al=b 返回!(a==b)

	————————————————————————————————————————————-——
	使用双向或随机迭代器的容器（vector、list、deque、array、set 和 map）是可反转的，
	它们提供了表 G.3 所示的方法。
	// 表 G.3 为可反转容器定义的类型和操作
	X::reverse_iterator;        // 指向类型 T 的反向迭代器
	X::const_reverse_iterator;  // 指向类型 T 的 const 反向迭代器
	a.rbegin();                 // 返回一个反向迭代器，指向 a 的超尾
	a.rend();                   // 返回一个指向 a 的开头的反向迭代器
	a.crbegin();                // 返回一个 const 反向迭代器，指向 a 的超尾
	a.crend();                  // 返回一个指向 a 的开头的 const 反向迭代器

	————————————————————————————————————————————————
	无序集合（set）和无序映射（map）无需支持表 G.4 所示的可选容器操作，但其他容器必须支持
	// 表 G.4 可选的容器操作
	<;                          // 如果 a 按词典顺序排在 b 之前，则 a<b 返回 true
	>;                          // a>b 返回 b<a
	<=;                         // a<=b 返回 !(a>b)
	>=;                         // a>=b 返回 !(a<b)

	容器的>运算符假设已经为值类型定义了运算符。词典比较是一种广义的按字母顺序排序，它逐元素
	地比较两个容器，直到两个容器中对应的元素相同时为止。
	在这种情况下，元素对的顺序将决定容器的顺序。
	例如，如果两个容器的前 10 个元素都相同，但第一个容器的第 11 个元素比第二个容器的第 11 个元素小，
	则第一个容器将排在第二个容器之前。
	如果两个容器中的元素一直相同，直到其中一个容器中的元素用完，则较短的容器将排在较长的容器之前。
*/