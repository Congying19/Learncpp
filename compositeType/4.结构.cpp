//�ṹ���û��Զ������� ���Դ洢�������͵�����
#include<iostream>
using namespace std;
//�ṹ������
struct inflatable
{
	char name[20];
	float volume;
	double price;
};//�ṹĩβ�Դ��ֺ�
//�ýṹ������main()�ⲿ����Ϊ�ⲿ�������ⲿ�������Ա��������к���ʹ�á��෴���ڲ�����ֻ�ܱ���������ʹ��
int main() {
	inflatable guest =
	{
		"Mark",
		3.12,
		29.99
	};//���ýṹ�������� ����ʼ��

	//���þ����������ʽṹ������Ա��
	cout << "guest's name is " << guest.name << endl;

	//�ṹ����
	inflatable guesta[2] = {
		{"mary",5,48.9},
		{"Jack",7.8,844}
	};
	return 0;

}