/*
	————————1.简单的文件I/O——————————

	-------程序写入文件必须这样做：
		1.创建一个ofstream对象来管理输出流
		2.将该对象与特定的文件关联起来
		3.把该对象当成cout来使用，唯一的区别是输出将进入文件，而不是屏幕

	首先包含头文件fstream（该文件自动包含iostream文件，不必显示包含iostream）
	然后声明一个ofstream对象：	
			ofstream fout;
			对象名可以是任意有效的C++名称，fout,outFile,
	接下来，必须将这个对象与特定文件关联，可以使用open()
		fout.open("jar.txt");
		或者利用构造函数将两步合并：
		ofstream fout("jar.txt");
		以这种方式打开文件来进行输出时，如果没有这样的文件，将创建一个新文件
			如果有这样的文件，则打开文件将清空文件。
	然后，像使用cout那样，使用fout：
		fout<<"hello world";

	由于ostream是ofstream的基类，可以使用所有的ostream方法，包括各种插入运算符定义、
	格式化方法和控制符。
	ofstream类使用被缓存的输出，程序在创建ofstream对象时，将为输出缓冲区分配空间。
	如果有两个对象就有两个输出缓冲区，每个对象各一个

	-------读取文件的要求与写入文件类似：
	包含fstream头文件
	声明ifstream对象					ifstream fin;
	将其与文件名关联起来				fin.open("jexy.txt");
	使用								fin>>buf;

	------文件关闭：
	1.当输入和输出流对象过期（如程序终止）时，与文件的连接将自动关闭
	2.使用close()方法来显式的关闭到文件的连接：fin.close()	fout.close()
	3.关闭连接不会删除流，只是断开与文件的连接，fin对象与它管理的输入缓冲区仍然存在，
		可以将流重新连接到同一个文件或者另一个文件
*/
/*
	——————————2.流状态检查和is_open()——————————————

	C++文件流从ios_base类那里继承了一个流状态成员。
	该状态成员指出了流状态信息：一切顺利、已经到达文件尾、I\O操作失败
	
	由于ifstream对象和istream对象一样，被放在 需要bool类型的地方 时，将被转换为
	bool值 ， 因此可以这样：
	fin.open("jext.txt");
	if(!fin){...}

	可以使用is_open()方法：
	if(!fin.is_open()) {...};
	这种方法之所以更好，因为它能检测出其他方式不能检测的微妙问题
*/
/*
	——————————3.打开多个文件——————————————

	如果需要同时打开两个文件，则必须分别为每个文件创建一个流
	如果需要依次处理一组文件，可以打开一个流，依次关联到各个文件：
			ifstream fin;
			fin.open("file1.txt");
			....
			fin.close();
			fin.clear();
			fin.open("file2.txt");
			...
			fin.close();
			fin.clear();
*/
/*
	——————————4.命令行处理技术——————————————
	
	文件处理程序通常使用命令行参数来指定文件。
	例如：要在UNIX和Linux系统中计算文件包含的字数，可以在命令行提示符下输入下面命令：
			wc report1 report2 report3
		其中wc是程序名，report1-3是作为命令行参数传递给程序的文件名

	C++有一种让 在命令行环境中运行的程序 能够访问命令行参数 的机制，方法是使用：
	int main(int argc , char *argv[] );
	argc为命令行中的参数个数，包括命令名本身
	argv是一个指针数组，argv[0]是一个指针，指向存储第一个命令行参数的字符串的第一个字符
	如果有下面命令行：
	wc report1 report2 report3
	则argc = 4 , argv[0] = wc ,....
*/
/*
	———————————5.文件模式——————————————————

	文件模式描述的是文件将如何被使用：读、写、追加等
	将流和文件关联时，可以提供指定文件模式的第二个参数
	ios_base类定义了一个openmode类型，用于表示模式
	-------常量------------------------------------含义--------------------
	ios_base::
			in						打开文件，以便读取
			out						打开文件，以便写入
			ate						打开文件，并移到文件尾
			app						追加到文件尾
			trunc					如果文件存在，则截短文件
			binary					二进制文件

	ifstream open() 将ios_base::in 作为模式参数的默认值
	ofstream open() 将ios_base::out|ios_base::trunc作为默认值
	位运算符OR（|）将两个位值并合并成一个可用于设置两个位的值

	fstream类不提供默认的模式值，创建对象时必须显式地提供

	ios_base::trunc打卡文件并截短，相当于清空以前的内容
	ios_base::app可以追加在文件尾，保留文件内容：
		ofstream fout("bagels", ios_base::out|ios_base::app);

	--------1.追加文件：使用ios_base::app打开

	--------2.二进制文件：
	将数据存储在文件时，可以将其存储为文本格式或二进制格式。

	文本格式指的是将所有内容都存储文本，包括将数字存储为对应字符。这需要将数字的计算机内部表示
			转换为字符格式，这正是<<插入运算符完成的工作
		优点：方便将一个文本从一个计算机系统传输到另一个计算机系统

	二进制格式是存储值的计算机内部表示。
		优点：1.对于数字来说比较精确，不会有转换误差或舍入误差
			  2.二进制格式保存数据的速度更快，不需要转换可以大块地存储数据
			  3.二进制格式通常占用内存小
			  4.另一种系统可能使用另一种内部表示，可能无法传输
	
	举例：对于一种结构：
		struct planet{ name; population ; g}  ;  planet p1;
	以文本格式保存：
		fout<<p1.name<<" "<<p1.population<<" "<<p1.g<<endl;
		缺点：需要自己手动加空格隔开，如果成员很多则很麻烦
	以二进制格式保存：
		ofstream fout( "planet.dat" , ios::out|ios::app|ios::binary );
		fout.write( (char*) &p1, sizeof p1 );
		//write()将内存中指定数目的字节复制到文件中
	恢复信息：
		ifstream fin( "planet.dat" , ios::in|ios::binary );
		fout.read( (char*) &p1, sizeof p1 );
		//这将从文件中复制sizeof p1个字节到p1结构中
	对于不使用虚函数的类，也可以这样保存，但是只有数据成员保存，方法不会被保存
*/
/*
	————————6.随机存取——————————————————————————

	随机存取指的是直接移动到文件的任何位置
	随机存取常被用于数据库文件，程序维护一个独立的索引文件，该文件指出数据在主数据文件中的位置。
	程序可以直接跳到这个位置，读取其中数据。
	如果文件由长度相同的记录组成，则这种方法实现起来非常容易。文件记录对应于结构或类

	可以创建fstream对象，以读写模式打开文件
	fstream对象从iostream类派生而来，而iostream类又是基于istream类和ostream类。
	因此fstream对象继承了两个缓冲区，一个用于输入，一个用于输出，并能同步化这两个缓冲区的处理。
		也就是说，当程序读写文件时，它将协调地移动输入缓冲区的输入指针和输出缓冲区的输出指针。

	fstream类继承了两个方法：seekg()和seekp()。
	seekg()将 输入指针 移动到指定的文件位置，
	seekp()将 输出指针 移动到指定的文件位置
	实际上，fstream类使用缓冲区来存储中间数据，因此指针指向的是缓冲区的位置，而不是实际的文件

	seekg()使用的是模版，对于char具体化，其原型为：
	istream& seekg( streamoff, ios_base::seekdir);
			定位到离第二个参数指定的文件位置特定距离（单位为字节）的位置
			seek_dir参数是ios_base类中定义的一种整型，有3个可能得值：
				ios_base::beg——相对文件开始处的偏移量
				ios_base::cur——相对当前位置的偏移量
				ios_base::end——相对文件尾的偏移量
	istream& seekg( streampos );
			定位到离文件开头特定距离的位置。第一个字节编号为0，即记得加1

	检查文件指针的当前位置：输入流——tellg()，输出流——tellp()，它们都返回streampos值，
		表示当前位置到文件开始处的距离。由于fstream对象的输入和输出一起管理，因此输入指针和输出指针
		将一前一后地移动，即tellg()和tellp()返回值相同。如果分开管理则不一样

*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> // for exit()
#include<iomanip>
const char* file = "guest.txt";//for test03()

//test04 数据：
inline void eatline() { while (std::cin.get() != '\n' )continue;
}
struct planet
{
	char name[20];
	double population;
	double g;
};
const char* file2 = "planets.dat";
//test 01
void test01();
void test02();
/*
	test03()：维护一个存储来客清单的文件。
*/
void test03();

