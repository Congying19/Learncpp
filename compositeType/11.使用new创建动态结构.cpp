#include<iostream>
using namespace std;
struct person {
	char name[20];
	int age;
};//����������ṹ��

int main() {
	//���ṹ����������������ʹ��new��������
	person* p1 = new person;
	//���ڲ�֪���������֣� ֻ֪������ָ����p1
	//����ָ����ʽṹ��Ա�Ѿ�������"."�滻��"->"��ͷ��Ա���������
	cout << "������p1�����䣺";
	cin >> p1->age;
	cout << "������p1�����֣�";
	cin >> p1->name;
	cout << p1->age<<endl;
	cout << p1->name;
	return 0;
}