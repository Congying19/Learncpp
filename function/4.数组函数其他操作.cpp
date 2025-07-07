//���ں��������������������ʵ���ԭʼ���� �������丱�� ��˿���ͨ�����øú�����ֵ��������Ԫ��
#include<iostream>
using namespace std;
int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revalue(double factor,double arr[], int n);
const int Max = 5;
int main() {
	double properties[Max];//��������
	int size = fill_array(properties, Max);//������� ����¼���鳤��
	show_array(properties, size);
	if (size > 0) {
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
	cin.get();//��ȡ��һ���س���
	cin.get();//�ó�����ͣ�ȴ�����س���
	return 0;
}

//�������Ԫ�صĺ���
int fill_array(double arr[], int limit)
{
	double temp;//��ʱ���� ������ʱ�����ж��Ƿ����Ҫ�� �ٷ�������
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ":";
		cin >> temp;
		if (!cin)//����������Ҫ���ò��������� ����cin������һ��cin>>temp��cin
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input;input process terminated.\n";//��������ͻ���ֹ���
			break;//�������forѭ��
		}
		else if (temp < 0)//�����븺����Ϊ������־
			break;
		arr[i] = temp;
	}
	return i;//ѭ�����һ���ʱ��i��1 ���i��������1 ��ʾԪ����Ŀ ����Ԫ����Ŀ����֪������˶���Ԫ��
}

//��ʾ����Ԫ�صĺ��� �������Ŀ������ʾ �������޸�Ԫ�� Ӧ�þ��������޸�
void show_array(const double arr[], int n)//const ���������� ��ζ�������������arr[]���鲻���޸� ������ζ������Ԫ�ر���ʱ����
{
	for (int i = 0; i < n; i++) {
		cout << "Property #" << (i + 1) << ": $";
		cout << arr[i] << endl;
	}
}

//�޸�����Ԫ�صĺ��� ������ÿ��Ԫ�س���һ������
void revalue(double r, double arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] *= r;
}