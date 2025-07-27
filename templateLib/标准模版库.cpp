/*
	标准模版库(standard template library)，简称STL
	STL提供了一组表示容器、迭代器、函数对象和算法的模版
	1.容器是同质的，即存储的值的类型相同
	2.算法是完成特定任务的处方（如对数组进行排序或在链表中查找特定的值）
	3.迭代器能够用来遍历容器的对象，与能够遍历数组的指针类似，是广义指针。
	4.函数对象是类似于函数的对象，可以是类对象或函数指针（包括函数名）
	STL使得能够构造各种容器(包括数组、队列和链表）和执行各种操作（包括搜索、排序和随机排列）
*/
/*
	所有STL容器都提供了一些基本方法：
	size()返回容器中元素数目
	swap()交换两个容器的内容
	begin()返回一个指向容器的第一个元素的迭代器
	end()返回一个表示超过容器尾的迭代器

	通过将指针广义化为迭代器，让STL能够为各种不同的容器类提供统一的接口。
	每个容器类都定义了一个合适的迭代器，该迭代器的类型是一个名为iterator的typedef,作用域为整个类
	例如：要为vector的double类型规范声明一个迭代器，可以这样做：
	vector<double>::iterator pd;

	这时就可以像使用指针那样使用pd
	wector<double> scores;
	pd = scores.begin();
	*pd = 22.3;
	++pd;

	善于利用auto自动类型推断：
	vector<double>::iterator pd = score.begin();
	简化为：auto pd = score.begin();

	遍历容器：
	for(pd = scores.begin();pd!=score.end();pd++)
		cout<<*pd<<endl;
*/