//使用矢量来模拟随机漫步：
#include<iostream>
#include<cstdlib>//rand() srand()原型
#include<ctime>//包含time()原型
#include"vector.h"
int main() {
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));//产生随机种子 不然每次运行都是同一个随机数
	double direction;//方向
	Vector step;//步伐向量
	Vector result(0.0, 0.0);//刚开始坐标设为（0，0) 模式为RECT
	unsigned long steps = 0;//步数
	double target;//目标距离：希望走出多远
	double dstep;//每一步的长度
	cout << "Enter target distance(q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		while (result.magval() < target)
		{
			direction = rand() % 360;//0到359的随机数
			step.reset(dstep, direction, Vector::POL);//传入POL只是判断 没有改变 还是RECT
			result = result + step;//result虽然是极坐标创建 但是都设置了xy 所以直接利用直角坐标加法
			steps++;//走了一步 步数增加 
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}