/*
	模板类 vector、forward_list、list、deque 和 array 都是序列容器，它们都前面列出的方法，
	但 forward_list 不是可反转的，不支持表 G.3 所示的方法。
	
	序列容器以线性顺序存储一组类型相同的值。
	
	i.如果序列包含的元素数是固定的，通常选择使用 array；
	
	ii.否则，首先考虑使用 vector，它让 array 的随机存取功能以及添加和删除元素的功能于一身。
	
	iii.然而，如果经常需要在序列中间添加元素，应考虑使用 list 或 forward_list。
	
	iiii.如果添加和删除操作主要是在序列两端进行的，应考虑使用 deque。

	array 对象的长度是固定的，因此无法使用众多序列方法。
	
——————————————————————————————————————————————————

	表 G.5 列出除 array 外的序列容器可用的其他方法（forward_list 的 resize()方法的定义稍有不同）。
	同样，其中 X 是容器类型，如 vector<int>；
	T 是存储在容器中的类型，如 int；
	a 是类型为 X 的值；
	t 是类型为 x::value_type 的左值或 const 右值；
	i 和 j 是输入迭代器；
	[i, j] 是有效的区间；
	il 是类型为 initilizer_list<value_type>的对象；
	p 是指向 a 的有效 const 迭代器；
	q 是可解除引用的有效 const 迭代器；
	[q1, q2] 是有效的 const 迭代器区间；
	n 是 x::size_type 类型的整数；
	Args 是模板参数包，而 args 是形式为 Args&&的函数参数包。

	X(n, t);			// 创建一个序列容器，它包含 t 的 n 个拷贝
	X a(n, t);			// 创建一个名为 a 的序列容器，它包含 t 的 n 个拷贝
	X(i, j);			// 使用区间[i, j]内的值创建一个序列容器
	X a(i, j);			// 使用区间[i, j]内的值创建一个名为 a 的序列容器
	X(il);				// 创建一个序列容器，并将其初始化为 il 的内容
	a = il;				// 将 il 的值复制到 a 中
	a.emplace(p, args); // 在 p 前面插入一个类型为 T 的对象，使用 args 封装的参数匹配的构造函数
	a.insert(p, t);		// 在 p 之前插入 t 的拷贝，并返回指向该拷贝的迭代器
	a.insert(p, rv);	// 在 p 之前插入 rv 的拷贝，并返回指向该拷贝的迭代器；可能使用移动语义
	a.insert(p, n, t);  // 在 p 之前插入 t 的 n 个拷贝
	a.insert(p, i, j);  // 在 p 之前插入[i, j]区间内元素的拷贝
	a.insert(p, il);	// 等价于 a.insert(p, il.begin(), il.end())
	a.resize(n);		// 如果 n > a.size(), 则在 a.end()之前插入 n - a.size()个元素
	a.resize(n, t);		// 如果 n > a.size(), 则在 a.end()之前插入 t 的 n - a.size()个拷贝
	a.assign(i, j);		// 使用区间[i, j]内的元素拷贝替换 a 当前的内容
	a.assign(n, t);		// 使用 t 的 n 个拷贝替换 a 当前的内容
	a.assign(il);		// 等价于 a.assign(il.begin(), il.end())
	a.erase(q);			// 删除 q 指向的元素；返回一个指向 q 后面的元素的迭代器
	a.erase(q1, q2);	// 删除区间[q1, q2]内的元素；返回一个指向 q2 原来指向的元素的迭代器
	a.clear();			// 与 erase(a.begin(), a.end())等效
	a.front();			// 返回*a.begin()（第一个元素）

——————————————————————————————————————————————————
	表6列出了一些序列(vector,forward_list,list和deque)都有的方法

	表 G.6				为某些序列定义的操作
	a.back();           // 返回*a.end()（最后一个元素） 
							[vector、list、deque]
	a.push_back(t);     // 将 t 插入到 a.end()前面 
							[vector、list、deque]
	a.push_back(rv);    // 将 rv 插入到 a.end()前面；可能使用移动语义 
							[vector、list、deque]
	a.pop_back();       // 删除最后一个元素 
							[vector、list、deque]
	a.emplace_back(args); // 追加一个类型为 T 的对象，创建该对象时使用与 args 封装的参数匹配的构造函数 
							[vector、list、deque]
	a.push_front(t);    // 将 t 的拷贝插入到第一个元素前面 
							[forward_list、list、deque]
	a.push_front(rv);   // 将 rv 的拷贝插入到第一个元素前面；可能使用移动语义 
							[forward_list、list、deque]
	a.emplace_front();  // 在最前面插入一个类型为 T 的对象，创建该对象时使用与 args 封装的参数匹配的构造函数 
							[forward_list、list、deque]
	a.pop_front();      // 删除第一个元素 
							[forward_list、list]
	a[n];               // 返回*(a.begin() + n) [vector、deque、array]
	a.at(n);            // 返回*(a.begin() + n)；如果 n>a.size，则引发 out_of_range 异常 
							[vector、deque、array]

	————————————————————————————————————————————————
	模版vector还包含了表7列出的方法，其中a表示 vector容器，n是x::size_type型整数

	表 G.7    vector 的其他操作

	a.capacity();    // 返回在不要求重新分配内存的情况下，矢量能存储的元素总量
	a.reserve(n);    // 提醒 a 对象：至少需要存储 n 个元素的内存。
						调用该方法后，容量至少为 n 个元素。
						如果 n 大于当前的容量，则需要重新分配内存。
						如果 n 大于 a.max_size(), 该方法将引发 length_error 异常

	————————————————————————————————————————————————
	模板 list 还包含表 G.8 列出的方法。
	其中，a 和 b 是 list 容器；
	T 是存储在链表中的类型，如 int；
	t 是类型为 T 的值；
	i 和 j 是输入迭代器；
	q2 和 p 是迭代器；
	q 和 q1 是可解除引用的迭代器；
	n 是 x::size_type 型整数。
	该表使用了标准的 STL 表示法[i,j]，这指的是从 i 到 j（不包括 j）的区间。

	表 G.8    list 的其他操作

	a.splice(p, b);				// 将链表 b 的内容移到链表 a 中，并将它们插在 p 之前
	a.splice(p, b, i);			// 将 i 指向的链表 b 中的元素移到链表 a 的 p 位置之前
	a.splice(p, b, i, j);		// 将链表 b 中[i, j]区间内的元素移到链表 a 的 p 位置之前
	a.remove(const T& t);		// 删除链表 a 中值为 t 的所有元素
	a.remove_if(Predicate pred); // 如果 i 是指向链表 a 中元素的迭代器，
									则删除 pred(*i)为 true 的所有值（Predicate 是布尔值函数或函数对象，参见第 15 章）
	a.unique();					// 删除连续的相同元素组中除第一个元素之外的所有元素
	a.unique(BinaryPredicate bin_pred); 
			// 删除连续的 bin_pred(*i, *(i - 1))为 true 的元素组中除第一个元素之外的所有元素（BinaryPredicate 是布尔值函数或函数对象，参见第 15 章）
	a.merge(b);					// 使用为值类型定义的<运算符，将链表 b 与链表 a 的内容合并。
		如果链表 a 的某个元素与链表 b 的某个元素相同，则 a 中的元素将放在前面。合并后，链表 b 为空
	a.merge(b, Compare comp);	// 使用 comp 函数或函数对象将链表 b 与链表 a 的内容合并。
		如果链表 a 的某个元素与链表 b 的某个元素相同，则链表 a 中的元素将放在前面。合并后，链表 b 为空


*/