//��̬���ࣺ�ڱ���ʱ����������ڴ棬��ʹ����ʱ��ʹ��������顣�����ڱ�д����ʱȷ�������С��
//��̬���ࣺʹ��new��������ʱ��Ҫ�ʹ���������������ʱȷ�����鳤�ȡ�
#include<iostream>
using namespace std;
int main() {
	//1.ʹ��new �������飺
	int* psome = new int[3];//��Ԫ�����ͺ���Ŀ����new��new��������ص�һ��Ԫ�صĵ�ַ��psome

	//ʹ�ö�̬���飺��ָ�뵱����������ʹ�ã�
	psome[0] = 1;
	psome[1] = 2;
	psome[2] = 4;
	cout << psome[0] << endl;
	cout << psome[1] << endl;
	cout << psome[2] << endl;

	//ָ��������ָ�����+1�����ӵ�������ָ�����͵��ֽ���
	cout << " psome is " << psome << " . *psome is " << *psome << endl;
	cout << " psome+1 is " << (psome + 1) << " . *(psome+1) is " << *(psome + 1) << endl;

	//C++������������Ϊ��һ��Ԫ�صĵ�ַ
	int p1[3] = { 1,2,3 };
	cout << "p1 is " << p1 << endl;
	cout << "&p1[0] is " << &p1[0] << endl;//һ��Ԫ�صĵ�ַ����һ��4�ֽ��ڴ��ĵ�ַ
	cout << "&p1[0]+1 is " << &p1[0]+1 << endl;
	cout << "&p1 is " << &p1 << endl;//����Ԫ�صĵ�ַ����һ��12�ֽ��ڴ��ĵ�ַ
	cout << "&p1+1 is " << &p1 + 1 << endl;

	//�����ʾ����ָ��psome[1],������p1[1]    �ڱ������п�����*(psome+1) *(p1+1)  ���ֱ�ʾ����������
	//��������1��ָ������޸� �������ǳ����������޸�
	//��������2��sizeof����������õ��������鳤�ȣ�������ָ��õ�����ָ�ų��ȡ�
	cout << "sizeof p1 is " << sizeof p1 << endl;//���鳤��=�������*�����ֽ�
	cout << "the number of p1 is " << sizeof p1 / sizeof p1[0] << endl;
	cout << "sizeof psome is " << sizeof psome << endl;
	delete[] psome;//[]���߳���Ӧ���ͷ��������������ָ��ָ���Ԫ�ء�
	return 0;
}
