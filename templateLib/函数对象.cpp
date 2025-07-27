/*
	很多STL算法都使用函数对象——也叫函数符。函数符是可以以函数方式与（）结合使用的任意对象
	包括函数名、指向函数的指针和重载了（）运算符的类对象
	for_each()原型：
	template<class InputIterator, class Function>
	Function for_each(InpuIterator first ,InputIterator last, Function f);
	ShowReview()的原型为
	void ShowReview(const Review &)
	则标识符ShowReview的类型是void(*)(const Review &)

	函数符的概念：
	生成器：不用参数就可以调用的函数符
	一元函数：用一个参数
	二元函数：两个参数
	谓词：返回bool值的一元函数
	二元谓词：返回bool值的二元函数
	list模版有一个将谓词作为参数的remove_if()成员，该函数将谓词应用与区间中的每个函数，
	如果谓词返回true，则删除这些元素。例如：
	bool tooBig(int n){return n > 100;}
	list<int> scores;
	...
	scores.remove_if(tooBig);
	如何传递100这个值？使用类函数符：
	class TooBig
	{
	private:
		T cutoff;
	public:
		TooBig(const T& t):cutoff(t){}
		bool operator()(const T &v){return v>cutoff ; }
	}
	这是可以把cutoff由构造函数设置

*/
/*
	transform():
	第一个版本接受4个参数
	transform(gr.begin(), gr.end(), out , sqrt);
	前两个参数是指定容器区间的迭代器。第三个参数是指定将结果复制到哪的迭代器。
	第四个参数是一个单值函数符

	第二个版本接受5个参数
	tansform(gr.begin(), gr.begin() , m.begin() , out , mean )
	最后一个是二元函数符：求平均数。因此需要另一个容器，但是只需要知道另一个容器开始位置即可
	所以第三个参数是另一个容器开始迭代器。第一个容器停止，另一个自然停止

	现在假设要将两个数组相加：
	double add(double x, double y){return x+y;}
	...
	transform(gr.begin(),gr.end(),m.begin(),out,add);
	这样需要为每个类型单独定义一个函数，更好的办法是定义一个模版
	头文件functional定义了多个模版类函数对象
	在C++标准库中，预定义函数符(也称为函数对象)是一组模板类，它们重载了函数调用运算符operator()，
	可以像函数一样被调用。这些函数对象定义在<functional>头文件中。
	其中包括plus<>(),使用方法：
	#include<functional>
	...
	plus<double> add;//这样就创建了一个plus<double>对象
	double y = add(2.3,3.4);
	原来代码可以写成：
	transform(gr.begin(),gr.end(),m.begin(),out, plus<double>);
*/
/*
	自适应函数符：函数符携带标识参数类型和返回类型的typedef成员
	这些成员是result_type，first_argument_type和second_argument_type
	例如，plus<int>对象的返回类型被标识为plus<int>::result_type

	函数符自适应性的意义在于：函数适配器对象可以使用函数对象，并认为存在这些typedef成员
	例如，接受一个自适应函数符参数的函数可以使用result_type成员来声明一个与函数的返回类型匹配的变量
	STL提供了这些工具的函数适配器类。
	multiplies()函数符可以执行乘法运行，但它是二元函数，有时要使用函数适配器，将接受两个参数的函数符
	转换为接受一个参数的函数符
	STL使用binder1st和binder2nd类自动完成这个过程
	假设有一个自适应二元函数对象f2()，则可以创建一个binder1st对象，该对象与一个将被用作f2()的第一个
	参数的特定值(val)相关联。这样只需要给f2的第二个参数即可
	binder1st(f2,val) f1;
	STL还提供了bind1st()简化binder1st类
	binder2nd(f2,val) f1;
	区别是上述代码将常数赋值给第二个参数，这样只需要给f2的第一个参数即可
*/