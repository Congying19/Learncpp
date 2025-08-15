// useless.cpp -- an otherwise useless class with move semantics
#include <iostream>
using namespace std;

// interface
class Useless
{
private:
    int n;    // number of elements 元素个数
    char* pc;    // pointer to data 元素指针
    static int ct;  // number of objects    对象创建个数，静态变量：整个类公有
    void ShowObject() const; //展示对象函数

public:
    Useless();//默认构造函数
    explicit Useless(int k);//强制显式转换
    Useless(int k, char ch);//带参数构造函数
    Useless(const Useless& f); // regular copy constructor 复制构造函数
    Useless(Useless&& f);    // move constructor 移动构造函数
    ~Useless();
    Useless operator+(const Useless& f)const; //重载加法运算
    // need operator=() in copy and move versions
    void ShowData() const;
};

// 类实现
int Useless::ct = 0; //使用类名访问静态数据成员

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "int, char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless& f) : n(f.n)
{
    ++ct;
    cout << "copy const called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}
Useless::Useless(Useless && f) : n(f.n)
{
    ++ct;
    cout << "move constructor called; number of objects: " << ct << endl;
    pc = f.pc;    // steal address 转让地址，也称为窃取
    f.pc = nullptr;  // give old object nothing in return 右值引用可以被复制，返回一个空地址给原来对象
    //防止析构函数析构两次
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "destructor called; objects left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete[] pc;
}

Useless Useless::operator+(const Useless & f)const
{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for (int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void*)pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "(object empty)";
    else
        for (int i = 0; i < n; i++)
            cout << pc[i];
    cout << endl;
}

// application
int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;    // calls copy constructor
        Useless three(20, 'o');
        Useless four(one + three); // 右值引用参数可以是表达式，这里调用移动构造函数
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
}
/*
    运行结果：
    int, char constructor called; number of objects: 1
    Number of elements: 10 Data address: 0000020EC5174190
    copy const called; number of objects: 2
    Number of elements: 10 Data address: 0000020EC5174730
    int, char constructor called; number of objects: 3
    Number of elements: 20 Data address: 0000020EC51748C0
    Entering operator+()
    int constructor called; number of objects: 4
    Number of elements: 30 Data address: 0000020EC516FE20
    temp object:
    Leaving operator+()
    object one: xxxxxxxxxx
    object two: xxxxxxxxxx
    object three: oooooooooooooooooooo
    object four: xxxxxxxxxxoooooooooooooooooooo
    destructor called; objects left: 3
    deleted object:
    Number of elements: 30 Data address: 0000020EC516FE20
    destructor called; objects left: 2
    deleted object:
    Number of elements: 20 Data address: 0000020EC51748C0
    destructor called; objects left: 1
    deleted object:
    Number of elements: 10 Data address: 0000020EC5174730
    destructor called; objects left: 0
    deleted object:
    Number of elements: 10 Data address: 0000020EC5174190
*/

/*
    由输出结果可知，创建对象four时，没有调用任何构造函数。相反，编译器推断出对象four是operator+()
    所做工作的受益人，因此将operator+()创建的对象转到four的名下。
    一般而言，编译器完全可以进行优化，只要结果与未优化时相同。
*/