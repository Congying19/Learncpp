#include<iostream>
#include<cmath>
using namespace std;
struct polar
{
	double distance;
	double angle;
};
struct rect {
	double x;
	double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

void show_polar2(const polar* dapos);
void rect_to_polar2(rect* xypos, polar* dapos);

int main() {
	//ʹ��ֵ���ݣ�
	cout << "ʹ��ֵ���ݽṹ\n";
	rect rplace;
	polar pplace;

	cout << "������x,y���꣺";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);//����һ���ṹ ����һ���ṹ
		show_polar(pplace);
		cout << "Next two numbers(q to quit): ";
	}
	cin.clear();
	while (cin.get() != '\n')
		continue;//����������� ��Ȼ�����while(cin>>)ֱ���ж�false����ȥѭ��
	cout << "Done.\n";

	//ʹ�õ�ַ���ݽṹ��
	cout << "ʹ�õ�ַ���ݽṹ\n";
	rect rplace2;
	polar pplace2;
	cout << "������x,y���꣺";
	while (cin >> rplace2.x >> rplace2.y)
	{
		rect_to_polar2(&rplace2, &pplace2);
		show_polar2(&pplace2);
		cout << "Next two numbers(q to quit): ";
	}
	cout << "Done.\n";
	return 0;
}

polar rect_to_polar(rect xypos)//ֵ���ݽṹ �����ڽṹ��С�ı���
{
	polar answer;
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}

void show_polar(polar dapos)
{
	const double Rad_to_deg = 57.29577951;
	cout << "distance = " << dapos.distance;
	cout << ",angle = " << dapos.angle * Rad_to_deg;
	cout << " degrees\n";
}

void rect_to_polar2(rect* xypos, polar* dapos) //���ڴ��ݵ���ָ�����ֱ���޸Ľṹ��ֵ ����Ҫ���ؽṹ
{
	dapos->distance = sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
	dapos->angle = atan2(xypos->y, xypos->x);
}

void show_polar2(const polar* dapos)//��ַ���� ���ڴ��ݵ��ǽṹ�ĵ�ַ Ҫ��->���ʽṹ��Ա
{
	const double Rad_to_deg = 57.29577951;
	cout << "distance = " << dapos->distance;
	cout << ",angle = " << dapos->angle * Rad_to_deg;
	cout << " degrees\n";
}