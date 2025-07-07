#include<iostream>
#include<cmath>
using namespace std;
struct polar
{
	double distance;
	double angle;
};
struct rect {
	double x;
	double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

void show_polar2(const polar* dapos);
void rect_to_polar2(rect* xypos, polar* dapos);

int main() {
	//使用值传递：
	cout << "使用值传递结构\n";
	rect rplace;
	polar pplace;

	cout << "请输入x,y坐标：";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);//传递一个结构 返回一个结构
		show_polar(pplace);
		cout << "Next two numbers(q to quit): ";
	}
	cin.clear();
	while (cin.get() != '\n')
		continue;//清除错误输入 不然后面的while(cin>>)直接判断false进不去循环
	cout << "Done.\n";

	//使用地址传递结构：
	cout << "使用地址传递结构\n";
	rect rplace2;
	polar pplace2;
	cout << "请输入x,y坐标：";
	while (cin >> rplace2.x >> rplace2.y)
	{
		rect_to_polar2(&rplace2, &pplace2);
		show_polar2(&pplace2);
		cout << "Next two numbers(q to quit): ";
	}
	cout << "Done.\n";
	return 0;
}

polar rect_to_polar(rect xypos)//值传递结构 适用于结构较小的变量
{
	polar answer;
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}

void show_polar(polar dapos)
{
	const double Rad_to_deg = 57.29577951;
	cout << "distance = " << dapos.distance;
	cout << ",angle = " << dapos.angle * Rad_to_deg;
	cout << " degrees\n";
}

void rect_to_polar2(rect* xypos, polar* dapos) //由于传递的是指针可以直接修改结构的值 不需要返回结构
{
	dapos->distance = sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
	dapos->angle = atan2(xypos->y, xypos->x);
}

void show_polar2(const polar* dapos)//地址传递 由于传递的是结构的地址 要用->访问结构成员
{
	const double Rad_to_deg = 57.29577951;
	cout << "distance = " << dapos->distance;
	cout << ",angle = " << dapos->angle * Rad_to_deg;
	cout << " degrees\n";
}