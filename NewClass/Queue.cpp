#include"Queue.h"
#include<cstdlib>

Queue::Queue(int qs) : qsize(qs)//初始化列表，还可以front(nullptr),rear(nullptr),items(0) 只要括号里面是常量或者参数列表里的参数
//初始化的顺序与类声明中的顺序相同，与初始化列表里面位置顺序无关
{ //只有构造函数才能用初始化列表
	front = rear = nullptr;//首尾指针指向空
	items = 0;
	//qsize = qs ;qsize是常量，不能给他赋值。通过初始化列表，对象在创建时就执行初始化列表，然后再执行花括号
	//引用的变量也必须初始化，所以也只能用初始化列表
}

bool Queue::isempty()const
{
	return items == 0;
}

bool Queue::isfull()const
{
	return items == qsize;
}

int Queue::queuecount()const
{
	return items;
}

//将项目添加到队尾
bool Queue::enqueue(const Item& item)
{
	if (isfull())//队列满了不增加
		return false;

	Node* add = new Node;//创建一个新节点
	add->item = item;//节点项目信息为新项目
	add->next = nullptr;//新节点指向空
	items++;
	if (front == nullptr)//队列是空的，将新项目当队首
		front = add;
	else
		rear->next = add;//如果不空，则队尾指针指向新项目
	rear = add;//而新项目成为新队尾
	return true;//添加成功返回true
}

//将项目从队首删除：
bool Queue::dequeue(Item& item)
{
	if (front == nullptr)
		return false;

	item = front->item;
	items--;
	Node* temp = front;//临时指针记录front,否则后面front更新时就丢失之前的内存了
	front = front->next; //第二个节点（front->next)称为新队首
	delete temp;//由于队首要么是nullptr，要么是enqueue()里面创建的new内存，所以delete不会有危险
	if (items == 0)
		rear = nullptr;
	return true;
}

Queue::~Queue()
{
	//dequeue()可以删除节点 但是为了保证 还需要在析构函数中删除剩余节点
	Node* temp;
	while (front != nullptr)
	{//利用循环 一个一个删
		temp = front;
		front = front->next;
		delete temp;
	}
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;//随机交易时间
	arrive = when;
}