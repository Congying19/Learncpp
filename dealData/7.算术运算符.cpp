//�ӷ������˷��ֱ�Ϊ+-*
//������Ϊȡ���ڲ����������ͣ�����������������������ִ�����������������С��ֱ�Ӷ����������һ�����Ǹ���������������Ǹ�����
//չʾ��ģ�����%
#include<iostream>
using namespace std;
int main() {
	const int Lbs_per_stn = 14;//1Ӣʯ����14��
	int lbs;

	cout << "Enter your weight in pounds: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn; //��ȡ���� ������ʯͷ
	int pounds = lbs % Lbs_per_stn;//��ȡʣ�� ��ɢ��ʯͷ
	cout << lbs << " pounds are " << stone
		<< " stone, " << pounds << " pound(s).\n";
	return 0;
}