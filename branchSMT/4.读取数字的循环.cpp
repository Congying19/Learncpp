//int n; cin>>n; ���û�����Ĳ�������ʱ�����������������n��ֵ���ֲ��䣬��ƥ����������ڶ����У�cin�����е�һ�������Ǳ����ã�
//��cin�����ĵ��÷���false
//�������ĸ�������������ö�ȡ���ֵ�ѭ����
#include<iostream>
using namespace std;
const int Max = 5;
int main() {
	//Ŀ�꣺����һ������ ���û����� ���û�������ĸʱ ��������
	double fish[Max];
	cout << "Please enter the weights of your fish.\n";
	cout << "You may enter up to " << Max
		<< " fish <q to terminate>.\n"; //�û�����������ʾ
	cout << "fish #1:";
	int i = 0;
	while (i<Max && cin >> fish[i]) {  //�ж��������Ƿ�Խ�� ���û������������ж��Ƿ���� 
		//cin>>fish[i]ʵ������һ��cin�����ĵ��� �ú�������cin ���cinλ�ڲ��������� ��ת��Ϊbool���� �ɹ�Ϊtrue ʧ��Ϊfalse
		if (++i < Max) {//ǰ��++ �ȼӺ��ж�
			cout << "fish #" << i + 1 << ":";//���������0��ʼ���� ����Ҫi+1 ֻ�ı����ֵ ���ı�i��ֵ ������i++
		}
	}
	for (int j = 0; j < Max; j++) {
		cout << fish[j] << "\t";
	}
	cout << endl;

	//���������������֮�����������Ӧ�ý��У�1.����cin�Խ����µ����� 2.ɾ���������� 3.��ʾ�û�������
	double fish2[Max];
	cout << "Please enter the weights of your fish.\n";
	cout << "You may enter up to " << Max
		<< " fish <q to terminate>.\n"; //�û�����������ʾ
	int k;
	for (k = 0; k < Max; k++) {
		cout << "fish #" << k + 1 << ": ";
		while (!(cin >> fish2[k])) {//�������뷵��false ����!false���Խ���ѭ�� �Ӷ�ɾ��
			cin.clear();//����cin
			while (cin.get() != '\n') {//һ��һ����ȡ��β֮ǰ���е����� �ﵽɾ��Ŀ��
				continue;//������ǰѭ��
			}
			cout << "Please enter a number: ";
		}
	}
	for (int j = 0; j < Max; j++) {
		cout << fish2[j] << "\t";
	}
	return 0;
}