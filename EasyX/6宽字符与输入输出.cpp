/*
	1.什么是宽字符
*/
#include<graphics.h>
#include<conio.h> // for _getch()
int main()
{
	//创建easyX窗口：宽度和高度
	initgraph(1000, 500);

	wchar_t ch = L'中';
	wchar_t arr[100] = L"01星球";

	//EasyX输出字符：第三个元素必须是宽字符类型，不能是字符串
	//outtextxy(50, 50, arr);

	int len = wcslen(arr);//获取宽字符长度

	while (true)
	{
		ExMessage msg;

		getmessage(&msg, EX_CHAR);

		if (msg.message == WM_CHAR) {

			//把用户输入的内放在arr内
			//wsprintf(arr, L"用户输入的内容是%c", msg.ch);

			arr[len] = msg.ch;
			len++;
			arr[len] = L'\0';//下一位设置为0

		}

		fillcircle(50, 50, 50);

		//将字体背景设为透明：
		setbkmode(TRANSPARENT);
		//文字颜色样式：
		settextcolor(0x00ff00);
		settextstyle(50, 0, L"黑体");
		outtextxy(50, 50, arr);
	}
	
	//将chs的4个字符转换为宽字符arr，但是arr最大是100
	char chs[100] = "12345";
	MultiByteToWideChar(0, 0,
		chs, 4,
		arr, 100
	);
	outtextxy(50, 50, arr);

	//将宽字符转换为普通字符：
	WideCharToMultiByte(0, 0,
		L"arr", 2,
		chs, 100,
		0,0
	);

	//卡住窗口：
	//_getch()接受一个字符输入，而且不用按回车，只要按一个字符即可
	_getch();

	//关闭窗口：
	closegraph();

	return 0;
}