//test binary
void test04();

//test 随机读取：
void test05();
int main()
{
	//system("cmd");
	//test01();
	
	//test03();

	//test04();
	
	test05();
	return 0;
}

void test01()
{
	using namespace std;
	string filename;

	cout << "Enter name for new file : ";
	cin >> filename;
	//给文件提供文件名：
	ofstream fout(filename.c_str());

	fout << "For your eyes only!\n";
	cout << "Enter your secret number: ";
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();

	ifstream fin(filename.c_str());
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))
		cout << ch;
	cout << "Done\n";
	fin.close();
}

void test02(int argc, char* argv[])
{
	using namespace std;
	if (argc == 1)//没有命令行参数就退出
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;
	long count;
	long total = 0;
	char ch;

	for (int file = 1; file < argc; file++)
	{
		//和命令行中每个文件关联
		fin.open(argv[file]);
		if (!fin.is_open())
		{
			cerr << "Could not open " << argv[file] << endl;
			fin.clear();
			continue;
		}
		count = 0;
		while (fin.get(ch))
			count++;
		cout << count << " characters in " << argv[file] << endl;
		total += count;
		fin.clear();
		fin.close();
	}
	cout << total << " characters in all files\n";
}

void test03()
{
	using namespace std;
	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << file << "file: \n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names ( enter a blank line to quit ):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << file << "file: \n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	cout << "Done\n";
}

