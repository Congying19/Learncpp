//�����Լ��ĺ���ʱ �����ṩ�������棺���� ԭ�� ����
#include<iostream>
using namespace std;

void simple(); //����ԭ�ͣ�����ͷ+�ֺ�; ����main()֮ǰ ���߱�������simple()����һ������ ��ֹ����
//Ҳ����ֱ�ӰѺ����������ǰ�� �����Ͳ���Ҫ����������
//����ԭ�Ͳ����б������ֻ�б������� ��������� ������ֻ��һ��ռλ�� ���Ը�����ͷ��һ��
int main() {
	cout << "main() will call the function :\n";
	simple();//�������ã�������+�������
	cout << "main() id finished with the simple() function.\n";
	return 0;
}

void simple() {//�������壺�����ĺ��� void��ʾ����Ϊ�� 
	cout << "I'm but a simple function.\n";
	//����з���ֵ ��Ҫдreturn��� ��������ҲҪд
}