#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_

//客户类：何时进入队列以及客户交易时间
// 模拟生成新客户时，程序将创建一个新的客户对象，并在其中存储客户的到达时间以及一个随机生成的交易时间
// 当客户到达队首时，程序将记录此时的时间，并将其与进入队列的时间相减，得到客户等候时间
class Customer
{
private:
	long arrive;//arrival time for customer
	int processtime;//交易时间
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when()const { return arrive; }//访问到达时间接口
	int ptime()const { return processtime; }
};

typedef Customer Item;//起别名方便换

//队列特征：
// 1.队列存储有序的项目序列
// 2.队列所能容纳的项目数有一定的限制
// 3.创建空队列
// 4.检查队列是否为空
// 5.检查队列是否为满
// 6.在队尾添加项目
// 7.在队首删除项目
// 8.确定队列中项目数
//
class Queue
{
private:
	struct Node
	{
		Item item;
		struct Node* next;
	};//链表：包含要存储的信息，以及下一个节点的地址
	//可以在类中嵌套结构声明或者类声明 使其作用域为整个类

	enum{Q_SIZE = 10};//将类中Q_SIZE替换成10
	Node* front;//第一个节点 相当于队首
	Node* rear;//队尾
	int items;//队列当前项目数
	const int qsize;//队列最大项目数

	//由于Queue类用到了new，最好还是要自定义一个复制构造函数，防止程序出错。但是Queue又用不上复制构造函数，则可以这样：
	Queue(const Queue &q): qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; };
	//上述方法称为伪私有方法
	//1.避免本来自动生成的默认复制构造函数
	//2.这方法是私有的，类对象不能广泛使用，相当于定义对象不准使用复制

public:
	Queue(int qs = Q_SIZE);//队列默认是10
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Item& item);//添加项目
	bool dequeue(Item& item);//删除项目
};

#endif
