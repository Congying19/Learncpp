#pragma once

//向量类：
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
namespace VECTOR
{//放在名称空间里面防止与其他名字冲突
	class Vector
	{
	public:
		enum Mode{RECT,POL};//直角坐标模式和极坐标模式
		//枚举变量描述类对象的状态，也称为状态成员
	private:
		double x;
		double y;
		double mag;//向量长度
		double ang;//向量角度
		Mode mode;//mode = RECT或者POL

		//私有成员函数设置向量
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);//默认模式是直角坐标
		void reset(double n1, double n2, Mode form = RECT);//重新设置
		~Vector();
		double xval()const { return x; }//访问x值的接口
		double yval()const { return y; }//只访问 不修改
		double magval()const { return mag;}//类声明中定义的函数自动生成内联函数
		double angval()const { return ang; }
		void polar_mode();//将模式转换为角坐标
		void rect_mode();//将模式转换为直角坐标
		Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif
