//��д������������һ��ֱ��д3.1415926��8.0��0.8  
// ��������E��ʾ�� 3.45E5��ʾ3.45*10^5��ѧ������ ���ֺ�e/E֮�䲻���пո���� 0.6E-9
//�������������֣�float, double, long double  ������Ч��λ������ָ����С��Χ������
//��Чλ���������������λ ����14759��Чλ��5�� 14000��Чλ��2������ֻ��ռλ������Чλ������С�����λ�ã�14.729��Чλ����5
//ͨ��floatΪ32λ double64λ long double 80��96����128λ
#include<iostream>
using namespace std;
int main() {
	cout.setf(ios_base::fixed, ios_base::floatfield); //����setf ��ʹ�ö����ʾ����� ��ֹ���򽫽ϴ����ת��Ϊ��ѧ������
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;

	cout << "tub= " << tub;
	cout << ", a million tubs = " << million * tub; //����float ����ֻ�ܱ�֤6����Чλ ��������漰��7λ������ ��������ȷ
	cout << ", \nand ten million tubs=";
	cout << 10 * million * tub << endl;

	cout << "mint= " << mint << " and a million mints = ";//double�ܱ�֤15λ
	cout << million * mint << endl;

	return 0;
}