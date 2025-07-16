#pragma once
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
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

#endif