//Ĭ�ϲ���ָ���ǣ�������������ʡ����ʵ��ʱ�Զ�ʹ�õ�һ��ֵ
//1.Ĭ�ϲ�����Ҫ�ں���ԭ�������� �������岻��
//2.���ڴ������б�ĺ�������������������Ĭ��ֵ�����һ������������Ĭ��ֵ�����ұߵ����в�����Ҫ����Ĭ��ֵ
#include<iostream>
using namespace std;
const int Asize = 80;
char* left(const char* str, int n = 1);
//1.�뷵���ַ�������char*
//2.�����޸��ַ�������const char* str
//3.����nĬ��ֵ��1
int main() {
	char sample[Asize];
	cout << "������һ���ַ���\n";
	cin.get(sample, Asize);//���ֱ����cin>>sample �͵��ֶ�������ַ�
	char* ps = left(sample, 4);//��ȡ����ĸ��ַ�
	cout << ps << endl;
	delete[] ps;
	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
	return 0;
}

char* left(const char* str, int n)//����Ҫ����Ĭ��ֵ
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];//ʹ��new������̬���� �����ǵü��Ͽ��ַ�
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';//��ʣ�ಿ������Ϊ0
	return p;
}