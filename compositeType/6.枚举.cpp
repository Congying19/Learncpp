#include<iostream>
using namespace std;
int main() {
	enum spectrum{red , orange ,yellow};
	//1.��spectrum��Ϊ�����͵����� spectrum��Ϊö��
	//2.��red orange yellow ��Ϊ���ų��� Ĭ�϶�Ӧ0 1 2 ��Щ��������ö����
	spectrum band = red;//ֻ�ܽ�ö������ֵ��ö�����͵ı���
	cout << band << endl;

	enum spectrum2{red2=10,orange2=19,yellow2};
	//�����ֶ���ֵ �������û�и�ֵ �ͱ�ǰ���1 ��һ��û�и�ֵ��Ϊ0
	spectrum2 band2 = yellow2;
	cout << band2;
	return 0;
}