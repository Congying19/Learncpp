//C����ַ�����char����ָ�� ���Խ�����Ϊ�ַ����������Ĳ���
#include<iostream>
using namespace std;
unsigned int c_in_str(const char* str, char ch);
char* buildstr(char c, int n);
int main() {
	char str1[20];
	cout << "������20��ĸ���ڵ��ַ�����\n";
	cin >> str1;
	cout << "��������Ҫ���ҵ���ĸ��\n";
	char ch;
	cin >> ch;
	cout << "�����ĸһ�������� " << c_in_str(str1, ch) << " ��\n";

	cout << "����������Ҫ���Ƶ���ĸ��\n";
	char ch2;
	cin >> ch2;
	cout << "����������Ҫ���ƵĴ�����\n";
	int times;
	cin >> times;
	//cout << "���ƽ��Ϊ��" << buildstr(ch2, times) << endl;
	char* ps = buildstr(ch2, times);
	cout << "���ƽ��Ϊ��" << ps << endl;
	delete[] ps;//�������ص���һ��new������ָ��ʱ��һ��Ҫ����һ��ָ��ָ��new�������ڴ� �����޷��ͷ�
	return 0;
}

//����ĳ����ĸ���ַ����г��ֵĴ�����
unsigned int c_in_str(const char* str, char ch)//����ı��ַ��� ��const����
{  //�����ַ�������Ҫ�����ַ������� ��Ϊ�ҵ����ַ����Զ�ͣ����
	unsigned int count = 0;
	while (*str)//str ��ʾ��һ���ַ��ĵ�ַ ���ַ�Ϊfalse���˳�ѭ��
	{
		if (*str == ch)
			count++;
		str++;//�ƶ�ָ��  �����ַ����ı�׼��ʽ
	}
	return count;
}

//����һ���ַ����������޷�����һ���ַ��� ���ǿ��Է����ַ����ĵ�ַ ��������Ч�ʸ���
char* buildstr(char c, int n) {
	char* pstr = new char[n + 1];//�������볤�ȴ�������
	pstr[n] = '\0';//����β���óɿ��ַ������ַ���
	while (n-- > 0)
		pstr[n] = c;//�Ӻ���ǰ�����ĸ
	return pstr;
}