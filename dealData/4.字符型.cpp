//�����ַ��ͱ���char
#include<iostream>
using namespace std;
int main() {
	char ch;    //����һ������
	cout << "Enter a characher: " << endl;
	cin >> ch;//cin�������������ĸM ����ASCII��ת��Ϊ��Ӧ������77 ����ch��
	//��ʹ������������Ҳ�ᱻ�����ַ���ȡ ����5�����ַ�"5" ��ת���ɶ�Ӧ�������ʹ洢
	cout << "you put " << ch << endl; //cout��77ת��Ϊ�ַ�M,cin\cout����Ϊ���ɱ������������ģ����������int �����77

	char ch2 = 'M'; //��c++����д�ַ�����ֵ�õ�����
	int i = ch2; //ch2���������Ը�ֵ�����ͱ���
	cout << "The ASCII code for M is " << i << endl;
	
	ch2 = ch2 + 1;//�ַ�����Ҳ���Լ���
	i = ch2;//�ٴν��ַ���ֵ����i��
	cout << "The ASCII code for " << ch2 << " is " << i << endl;

	//����ʹ�ó�Ա����cout.put()��������ַ�
	cout.put(ch2);
	return 0;
}