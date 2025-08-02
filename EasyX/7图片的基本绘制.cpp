#include<graphics.h>
#include<conio.h> // for _getch()
int main()
{
	//创建easyX窗口：宽度和高度
	initgraph(1000, 500);

	/*
		这个函数用于从文件中读取图像，对到保存图像的 IMAGE 对象指针
		// 从图片文件获取图像(bmp/gif/jpg/png/tif/emf/wmf/ico)
		void loadimage(
			IMAGE* pDstImg,			// 保存图像的 IMAGE 对象指针，
									如果为 NULL，表示图片将读取至绘图窗口
			LPCTSTR pImgFile,		// 图片文件名
			int nWidth = 0,			// 图片的拉伸宽度
			int nHeight = 0,		// 图片的拉伸高度
			bool bResize = false	// 是否调整 IMAGE 的大小以适应图片
		);
		注意：
			1.文件名是路径加名字，前面记得加L，而且是两个\\，因为一个\表示转义字符
		图片加载失败原因：
			1.文件路径问题：建议全英文加数字
			2.缺少后缀名
			3.图片本身格式不支持
			4.绝对路径：从磁盘开始
			  相对路径：当前项目为一个目录
	*/
	loadimage(NULL,
		L"C:\\Users\\Soneyin\\Pictures\\Screenshots\\屏幕截图 2025-08-02 143441.png",
		1000,500
	);

	IMAGE img;
	loadimage(&img,
		L"C:\\Users\\Soneyin\\Pictures\\Screenshots\\屏幕截图 2025-06-21 155350.png",
		300, 300);

	putimage(200,200,&img);

	//卡住窗口：
	//_getch()接受一个字符输入，而且不用按回车，只要按一个字符即可
	_getch();

	//关闭窗口：
	closegraph();

	return 0;
}