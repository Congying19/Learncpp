//如何将类方法应用于对象
//1.创建类对象 2.使用句点运算符 3.对象调用自己的成员函数时 使用的是它对象的数据成员
//所创建的每个新对象都有自己的存储空间，用于存储其内部变量和类成员。但同一个类的所有对象共享同一组类方法（成员函数），即每个方法只有一个副本。
//例如kate和joe都是Stock对象，则kate.share和joe.share占据不同的内存块，但是kate.show()和joe.show()都执行同一个代码块，只是将这些代码用于不同的数据。
//调用成员函数被称为发送消息。
#include<iostream>
#include"stock00.h"

const int STKS = 4;
int main() {
	{
		//显式地调用构造函数：
		Stock fluffy_the_cat = Stock("NamoSmart", 20, 12.5);
		fluffy_the_cat.show();
		fluffy_the_cat.buy(15, 18.125);
		fluffy_the_cat.show();
		fluffy_the_cat.sell(400, 20.00);
		fluffy_the_cat.show();
		fluffy_the_cat.buy(300000, 40.125);
		fluffy_the_cat.show();
		fluffy_the_cat.sell(300000, 0.125);
		fluffy_the_cat.show();
		std::cout << "\n";
		//隐式地调用构造函数：与显式调用等价
		Stock garment("Furry Mason", 50, 2.5);
		garment.show();

		//使用默认构造函数时不需要使用圆括号：
		Stock garment2;
		garment2.show();
		
		garment2 = Stock("New Furry Mason", 40, 2.5);//对garment2进行赋值，先利用构造函数创建一个临时变量，
		//然后将其内容复制给garment2,随后程序调用析构函数以删除临时对象
		garment2.show();
		std::cout << "\n";

		std::cout << "the bigger between Furry Mason and New Furry Mason is \n";
		garment.topval(garment2).show();//garment.topval(garment2)是一个对象可以直接调用show()
		std::cin.get();//暂停查看临时变量是否析构

		//创建对象数组：
		Stock stocks[STKS] = {
			Stock("NanoSmart",12,20.0),
			Stock("Boffo Objects",200,2.0),
			Stock("Monolithic Obelisks",130,3.25),
			Stock()//调用默认构造
		};//要创建类对象数组，这个类必须有默认构造函数。因为初始化对象数组首先使用默认构造函数创建数组元素，然后花括号里面的构造函数创建临时变量
		//在把临时变量的值复制到相应的元素

		//找出对象数组最大值：
		std::cout << "Stock holdings:\n";
		int st;
		for (st = 0; st < STKS; st++) {
			stocks[st].show();
		}
		const Stock* top = &stocks[0];//假设第一个元素最高 一次比较两个 数组元素没有交换 而是指针不断指向最高值
		for (st = 1; st < STKS; st++)
			top = &top->topval(stocks[st]);//top->topval(stocks[st])最开始相当于stocks[0].topval(stocks[0])返回最大对象的引用，再把地址传给top
		std::cout << "\nMost valuable holding : \n";
		top->show();

	}//增加一个大括号，变成一个代码块，当这个代码块结束执行析构函数时就能看见了
	//由于自动变量被放在栈中，因此最后创建的对象最先调用析构函数
	return 0;
}