/*
	STL是一种泛型编程
	面向对象编程关注的是编程的数据方面
	泛型编程关注的是算法
*/
/*
	为什么使用迭代器：
	模版使得算法独立于存储的数据类型
	迭代器使得算法独立于使用的容器类型

	首先在一个double数组中搜索特定值的函数：
	double * find_ar(double * ar, int n, const double & val)
	{
		for( int i = 0 ; i < n ;i ++)
			if(ar[i] == val)
				return &ar[i];
		return 0;
	}
	使用模版可以将该算法推广到包含==运算符的、任意类型的数据
	但是这种算法还是与一种特定的数据结构（数组）关联

	再看看链表
	Node* find_ll(Node* head, double & val)
	{
		Node* start;
		for (start = head ; start != 0 ; start = start ->p_next)
			if ( start->item == val )
				return start;
		return 0;
	}
	这种算法也是与特定的数据结构——链表关联

	算法细节上两个find不同：一个利用数组索引来遍历元素，一个将start重置为start->p_next
	但是广义上来讲，两种算法是相同的：将值依次与容器中每个值进行比较
	
	泛型编程就旨在使用同一个find来处理数组、链表等等
	模版提供了存储在容器中的数据类型的通用表示
	而迭代器提供了遍历容器中的值的通用表示

	要实现find函数，迭代器应该具备哪些特征：
	1.能够进行解引用：如果p是一个迭代器，则应对*p进行定义
	2.能够将一个迭代器赋给另一个：如果p,q都是迭代器，应该对p=q进行定义
	3.能够将两个迭代器进行比较，看是否相等：对p==q和p!=q进行定义
	4.能够遍历所有元素：对p++和++p定义

	class iterator
	{
		Node* pt;
	public:
		iterator(): pt(0) {}
		iterator(Node * pn) : pt(pn) {}
		double operator* () {return pt->item;}
		iterator& operator++()//前置++，使用之后的值
		{
			pt = pt->p_next;
			return *this;
		}
		interator operator++(int)//int仅仅是占位符，表示后置++,使用当前的值
		{
			iteartor tmp = *this;
			pt = pt->p_next;
			return tmp;
		}
		...
	}
	STL遵循上面的方法。
	首先，每个容器类定义了相应的迭代器类型。对于其中某个类，迭代器可能是
		指针；对于另一个类，则可能是对象。
	其次，每个容器类都有一个超尾标记，当迭代器递增到超越容器的最后一个值后，
		这个值将被赋给迭代器。每个容器类都有begin()和end()方法，它们分别返回
		一个指向容器第一个元素和超尾位置的迭代器
	
	使用时最好避免直接使用迭代器（声明迭代器，再解引用使用值），应尽可能使用STL函数
	例如for_each()，只传入参数，来处理细节。也可以使用范围for循环
			
*/
/*
	----------迭代器类型----------
	STL定义了5种迭代器类型
	输入迭代器
	输出迭代器
	正向迭代器
	双向迭代器
	随机访问迭代器

	例如find()原型与下面类似：
	template<class InputIterator , class T>
	InputIterator find(InputIterator first, InputIterator last, const T& value)

	对于5种迭代器都可以执行解除引用操作，也可以进行比较。

	1.输入迭代器：
	术语“输入”是从程序角度说的。来自容器的信息被称为输入。
	对输入迭代器解除引用可以使程序读取容器的值。不一定可以修改程序的值
	输入迭代器是单向迭代器，可以递增，不能倒退
	2.输出迭代器：
	对输出迭代器解除引用能让程序修改容器值，但不能读取程序的值。
	输出迭代器也是单向迭代器。
	3.正向迭代器：
	和输入迭代器、输出迭代器相似，只能用++运算符来遍历容器，每次沿着容器向前移动一个元素
	与输入迭代器和输出迭代器不同的是，它总是按照相同的顺序遍历一系列值
	而且将正向迭代器递增后，仍然可以对前面的迭代器值解除引用
	正向迭代器既可以读取也能修改
	4.双向迭代器：
	有正向迭代器所有特性，且支持前缀和后缀递减运算符
	5.随机访问迭代器：
	有些算法（如二分检索）要求能够直接跳到容器中的任何一个元素，这就叫随机访问
	具有双向迭代器的所有特性，同时添加了支持随机访问的操作（如指针增加运算）
*/
/*
	正向迭代器是一些列要求，而不是类型。所设计的迭代器可以满足这种要求，常规指针也可以

	STL文献中
	---概念---用来描述一系列的要求，例如输出迭代器概念、正向迭代器概念等等
	---改进---用来描述概念上的继承，例如双向迭代器是对正向迭代器的改进
	---模型---用来称为概念的具体实现，指向int的常规指针也是一种随机访问迭代器模型

	1.将指针用作迭代器：
	迭代器是广义指针，而指针满足所有的迭代器要求。
	迭代器是STL算法的接口，而指针是迭代器，因此STL算法可以使用指针来对
	基于指针的非STL容器进行操作。例如，将STL算法用于数组：
	const int SIZE = 100;
	double Receipts[SIZE];
	sort(Receipts,Receipts+SIZE);
	C++支持将超尾概念用于数组
	同样，可以将STL算法用于自己设计的类，只要提供适当的迭代器和超尾指示器即可。

	2.STL提供了一些预定义迭代器。
	copy()算法可以将数据从一个容器复制到另一个容器中。
	int casts[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> dice[10];
	copy(casts, casts+10 , dice.begin());
	前两个参数表示要复制的范围。最后一个参数表示要将第一个元素复制到什么位置
	前两个必须是输入迭代器，最后一个必须是输出迭代器

	1111------ostream_iterator--------

	现在要将信息复制到显示器上。STL为表示输出流的迭代器提供了ostream_iterator模版
	该模版是输出迭代器概念的一个模型，通过包含头文件iterator并作以下声明来创建这种迭代器：
	#include<iterator>
	...
	ostream_iterator<int , char>out_iter(cout," ");
	out_iter迭代器现在就是一个接口，让我们能够使用cout来显示信息
	第一个参数int指出被发送给输出流的数据类型
	第二个参数char指出了输出流使用的字符类型（另一个可能得值是wchar_t）
	构造函数第一个参数（这里是cout）指出了要使用的输出流，也可以是文件输出流
	最后一个字符串参数是在发送给输出流的每个数据项后显示的分隔符
	（1）可以这样使用：
	*out_iter++ = 15;
	后置++使用当前的值，意味着先把15和分隔符" "发送到cout管理的输出流中，再++为下一个
	输出做好准备
	（2）可以利用copy()
	copy(dice.begin() , dice.end() , out_iter);
	这意味着将dice容器的整个区间复制到输出流中，即显示容器的内容。也可以直接构建：
	copy(dice.begin() , dice.end() , ostream_iterator<int , char>(cout," "));

	2222------istream_iterator---------

	STL还定义了istream_iterator模版：
	可以利用两个istream_iterator对象来定义copy()的输入范围：
	copy(istream_iterator<int,char>(cin) , istream_iterator<int,char>() , dice.begin() );
	使用构造函数cin表示用cin管理的输入流，省略构造函数参数表示输入失败，
	从输入流中读取，直到文件结尾、类型不匹配或其他故障为止

	3333-------reverse_iterator--------

	功能：对reverse_iterator执行递增操作将导致它递减，原因是为了简化对已有的函数的使用
	vector类有rbegin()的成员函数：返回一个指向超尾的反向迭代器
	和rend()的成员函数：返回一个指向第一个元素的反向迭代器
	因为对迭代器执行递增操作将导致它递减，则可以反向打印内容：
	copy(dice.rbegin(), dice.rend() , out_iter);
		甚至不用声明反向迭代器
		这里rbegin()和end()返回值都是超尾，但类型不同(reverse_iterator和iterator)
	问题：区间结尾处不包括区间内，导致dice.rend()提前停止
	解决：反向指针先递减再解引用。例如，dice.rbegin()是超尾，*dice.rbegin()在当前值之前
	即最后一个元素处解引用。dice.rend()--是第二个位置，*dice.rend()在当前值之前即第一个位置
	解引用。

	？？？？？如果预先不知道dice的长度，要将元素添加到dice中，且不覆盖已有内容，怎么办
	三种插入迭代器：插入将添加新的元素，而不会覆盖已有的数据，并使用自动内存分配来确保
	能够容纳新的信息
	（1）back_insert_iterator：将元素插入到容器尾部
	限制：只能用于允许在尾部快速插入的容器,例如vector
	（2）first_insert_iterator：将元素插入到容器前段
	限制：只能用于允许在起始位置做时间固定插入的容器类型，vector不行，queue可以
	（3）insert_iterator：将元素插入到insert_iterator构造函数的参数指定的位置前面
	没有限制，但是速度没有前两个快

	使用：将容器类型作为模版参数，将容器名称作为构造函数参数：
	back_insert_iterator<vector<int>>  back_iter(dice);
	声明了vector容器类型，back_iter就可以使用vector的方法push_back()来扩大容器大小
	insert_iterator<vector<int>> insert_iter(dice, dice.begin());
	insert_iterator构造函数多了一个指定位置的参数
*/
/*
	容器概念：
	概念是具有名称（如容器，序列容器，关联容器）的通用类别
	容器是存储其他对象的对象。
	被存储的对象必须是同一种类型。类型必须是可复制构造的和可赋值的。
	即可复制插入，可移动插入
	所有容器都提供某些特征和操作
	假设X 表示容器类型，T表示存储在容器里面的对象类型，
	a和b是类型为X的值，r是类型为X&的值，u是类型为X的标识符
	则：
	X::iterator		返回指向T的迭代器类型，满足正向迭代器要求的任何迭代器
					复杂度:编译时间
	X::value_type	返回类型为T,复杂度：编译时间
	X u;			创建一个名为u的空容器
					复杂度：固定
	X u(a)			调用复制构造函数后u==a
					复杂度：线性
	r = a			返回X&，调用赋值运算符后r==a
					复杂度：线性
	a.swap(b)		交换a和b的内容
					复杂度：线性
	“复杂度”描述执行操作所需时间：
	从快到慢依次为：编译时间，固定时间，线性时间
	复杂度为编译时间，则操作将在编译时执行，执行时间为0
	复杂度为固定时间，则操作发生于运行阶段，但是独立于对象中的元素数目
	复杂度为线性时间，则时间与元素数目成正比
*/
/*
	序列：可以通过添加要求来改进基本的容器概念。序列就是一个重要改进
	7种STL容器类型(deque , forward_list , list , queue , priority_queue , stack  和 vector)
	都是序列。
	序列新增要求：
	1.迭代器至少是正向迭代器，保证了元素按照特定顺序排列，不会在两次迭代之间发生变换
	2.元素按照严格的线性顺序排列，即存在第一个元素、最后一个元素，除了第一个元素和最后一个
		元素外，每个元素前后都有一个元素

	七个序列：
	（1）vector：vector是最简单的序列模型，除非其他类型的特殊优点能更好的满足要求
		在vector对象末尾插入和删除对象的复杂度是固定的
		在vector对象首端插入和删除对象的复杂度是线性的
	（2）deque：
		1.在头文件deque中声明
		2.表示双端队列(double_ended queue)
		3.其实现类似于vector，主要区别在于可以直接在deque对象开始位置插入和删除对象
		即时间复杂度为固定的。
		4.在执行随机访问和中部线性时间的插入和删除时，vector更快
	（3）list:
		1.在头文件list中声明
		2.表示双向链表，除了第一个和最后一个元素外，每个元素都和前后元素相链接
		3.list在链表中任意位置进行插入和删除的时间都是固定的。
		4.vector强调通过随机访问进行快速访问，list强调的是元素的快速插入
		5.list不支持数组表示法和随机访问。
		6.从容器中插入或删除元素之后，链表迭代器指向元素不变。因为它不需要像vector那样整体
		挪动以腾出位置，只是链接的元素发生变化，指向某个元素的迭代器仍然指向该元素

*/
/*
	关联容器是对容器概念的另一个改进。
	1.关联容器将值和键关联在一起，并使用键来查找值
	2.优点：提供了对元素的快速访问。
	3.关联容器通常是使用某种树实现的。
		树是一种数据结构，其根节点链接到一个或两个节点，而这些节点再链接下去，形成分支结构。
		节点使得添加或者删除数据项比较简单，而且树的查找速度比链表快
	
	STL提供了四种关联容器：
	头文件set中：set,multiset
	头文件map中：map,multimap
		1.最简单的关联容器是set，其值的类型与键相同。键是唯一的。集合中不会有多个相同的键。
		set键就是值，值就是键
		multiset类似于set只是可能多个值的键相同。
		2.map中值和键类型不同，键是唯一的，每个键只对应一个值。multimap与map类似，只是一个键
		可能对应多个值

	1.set示例：
	（1）set也使用模版参数来指定要存储的值类型：
		set<string> A;
		第二个模版参数是可选的，用于指示用来对键进行排序的比较函数或对象，默认情况下使用模版less<>
	(2) 代码示例：
	const int N =6;
	string s1 = {"buffon","thinker","for","heavy","can","for"};
	set<string> A(s1, s1+N);
	ostream_iterator<string, char> out(cout , " ");
	copy(A.begin(), A.end() , out);
	set也有一个将迭代器区间作为参数的构造函数，可以将集合初始化为数组内容
	上述代码输出：
	buffon can for heavy thinker
	这表明键是唯一的，而且集合被排序

	（3）set是集合，可以进行并集等操作
	1.set_union( A.begin(), A.end() , B.begin() , B.end() , 
			ostream_iterator<string,char>(cout," "));
			显示AB的并集
	set_union()第五个参数必须是输出迭代器。想要把结果放在集合C，
	不能是C.begin()，因为：关联集合将键看做常量，C.begin()返回的是常量迭代器
	其次，与copy()相似，set_union()将覆盖已有数据，并要求有足够空间，C是空的，不满足
	可以使用insert_iterator解决，因为它将复制转为插入，而且还模拟了输出迭代器概念
	set_union( A.begin(), A.end() , B.begin() , B.end() , 
			insert_iterator<string> (C , C.begin()));

	2.set_intersection()查找交集，参数与set_union()相同
	3.set_difference()获得两个集合的差，参数与set_union()相同

	（4）其他操作：
	1.lower_bound()将键作为参数并返回一个迭代器，该迭代器指向集合中第一个不小于键参数的成员
	2.upper_bound()将键作为参数并返回一个迭代器，该迭代器指向集合中第一个大于键参数的成员
	3.由于不管在哪插入，都会自动排序，因此：可以只指定插入信息，无需插入位置
	string s("tennis");
	A.insert(s);
	B.insert(A.begin(),A.end());

	2.multimap示例：multimap也是可反转的、经过排序的关联容器。
	（1）声明：multimap<int,string> codes;
		键类型为int，存储的值类型为string，第三个参数跟set一样，默认比较函数为less<>
	（2）为了将信息结合在一起，实际的值类型包括了键类型。
		STL使用模版类pair<class T,class U>将两种值存储到一个对象当中。
		multimap<int,string> codes;这个声明的codes对象的值类型为pair<const int , string>
		例如：用键存储城市名：
		pair<const int, string> item(213,"Los Angeles");
		codes.insert(item);
		先创建一个pair再将它插入,对于pair对象可以用first和second成员来访问其两个部分
	（3）函数：
	成员函数count()接受键做参数，并返回具有该键的元素数目
	成员函数lower_bound()和upper_bound()作用和set一样、
	成员函数equal_range()将键作为参数，且返回两个迭代器，表示的区间与键匹配

*/