#include<iostream>
using namespace std;
int main() {
	int choice;
	cin >> choice;
	while (choice < 5) {
		switch (choice) { //choice ������һ�����Ϊ����ֵ�ı��ʽ
		case 1://case �����ֵ �Ǳ��ʽ���ܵý��
			cout << "���һ\n";
			break;//breakȷ��ִֻ���ض�������䣬û��break�ͻ�ִ����һ��case 
			//break����switch������switch , ��������switch���ڵ�ѭ��
			//continueֻ������ѭ���� ������һ��ʣ��Ĵ���
		case 2:
			cout << "�����\n";
			break;
		case 3:
			cout << "�����\n";
			break;
		case 4:
			cout << "�����\n";
			break;
		default:
			cout << "û��������\n";
			break;
		}
		cin >> choice;
	}
	return 0;
}