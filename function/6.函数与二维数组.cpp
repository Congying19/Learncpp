#include<iostream>
using namespace std;
int sum(int (*arr)[4], int size);
//int (*arr)[4] ��ʾһ��ָ����4��int��ɵ����顱��ָ��
//int *arr[4]��ʾһ������4��ָ��int��ָ�롱��ɵ�����
int main() {
	int data[3][4] = {
		{1,2,3,4},
		{2,5,4,6},
		{4,5,2,5}
	};
	cout << "sum = " << sum(data, 3) << endl;
	return 0;
}

int sum(int (*arr)[4], int size)//Ҳ����д��int sum(int arr[][4],int size) 4������ �̶� ����Ҫ����
{
	int total = 0;
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < 4; c++)
			total += arr[r][c];//ʹ�õ�ʱ��ֱ�Ӱ�arr��������������
	}
	return total;
}