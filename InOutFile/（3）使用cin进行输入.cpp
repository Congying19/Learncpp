/*
	如果键入字符序列2011，cin对象将从输入流中抽取这几个字符。
	输入可以是字符串的一部分，int值，float值等等
	cin对象根据接受值的变量类型，使用其方法将字符序列转换为所需类型
*/
/*
	istream类重载了抽取运算符（>>），使之能够识别基本类型
	>>运算符函数称为格式化输入函数，因为它们能够将输入数据转换为目标指定的格式

	典型运算符函数原型：istream& operator>>( int &);
		1.由于参数类型为引用，所以cin能够直接修改用作参数的变量的值
		2.如果输入字符流2、3、1、4，变量类型为int，就会对应上述函数，这个函数将字符
		转换为整数2314的2字节二进制表示
		3.可以将hex、oct、和dec控制符与cin一起使用，用来指定将整数解释为十六进制、八进制
		还是十进制。
		4.抽取运算符返回引用使得能够将输入拼接

	istream类还为下列字符指针类型重载了>>抽取运算符：
	signed char*		char*		unsigned char*
	对于这种类型，抽取运算符将读取输入中的下一个单词，将它放置在指定的地址，并加上一个
	空值字符，使之成为字符串
*/
/*
	——————cin>>如何检查输入————————————

	不同版本的抽取运算符查看输入流的方法是相同的：
	1.它们跳过空白（空格、换行符和制表符），直到遇到非空白字符
	2.读取从非空白字符开始，到与目标类型不匹配的第一个字符之间的全部内容
	3.没读取的字符将留在输入流中，下一个cin语句继续读取
	4.如果第一个非空白字符就不是目标类型，则cin语句不会修改变量的值，并返回0，返回这个
		false可以让程序检查输入
*/
/*
	————————流状态——————————

	cin或cout对象包含一个描述流状态的数据成员（从ios_base类继承）。
	流状态由3个ios_base元素组成：eofbit、badbit、failbit
	每个元素都是一位，可以设置为1或0，1表示设置，0表示清除
		1.当cin操作到达文件末尾时，它将设置为eofbit
		2.当cin操作未能读取到预期的字符时，它将设置为failbit
		3.I/O失败，也可能将failbit设置为1
		4.当三个状态全部设置为0时，说明一切顺利。
		5.程序可以检查流状态，并使用这种信息来决定下一步做什么

	-----成员----------------------------描述--------------------
	eofbit					达到文件尾，设置为1
	badbit					如果流被破坏，例如文件读取错误，设置为1
	failbit					如果输入操作未能读取预期字符，设置为1
	goodbit					另一种表示0的写法
	good()					如果流可以使用，则返回true
	eof()					如果eofbit被设置为1，则返回true
	bad()					如果badbit被设置为1，则返回true
	fail()					如果failbit被设置为1，则返回true
	rdstate()				返回流状态
	exceptions()			返回一个位掩码，指出哪些标记导致异常被引发
	clear(iostate s)		将流状态设置为s,s的默认值为0，
							如果(restate()& exceptions())!=0则引发异常
							basic_ios::failure
	exceptions(isostate ex)	设置哪些状态将导致clear()引发异常。
							例如如果ex = eofbit，则如果eofbit被设置（到达文件尾）
							clear()将引发异常basic_ios::failure
	（1）设置状态：
		clear()方法将状态设置为它的参数：
			clear(); 没参数则把三个状态位都清除（设置为0）
			clear(eofbit);只有eofbit设置为1，另外两个状态位被清除
		setstate()方法只影响其参数已设置的位：
			setstate(eofbit);只有eofbit被设置，但是其他两个不变，和原来一样

	（2）I/O和异常：
		ios_base::failure异常类是从std::exception类中派生的，因此包含what()方法

	（3）流状态的影响：
		1.只有在流状态良好（所有位都被清除）的情况下，下面测试才返回true:
			while(cin>>input);
		2.如果流状态被设置，流将对后面的输入或输出关闭，直到位被清除。
			只用clear()还不够，错误输入仍留在输入队列中，必须跳过它：、
			法一：一直读取字符，直到空白为止，isspace()函数是一个cctype函数，
				它在参数是空白字符时返回ture
				while(!isspace(cin.get()))
					continue;
			法二：丢弃行中剩余部分：一直读直到换行符
				while(cin.get()!='\n')
					continue;
*/
/*
	————————其他istream类方法——————————
	成员函数（又称方法）get(char&)和get(void) 提供不跳过空白字符的单字符输入功能
	函数（非成员函数）get(char* ,int,char)和getline(char*,int,char)在默认情况下
		读取整行而不是一个单词
	上述两个都称为 非格式化输入函数，因为它们只是读取字符输入，而不会跳过空白，也不进行数据转换
	
	1.单字符输入
	（1）成员函数get(char & ch)：将输入字符赋给其参数，即使是空白字符
		1.cin.get(ch)返回调用函数的引用，因此可以cin.get(ch1).get(ch2);
		2.cin.get(char&)到达文件尾时，不会进行赋值（没值可赋），同时还会调用
			setstate(failbit)，导致cin的测试结果为false
	（2）成员函数get(void)：利用返回值将输入传递给程序，也读取空白字符
			ch = cin.get();
			1.get(void)成员函数返回类型是int（字符编码），不是类对象，不能连用
			3.到达文件尾，返回值EOF——头文件iostream提供的符号常量。可以用来读取输入

	2.采用哪种单字符形式
		跳过空白：使用抽取运算符>>
		不跳过：get(char&)

	3.字符串输入：成员函数getline()和get()的字符串读取版本都读取字符串，且函数特征标相同
	istream& get(char* , int , char);
	istream& getline(char* , int ,char);
	istream& get(char* , int);
	istream& getline(char* , int);
	第一个参数是用于放置输入字符串的内存单元的地址
	第二个参数比要读取的字符串的最大字符数大1
	第三个参数指定用作分界符的字符，只有两个参数的版本用换行符当分界符
		01.上述函数都在读取最大字符或者换行符后为止
		02.区别：
			get()将换行符留在输入流中
			getline()抽取并丢掉输入流中的换行符
	
	ignore()成员函数：读取并丢弃字符
		原型：istream& ignore(int = 1 , int = EOF);
		第一个参数表示读取的最大字符数，第二个参数是字符用作分界符
		cin.ignore(255,'\n');

	4.意外字符串输入
	（1）不能抽取字符时，两个函数get()和getline()将把空值字符放置到输入字符串中，并使用
		setstate()设置failbit。
		情况一：输入方法立刻到达了文件尾
		情况二：对于get(char*,int)输入了空行，因为它不读取换行符，而是留在输入流。
				反观getline()即使输入空行，它也读取，只是不存储
	（2）遇到文件尾时将设置eofbit，遇到流被破坏，将设置badbit
	（3）如果getline()输入队列数的字符数等于或者超过了
			输入方法指定的最大字符数，则设置failbit
			反观get()则不会。
	
*/
/*
	——————其他istream方法————————————

	read()函数读取指定数目的字节，并将它们存储在指定的位置中，
		char gross[44];
		cin.read( gross , 44);
		1.read()不会在输入后加上空值字符，不能将输入转换为字符串
		2.经常和ostream write()函数结合使用，完成文件输入和输出
		3.返回istream& ，可以拼接
	peek()函数返回输入中的下一个字符，但不能抽取输入流中的字符，即只查看不抽取
		1.假设遇到换行符或句点就停止：
			while( (ch = cin.peek()) != '.'&& ch != '\n' );
	gcount()方法返回最后一个非格式化抽取方法读取的字符数
	putback()函数将一个字符插入到输入字符串中，被插入的字符将是下一条输入语句读取的第一个
	字符
		1.接受一个char参数——要插入的字符，返回一个istream&
*/





#include<iostream>
#include<exception>
//test cin>>hex
void test01();
//test basic_ios::failure
void test02();

int main()
{
	//test01();
	test02();
	return 0;
}

void test01()
{
	int n;
	std::cin >> n;
	int m;
	std::cin >> std::hex >> m;
	std::cout << n << "\n" << m << "\n";
}

void test02()
{
	using namespace std;
	//设置读取失败 作为clear()引发异常的原因
	cin.exceptions(ios_base::failbit);
	cout << "Enter numbers:  ";
	int sum = 0;
	int input = 0;
	try {
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure& bf)
	{
		cout << bf.what() << endl;
		cout << "O the horror\n";
	}
	cout << "Last value entered = " << input << endl;
	//cin >> input;没有清除位之前，不能再输入了
}

