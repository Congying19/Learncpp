#pragma once
#ifndef STACKTP_H_
#define STACKTP_H_
//类模版声明：
template<class Type>//开始使用模版
class Stack
{
private:
	enum {MAX = 10};
	Type items[MAX];//存放栈类元素
	int top;//栈顶
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const Type& item);
	bool pop(Type& item);
};

//以下称为成员函数模版
//类模版和成员函数模版都不是类和成员函数定义，它们是C++编译器指令，
//它们说明了如何生成类和成员函数定义
//由于模版不是函数，不能单独编译。
//模版必须和实例化请求一起使用，因此成员函数模版和类模版放在同一个文件里面最好
template<class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}

template<class Type>
bool Stack<Type>::isfull()
{
	return top == MAX;
}

template<class Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template<class Type>
bool Stack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}


#endif // !STACKTP_H_

//数组模版示例：
//templat<class Type,int n>
// class Array
// {
//		T arr[n];
// }
//这里n 称为非类型参数。n不能被修改，模版中不能写n++