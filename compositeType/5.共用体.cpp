//��������Դ洢��ͬ���͵ı���������һ��ֻ�ܴ洢һ��������������һ��
#include<iostream>
using namespace std;
union one4all {
	int int_val;
	long long_val;
	double double_val;
};
int main() {
	one4all pail;
	pail.int_val = 15;
	cout << pail.int_val << endl;
	pail.double_val = 19.9;
	cout << pail.double_val << endl;//�����ĺô��ǽ�ʡ�ڴ� ��Щ�����ж�����ʽ ����Ʒ������ ���ַ�Ҳ������
	return 0;
}