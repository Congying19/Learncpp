//���������Ƕ����ư˽���ʮ��������ô��ֵ
#include<iostream>
using namespace std;
int main() {
	int chest = 42;
	int waist = 0x42;//0x��ͷ��ʾʮ��������  Ŀ������֪ʮ�������� �����ֱ�Ӹ�ֵ û��Ҫת��Ϊʮ�����ٸ�ֵ
	int inseam = 042;//0��ͷ��ʾ�˽�����

	//Ĭ������� cout��ʮ���������Щ�� ��Щ���ڼ�����ڲ��Զ����Ʊ���
	cout << "chest = " << chest << endl;
	cout << "waist = " << waist << endl;
	cout << "inseam = " << inseam << endl;

	//�����Ҫ����˽��ƻ���ʮ������ ����ʹ��iostream�ṩ�Ŀ��Ʒ� ����ʹ��endlһ��
	cout << "chest = " << chest << endl;
	cout << hex;//����cout��ʮ���������
	cout << "waist = " << waist << endl;
	cout << oct; //�԰˽������
	cout << "inseam = " << inseam << endl;
	cout << dec;//�л���ʮ����
	return 0;
}