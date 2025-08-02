/*
	1.什么是消息：
		鼠标：鼠标移动、鼠标点击、鼠标滚轮
		键盘：按下，抬起
		字符、窗口消息

	2.怎么接受消息：
		用什么接受：getmessage()
		
		如何识别消息：ExMessage的message属性

	3.什么是阻塞：
		阻塞：接受消息时，如果没有消息，程序会等待

		非阻塞：接受消息时，如果没有消息，程序会往下执行
*/
/*
	实现开门和关门，白天和黑夜切换

	思路：
		flag1:0表示白天，1表示黑夜
		flag2:0表示没开门，1表示开门
		while(true){
			1.接受消息：
				如果是点击门：修改flag2
				如果是按下空格：修改flag1

			2.绘制：
				绘制门时：判断flag2
				绘制背景和太阳月亮时：判断flag1
*/
#include<graphics.h>
#include<conio.h> // for _getch()
#include<stdio.h> // for EX_SHOWCONSOLE
int main()
{
	//创建easyX窗口：宽度和高度
	initgraph(1000,700,EX_SHOWCONSOLE);

		//while (true)
		//{
		//	printf("-");
		//	Sleep(100);

		//	ExMessage msg;
		//	/*
		//	    void getmessage(ExMessage *msg, BYTE filter = -1);
		//		1.这个函数用于获取一个消息。如果当前消息队列中没有，就一直等待
		//		2.filter指定要获取的消息范围，默认 -1 获取所有类别的消息。
		//			可以用以下值或值的组合获取指定类别的消息：
		//				EX_MOUSE	鼠标消息。
		//				EX_KEY	按键消息。
		//				EX_CHAR	字符消息。
		//				EX_WINDOW	窗口消息。
		//	*/
		//	//getmessage(&msg, EX_MOUSE | EX_KEY);
		//	
		//	/*
		//		bool peekmessage(ExMessage *msg, BYTE filter = -1, bool removemsg = true);
		//		这个函数用于获取一个消息（鼠标不动也是消息），并立即返回。
		//		用处：解决程序阻塞问题
		//	*/
		//	peekmessage(&msg, EX_MOUSE | EX_KEY);


		//	//判断消息：
		//	if (msg.message == WM_LBUTTONDOWN)
		//	{
		//		printf("鼠标在(%d,%d)按下了左键\n", msg.x, msg.y);
		//	}
		//	else if (msg.message == WM_KEYDOWN)
		//	{
		//		printf("键盘按下了%d", msg.vkcode);
		//	}
		//}
	//0表示白天，1表示晚上
	int flag1 = 0;
	//0表示关门，1表示开门：
	int flag2 = 0;
	while (true)
	{
		BeginBatchDraw();

		ExMessage msg;
		getmessage(&msg, EX_MOUSE | EX_KEY);

		//判断是否点击门：
		if (msg.message == WM_LBUTTONDOWN && msg.x> 165&&msg.x<220
			&& msg.y<430 && msg.y>325)
		{
			//便捷处理两个值：只有开和关的时候采用
			flag2 = (flag2 != 1);
		}

		//判断是否按下空格：
		if (msg.message == WM_KEYDOWN && msg.vkcode == 32)
		{
			//便捷处理两个值：只有开和关的时候采用
			flag1 = (flag1 != 1);
		}

		//设置背景颜色：
		if (flag1)setbkcolor(0);
		else setbkcolor(0xead999);
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
		if (flag2) setfillcolor(0);
		else setfillcolor(0xb0e4ff);
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
		//门把手：开门不画门把手
		if( !flag2) solidcircle(207, 385, 9);

		//地板颜色：
		setfillcolor(0x4cbe22);
		//地板：
		fillrectangle(0, 430, 1200, 7000);

		//太阳：
		if (flag1) setfillcolor(0xCCCCCC);
		else	setfillcolor(0x00f2ff);

		solidcircle(625, 55, 50);

		FlushBatchDraw();
	}



	//卡住窗口：
	//_getch()接受一个字符输入，而且不用按回车，只要按一个字符即可
	_getch();

	//关闭窗口：
	closegraph();

	return 0;
}