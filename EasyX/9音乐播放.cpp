#include<windows.h>
#include<mmsystem.h>

#pragma comment(lib,"winmm.lib");

/*
	mciSendString()
	参数：命名字符串、返回信息缓冲区、缓冲区大小、回调串口句柄
	返回值：如果返回0，表示成功，失败则返回错误码

	播放：
		mciSendString(L"play 文件路径", 0, 0, 0);

	打开设备：
		mciSendString(L"open 文件路径 alias 别名 type mpegvideo",0,0,0);
		如果想要循环播放，或设置音量大小，需要指定类型为mpegvideo

	循环播放：
		mciSendString(L"play 文件路径或者别名 repeat",0,0,0);

	设置音量：
		mciSendString(L"setaudio 文件路径或者别名 volume to 0~1000",0,0,0);

	暂停：
		mciSendString(L"pause 文件路径或者别名 ",0,0,0);

	停止：
		区别：stop之后从头开始，pause之后截止播放
		mciSendString(L"stop 文件路径或者别名 ",0,0,0);
		注意如果stop用于别名，则和pause效果一样

	关闭设备：
		mciSendString(L"close 文件别名 ",0,0,0);
*/
