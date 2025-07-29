/*
	——————重载的<<运算符——————

	（1）<<运算符的默认含义是按位左移运算符。
	表达式x<<3表示将x的二进制表示中所有位向左移动3位。
	（2）ostream类重新定义了<<运算符，将其重载为输出，叫做插入运算符
	（3）插入运算符被重载，使之能够识别C++中所有基本类型
		unsigned char \ signed char \ char \ short \ unsigned short 
		int \ unsigned int \ long \ .....
		对于每种数据类型，ostream类都提供了operator<<()函数的定义
*/
/*
	——————1.输出和指针——————

	ostream类还为下面指针定义了插入运算符：
	const signed char* \ const unsigned char* \ const char* \ void *
	
	C++用指向字符串存储位置的指针来表示字符串，这些指针可以是：
	（1）char数组的数组名：char name[20] = "nblllll";
	（2）显式的char指针：char* pn = "nbllll"
	（3）引号括起来的字符串："nblllll"
	方法使用字符串中的终止空字符来决定何时停止显示字符串

	对于其他类型的指针，C++将其对应于void*，并打印指针的数值表示
	获取字符串的地址要强制转换：cout<<(void *) amount
*/
/*
	——————2.拼接输出————————

	插入运算符所有化身都是返回ostream&，即返回调用运算符的对象，这使得能够通过插入来连接输出
*/
/*
	——————其他ostream方法——————

	除了operator<<()方法外，ostream类还提供了put()方法和write()方法，
	put()用于显示字符:  原型： ostream& put(char);也是返回一个调用函数对象
						因此可以：cout.put('I').put('t');
	write()用于显示字符串：
		原型：basic_ostream<charT,traits> write(const char_type* s,s streamsize n);
		将write()用于数值：
			long val = 560232154;
			cout.write( (char*) & val , sizeof( long ) );
		解释：long是4字节，sizeof( long ) = 4;将作为独立的4个字节传输，
			 输出设备将每个字节作为ASCLL码解释，因此560232154将被显示未4个字符组合
*/
/*
	——————刷新输出缓冲区——————

	一般来说，cout对象处理的输出将被存储在缓冲区，直到缓冲区填满，程序再刷新缓冲区
	将内容发送出去，并情况缓冲区。一般缓冲区为512字节或者其整数倍

	但是对于屏幕来说，为了发一条很短的消息而填满缓冲区，很不方便
	因此，在屏幕输出时，程序不必等缓冲区被填满：
	（1）将换行符发送到缓冲区时，就会刷新缓冲区
	（2）输入即将发生时，也会刷新缓冲区：
			cout<<"Enter a number: ";
			float num;
			cin>>num;
	（3）还可以手动刷新：flush ( cout );或者cout << flush;
	（4）endl：不仅刷新缓冲区，还插入一个换行符
*/
/*
	——————用cout进行格式化——————

	ostream插入运算符将值转换为文本格式。
	（1）默认情况下：
		1.对于char值：如果可打印，将作为一个字符显示在宽度为一个字符的字段中
		2.对于数值整型：将以十进制方式显示在一个刚好容纳该数字及负号的字段中
		3.字符串：将被显示在宽度等于该字符串长度的字段中
		4.浮点数：浮点类型显示为6位，末尾0不显示
				  指数大于6或者小于等于-5时用科学计数法
				  字段恰好容纳数字和负号
		因为每个值的显示宽度都等于它的长度，因此必须显式地在值与值之间插入空格才能隔开

	（2）修改显示时使用的计数系统：
	ostream类从ios类派生，而ios类从ios_base类派生，ios_base类存储关于格式的信息。
	十进制：dec	十六进制：hex	八进制：oct
		这些都是控制符，既可以写成hex( cout )也可以写成cout << hex
		控制符不是成员函数，不能cout.hex
	
	（3）调整字段宽度：由于数字字段不同输出时不一定对齐，可以使用width成员函数将长度
	不同的数字放到宽度相同的字段中。
	原型：
		int width();  返回当前字段宽度的设置	
		int width(int i);  将字段宽度设置为i个空格，并返回以前字段宽度值，以便恢复以前
	1.width()只影响下一个项目，然后遍恢复默认值
	2.数字将被放在字段最右边，称为右对齐。cout通过加入空格来填满整个字段。
		用来填充的字符叫做填充字符。
		右对齐是默认的
	3.C++永远不会截断数据，如果字段宽度不够，就会增宽字段，以便容纳该数据

	（4）填充字符
		1.默认使用空格填充
		2.使用fill()成员函数可以改变：
			cout.fill('*');表示用星号填充
		3.新的填充字符一直有效，直到下一次改变
	
	（5）设置浮点数的显示精度：浮点数精度的含义取决于输出模式
		默认模式：精度表示显示的总位数
		定点模式和科学模式：精度表示小数点后面的位数
	  1.C++默认精度为6位，末尾0不显示
	  2.使用precision()成员函数可以选择其他值
			cout.precision(2);
	  3.新的精度一直有效，直到下一次改变

	（6）打印末尾的0和小数点：cout.setf(ios_base::showpoint);显示末尾小数点
		showpoint是ios_base类中定义的类级静态常量
		通常搭配cout.precision()使用
	
	（7）再谈setf()：有两个原型
		1.fmtflags setf( fmtflags );
		fmtflags是bitmask类型的typedef别名
		参数是一个fmtflags值，指出要设置的东西
		返回值是一个fmtflags值，指出所有标记以前的设置，如果打算恢复设置，则可以保存这个值
		--------常量——————————含义——————————————————————
		ios_base::
				boolalpha			输入和输出bool值，可以为true和false
				showbase			对于输出，使用C++前缀（0,0x）
				showpoint			显示末尾的小数点
				uppercase			对于16进制使用大写字母，E表示法
				showpos				在正数前面加上+
		上述修改一直有效，直到下次更改

		2.fmtflags setf( fmtflags , fmtflags );
		———第二个参数——————第一个参数——————含义——————————
		ios_base::  以下都要加这个类作用域运算符
			basefield				dec					使用基数10
									oct					使用基数8
									hex					使用基数16
			floatfield				fixed				使用定点计数法
									scientific			使用科学计数法
			adjustfield				left				使用左对齐
									right				使用右对齐
									internal			符号或者基数前缀 左对齐
														值右对齐
		定点表示法使用格式123.4来表示浮点值，不管数字长度如何
		科学计数法使用1.23e04,，不考虑数字长度

		可以使用unsetf()消除调用setf()的效果，unsetf()原型：
		void unsetf(fmtflags mask);
		例如：
		cout.setf(ios_base::boolalpha);
		cout.unsetf(ios_base::boolalpha);

	（8）标准控制符：
		使用setf()很麻烦，可以直接使用相应控制符，就相当于调用了setf()函数
		就像hex控制符一样，既可以hex(cout)，也可以cout<<hex;
		————控制符——————————含义——————————
			boolalpha			输入和输出bool值，可以为true和false
			noboolalpha			关掉boolalpha的效果
			showbase			对于输出，使用C++前缀（0,0x）
			noshowbase							
			showpoint			显示末尾的小数点
			noshowpoint											
			uppercase			对于16进制使用大写字母，E表示法
			nouppercase
			showpos				在正数前面加上+
			dec					使用基数10
			oct					使用基数8
			hex					使用基数16
			fixed				使用定点计数法
			scientific			使用科学计数法
			left				使用左对齐
			right				使用右对齐
			internal			符号或者基数前缀 左对齐
								值右对齐

	（9）头文件iomanip
		使用iostream工具还是不太方便，可以使用iomanip提供的控制符：
		setprecision()				设置精度，参数int
		setfill()					设置填充字符，参数char
		setw()						设置字段宽度，参数int
		以上都是控制符，不仅能直接cout<<，还能带上参数()
*/

#include<iostream>
using namespace std;
//test write()
void test01();

//test flush()
void test02();

int main()
{
	//test01();
	test02();
	return 0;
}

void test01()
{
	long val = 6364656667;
	cout.write((char*)&val, sizeof(long));
}

void test02()
{
	cout << "没有换行符，没有flush:";
	cout << "没有换行符，但是有flush:" << flush;
	cout << "没有换行符，没有flush:\n";
	cout << "\nnnnn";
}