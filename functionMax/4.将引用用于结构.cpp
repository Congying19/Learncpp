#include<iostream>
#include<string>
using namespace std;
struct free_throws
{
	string name;
	int made;//制作成功个数
	int attempt;//制作尝试次数
	float percent;//所占百分比
};
void display(const free_throws& ft);
void set_pc(free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);
int main() {
	free_throws one = { "Mark",13,14 };
	free_throws two = { "Jack",10,16 };
	free_throws three = { "Mary",7,9 };
	free_throws four = { "Tom",5,9 };
	free_throws five = { "Tim",6,14 };
	free_throws team = { "Throwgoods",0,0 };//整个团队

	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	dup = accumulate(team, five);
	cout << "Displaying team:\n";
	display(team);
	cout << "Displaying dup after assignment:\n";
	display(dup);
	return 0;
}

void display(const free_throws& ft)
{
	cout << "Name: " << ft.name << endl;
	cout << "Made: " << ft.made << endl;
	cout << "Attempts: " << ft.attempt << endl;
	cout << "Percent: " << ft.percent << endl;
}

void set_pc(free_throws& ft)
{
	if (ft.attempt != 0) {
		ft.percent = 100.0f * float(ft.made) / float(ft.attempt);
	}
	else {
		ft.percent = 0;
	}
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempt += source.attempt;
	target.made += source.made;
	set_pc(target);
	return target;//返回引用 返回引用的函数实际上是被引用的变量的别名
	//传统返回变量 是先复制到临时位置 再复制到函数调用位置
	//返回引用是直接复制到函数调用位置 效率更高

	//不能返回临时变量的引用和指针 因为函数结束这个临时变量就不复存在了
}

//使用引用的理由：1.想修改数据 2.通过传递引用而不是数据对象 提高程序运行速度

//对于使用传递的值而不修改的函数：
//1、数据对象很小 按值传递
//2、数据对象是数组 使用指针 并将指针声明为指向const的指针
//3、数据对象是较大结构 使用const指针或const引用 
//4、数据对象是类对象 则使用const引用