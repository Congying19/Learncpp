/*
	画板程序：
		1.左上角显示笔刷颜色和大小
		2.按下q和w，切换笔刷颜色
			目前有0xffffff,0xe0b0fe,0xbe8be2,0x7946a8,0x6354ec,0x6af2fe,0x0
		3.鼠标滚轮切换笔刷大小
		4.鼠标按下移动时 绘制
		5.按下r，清空画板内容
		6.拓展：按下d，撤回上一笔（难
				可以新增白色作为橡皮
*/

/*
	笔刷大小和颜色：
		
		maxsize; 笔刷最大值
		minxsize;笔刷最小值
		nowsize; 笔刷当前值

		int 颜色数组；
		index 当前颜色；

		while(true){
			1.接受消息：

			如果是键盘消息{
				q
				w
				r
			}如果是鼠标移动{
				移动：左键是否按下
				鼠标点击：
					1.绘制一个圆形
					2.清空上一次绘制时记录的坐标
				鼠标滚轮：
			}
*/
#include<graphics.h>
#include<conio.h> // for _getch()
int main()
{
	//创建easyX窗口：宽度和高度
	initgraph(1000, 700);

	//背景颜色设置为白色：
	setbkcolor(0xffffff);
	cleardevice();

	//画板颜色数组：
	int myColor[] = { 0xffffff,0xe0b0fe,0xbe8be2,0x7946a8,0x6354ec,0x6af2fe,0x0 };

	//画板中存在的颜色数量：
	int cNum = 7;

	//当前选择的颜色：
	int cIndex = 0;

	//笔刷大小：
	int maxSize = 25, minSize = 1, nowSize = 5;

	//鼠标上一个点的坐标：
	int preX = 0, preY = 0;

	while (true)
	{
		ExMessage msg;
		getmessage(&msg, EX_MOUSE | EX_KEY);
		switch (msg.message)
		{
		case WM_KEYDOWN:
			switch (msg.vkcode)
			{
			case 'Q':
				//最小值考虑越界情况：
				cIndex--;
				if (cIndex < 0) cIndex = cNum - 1;
				//绘制纯白色的矩形：用来挡住之前的大小：
				setfillcolor(0xffffff);
				solidrectangle(0, 0, 100, 100);
			
				//绘制和笔刷大小颜色一样的圆形：用来提示用户
				setfillcolor(myColor[cIndex]);
				solidcircle(50, 50, nowSize / 2);

				setlinecolor(myColor[cIndex]);
				break;
			case 'W':
				cIndex++;
				if (cIndex > cNum-1) cIndex = 0;
				//绘制纯白色的矩形：用来挡住之前的大小：
				setfillcolor(0xffffff);
				solidrectangle(0, 0, 100, 100);

				//绘制和笔刷大小颜色一样的圆形：用来提示用户
				setfillcolor(myColor[cIndex]);
				solidcircle(50, 50, nowSize / 2);

				//设置笔刷颜色：即线的颜色：
				setlinecolor(myColor[cIndex]);
				break;
			case 'R':
				cleardevice();

				//绘制和笔刷大小颜色一样的圆形：用来提示用户
				setfillcolor(myColor[cIndex]);
				solidcircle(50, 50, nowSize / 2);
				break;
			}
			break;

		case WM_LBUTTONDOWN:
			//鼠标左键按下：记录当前坐标，并绘制一个圆形
			//solidcircle(50, 50, nowSize / 2);
			preX = msg.x;
			preY = msg.y;
			
			break;

		case WM_MOUSEMOVE:
			//鼠标移动：如果左键是按下状态则继续，否则跳出：
			if (!msg.lbutton) break;
			//绘制线：从上一个点到现在这个点
			line(preX, preY, msg.x, msg.y);

			//只要稍微移动就更换为之前的坐标，实现绘制曲线
			preX = msg.x;
			preY = msg.y;

		case WM_MOUSEWHEEL:
			nowSize +=msg.wheel / 120;
			if (nowSize > maxSize) nowSize = minSize;
			else if (nowSize < minSize) nowSize = maxSize;
			//设置线条宽度
			setlinestyle(PS_SOLID, nowSize);

			//绘制纯白色的矩形：用来挡住之前的大小：
			setfillcolor(0xffffff);
			solidrectangle(0, 0, 100, 100);

			//绘制和笔刷大小颜色一样的圆形：用来提示用户
			setfillcolor(myColor[cIndex]);
			solidcircle(50, 50, nowSize / 2);
		}
	}


	//卡住窗口：
	//_getch()接受一个字符输入，而且不用按回车，只要按一个字符即可
	_getch();

	//关闭窗口：
	closegraph();


	return 0;
}