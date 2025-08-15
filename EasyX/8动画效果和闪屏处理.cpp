#include<graphics.h>
#include<conio.h> // for _getch()
int main()
{
	//创建easyX窗口：宽度和高度
	initgraph(500, 500);

	IMAGE ik_m;
	loadimage(&ik_m, L"C:\\Users\\Soneyin\\Pictures\\Screenshots\\cartoon.png");
	BeginBatchDraw();
	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			/*
				// 绘制图像(指定宽高和起始位置)
				void putimage(
					int dstX,				// 绘制位置的 x 坐标
					int dstY,				// 绘制位置的 y 坐标
					int dstWidth,			// 绘制的宽度
					int dstHeight,			// 绘制的高度
					IMAGE *pSrcImg,			// 要绘制的 IMAGE 对象指针
					int srcX,				// 绘制内容在 IMAGE 对象中的左上角 x 坐标
					int srcY,				// 绘制内容在 IMAGE 对象中的左上角 y 坐标
					DWORD dwRop = SRCCOPY	// 三元光栅操作码
				);
				用处：用于分别打印一张图里面的不同内容
			*/
			putimage(20, 20, 838, 471, &ik_m, 104 * i, 0);
			FlushBatchDraw();
			Sleep(200);
		}
	}
	EndBatchDraw();

	/*
		rotateimage
		这个函数用于旋转 IMAGE 中的绘图内容。

		void rotateimage(
			IMAGE *dstimg,				指定目标 IMAGE 对象指针，用来保存旋转后的图像
			IMAGE *srcimg,				指定原 IMAGE 对象指针
			double radian,				旋转的弧度
			COLORREF bkcolor = BLACK,	旋转后产生的空白区域的颜色。默认为黑色
			bool autosize = false,		目标 IMAGE 对象是否自动调整尺寸以完全容纳旋转后的图像。默认为 false
			bool highquality = true		是否采用高质量的旋转。在追求性能的场合请使用低质量旋转。默认为 true
		);
	*/
	//rotateimage();
	
	//截取：getimage();

	//保存：saveimage();

	//卡住窗口：
	//_getch()接受一个字符输入，而且不用按回车，只要按一个字符即可
	_getch();

	//关闭窗口：
	closegraph();

	return 0;
}