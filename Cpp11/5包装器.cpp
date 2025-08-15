/*
	（1）包装器function及模版的低效性：

	示例：
		// somedefs.h
        #include <iostream>
        template <typename T, typename F>
        T use_f(T v, F f)
        {
            static int count = 0;
            count++;
            std::cout << " use_f count = "<< count
            << ", &count = "<< &count << std::endl;
            return f(v);
        }

        class Fp
        {
        private:
            double z_;
        public:
            Fp(double z = 1.0) : z_(z) {}
            double operator()(double p) { return z_*p; }
        };

        class Fq
        {
        private:
            double z_;
        public:
            Fq(double z = 1.0) : z_(z) {}
            double operator()(double q) { return z_+ q; }
        };

        // callable.cpp -- callable types and templates
        #include "somedefs.h"
        #include <iostream>

        double dub(double x) {return 2.0*x;}
        double square(double x) {return x*x;}

        int main()
        {
            using std::cout;
            using std::endl;

            double y = 1.21;
            cout << "Function pointer dub:\n";
            cout << " "<< use_f(y, dub) << endl;
            cout << "Function pointer square:\n";
            cout << " "<< use_f(y, square) << endl;
            cout << "Function object Fp:\n";
            cout << " "<< use_f(y, Fp(5.0)) << endl;
            cout << "Function object Fq:\n";
            cout << " "<< use_f(y, Fq(5.0)) << endl;
            cout << "Lambda expression 1:\n";
            cout << " "<< use_f(y, [](double u) {return u*u;}) << endl;
            cout << "Lambda expression 2:\n";
            cout << " "<< use_f(y, [](double u) {return u*u/2.0;}) << endl;
            return 0;
        }

在每次调用中，模板参数 T 都被设置为类型 double。
模板参数 F 呢？每次调用时，F 都接受一个 double 值并返回一个 double 值，
因此在 6 次 use_f() 调用中，好像 F 的类型都相同，因此只会实例化模板一次。
但正如下面的输出表明的，这种想法太天真了：

Function pointer dub:
    use_f count = 1, &count = 0x402028
    2.42
Function pointer square:
    use_f count = 2, &count = 0x402028
    1.1 
Function object Fp:
    use_f count = 1, &count = 0x402020
    6.05
Function object Fq:
    use_f count = 1, &count = 0x402024
    6.21
Lambda expression 1:
    use_f count = 1, &count = 0x405020
    1.4641
Lambda expression 2:
    use_f count = 1, &count = 0x40501c
    1.815

模板函数 use_f() 有一个静态成员 count，可根据它的地址确定模板实例化了多少次。
有 5 个不同的地址，这表明模板 use_f() 有 5 个不同的实例化。

为了解其中的原因，请考虑编译器如何判断模板参数 F 的类型。
    首先，来看下面的调用：
    use_f(y, dub);
    其中的 dub 是一个函数的名称，该函数接受一个 double 参数并返回一个 double 值。
    函数名是指针，因此参数 F 的类型为 double(*) (double)：
            一个指向这样的函数的指针，即它接受一个 double 参数并返回一个 double 值。

    下一个调用如下：
    use_f(y, square);
    第二个参数的类型也是 double(*) (double)，因此该调用使用的 use_f() 实例化与第一个调用相同。

    在接下来的两个 use_f() 调用中，第二个参数为对象，F 的类型分别为 Fp 和 Fq，
    因此将为这些 F 值实例化 use_f() 模板两次。

    最后，最后两个调用将 F 的类型设置为编译器为 lambda 表达式使用的类型。
*/
/*
    （2）修复问题 ：包装器 function 让您能够重写上述程序，使其只使用 use_f() 的一个实例而不是 5 个。
    
     注意到程序清单 18.7 中的函数指针、函数对象和 lambda 表达式有一个相同的地方，
     它们都接受一个 double 参数并返回一个 double 值。
     可以说它们的调用特征标（call signature）相同。
 
     调用特征标是有返回类型以及用括号括起并用头号分隔的参数类型列表定义的，
     因此，这六个实例的调用特征标都是 double(double)。

    模板 function 是在头文件 functional 中声明的，它从调用特征标的角度定义了一个对象，
    可用于包装调用特征标相同的函数指针、函数对象或 lambda 表达式。

    例如，下面的声明创建一个名为 fdci 的 function 对象，
    它接受一个 char 参数和一个 int 参数，并返回一个 double 值：

    std::function<double(char, int)> fdci;

    然后，可以将接受一个 char 参数和一个 int 参数，
    并返回一个 double 值的任何函数指针、函数对象或 lambda 表达式赋给它。

    在程序清单 18.7 中，所有可调用参数的调用特征标都相同：double(double)。
    要修复程序清单 18.7 以减少实例化次数，可使用 function<double(double)>创建六个包装器，
    用于表示 6 个函数、函数符和 lambda。
    这样，在对 use_f() 的全部 6 次调用中，让 F 的类型都相同（function<double(double)>），因此只实例化一次。

《示例5》
*/

/*
    （6）其他方式

    下面介绍使用 function 可完成的其他两项任务。
    首先，在程序清单 18.8 中，不用声明 6 个 function<double(double)>对象，
    而只使用一个临时 function<double(double)>对象，将其用作函数 use_f() 的参数：
        typedef function<double(double)> fdd; // simplify the type declaration
        cout << use_f(y, fdd(dub)) << endl; // create and initialize object to dub
        cout << use_f(y, fdd(square)) << endl;
        ...

    其次，程序清单 18.8 让 use_f() 的第二个实参与形参 f 匹配，
    但另一种方法是让形参 f 的类型与原始实参匹配。
    为此，可在模板 use_f() 的定义中，将第二个参数声明为 function 包装器对象，如下所示：

    #include <functional>
    template <typename T>
    T use_f(T v, std::function<T(T)> f) // f call signature is T(T)
    {
        static int count = 0;
        count++;
        std::cout << " use_f count = " << count
        << ", &count = " << &count << std::endl;
        return f(v);
    }

    这样函数调用将如下：
    cout << " " << use_f<double>(y, dub) << endl;
    ...
    cout << " " << use_f<double>(y, Fp(5.0)) << endl;
    ...
    cout << " " << use_f<double>(y, [](double u) {return u*u;}) << endl;

    参数 dub、Fp(5.0)等本身的类型并不是 function<double(double)>，
    因此在 use_f 后面使用了 <double>来指出所需的具体化。
    这样，T 被设置为 double，而 std::function<T(T)>变成了 std::function<double(double)>。
*/