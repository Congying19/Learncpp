//���������Ͳ���ȷ��ʱ����ʹ��decltype�ؼ��� ����xyp=T1+T2;T1,T2���Ǵ�������xyp����ȷ��
//decltype�﷨��decltype(expression) var;
//��һ����expression��û�����ŵı�ʶ������var���ʶ��������ͬ
//�ڶ�����expression�Ǻ������ã���var��expression����������ͬ��ע��ֻ�ǲ鿴����ԭ�� ��û���������ú���
//��������expression���������ţ�varΪָ��expression���͵�����
//���Ĳ���ǰ���������ǣ���var��expression������ͬ
#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T1,typename T2>
void test1(T1 x, T2 y);

template<typename T1, typename T2>
auto test2(T1 x, T2 y) -> decltype(x + y);

int main() {
	int t1 = 10;
	double t2 = 10.2;
	//��һ��
	decltype(t1) t11;
	cout << "Type of t11 is " << typeid(t11).name() << endl;

	//������
	decltype((t2)) t22=t2;
	cout << "Type of t22 is " << typeid(t22).name() << endl;

	//���Ĳ�
	decltype(10 + 20.2) t33;
	cout << "Type of t33 is " << typeid(t33).name() << endl;

	test1(t1, t2);
	cout << "test2 = " << test2(t1, t2) << endl;
	cout << "Type of test2 is " << typeid(test2(t1, t2)).name() << endl;
	return 0;
}

template<typename T1,typename T2>
void test1(T1 x, T2 y)
{
	typedef decltype(x + y) xytype;//��x+y�������������һ������ xytype
	xytype xpy = x + y;//�������������һ������
	cout << "Type of xpy is " << typeid(xpy).name() << endl;
}

//����뷵��x+y��ô�죿
template<typename T1, typename T2>
auto test2(T1 x,T2 y) ->decltype(x+y)//���÷�������
{
	return x + y;
}

