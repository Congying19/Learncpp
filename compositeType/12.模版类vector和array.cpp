//ģ����vecter�Զ����new ��delete ʹ�������ܷ��㣬����Ч�ʽϵ�
//ģ����array������һ�������ȹ̶���Ҳʹ�þ�̬�ڴ����
#include<iostream>
#include<vector>//ʹ��vector������������
#include<array>
using namespace std;
int main() {
	//vector�Ķ��壺
	vector<int> vi;//vi��ʼ���ȿ���Ϊ0����Ϊvector�����ڲ���������ʱ�Զ���������
	vi[0] = 1;
	vi[1] = 2;
	vi[2] = 3;
	vi[3] = 4;
	/*int n;
	cin >> n;
	vector<double> vd(n);*/

	//array�Ķ��壺
	array<int, 5> ai;
	array<double, 4> ad = { 0.1,0.2,0.3,0.4 };
	return 0;
}