//1.ʹ��new�������ʼ����
//����һ�������﷨��int *pi = new int (6);
//���������������﷨��
// struct where{double x,double y,double z};
// where *one = new where{2.5,3.3,4.6};

//2.��λnew�����
//ͨ����new�����ڶ����ҵ�һ�������ܹ�����Ҫ����ڴ�顣
//new����һ�ֱ��壬����Ϊ��λnew�����������ָ��Ҫʹ�õ�λ�á�
#include<iostream>
#include<new>//ʹ�ö�λnew���������������ͷ�ļ���
using namespace std;
const int BUF = 512;
const int N = 5;
char buffer[BUF];
int main() {
	double* pd1, * pd2;
	int i;
	cout << "Calling new and placement new:\n";
	pd1 = new double[N];//�ڶ�������λ��
	pd2 = new (buffer) double[N];//ֱ����buffer��������λ��
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "Memory addresses:\n" << " heap:" << pd1
		<< " static:" << (void*)buffer << endl;//��char��������ǿ��ת��
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete[] pd1;//ֻ���ͷų���new������ڴ� �����ͷŶ�λnew����������ı���
}