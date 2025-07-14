#pragma once
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;//给unsigned long起别名 用起来方便，如果要创建double栈，只需要将unsigned long替换成double

//栈类：
class Stack
{
private:
	enum{Max = 10};//创建一个常量供所有类对象使用
	//不能写:const int Max = 10;因为类声明只是描述了对象的形式，并没有创建对象，没有用于存储值的空间
	//这里枚举并不会创建数据成员，也就是说，所有对象中都不包含枚举，Max只是一个符号名称，在类的作用域中的代码遇到它时，编译器将它替换成10
	//由于不需要创建枚举变量 因此不需要提供枚举名

	Item items[Max];//存储栈的元素
	int top;//栈顶元素序号
public:
	Stack();//默认构造函数
	bool isempty() const;//查看栈是否为空
	bool isfull()const;//查看栈是否填满
	bool push(const Item& item);//添加元素到栈
	bool pop(Item& item);//从栈中删除元素

};
#endif // !STACK_H_
