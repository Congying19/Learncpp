#include<iostream>
#include<string>
using namespace std;
struct free_throws
{
	string name;
	int made;//�����ɹ�����
	int attempt;//�������Դ���
	float percent;//��ռ�ٷֱ�
};
void display(const free_throws& ft);
void set_pc(free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);
int main() {
	free_throws one = { "Mark",13,14 };
	free_throws two = { "Jack",10,16 };
	free_throws three = { "Mary",7,9 };
	free_throws four = { "Tom",5,9 };
	free_throws five = { "Tim",6,14 };
	free_throws team = { "Throwgoods",0,0 };//�����Ŷ�

	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	dup = accumulate(team, five);
	cout << "Displaying team:\n";
	display(team);
	cout << "Displaying dup after assignment:\n";
	display(dup);
	return 0;
}

void display(const free_throws& ft)
{
	cout << "Name: " << ft.name << endl;
	cout << "Made: " << ft.made << endl;
	cout << "Attempts: " << ft.attempt << endl;
	cout << "Percent: " << ft.percent << endl;
}

void set_pc(free_throws& ft)
{
	if (ft.attempt != 0) {
		ft.percent = 100.0f * float(ft.made) / float(ft.attempt);
	}
	else {
		ft.percent = 0;
	}
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempt += source.attempt;
	target.made += source.made;
	set_pc(target);
	return target;//�������� �������õĺ���ʵ�����Ǳ����õı����ı���
	//��ͳ���ر��� ���ȸ��Ƶ���ʱλ�� �ٸ��Ƶ���������λ��
	//����������ֱ�Ӹ��Ƶ���������λ�� Ч�ʸ���

	//���ܷ�����ʱ���������ú�ָ�� ��Ϊ�������������ʱ�����Ͳ���������
}

//ʹ�����õ����ɣ�1.���޸����� 2.ͨ���������ö��������ݶ��� ��߳��������ٶ�

//����ʹ�ô��ݵ�ֵ�����޸ĵĺ�����
//1�����ݶ����С ��ֵ����
//2�����ݶ��������� ʹ��ָ�� ����ָ������Ϊָ��const��ָ��
//3�����ݶ����ǽϴ�ṹ ʹ��constָ���const���� 
//4�����ݶ���������� ��ʹ��const����