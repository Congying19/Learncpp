#include"stack.h"
Stack::Stack()//创建空栈
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;//栈顶==0 返回true说明为空 返回false说明不为空
}

bool Stack::isfull() const
{
	return top == Max;
}

bool Stack::push(const Item& item)
{
	if (top < Max)
	{
		items[top++] = item;//后置++ 先把元素放入当前top 再将top往后移
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = items[--top];//top往下移 即为删除 实际上还在那
		return true;
	}
	else
		return false;
}