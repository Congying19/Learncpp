//�ַ����Ǵ洢���ڴ�������ֽ��е�һϵ���ַ���

//c++�����ַ�����ʽһ��C����ַ�����һϵ���ַ��������Ϊ������char�����С�
// C����ַ����ص㣺�Կ��ַ�"\0"��β �����磺
//char dog[8] = { 'b','a','d','b','a','w','a','0'};�����ַ��� ֱ��cout<<dog �ᳬ�����鷶Χ,ֱ���������ַ� ֻ��ѭ���������
//char cat[8] = { 'b','a','d','b','a','w','a', '\0' };���ַ��� ����ֱ��cout<<cat
//һ����ĸһ����ĸ�ĸ�ֵ̫�鷳 ����ֱ��char fish[]="Bubbles" ���ַ�ʽ��ʽ�ذ������ַ� �������鳤�ȼǵü���
//�ַ���ƴ�� �ɿհ��ַ����ո��Ʊ���ͻ��з����������ַ��������Զ�ƴ����һ��
//���������룺getline()��ȡ����ͨ���س�������Ļ��з���ȷ�������β���������滻�з�
//			����cin.getline()��������������1.�������� 2.��ȡ�ַ�����������20���Ͷ�ȡ19���ַ� ʣ��һ�������ַ�
//���������룺get()������getline()һ�� ����get��ѻ��з�������������� �ٴ�ʹ�þͻ�������з�
#include<iostream>
#include<cstring>//����strlen()���Լ����ַ����� ���������ַ�
using namespace std;
int main() {
	char dog[8] = { 'b','a','d','b','a','w','a','0'};
	char cat[8] = { 'b','a','d','b','a','w','a', '\0' };
	cout << cat<<endl;

	////�ַ���ƴ�ӣ�
	cout << "hello" "world\n";
	cout << "hello"	"world\n";
	cout << "hello"
		"world\n";

	////C����ַ�����ʹ��
	char name1[15];
	char name2[15] = "c++owboy";
	cin >> name1;//�Ӽ���ֱ������ ���ǲ��ܳ�������
	cout << "your name has " << strlen(name1) << " words.\n";
	name2[3] = '\0';//�ֶ������ĸ�Ԫ������Ϊ���ַ� ֻ���ǰ����
	cout << name2;

	//getline()ʹ�ã�
	char name3[15];
	cin.getline(name3, 8);
	cout << name3 << endl;

	//get()�Ĳ�ͬ��
	char name4[15];
	cin.get(name4, 8);
	cout << name4 << endl;
	cin.getline(name4, 8);//��ȡ��get�������Ļ��з�ֱ�ӽ���
	cout << name4 << endl;
	
	//getline()�������÷���
	cin.getline(name3, 8).getline(name4,8);
	cout << name3 << endl << name4 << endl;

	//���ֺ��ַ���������룺
	int age;
	char name5[15];
	(cin >> age).get();//cin�������� ����cin�����������get()��ȡ�������Ļس���
	cin.getline(name5, 7);
	cout << age << endl << name5 << endl;
	return 0;
}