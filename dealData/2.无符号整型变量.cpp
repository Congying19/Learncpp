//�����޷������ͱ����Լ������������
#include<iostream>
#include<climits>
#define ZERO 0   //1.���峣���﷨ 2.define��ʾԤ��������������ZERO�����滻����0 3.����һ�㶼�ô�д��ĸ��ʾ
using namespace std;
int main() {
	short sam = SHRT_MAX;	//��ʼ��һ������,Ĭ���з���
	unsigned short sue = sam; //1.sam�Ѿ������˿��Ը�ֵ������ 2.�޷��ű���ֻ��Ҫǰ���һ��unsigned
	
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl	//һ�仰������д
		<< "Add $1 to each account." << endl << "Now ";
	sam = sam + 1;         //�з����ͷ�Χ��-32768��32767
	sue = sue + 1;			//�޷����ͷ�Χ��0��65535   ����������ƾͻ�ص�0����һ��
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited.\nPoor Sam!" << endl;	// \n�൱��endl���з�
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl;
	cout << "Take $1 from each account." << endl << "Now ";
	sam = sam - 1;
	sue = sue - 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
	return 0;

}