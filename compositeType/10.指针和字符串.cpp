//��cout�Ͷ���C++���ʽ�У�char��������charָ�룬�Լ����������������ַ���������������Ϊ�ַ�����һ���ַ��ĵ�ַ��
//cout�յ��ַ�����һ���ַ���ַ�ͻ��ӡ�ô��ַ�����������ӡ��ַ������ַ���ֱ���������ַ�Ϊֹ��
#include<iostream>
#include<cstring>
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

	//��ȡ�ַ�������������
	char animal[10] = "fox";
	char* pn = new char[strlen(animal) + 1];//����һ����ָ̬��
	//ע�ⲻ��ֱ�� pn=animal �����ᵼ��new���������鶪ʧ���޷��ڼ�������
	strcpy_s(pn, strlen(animal) + 1, animal);//���ַ������Ƶ�pn strcpy_s���������� ����һ������
	cout << pn << endl;
	cout << (int*)pn << endl;
	cout << (int*)animal << endl;
	delete[] pn;
	return 0;
}