//whileѭ������ʵ���ó���ȴ�һ��ʱ��
#include<iostream>
#include<ctime>//����clock()���� ��clock_t����
using namespace std;
int main() {
	cout << "Enter the delay time , in seconds:";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;//CLOCKS_PER_SEC��ʾÿ���Ӱ�����ϵͳʱ�䵥λ��������ת��Ϊϵͳʱ��
	cout << "starting\a\n";
	clock_t start = clock();//clock()���س���ʼִ�к��ϵͳʱ��
	while (clock() - start < delay);
	cout << "done\a\n";
	return 0;
}