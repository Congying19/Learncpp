//����ָ������ã���һ��������Ҫ������������ʱ ����һ��һ��д����
#include<iostream>
using namespace std;
double betsy(int);
double pam(int);
double ppp(int);
//��������������һ�� ������ͬ����ָ���ʾ
void estimate(int lines, double (*pf)(int));
//��������ָ��ʱ ��������ָ��ָ��ĺ������� ��ȷ���������͵�֪���������������͡����������б�����������Ҫ��ÿ������ĺ�������һ����
//double (*pf)(int)��ʾһ��ָ�򡰷�������Ϊdouble,�����б���һ��Int���ĺ�����ָ�� �Ͷ�ά����һ�� ���Ų�����
//����֮��Ϳ��԰�  (*pf)  ����������ʹ�� ���߰�  pf  ֱ�ӵ���������ʹ��
int main() {
	int code;
	cout << "How many lines of code do you need?";
	cin >> code;
	cout << "Here's Betsy's estimate:\n";
	estimate(code, betsy);//����ָ�봫��ֱ���ú���������
	cout << "Here's Pam's estimate:\n";
	estimate(code, pam);

	//�����������̫����ô�죿ʹ��auto�Զ��ж�����
	auto p1 = betsy;
	cout << betsy(code) << endl;
	cout << p1(code) << endl;

	//����ָ������������
	double (*pf[3])(int) = { betsy,pam,ppp };
	cout << pam(code) << endl;
	cout << pf[1](code) << endl;
	cout << (*pf[1])(code) << endl;
	return 0;
}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

double ppp(int lns) {
	return 0;
}

void estimate(int lines, double (*pf)(int)) {
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n";
}