void test04()
{
	using namespace std;
	planet p1;
	cout << fixed << right;

	ifstream fin;
	fin.open(file2,ios::in|ios::binary);

	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << file2 << "file: \n";
		while (fin.read((char*)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}

	ofstream fout(file2, ios::out | ios::app | ios::binary);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file2 << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter planet name (enter a blank line to quit ):\n";
	cin.get(p1.name,12);
	while (p1.name[0] != '\0')
	{
		eatline();
		cout << "Enter planetary population: ";
		cin >> p1.population;
		cout << "Enter planet's acceleration of gravity: ";
		cin >> p1.g;
		eatline();
		fout.write((char*)&p1, sizeof p1);
		cout << "Enter planet name (enter a blank line to quit ):\n";
		cin.get(p1.name, 12);
	}
	fout.close();

	fin.clear();
	fin.open(file2, ios::in | ios::binary);

	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << file2 << "file: \n";
		while (fin.read((char*)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	cout << "Done\n";
}

void test05()
{
	using namespace std;
	planet p1;
	cout << fixed ;

	//随机读写对象：
	fstream finout;
	finout.open(file2, ios::in | ios::out | ios::binary);
	//当做记录号，以便随机访问
	int ct = 0;
	if (finout.is_open())
	{
		//将指针移到开始处：
		finout.seekg(0);
		cout << "Here are the current contents of the " << file2 << " file : \n";
		while (finout.read((char*)&p1, sizeof p1))
		{
			cout << ct++ << ": " << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population<<"\t"
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		if (finout.eof())
			finout.clear(); // 读到文件尾要清空设置，不然会影响下一次写入
		else
		{
			cerr << "Error in reading " << file2 << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file2 << " could not be opened -- bye.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter the record number you wish to change: ";
	long rec;
	cin >> rec;
	eatline();//每次输入完就要清空行
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invailid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	/*
	相同的数据结构所占字节相同，一个文件里面存储相同数据
	因此，直接利用 编号 乘 每个结构所占字节 即可获得距离文件开头的字节距离
	*/
	streampos place = rec * sizeof p1;
	//将指针定位到这个位置——随机访问
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "Error on attempted seek.\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&p1, sizeof p1);
	cout << "Your selection:\n";
	cout << rec << ": " << setw(20) << p1.name << ": "
		<< setprecision(0) << setw(12) << p1.population << "\t"
		<< setprecision(2) << setw(6) << p1.g << endl;
	if (finout.eof())
		finout.clear();

	cout << "Enter planet name: ";
	cin.get(p1.name, 20);
	eatline();
	cout << "Enter planetary population: ";
	cin >> p1.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> p1.g;
	finout.seekp(place);
	finout.write((char*)&p1, sizeof p1) << flush;
	if (finout.fail())
	{
		cerr << "Error on attempted seek.\n";
		exit(EXIT_FAILURE);
	}
    ct = 0;
	if (finout.is_open())
	{
		//将指针移到开始处：
		finout.seekg(0);
		cout << "Here are the current contents of the " << file2 << " file : \n";
		while (finout.read((char*)&p1, sizeof p1))
		{
			cout << ct++ << ": " << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population << "\t"
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		if (finout.eof())
			finout.clear(); // 读到文件尾要清空设置，不然会影响下一次写入
		else
		{
			cerr << "Error in reading " << file2 << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file2 << " could not be opened -- bye.\n";
		exit(EXIT_FAILURE);
	}
	finout.close();
	cout << "Done\n";

}