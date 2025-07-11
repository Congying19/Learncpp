//����ģ�棺�������㷨��ͬ ֻ�Ǳ������Ͳ�ͬʱ �����ú���ģ��򻯱�� ����ʵ�����ɵĿ�ִ�г���û������
#include<iostream>
using namespace std;
//ģ��ԭ�ͣ�
template<typename T>//���üӷֺ� Ҳ����д��class <typename T>  
void Swap(T& a, T& b);//д��ģ��ԭ��֮��Ϳ��԰�ģ�浱�ɱ�������ʹ��

//�������㷨��һ��ʱ �������غ���ģ��
template<typename T>//Ҫ��ʼʹ��ģ����
void Swap(T* a, T* b, int n);
void Show(int a[]);
const int Lim = 8;
int main() {
	int i = 10;
	int j = 20;
	cout << "i,j = " << i << "," << j << ".\n";
	cout << "After swap\n";
	Swap(i, j);//���ݴ���Ĳ�����int ����Swap(int &a, int &b)����
	cout << "Now i,j = " << i << "," << j << ".\n";

	double x = 14.5;
	double y = 20.6;
	cout << "x,y = " << x << "," << y << ".\n";
	cout << "After swap\n";
	Swap(x, y);//���ݴ���Ĳ�����int ����Swap(int &a, int &b)����
	cout << "Now x,y = " << x << "," << y << ".\n";

	int a1[Lim] = { 1,2,3,4,6,7,8,5 };
	int a2[Lim] = { 4,5,2,7,4,8,6,1 };
	Show(a1);
	Show(a2);
	cout << "After swap\n";
	Swap(a1, a2, Lim);
	Show(a1);
	Show(a2);
	return 0;
}

//����ģ�涨�壺
template<typename T>//���߱���������Ҫ��ʼʹ��ģ����
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//��������
template<typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	for (int i = 0; i < Lim; i++)
	{
		cout << a[i];
	}
	cout << endl;
}