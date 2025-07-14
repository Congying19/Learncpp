#include<iostream>
#include"mytime.h"

int main() {
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing)  = ";
	total.Show();
	cout << endl;

	total = planning + fixing; //相当于planning.operator+(fixing)
	cout << "planning + fixing  = ";
	total.Show();
	cout << endl;

	total = total + coding + fixing;//相当于total.operator+(coding + fixing)   //coding + fixing返回一个Time对象  因此可以连续加
	cout << "total + coding + fixing  = ";
	total.Show();
	cout << endl;

	Time diff;
	diff = fixing - coding;
	cout << "fixing - coding = ";
	diff.Show();
	cout << endl;

	double n = 0.5;
	Time result;
	result = diff * n;//n * diff就不行，得另外重载
	cout << "diff*0.5=";
	result.Show();
	cout << endl;

	result = n * diff;
	cout << "0.5*diff = ";
	cout << result << endl;
	return 0;
}