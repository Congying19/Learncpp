//���ã���������һ������
#include<iostream>
using namespace std;
int main() {
	int rats = 101;
	//���ñ���������
	int& rodents = rats;//int &��int *һ�� ��ʾrodents��ָ��int������
	cout << "rats = " << rats << " at "<<&rats<<endl;
	cout << "rodents = " << rodents << " at " << &rodents << endl;
	rodents++;
	cout << "rats = " << rats << endl;
	cout << "rodents = " << rodents << endl;

	//���ú�ָ�������1.���ñ����ʼ�� 2.���ܸ�Ϊ���������ı�����������ֻ����ͨ�ĸ�ֵ������rodents = 10�����������ܸı�����
	int rats2 = 200;
	rodents = rats2;
	cout << "rats = " << rats << endl;
	cout << "rodents = " << rodents << endl;
	
	return 0;
}