//�����������ú���ʱ����main()��ʼ���� ������������ʱ ����ת������λ��
//�������������������뵽main() �Ͳ�����ת����ĵط���ʡʱ��
//�����������벻��̫�� ͨ��ֻ��һ����
//�����������ܵݹ�
#include<iostream>
using namespace std;

inline double square(double x) { return x * x; }
//�ں�������ǰ���һ��inline  ��Ϊ��������
//��������ͨ��ʡ�Ժ���ԭ�� ֱ�ӰѶ������ǰ��
int main() {
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << "a = " << a << " ,b = " << b << "\n";
	cout << "c = " << c;
	cout << ",c squared = " << square(c++) << endl; //����++ �ȴ���c=13 ��c++
	cout << "Now c = " << c << endl;
	return 0;
}