#include<cmath>
#include"vector.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{//名称空间开放性可以随时添加：
	const double Rad_to_deg = 45.0 / atan(1.0);//rad换算成度
	
	void Vector::set_mag()//已知直角坐标设置极坐标
	{
		mag = sqrt(x * x + y * y);//私有成员函数计算向量长度
	}

	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	//已知极坐标求直角坐标
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{//一个向量用两种方式表达：
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() --";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{//虽然reset()函数跟构造函数一模一样 但是使用时可以直接改变对象 而不是先创建临时对象再赋值改变对象
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() --";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector& b)const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-(const Vector& b)const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-()const
	{
		return Vector(-x, -y);//重载负号
	}

	Vector Vector::operator*(double n)const
	{
		return Vector(n * x, n * y);
	}

	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	;
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)//友元函数不属于类，不在类的作用域里面，因此要访问RECT必须加上作用域，而成员函数则不用。
		{
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		}
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}