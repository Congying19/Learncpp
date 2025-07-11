//1.���ڸ����ĺ������������� ��ģ�溯����ģ�溯������ʾ���廯ģ�溯���Լ����ߵ����ذ汾
//2.��ʾ���廯��ԭ�ͺͶ�����template<>��ͷ����ͨ��������ָ������
//3.���廯�����ڳ���ģ��  ��ģ�溯�������ھ��廯�ͳ��溯��
#include<iostream>
using namespace std;
//����ģ��
template<typename T>
void Swap(T& a, T& b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

//���廯ģ��
template<> void Swap<job>(job& j1, job& j2);//���廯ģ��ԭ��
void Show(job& j);

int main() {
	cout.precision(2);//�趨���С�����2λ
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j = " << i << ", " << j << ".\n";
	cout << "ʹ�ó���ģ��\n";
	Swap(i, j);//�����ṩ��int��������int��ģ��ʵ�� ��Ϊ��ʽʵ����
	Swap<int>(i,j);// ��ʽʵ���� ��
	//��ʽʵ���� ��ʽʵ���� ��ʽ���廯����Ϊ���廯
	cout << "Now i,j = " << i << ", " << j << ".\n";

	job sue = { "Susan",73000.60,7 };
	job sidney = { "Sidney",78060.72,9 };
	cout << "����ǰ��\n";
	Show(sue);
	Show(sidney);
	cout << "������\n";
	Swap(sue, sidney);
	Show(sue);
	Show(sidney);
	return 0;
}

template<typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<> void Swap<job>(job& j1, job& j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job& j)
{
	cout << j.name << ":  $" << j.salary
		<< " on floor " << j.floor << endl;
}