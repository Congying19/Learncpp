#include<iostream>
using namespace std;
int main() {
	int age = 80;
	const int* pt = &age;//����ptָ��const int ��˲���ͨ��pt���޸����ֵ 
	//��pt���� ��ָ���ֵ�ǳ��� ����age����const ������age���޸�age��ֵ
	cout << "age is " << age << endl;
	cout << "*pt is " << *pt << endl;
	cout << "After change age \n";
	age += 90;
	cout << "age is " << age << endl;
	cout << "*pt is " << *pt << endl;//age��ֵ�޸� *pt��ȻҲ���޸� ��ӴﵽĿ��

	//const ���ݻ��߷�const���ݵĵ�ַ���Ը�ֵ��constָ�롣
	//��constָ��ֻ�ܽ��շ�const���ݵĵ�ַ
	//ptָ��const int ���Ըı�pt��ֵ ��ָ����ֵ ������Ȼ������*pt�޸�ֵ
	int age2 = 88;
	pt = &age2;
	cout << "now *pt is " << *pt << endl;

	int sloth = 9;
	int* const pt2 = &sloth;//����const pt2ָ��sloth ˵��pt2��ֵ���ܱ� ���ǿ���ͨ��pt2�ı�sloth��ֵ
	*pt2 += 20;
	cout << "*pt2 is " << *pt2 << endl;
	return 0;
}