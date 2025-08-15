/*
	（1）新类型：
		i.C++11新增了类型long long 和unsigned long long ，支持64位的整型
		ii.新增char16_t ， char32_t
*/
/*
	（2）统一的初始化：C++11扩大了 用大括号括起来 的 初始化列表 的适用范围，使用时，可以添加等号也可以
						不添加。
		可用于所有的内置类型：
			整型：int x = {5};
			浮点型：double y {2.75};
			数组：short quar[5] {2,34,5,6,1};
		用于new表达式：
			int * ar = new int [4] {2,3,5,6};
		用于用户定义的类：
			class Stump
			{
			private:
				int roots;
				double weight;
			public:
				Stump(int r , double w):roots(r),weight(w){}
			}
			可以使用大括号创建对象：Stump s1{2,34.3};
			可以使用圆括号创建对象：Stump s2(2,34.2);

		1.缩窄：初始化列表语法可以防止缩窄，即禁止将数值赋给无法存储它的数值变量。
				char c1 = 1.34e34;		//不会报错
				char c1 {1.34e34};		//会报错compile-timer error
				如果较窄类型能够存储，则允许转换为较窄类型：
				char c1 {66};		//int to char , in range ,allowed
				允许转换为较宽的类型：
				double c2 {66};		//int to double ,allowed

		2.std::initializer_list ：是一个模版类，包含在头文件initializer_list，包含begin()和end()
								可以将其用于构造函数的参数。
			STL提供了将initializer_list作为参数的构造函数，则允许：
					vector<int> a1{3,34,5};		//将容器里三个元素设置为3,34,5
			可以将initializer_list作为常规函数的参数：
					double sum(std::initializer_list<double> il);

					调用：sum({2,4,5,6});

*/
/*
	（3）声明：C++11提供了多种简化声明的功能，尤其在使用模版时。

	1.auto:	auto 关键字用于实现自动类型推断，要求进行显式初始化，
			让编译器能够将变量类型设置为初始值的类型。
		例如：
			auto maton = 112;		// maton is type int
			auto pt = &maton ;		// pt is type int*
			double fm(double ,int);
			auto pf = fm;			//pf is type double(*)(double,int)
		简化模版声明：
		for(std::initializer_list<double>::iterator p = il.begin();p!=il.end();p++)
		简化为：
		for(auto p = il.begin() ; p!= il.end(); p++);

	
	2.decltype ：将变量类型声明为表达式指定的类型
		decltype(x) y;	//y的类型与x相同，其中x是表达式

		定义模版时使用：因为只有模版被实例化才确定类型
		template<typename T , typename U>
		void ef(T t, U u)
		{
			decltype(T*U) tu;
			...
		}


	3.返回类型后置：在函数名和参数列表后面指定返回类型，而不是前面
		double f1(double , int);
		auto f2(double , int ) -> double;
		用于使用decltype来指定模版函数的返回值：
		auto eff(T t ,U u) -> decltype (T*U);


	4.模版别名：using =
	对于冗长或复杂的标识符，如果能够创建其别名将很方便。
		以前：用typedef：typedef std::vector<std::string>::iterator itType
		现在：用using：using itType = std::vector<std::string>::iterator itType
		区别：using可以用于模版部分具体化（只具体化了一部分，仍是一个模版），typedef不行
			例如：
			templating<typename T>
			 using arr12 = std::array<T,12>;	//将参数int设置为12，arr12是一个模版的别名
			 则arr12<double> 表示 std::array<double , 12>


	5.nullptr:
		空指针是不会指向有效数据的指针。
		以前，使用0 NULL表示空指针，但是存在问题，0既可以表示空指针，又可以表示整型常量。
		现在，nullptr用于表示空指针，它是指针类型，不能转换为整型类型。
		C++11仍然允许用0表示空指针，因此表达式nullptr == 0 为true。
		但是不能把nullptr当成0使用
*/
/*
	（4）智能指针：C++11摒弃了auto_ptr，使用unique_ptr,shared_ptr,weak_ptr

*/
/*
	（5）异常规范方面的修改
	摒弃了异常规范：
		void f501(int) throw(bad_dog);
*/
/*
	（6）作用域内枚举：
	传统枚举提供了一种创建名称常量的方式，但是类型检查相当低级。而且枚举名的作用域为枚举定义所属的
		作用域，这意味着如果在同一个作用域内定义的两个枚举的成员不能同名。
	C++11新增一种枚举：使用class和struct定义。
		enum class New1 {never, sometimes};
		新枚举要求进行显式限定，以免发生名称冲突。因此引用特定枚举时，需要使用New1::never
*/
/*
	（7）对类的修改

	1.显式转换运算符：C++引入关键字explicit（显式地），以禁止单参数构造函数导致的自动转换
	例如：
		class Plebe 
		{
			Plebe(int) ;//允许int to Plebe的自动转换
			explicit Plebe(double);	//禁止double to Plebe的自动转换，必须是显式转换
		}
		Plebe a,b;
		a = 5;	//allowed
		b = 0.5;//not allowed
		b = Plebe(0.5);	//allowed

	2.类内成员初始化：可以在类定义中初始化成员。
	例如：
		class Session
		{
			int mem1 = 10;	//可以使用等号
			double mem2 {123.42};//也可以使用大括号，不能使用圆括号
		}
		其结果与构造函数提供初始化列表一样。

*/
/*
	（8）模版和STL方面的修改

	1.基于范围的for循环：
		double prices[5] = {2.44,3.44,2.11,53.33,55.333};
		遍历：
		for(auto x : prices) std::cout<<x<<std::endl;
		遍历并修改：
		for(auto &x : prices) x = std::rand();


*/

/*
	（9）右值引用：
	传统的C++引用（称为左值引用）使得标识符关联到左值。
		左值是一个表示数据的表达式，程序可以获取其地址。
	C++11新增了右值引用，用&&表示。
		右值引用可以关联到右值，即可出现在赋值表达式的右边，但不能对其应用地址运算符的值。
		右值包括字面常量、诸如x+y等表达式以及返回值的函数（该函数返回的不是引用）
		将右值关联到右值引用（int && r1 = 10）导致右值被存储到特定的位置，且可以获取该位置的地址。
		10与特定的地址关联，可以通过r1（右值引用）来访问数据。
*/