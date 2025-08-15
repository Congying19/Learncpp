/*
	（1）为什么需要移动语义
	例如：函数：
	vector<string> allcaps(const vector<string> & vs)
	{
		vector<string> temp;
		//将vs所有元素都复制到temp，再返回temp
		return temp;
	}
	这里 返回temp时会创建一个临时对象，然后再删除临时对象。这导致有很多无用功
	能不能不将元素复制到新地方，而是将元素保存在原来的地方，而只修改记录，让数据所有权都转让给要复制的
	变量。这种方法被称为 “移动语义” 。

	可以定义两个构造函数，其中一个是常规复制构造函数（深拷贝），它使用const左值引用作为参数。
	另一个是移动构造函数，它使用右值引用作为参数，只调整记录。将所有权转移给新对象的过程中，移动
	构造函数可能修改其实参，所以不能是const。
*/
/*
	（2）移动语义示例：《示例1》
*/
/*
	（3）移动构造函数解析：

	要让移动语义发生，需要两个步骤：
		首先，右值引用让编译器知道何时可使用移动语义：
			Useless two = one ; //one 是左值，与左值引用匹配：const Useless&
			Useless four( one + three ); //one + three是右值，与右值引用匹配
		其次，编写移动构造函数，使其提供所需的行为。
*/
/*
	（4）赋值：
	Useless & Useless::operator=(const Useless & f)
	{
		if (this == &f)
			return *this;
		delete [] pc;
		n = f.n;
		pc = new char[n]; //无法消除f，只能重新找个地址，这样才能防止delete两次
		for (int i = 0; i < n; i++)
			pc[i] = f.pc[i];
		return *this;
	}
	移动赋值运算符
	Useless & Useless::operator=(Useless && f)    // move assignment
	{
		if (this == &f)
			return *this;
		delete [] pc;
		n = f.n;
		pc = f.pc;
		f.n = 0;
		f.pc = nullptr;//可以直接改变f,不需要重新找地址，十分方便
		return *this;
	}
*/
/*
	（5）强制移动：移动构造函数和移动赋值运算符发使用右值。如果强行使用左值怎么办？
				   ——》使用头文件utility中声明的函数std::move()
		《示例2》
*/