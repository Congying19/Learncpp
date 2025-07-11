#include<iostream>
using namespace std;
void swap1(int& a, int& b);
void swap2(int* a, int* b);
void swap3(int a, int b);
double cube(const double& a);//ʹ�����õ��ǲ��޸ı��� �⿴������ֵ�������� �����ڴ������ݴ�ı���ʱ ����Ҫ�������� ��˺�����

int main() {
	int wallet1 = 200;
	int wallet2 = 300;
	cout << "�����ô��ݽ�����\n";
	swap1(wallet1, wallet2);
	cout << "wallet1 = " << wallet1 << endl;
	cout << "wallet2 = " << wallet2 << endl;

	cout << "����ַ���ݽ�����\n";
	swap2(&wallet1, &wallet2);
	cout << "wallet1 = " << wallet1 << endl;
	cout << "wallet2 = " << wallet2 << endl;
	
	cout << "��ֵ���ݽ�����\n";
	cout << "wallet1 = " << wallet1 << endl;
	cout << "wallet2 = " << wallet2 << endl;

	double a = 3.0;
	cout << cube(a) << " = cube of " << a << endl;
	//����const���� ��ֻ������Ϣ ���ı�ֵ��ʱ�� ������������������´�����ʱ������
	//1.ʵ��������ȷ����������ֵ����һЩ���ʽ�ȵ�
	//2.ʵ�����Ͳ���ȷ�����ǿ���ת��Ϊ��ȷ����
	//��ʱ����ֻ�ں�������ʱ���� ����������������ɾ��
	long b = 5L;
	cout << cube(b) << " = cube of " << b << endl;
	cout << cube(4.2 + 1.8) << " = cube of " << 4.2 + 1.8 << endl;
	//������ʹ��const,��Ϊ��
	//1.ʹ��const���Ա����������޸����ݵı�̴���
	//2.ʹ��constʹ�����ܹ�����const�ͷ�constʵ�Σ�����ֻ�ܽ��շ�constʵ��
	
	return 0;
}

void swap1(int& a, int& b)//�����β��ں������ô���ʼ��Ϊʵ��
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap3(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

double cube(const double& a)
{
	return a * a * a;
}