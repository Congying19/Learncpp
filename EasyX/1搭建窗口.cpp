#include<graphics.h>
#include<conio.h> // for _getch()
int main()
{
	//创建easyX窗口：宽度和高度
	initgraph(500, 500);

	//卡住窗口：
	//_getch()接受一个字符输入，而且不用按回车，只要按一个字符即可
	_getch();

	//关闭窗口：
	closegraph();

	return 0;
}