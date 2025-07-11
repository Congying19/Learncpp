//名称空间问题：使用多个厂商的类库时，可能导致名字冲突，例如两个库都使用了List、Tree的类，但定义的方式不兼容。用户可能希望用一个库的List类,
//而使用另一个库的Tree类。

//声明区域：可以在其中进行声明的区域。
//潜在作用域：变量的潜在作用域从声明点开始，到其声明区域的结尾。潜在作用域比声明区域小。
//变量并非在潜在作用域内任何位置都可见。有可能被另一个嵌套声明区域内同名变量隐藏。

//可以通过定义一个新的声明区域来创建一个有名字的名称空间。一个名称空间的名称不会与另外一个名称空间的相同名称发生冲突，同时允许程序其他部分使用
//该名称空间中声明的东西。例如：
namespace Jack {
	double pail;
	void fetch();
	int pal;
	struct well{};
}
namespace Jill {
	double pail;
}
//名称空间可以是全局的，也可以是位于另一个名称空间中，但不能位于代码块中。因此，默认情况下，在名称空间中声明的名称的链接性为外部的。
//除了用户定义的名称空间之外，还存在另一个名称空间——全局名称空间。它对应于文件级声明区域。
//名称空间是开放的，可以直接把名称添加到已有的名称空间中
namespace Jack {
	void fetch()
	{
	}
}

//使用作用域解析运算符::使用名称空间来限定该名称
//Jack::pail = 13.14;
//每次使用名称都要加Jack::，很麻烦，可以使用using声明 和 using编译指令
//using声明使得特定的标识符可用，using编译指令使得整个名称空间可用

using Jack::pail;//在外部使用using声明，将把名称添加到全局名称空间中
//using Jill::pail;不能同时使用这两个using声明
using namespace Jack;//using编译指令使得整个名称都可用
int main() {
	using Jack::pail;
	pail = 20;//后面直接使用pail即可
}

//可以将名称空间声明进行嵌套：
namespace elements
{
	namespace fire
	{
		int flame;
	}
	float water;
}
//对fire的编译指令
using namespace elements::fire;
//对flame的using声明
using elements::fire::flame;
//名称空间名字太长 可以起别名：
namespace EF = elements::fire;