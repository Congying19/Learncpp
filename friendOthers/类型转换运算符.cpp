/*
	进行类型转换的原因：
	让编译器能够检查程序的行为是否与设计者想法吻合。

	4个类型转换运算符：
	dynamic_cast;
		语法：dynamic_cast<type-name>(expression);
		用途：使得能够在类层次结构中进行向上转换

	const_cast;
		用途：执行只有一种用途的类型转换，即改变值为const或volatile
		语法：const_cast<type-name>(expression)
		除了有无const和volatile之外，type_name和expression的类型必须相同
		一般在需要将常量改为变量时，利用const_cast修改它

	static_cast;
		语法：static_cast<type-name>(expression)
		仅‘当type_name可以被隐式转换为expression所属的类型’或‘expression可以被隐式转换为
		type_name所属的类型’时，上述语法才是合法的，两个只要满足一个
		例如枚举变量可以隐式转换为整型，那么就可以用static_cast将整型转换为枚举型

	reinterpret_cast;
		语法：reinterpret_cast<type-name>(expression)
		用途：用于天生危险的类型转换，例如把指针转换为足以存储指针表示的整型
*/