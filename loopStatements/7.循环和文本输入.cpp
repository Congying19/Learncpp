//ѭ������Ҫ������������ַ��ض�ȡ�����ļ����߼��̵��ı���
#include<iostream>
using namespace std;
int main() {
	char ch = 0;
	int count = 0;
	cout << "Enter characters;enter # to quit:\n";
	cin >> ch;
	while (ch != '#') {//�Ӽ��̶�ȡ���� ����#��ֹͣ
		cout << ch;
		count++;
		cin >> ch;//����һ��������abcdefg# ÿ��ѭ���������ȡһ��ֱ������#
	}
	cout << endl << count << "characters read\n";

	return 0;
}