#include<iostream>
using namespace std;
long double probability(unsigned numbers, unsigned picks); //unsigned int ���unsigned
//�����numbers�г�picks�� ���н��ĸ���
int main() {
	double total, choice;
	cout << "���뿨Ƭ��������Ҫ��ȡ��������\n";
	while (cin >> total >> choice && choice <= total) {//��cin>>������������������� �ֿ����ж��Ƿ����
		cout << "���н��ĸ����ǣ�\n";
		cout << 1/probability(total, choice)<<endl;
		cout << "�ٴ������������֣�����q�����˳�����\n";
	}
	return 0;
}

long double probability(unsigned numbers, unsigned picks)//���ڽ��մ���ֵ�ı�����Ϊ�β� �βθı�ʱ ʵ�β���ı�
{
	long double result = 1.0;//�������������ľֲ����� ֻ�ں������������� �ͱ�ĵط�����û�й�ϵ ��ʹ����һ��
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; p--, n--) {
		result = result * n / p;//���ó�һ����һ������ �����ȳ˺��ʱ�м������󳬳���Χ
	}
	return result;//����ֵ���� ����ͺ���ͷһ��
}
