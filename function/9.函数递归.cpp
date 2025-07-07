//�������Ե����Լ� ���ֹ��ܳ�Ϊ�ݹ�
#include<iostream>
using namespace std;
void countdown(int n);
//�ݹ鳣���ڽ�һ������Ϸ�Ϊ�����С�ġ����ƵĹ��� ��ʱ��Ҳ����Ϊ�ֶ���֮����
void subdivide(char arr[], int low, int high, int level);
const int Len = 88;
const int Divs = 5;
int main() {
	countdown(4);

	//ϸ�ֳ���
	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++) {
		ruler[i] = ' ';
	}
	ruler[Len - 1] = '\0';//����Ϊ�ַ���
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	cout << ruler << endl;
	for (i = 1; i <= Divs; i++) {
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		for (int j = 1; j < Len - 2;j++)
			ruler[j] = ' ';//�������ó���
	}
	return 0;
}

void countdown(int n)
{
	cout << "Counting down ..." << n <<"(n at "<<&n<<")" << endl;//ÿ�ε��ö�������µ�n ��ַ��һ��
	if (n > 0)//1.Ҫ��if��ֹ����
		countdown(n - 1);//2.Ҫ�ı䴫��Ĳ���
	cout << n << ": Kaboom!" << "(n at " << &n << ")" << endl;
}

//��һ�ѳ��Ӳ���ϸ��
void subdivide(char arr[], int low, int high, int level)
{
	if (level == 0)
		return;//if��ֹ����
	int mid = (high + low) / 2;
	arr[mid] = '|';//�ҵ��м�ֵ
	subdivide(arr, low, mid, level - 1);//�ϰ벿�ּ�����
	subdivide(arr, mid, high, level - 1);//�°벿�ּ�����
}