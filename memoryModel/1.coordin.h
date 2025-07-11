#pragma once
//头文件常包含一下内容：
//函数原型
//使用#define或者const定义的符号常量
//结构声明
//类声明
//模版声明
//内联函数
//解释：声明不创建变量，从而被使用时不会导致多重声明的问题。而const数据和内联函数有特殊的链接属性，因此可以包含在头文件中


#ifndef COORDIN_H_ //#ifndef即为if not defined 表示只有在以前没有使用预处理器编译指令#define定义名称COORDIN_H_时，才处理#ifndef和#endef之间的代码
//能够避免同文件被多次包含
#define COORDIN_H_//通常COORDIN_H_后面还要跟具体值 但这里只是作为记号使用 #define COORDIN_H_;就已经定义了名称COORDIN_H_。
//编译器第一次遇到名称COORDIN_H_时这个名称还没有被定义 就会执行#ifndef和#endef之间的代码 从而COORDIN_H_就被定义了 下次就不执行
//结构声明
struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};
//函数声明
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
#endif
