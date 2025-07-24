/*
	异常引发后，在两种情况下会导致问题：
	1.意外异常：如果异常是在带异常规范的函数中引发的，则必须与规范列表中的某种异常匹配
	否则称为意外异常

	2.未捕获异常：异常不是在函数中引发的，或者函数没有异常规范时，没有捕获（没有try块或没有匹配
	catch块时）
	未捕获异常不会导致程序立刻终止，程序会先调用terminate()，默认情况下，terminate()调用
	abort()函数，可以指定terminate()调用的函数来修改这一行为。
	为此可以调用set_terminate()函数，它们都在头文件exception中声明的:
	typedef void (*terminate_handler)();表示terminate_handler是这样一种类型：
	指向没有参数和返回值的函数的指针
	terminate_handler set_terminate(terminate_handler f) noexcept;
	void terminate() noexcept;
	
	使用方法：
	(1)设计一个没有参数和返回值的函数：
	void myQuit()
	{
		//打印消息：
		cout<<"Terminating due to uncaught exception\n";
		//设置退出值：
		exit(5);
	}
	(2)包含头文件：
	#include<exception>
	using namespace std;
	(3)在程序开头将终止操作指定为调用该函数：
	set_terminate(myQuit);
	这时候如果引发异常，但是throw没有找到try，则程序会调用terminate()，后者将会调用myQuit()
*/