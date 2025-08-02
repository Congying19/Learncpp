/*
	有边框，无填充：
		没有前缀：circle(), rectangle();
	有边框，有填充：
		file前缀：fillcircle(),fillrectangle();
	无边框，有填充：
		solid前缀：solidcircle(), solidrectangle();
*/
/*
	获取颜色：
		使用截图工具，RGB (red green blue);
		截屏时，0x123456，,12表示红色，34表示绿色，56表示蓝色。
		写入程序时，按照蓝色绿色红色，倒过来写
*/
#include<graphics.h>
#include<conio.h> // for _getch()
int main()
{
	////设置背景颜色：
	//setbkcolor(0xead999);
	//cleardevice();不能写在创建窗口前面，否则不会创建窗口
	
	//创建easyX窗口：宽度和高度
	initgraph(1200, 700);
	
	//设置背景颜色：
	setbkcolor(0xead999);
	//在设置背景色之后，并不会改变现有背景色，而是只改变背景色的值，
	// 之后再执行绘图语句，例如 outtextxy，会使用新设置的背景色值。
	//如果需要修改全部背景色，可以在设置背景色后执行 cleardevice() 函数。
	cleardevice();

	//设置线的样式：
	setlinestyle(PS_SOLID, 4);
	//设置线的颜色：
	setlinecolor(0);

	//绘制房子：

	//设置屋顶填充色：
	setfillcolor(0xE8A200);
	//屋顶
	POINT arr[3] = { {240,20},{45,200},{435,200} };
	fillpolygon(arr, 3);

	//设置烟囱颜色：
	setfillcolor(0x577AB9);
	//烟囱：
	fillrectangle(330, 30, 380, 160);

	//主体填充颜色：
	setfillcolor(0xFFFFFF);
	//主体：
	fillrectangle(100, 200, 375, 430);

	//门和窗户的边框：
	setlinecolor(0x577AB9);

	//门的填充色：
	setfillcolor(0xb0e4ff);
	//门
	fillrectangle(165, 325, 220, 430);

	setfillcolor(0x7f7f7f);
	//窗户：
	fillrectangle(275, 235, 335, 295);
	line(305, 235, 305, 295);
	line(275, 265, 335, 265);

	//颜色重置为黑色
	setlinecolor(0);
	setfillcolor(0x7f7f7f);
	//门把手：
	solidcircle(207, 385, 9);

	//地板颜色：
	setfillcolor(0x4cbe22);
	//地板：
	fillrectangle(0, 430, 1200, 7000);

	//太阳：
	setfillcolor(0x00f2ff);
	solidcircle(625, 55, 50);
	while (true)
	{
		
	}

	//关闭窗口：
	//closegraph();

	return 0;
}