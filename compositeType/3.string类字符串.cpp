//�ַ�������ʽ��������string ����
//ʹ��string �����������ͷ�ļ�string
//1.����ʹ��C����ַ�������ʼ��string����
//2.����ֱ��cin����������洢��string������
//3.cout����ֱ�����
//4.�������������±���ʴ洢��string�ڵ��ַ�

//string�Ĳ�����
//1.��ֵ ����str2 = str1
//2.ƴ�� str2+str1
//3.���� str1+=str2

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main() {
	//string ƴ��
	string str1 = "hello";
	string str2 = " world";
	cout << str1 + str2<<endl;

	//����string����
	cout << "The size of " << str1 << " is " << str1.size()<<endl;

	
	//getline()��ȡstring����
	string str3;
	getline(cin, str3);//���ｫcin��Ϊ���� ��ʾҪ������ȥ�������� ���ⲻ�ö������볤�� string���������Զ�������С
	cout << str3 << endl;

}