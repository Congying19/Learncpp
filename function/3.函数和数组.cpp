#include<iostream>
using namespace std;
const int ArSize = 8;
int sum_arr(int arr[], int n);
int main() {
	int cookies[ArSize] = { 10,20,14,66,85,12,54,11 };
	int sum = sum_arr(cookies, ArSize);
	//cookies�ǵ�һ��Ԫ�ص�ַ ��Ϊintָ�� ��������int* ��������ʱ����Ӧ����int* arr ˵��int* arr��int arr[]������ȷ�ġ�
	//ֻ���ں���ͷ���ߺ���ԭ����int* arr ��int arr[]���������ͬ��
	cout << "Total cookies eaten: " << sum << endl;
	cout << "size of cookies is " << sizeof cookies << endl;
	//����ֻ��ͨ���ڶ���������֪����Ԫ�ظ��� ��˿��ԶԺ���˵��
	int sum2 = sum_arr(cookies + 4, 4);//�������λ
	cout << "The last four cookies eaten: " << sum2 << endl;
	return 0;
}

int sum_arr(int arr[], int n) {//�����βν��������ַ ֻ�ǿ�����һ�ݵ�ַ û�п���һ������
	//����ͷ�����int n����ʽ�������鳤�� 
	//�ں������޷�����sizeof arr/sizeof arr[0]��������鳤�ȣ���Ϊsizeof arrֻ��ָ�볤�ȣ�sizeof cookies �������鳤�ȣ���ʹarr = cookies
	cout << "size of arr is " << sizeof arr<<endl;
	int total = 0;
	for (int i = 0; i < n; i++)
		total = total + arr[i];
	return total;
}