#include<iostream>
using namespace std;
int main() {
	int n;
	do {
		cin >> n;
		if (n < 10)
			cout << "Too low" << endl;
		else if (n > 10)
			cout << "Too high" << endl;
		else
			cout << "right" << endl;

	} while (n != 10);

	//if else ���Ա�?:���ʽ���� ?:��Ϊ���������
	int i = (5 > 2) ? 7 : 8;//������ʽ����˼��5>2? ��ȷ��ֵΪ7 ������ֵΪ8 
	return 0;
}