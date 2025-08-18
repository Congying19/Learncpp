/*
	（1）新增的容器：

	C++11 新增了如下容器：array、forward_list、unordered_set 
	以及无序关联容器 unordered_multiset、unordered_map 和 unordered_multimap。

	array 容器一旦声明，其长度就是固定的，它使用静态（栈）内存，而不是动态分配的内存。
			提供它旨在替代数组；array 受到的限制比 vector多，但效率更高。

	容器 list 是一种双向链表，除两端的节点外，每个节点都链接到它前面和后面的节点。
	
	forward_list 是一种单向链表，除最后一个节点外，每个节点都链接到下一个节点。
	相对于 list，它更紧凑，但受到的限制更多。

	与 set和其他关联容器一样，无序关联容器让您能够使用键快速检索数据，
	差别在于关联容器使用的底层数据结构为树，而无序关联容器使用的是哈希表。
*/
/*
	（2）C++11对C++98做的修改

	C++11 对容器类的方法做了三项主要修改。

	首先，新增的右值引用使得能够给容器提供移动语义（参见第18章）。
		  因此，STL现在给容器提供了移动构造函数和移动赋值运算符，这些方法将右值引用作为参数。

    其次，由于新增了模板类 initializer_list（参见第18章），
	因此新增了将 initializer_list 作为参数的 构造函数和赋值运算符。
	这使得可以编写类似于下面的代码：
		vector<int> vi{100, 99, 97, 98};
				vi = {96, 99, 94, 95, 102};

	第三，新增的可变参数模板（variable template）和函数参数包（parameter pack）
	使得可以提供就地创建（emplacement）方法。这意味着什么呢？与移动语义一样，就地创建旨在提高效率。

	请看下面的代码段：
		class Items
		{
			double x;
			double y;
			int m;
		public:
			Items();    // #1
			Items(double xx, double yy, int mm); // #2
			...
		};

		vector<Items> vt(10);
		...
		vt.push_back(Items(8.2, 2.8, 3)); //

		调用 insert() 将导致内存分配函数在 vt 末尾创建一个默认 Items 对象。
		接下来，构造函数 Items() 创建一个临时 Items 对象，该对象被复制到 vt 的开头，然后被删除。

	在 C++11 中，您可以这样做：
	vi.emplace_back(8.2, 2.8, 3);

	方法 emplace_back() 是一个可变参数模板，将一个函数参数包作为参数：
	template <class... Args> void emplace_back(Args&&... args);

	上述三个实参（8.2、2.8 和 3）将被封装到参数 args 中。
	参数 args 被传递给内存分配函数，而内存分配函数将其展开，并使用接受三个参数的 Items 构造函数 (#2)，而不是默认构造函数 (#1)。也就是说，它使用 Items(args...)，这里将展开为 Items(8.2, 2.8, 3)。因此，将在矢量中就地创建所需的对象，而不是创建一个临时对象，再将其复制到矢量中。
	STL 在多个就地创建方法中使用了这种技术。
*/
/*
	（2）大部分容器都有的成员：

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