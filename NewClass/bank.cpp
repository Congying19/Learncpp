//程序允许用户输入3个数：队列最大长度，程序模拟持续时间，平均每小时的客流量
//程序完成下面工作：
// 1.判断是否有新客户，如果有，而且队列没满则添加，否则拒绝
// 2.如果没有客户交易，则选取队列的第一个客户。确定该客户的已等候时间，并将wait_time计数器设置为新客户所需处理时间
// 3.如果客户正在处理，则将wait_time减1
// 4.记录各种数据，如获得服务的客户数目，被拒绝的客户数目，排队等候的累计时间以及累计的队列长度。
// 想要平均每小时来10个，但是每6分钟来1个不现实，利用：
// bool newcustomer(double x)
// {
//		return (std::rand() * x / RAND_MAX < 1 ;
// }原理：RAND_MAX是cstdlib中定义的，是rand()可能返回的最大值。如果x=6，则rand() * x/RAND_MAX返回 0到6的值。
//

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));//随机种子

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;//程序每一分钟循环一次

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;//得到每分钟来的人

	Item temp;//
	long turnaways = 0;//拒绝的人数
	long customers = 0;//接受的人数
	long served = 0;//持续期间服务的人数
	long sum_line = 0;//累计队列长度
	int wait_time = 0;//等待时间
	long line_wait = 0;//累计待在队列的时间

	for (int cycle = 0; cycle < cyclelimit; cycle++)//每一分钟处理一轮
	{
		if (newcustomer(min_per_cust))//随机数产生客户
		{
			if (line.isfull())
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp.set(cycle);//when = cycle 何时到达 并设置随机交易时间
				line.enqueue(temp);//加入队列
			}
		}
		if (wait_time <= 0 && !line.isempty())//没有等待时间而且队列不是空,就有客户开始处理
		{
			line.dequeue(temp);//减去临时客户
			wait_time = temp.ptime();//下一个客户时间是上一个客户处理时间
			line_wait += cycle - temp.when();//累计等待时间，要减去客户自己处理时间
			served++;
		}
		if (wait_time > 0)
			wait_time--;//如果这一轮客户等待时间大于0，相当于这一分钟过去了，但队首没变，只是等待时间减1
		sum_line += line.queuecount();//每一分钟加和队列长度，最后求平均值
	}

	//银行持续工作结束，汇报情况：
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "		  turnaways:" << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time:"
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}