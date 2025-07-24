/*
	exception头文件定义了exception类
	1.可以将exception类用作其他异常类的基类
	2.exception类有一个名为what()的虚拟成员函数，它返回一个字符串
	例如：之前的bad_hmean和bad_gmean就可以这样定义：
	#include<exception>
class bad_hmean :public std::exception
{
public:
	const char* what() { return "错误输入给hmean()"; }
};
class bad_gmean :public std::exception
{
public:
	const char* what() { return "错误输入给gmean()"; }
};
	然后再同一处理：
	try{
	...
	}
	catch(std::exception& e)
	{
		cout<<e.what()<<endl;
		...
	}
*/
/*
	C++定义了很多基于exception类的异常类型

	1.stdexcept异常类
	头文件stdexcept定义了 logic_error类 和 runtime_error类
	这两个类又将作为两个派生类系列的基类

	class logic_error : public exception{
	public:
	explicit logic_error(const string& what_arg);
	...
	}
	class domain_error : public logic_error{
	public: 
	explicit domain_error(const string & what_arg);
	..>
	}

	异常类系列logic_error描述了典型的逻辑错误：
	domain_error  域错误
	invalid_argument  无效参数
	length_error  长度错误
	out_of_bounds  越界

	异常类系列runtime_error描述了可能在运行期间发生但难以预计和防范的错误
	range_error  范围
	overflow_error  上溢
	underflow_error  下溢

*/
