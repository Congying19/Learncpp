//��cout�Ͷ���C++���ʽ�У�char��������charָ�룬�Լ����������������ַ���������������Ϊ�ַ�����һ���ַ��ĵ�ַ��
//cout�յ��ַ�����һ���ַ���ַ�ͻ��ӡ�ô��ַ�����������ӡ��ַ������ַ���ֱ���������ַ�Ϊֹ��
#include<iostream>
using namespace std;
int main() {
	char p1[10] = "world";
	const char* p2 = "hello";//�ַ����������븳ֵ������ָ�� �����޸�ָ��ָ��ĵ�ַ
	cout << p1 << endl;
	cout << p2 << endl;//�����ӡ�Ķ����ַ����������ǵ�ַ����Ϊcout����char*����ָ�����ʾ�ַ�����
	cout << (int*)p1 << endl;
	cout << (int*)p2 << endl;
	cin >> p1;
	cout << p1 << endl;
	return 0;
}