//cv-限定符：const 和 volatile 
//volatile表示即使程序代码没有对内存单元进行修改，其值也可能发生变化（硬件可能修改其中的内容）。volatile告诉编译器不要假设某个变量的值不变。

//mutable:可以用mutable指出，即使结构（或类）变量为const，其某个成员也可以被修改。
//struct data
//{
//	char name[20];
//	mutable int accesses;
//};
//const data veep = { "JOll",0 };
//veep.accesses++;

//const:
//1.全局变量前面加const 跟加static效果一样，将链接性变成内部。这使得能在头文件里面使用const，别的源文件包含头文件时，都是内部链接性的全局变量，
//不会违反单定义规则。
//那怎么定义外部常量？ extern const int global = 1000;这样就定义了外部常量，其他文件使用记得用extern声明