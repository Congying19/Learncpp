#include<iostream>			//ͷ�ļ� ����cin cout
#include<climits>			//ͷ�ļ� ��������������Ϣ
using namespace std;

int main() {
	int n_int = INT_MAX;	//��������Ӣ�������»��ߡ����ֲ��ܿ�ͷ���»��߾�����Ҫ��ͷ��ʹ�������������
	short n_short = SHRT_MAX; //������һ��������Ҫ�á�=�����и�ֵ
	long n_long = LONG_MAX;	// INT_MAX��Щ��ʾ��Ӧ���͵����ֵ��������climits ͷ�ļ���
	long long n_llong = LLONG_MAX;	//һ����Ϊ�ĸ�����

	cout << "int is " << sizeof(int) << " bytes." << endl;	//sizeof����������� �����ر����������͵ĳ��� ����λ���ֽ�byte��
	//sizeof�������͵��﷨ ��Ҫ����
	cout << "short is " << sizeof n_short << " bytes." << endl;	//sizeof ���ر������﷨ ����Ҫ����
	cout << "long is " << sizeof n_long << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl;//�ֽ�������ʵ�֣���ͬϵͳ�������ֽڿ��ܲ�ͬ

	cout << "Maximum value:" << endl;
	cout << "int:" << n_int << endl;
	cout << "short:" << n_short << endl;
	cout << "long:" << n_long << endl;
	cout << "long long:" << n_llong << endl;

	return 0;
}